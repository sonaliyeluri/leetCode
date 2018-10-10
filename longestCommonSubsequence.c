#include <stdio.h>
#include <string.h>

int max(int a, int b) {
        return (a>b)?a:b;
}

int lcs(char *x, char *y, int m, int n) {
	int i, j;
	int l[m+1][n+1];
	for (i=0;i<=m;i++) {
		for (j=0;j<=n;j++) {
			if (i == 0 || j == 0)
				l[i][j] = 0;
			else if(x[i-1] == y[j-1])
				l[i][j] = 1+l[i-1][j-1];
			else 
				l[i][j] = max(l[i-1][j],l[i][j-1]);
		}
	}
	return l[m][n]; 
	//if (m == 0 || n == 0)
	//	return 0;
	//else if (x[m-1] == y[n-1])
	//	return 1+lcs(x, y, m-1, n-1);
	//else
	//	return (max(lcs(x, y, m-1, n),lcs(x, y, m, n-1)));
}

int main() {
	char x[] = "AGGTAB";
	char y[] = "GXTXAYB";
	int m = strlen(x);
	int n = strlen(y);
	printf("Length of Longest Common Subseuence %d", lcs(x,y,m,n));
	printf("\n");
	return 0;
}
	
