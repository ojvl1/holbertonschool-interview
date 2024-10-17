#ifndef SANDPILES__H
#define SANDPILES__H

#define N_ROWS 3
#define N_COLS 3
#define MAX_GRAINS 3

void print_sandpile(int grid[3][3]);
int check_is_stable(int grid1[3][3], int grid2[3][3]);
void sum_grids(int grid1[3][3], int grid2[3][3]);
void toppling_round(int grid1[3][3], int grid2[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void topple(int grid[3][3]);
int is_unstable(int grid[3][3]);
static void print_grid(int grid[3][3]);
static void print_grid_sum(int grid1[3][3], int grid2[3][3]);

#endif // SANDPILES_H
