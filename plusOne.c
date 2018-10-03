#include <stdio.h>
#include <stdlib.h>

int* plusOne(int a[], int n) {
	int i = n-1;
	int r[n+1];
	int sum, carry=0;
	sum = a[i]+1;
	while (sum == 10 && i >= 0) {
		carry = 1;
		a[i] = 0;
		if (carry) {
			i--;
			sum = a[i]+carry;
		}
	}
	if (i != -1) {
		a[i] = sum;
	}
	else {
		//int r[n+1];
		for (i=1;i<=n;i++)
			r[i] = a[i-1];
		r[0] = 1;
		return r;
	}
	return a;
}

int main() {
	int a[] = {9,9,9,9};
	int n = sizeof(a)/(sizeof(a[0]));
	int *ptr;
	ptr = &a;
	ptr = plusOne(a,n);
	int i;
	for (i=0;i<n;i++)
		printf("%d\t",*(ptr+i));
	printf("\n");
}
