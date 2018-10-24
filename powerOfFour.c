#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool isPower(int n) {
	int i = 0;
	if (n < 4 && n != 1)
		return 0;
	while (pow(4, i) <= n) {
		if (pow(4, i) == n)
			return true;
		i++;
	}
	return false;
}

int main() {
	int n;
	printf("Enter a number to check is Power of 4: ");
	scanf("%d",&n);
	if (isPower(n) == true)
		printf("True");
	else
		printf("False");
	printf("\n");
	return 0;
}
