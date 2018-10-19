#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int singleNumber (int a[], int n) {
	int res = 0;
	for (int i=0;i<n;i++)
		res = res^a[i];
	return res;
}

int main() {
	int a[] = {4,2,1,2,1};
	int n = sizeof(a)/sizeof(a[0]);
	printf("Single Number %d",singleNumber(a,n));
	printf("\n");
	return 0;
} 
