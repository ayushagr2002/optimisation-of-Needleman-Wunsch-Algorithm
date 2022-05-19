#include "helper.h"
#include <sys/time.h>
#include <stdlib.h>
using namespace std;
int getIndex(char A)
{
    if(A == 'A' or A == 'a')
        return 0;
    else if(A == 'T' or A == 't')
        return 1;
    else if(A == 'G' or A == 'c')
        return 2;
    else
        return 3;
}

pair<int, int> max_score(int A, int B, int C)
{
    if(A >= B && A >= C)
        return make_pair(A, 2);
    else if(B >= A && B >= C)
        return make_pair(B, 0);
    else if(C >= A && C >= B)
        return make_pair(C, 1);
}

void tick(struct timeval *t)
{
    gettimeofday(t, NULL);
}

double tock(struct timeval *t)
{
    struct timeval now;
    gettimeofday(&now, NULL);
    return(double) (now.tv_sec - t->tv_sec) + 
    ((double)(now.tv_usec - t->tv_usec)/1000000.);
}

void Print_Matrix(int *Matrix, size_t sizea, size_t sizeb)
{
    for (size_t i = 0; i <= sizeb; i++)
    {
        for (size_t j = 0; j <= sizea; j++)
        {
            printf("%3d ", Matrix[i * (sizea + 1) + j]);
        }
        cout << "\n";
    }
}

void Print_Alignment(int *TB_Matrix, string A, string B, size_t sizea, size_t sizeb)
{
    size_t i = sizeb, j = sizea;
    string align_a = "", align_b = "";
    while (!(i == 0 && j == 0))
    {
        if (TB_Matrix[i * (sizea + 1) + j] == 0)
        {
            align_a += A[j - 1];
            align_b += B[i - 1];
            i--;
            j--;
        }
        else if (TB_Matrix[i * (sizea + 1) + j] == 1)
        {
            align_a += '_';
            align_b += B[i - 1];
            i--;
        }
        else
        {
            align_a += A[j - 1];
            align_b += "_";
            j--;
        }
    }

    // Print the Alignment
    reverse(align_a.begin(), align_a.end());
    reverse(align_b.begin(), align_b.end());
    cout << align_a << "\n"
         << align_b << "\n";
}