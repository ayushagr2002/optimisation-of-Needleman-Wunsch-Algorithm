# optimisation-of-Needleman-Wunsch-Algorithm
An optimised implementation of Needleman Wunsch Algorithm for Global Alignment of DNA sequences using anti-diagonal and tile based approach

## Team Members:
- Ayush Agrawal (2020101025)
- Shreyansh Agarwal (2020101013)

Due to the dependency involved from up, left and diagonal cell, it is a challenge to parallelize the Needleman Wunsch Algorithm.
There are two approaches followed in the code to optimise the program:
- **Anti Diagonal Based Approach**: We observe that there are no dependencies involved in calculating cells in an anti-diagonal. Therefore, we can parallelize the calculation of cells on different cores of the CPU.
- **Tiling Based Approach**: We can divide the entire `m X n` matrix into tiles of size `k X k` and along an anti-diagonal, tiles can be computed in parallel and within the tiles, individual cells can be computed using the traditional row major fashion. This gives the combined advantage of parallelization and cache coherency.

We were able to achieve a speed-up of approximately **8.5X** using the tile based approach as compared to the traditional sequential row calculation of cells.
