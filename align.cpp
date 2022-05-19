#include "align.h"
void Needleman_Wunsch(std::string A, std::string B, size_t sizea, size_t sizeb, 
                        int match, int mismatch, int gap)
{
    // create memory for DP matrix
    int **DP_Matrix = new int* [sizeb+1];
    for(int i = 0; i <= sizeb; i++)
    {
        DP_Matrix[i] = new int [sizea+1];
    }

    // create memory for Traceback Matrix
    char **TB_Matrix = new char* [sizeb+1];
    for(int i = 0; i <= sizeb; i++)
    {
        TB_Matrix[i] = new char [sizea+1];
    }

    struct timeval t;
    tick(&t);
    // Initialise First row and column of DP and Traceback Matrix
#pragma omp parallel for
    for(int j = 0; j <= sizea; j++)
    {
        DP_Matrix[0][j] = j*gap;
        TB_Matrix[0][j] = 2;
    }
    
#pragma omp parallel for
    for(int i = 0; i <= sizeb; i++)
    {
        DP_Matrix[i][0] = i*gap;
        TB_Matrix[i][0] = 1;
    }

    // algorithm
    for(int i = 1; i <= sizeb; i++)
    {
        for(int j = 1; j <= sizea; j++)
        {
            char nuc_a = A[j-1];
            char nuc_b = B[i-1];

            int diag_score;
            if(nuc_a == nuc_b)
                diag_score = DP_Matrix[i-1][j-1] + match;
            else
                diag_score = DP_Matrix[i-1][j-1] + mismatch;
            
            pair<int, int> temp = max_score(DP_Matrix[i][j-1] + gap, diag_score, DP_Matrix[i-1][j] + gap);
            DP_Matrix[i][j] = temp.first;          
            TB_Matrix[i][j] = temp.second;
        }
    }

    /* for(int j = 1; j <= sizea; j++)
    {
        for(int i = 1; i <= sizeb; i++)
        {
            char nuc_a = A[j-1];
            char nuc_b = B[i-1];

            int diag_score;
            if(nuc_a == nuc_b)
                diag_score = DP_Matrix[i-1][j-1] + match;
            else
                diag_score = DP_Matrix[i-1][j-1] + mismatch;
            
            pair<int, int> temp = max_score(DP_Matrix[i][j-1] + gap, diag_score, DP_Matrix[i-1][j] + gap);
            DP_Matrix[i][j] = temp.first;          
            TB_Matrix[i][j] = temp.second;
        }
    } */
    cout << DP_Matrix[sizeb][sizea] << "\n";
    double time = tock(&t);
    cout << time*1000 << " ms\n";
    // print the matrix
    //Print_Matrix(&DP_Matrix[0][0], sizea, sizeb);
 
    //cout << "\n\n";
    /* for(int i = 0; i <= sizeb; i++)
    {
        for(int j = 0; j <= sizea; j++)
        {
            printf("%2d ", TB_Matrix[i][j]);
        }
        std::cout << "\n";
    }

    cout << "\n\n"; */

    /* Print_Alignment(TB_Matrix, A, B, sizea, sizeb); */
    delete[] DP_Matrix;
    delete[] TB_Matrix;
    return;
}