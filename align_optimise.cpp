#include "align.h"
#include <stdlib.h>
#include <sys/time.h>
#include <stdlib.h>
#include <omp.h>
using namespace std;

void Needleman_Wunsch_optimise(std::string A, std::string B, size_t sizea, size_t sizeb,
                               int match, int mismatch, int gap)
{
    int *DP_Matrix = new int[(sizeb + 1) * (sizea + 1)];
    int *TB_Matrix = new int[(sizeb + 1) * (sizea + 1)];
    size_t sum = 0;
    struct timeval t;
    tick(&t);
#pragma omp parallel for
    for (size_t j = 0; j <= sizea; j++)
    {
        DP_Matrix[j] = j * gap;
        TB_Matrix[j] = 2;
    }

#pragma omp parallel for
    for (size_t i = 0; i <= sizeb; i++)
    {
        DP_Matrix[i * (sizea + 1)] = i * gap;
        TB_Matrix[i * (sizea + 1)] = 1;
    }

    for (sum = 2; sum < (sizeb + 1) + (sizea + 1); sum++)
    {

#pragma omp parallel for simd
        for (size_t i = sum - min(sum, sizea + 1) + 1, j = min(sum, sizea + 1) - 1;
             i <= (min(sum, sizeb + 1) - 1); i++, j--)
        {
            char nuc_a = A[j - 1];
            char nuc_b = B[i - 1];

            int diag_score;
            if (nuc_a == nuc_b)
                diag_score = DP_Matrix[(i - 1) * (sizea + 1) + j - 1] + match;
            else
                diag_score = DP_Matrix[(i - 1) * (sizea + 1) + j - 1] + mismatch;

            pair<int, int> temp = max_score(DP_Matrix[(i) * (sizea + 1) + j - 1] + gap, diag_score, DP_Matrix[(i - 1) * (sizea + 1) + j] + gap);
            DP_Matrix[i * (sizea + 1) + j] = temp.first;
            TB_Matrix[i * (sizea + 1) + j] = temp.second;
        }
    }
    cout << DP_Matrix[(sizeb) * (sizea + 1) + sizea] << "\n";
    double time = tock(&t);
    cout << time * 1000 << " ms\n";
    /* cout << "DP MATRIX\n";
    Print_Matrix(DP_Matrix, sizea, sizeb);
    cout << "TB MATRIX\n";
    Print_Matrix(TB_Matrix, sizea, sizeb);
    cout << "\n\n";
    Print_Alignment(TB_Matrix, A, B, sizea, sizeb); */
    delete[] DP_Matrix;
    delete[] TB_Matrix;
}