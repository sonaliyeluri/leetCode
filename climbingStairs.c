#include <stdio.h>
#include <stdlib.h>

int climbingStairs(int n) {
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else
		return climbingStairs(n-1)+climbingStairs(n-2);
}

int main() {
	int n;
	printf("Enter no of steps: ");
	scanf("%d",&n);
	printf("No.of ways to climb %d steps: %d", n, climbingStairs(n));
	printf("\n");
	return 0;
}
