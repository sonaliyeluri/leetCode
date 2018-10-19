#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int squareRoot(int n) {
	int res;
	res = pow(n, 0.5);
	return res;
}

int main() {
	int n = 8;
	int res = squareRoot(n);
	printf("Sqrt(%d) is %d", n, res);
	printf("\n");
	return 0;
}
