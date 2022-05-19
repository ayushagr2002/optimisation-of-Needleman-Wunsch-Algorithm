#include <bits/stdc++.h>
#include "align.h"
using namespace std;

int main()
{
    string A, B;

    // take input of both sequences
    ifstream inputFile("Sequences.txt");
    if (inputFile.is_open())
    {
        getline(inputFile, A);
        getline(inputFile, B);
        inputFile.close();
    }
    else
    {
        cout << "Unable to open file\n";
        return 0;
    }

    // cout << A << "\n" << B << "\n";
    /* Needleman_Wunsch(A, B, A.size(), B.size(), 2, -1, -1);
    Needleman_Wunsch_optimise(A, B, A.size(), B.size(), 2, -1, -1); */
    Needleman_Wunsch_optimise_tile(A, B, A.size(), B.size(), 2, -1, -1, 3);
    return 0;
}