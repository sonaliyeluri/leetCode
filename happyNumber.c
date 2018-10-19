#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int numSquare(int n) {
	int sum = 0;
	int temp;
	while (n != 0) {
		temp = n%10;
		n = n/10;
		sum = sum+(temp*temp);
	}
	return sum;
}

int happy(int n) {
	int temp = n;
	if (n == 1)
		return 1;
	while (n != 1) {
		n = numSquare(n);
		if (n == 1)
			return 1;
		else if (temp == n || n == 4)
			return 0;
	}
	return 0;
}

int main() {
	int n;
	printf("Enter a number to check if its happy number: ");
	scanf("%d",&n);
	if (happy(n) == 1)
		printf("Happy Number\n");
	else
		printf("Not a Happy Number\n");
	return 0;
} 
