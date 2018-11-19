#include <stdio.h>
#include <stdlib.h>

#define n 3
#define m 3

void transpose(int a[][n], int b[][m]) {
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			b[i][j] = a[j][i];
}

void printMatric(int a[][n]) {
	for (int i=0;i<m;i++) {
		for (int j=0;j<n;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
}

int main() {
	int a[m][n] = {{1,2,3},{4,5,6},{7,8,9}};
	int b[n][m];
	printMatric(a);
	transpose(a,b);
	printMatric(b);
	printf("\n");
	return 0;
}	
