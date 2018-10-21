#include <stdio.h>
#include <stdlib.h>

int pivotIndex(int a[], int n) {
	if (n == 0)
		return 0;
	int lsum;
	int rsum;
	int i, j, k;
	int pivot = -1;
	for (i=0;i<n;i++) {
		lsum = 0;
		rsum = 0;
		for (j=0;j<i;j++)
			lsum += a[j];
		for (k=i+1;k<n;k++)
			rsum += a[k];
		if (lsum == rsum) {
			pivot = i;
			break;
		}
	}
	return pivot;
}

int main() {
	int a[] = {1, 2, 3};
	int n = sizeof(a)/sizeof(a[0]);
	printf("Pivot Index = %d\n",pivotIndex(a,n));
	return 0;
}
		
