#include <stdio.h>
#include <stdlib.h>

void pascalTriangle(int n) {
	int c;
	for (int i=1;i<=n;i++) {
		c = 1;
		for(int j=1;j<=i;j++) {
			printf("%d ",c);
			c = c*(i-j)/j;
		}
		printf("\n");
	}
}

int main() {
	int n = 5;
	pascalTriangle(n);
	printf("\n");
	return 0;
}
