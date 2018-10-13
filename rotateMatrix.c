#include <stdio.h>
#include <stdlib.h>
#define N 3

void rotateMatrix(int mat[][N]) {
	int x, y, temp;
	for(x=0;x<N/2;x++) {
		for(y=x;y<N-x-1;y++) {
			temp = mat[x][y];
			mat[x][y] = mat[y][N-1-x];
			mat[y][N-1-x] = mat[N-1-x][N-1-y];
			mat[N-1-x][N-1-y] = mat[N-1-y][x];
			mat[N-1-y][x] = temp;
		}
	}
}
void displayMatrix(int mat[][N]) {
	int i, j;
        for(i=0;i<N;i++){
                for(j=0;j<N;j++)
                        printf("%d ",mat[i][j]);
                printf("\n");
        }
}

int main() {
	int mat[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int n = sizeof(mat)/sizeof(mat[0]);
	printf("Size od Matrix: %dx%d\n",n,n);
	displayMatrix(mat);
	printf("Matrix after rotating by 90..\n");
	rotateMatrix(mat);
	displayMatrix(mat);
	return 0;
}
