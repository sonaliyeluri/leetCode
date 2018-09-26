#include <stdio.h>

#define N 9
#define UNASSIGNED 0

int isUsedInRow(int grid[N][N], int row, int num){
	for (int col = 0; col < 9; col++) 
		if (grid[row][col] == num) 
			return 1;
	return 0;
}

int isUsedInCol(int grid[N][N], int col, int num) {
	for (int row = 0; row < 9; row++)
		if (grid[row][col] == num)
			return 1;
	return 0;
}

int isUsedInBox(int grid[N][N], int startRow, int startCol, int num) {
	for (int row = 0; row < 3; row++) 
		for (int col = 0; col < 3; col++)
			if (grid[row + startRow][col + startCol] == num) 
				return 1;
	return 0;
}

int isNumUsed(int grid[N][N], int row, int col, int num) {
	return !isUsedInRow(grid, row, num) 
			&& !isUsedInCol(grid, col, num) 
			&& !isUsedInBox(grid, row - (row % 3), col - (col %3), num);
}

int findUnassigned(int grid[N][N], int *row, int *col) {
	for (*row = 0; *row < N; (*row)++)
		for (*col = 0; *col < N; (*col)++)
			if (grid[*row][*col] == 0)
				return 1;
	return 0;
}

int solve(int grid[N][N]) {
	
	int row = 0;
	int col = 0;
	
	if (!findUnassigned(grid, &row, &col))
		return 1;
	
	for (int num = 1; num <= N; num++ ) {
		if (isNumUsed(grid, row, col, num)) {
			grid[row][col] = num;
			if (solve(grid))
				return 1;
			grid[row][col] = UNASSIGNED;
		}
	}
	return 0;
}

void printGrid(int grid[N][N]) {
	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++)
			printf("%2d", grid[row][col]);
		printf("\n");
	}
}

int main() {
	
	int grid[N][N] = {{0,0,0, 0,0,3, 2,9,0},
			 {0,8,6, 5,0,0, 0,0,0},
			 {0,2,0, 0,0,1, 0,0,0},
			 {0,0,3, 7,0,5, 1,0,0},
			 {9,0,0, 0,0,0, 0,0,8},
			 {0,0,2, 9,0,8, 3,0,0},
			 {0,0,0, 4,0,0, 0,8,0},
			 {0,4,7, 1,0,0, 0,0,0}};
	
	if (solve(grid))
		printGrid(grid);
	else
		printf("No solution Exists");

	return 0;
}
