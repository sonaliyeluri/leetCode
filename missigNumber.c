#include <stdio.h>
#include <stdlib.h>

int missingNumber (int a[], int n) {
	int total;
	total = (n+1)*(n+2)/2;
	for (int i=0;i<n;i++)
		total -= a[i];
	return total;
}

int main() {
	int a[] = {1, 2, 3, 5, 6};
	int n = sizeof(a)/sizeof(a[0]);
	printf("Missing Number: %d",missingNumber(a,n));
	printf("\n");
	return 0;
}
