#include <stdio.h>

int sum(int a, int b) {
	if (a == 0)
		return b;
	else if (b == 0)
		return a;
	else
		return sum(a^b, (a&b)<<1);
}

int main() {
	int a = 0, b = 4;
	printf("Sum of %d and %d: %d", a, b, sum(a,b));
	printf("\n");
	return 0;
}
