#include <bits/stdc++.h>
#include "helper.h"
using namespace std;
void Needleman_Wunsch(std::string A, std::string B, size_t sizea, size_t sizeb, 
                        int match, int mismatch, int gap);
void Needleman_Wunsch_optimise(std::string A, std::string B, size_t sizea, size_t sizeb, 
                        int match, int mismatch, int gap);

void Needleman_Wunsch_optimise_tile(std::string A, std::string B, size_t sizea, size_t sizeb,
                               int match, int mismatch, int gap,int tile_size);