#include<stdio.h>
#define N 9
int grid [N][N];
isSafe(int row, int col, int num) {
    int i, j;

        for (i = 0; i < N; i++) {
        if (grid[row][i] == num) {
            return 0;
        }
    }

        for (i = 0; i < N; i++) {
        if (grid[i][col] == num) {
            return 0;
        }
    }

       int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[startRow + i][startCol + j] == num) {
                return 0;
            }
        }
    }

    return 1; }
