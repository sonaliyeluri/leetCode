#include <stdio.h>
#include <stdlib.h>

int modularExp(int x, int y, int p) {
	int i;
	for (i=1;i<y;i++) {
		x = x<<1;
	}
	int res = x%p;
	printf("%d\n",res);
	return res;
}

int main() {
	int x = 2;
	int y = 4;
	int p = 15;
	int res = modularExp(x,y,p);
	printf("\nModular Exponentiation: %d",res);
	printf("\n");
	return 0;
}
		
