#include <stdio.h>
#include <stdlib.h>

int isHeap(int a[], int n) {
	int i;
	for (i=0;i<(n-2)/2;i++) {
		if (a[2*i+1] > a[i])
			return 0;
		if (a[2*i+2] > a[i])
			return 0;
	}
	return 1;
}

int main() {
	int a[] = {9, 15, 10, 7, 12, 11};
	int n = sizeof(a)/sizeof(a[0]);
	int isheap = isHeap(a,n);
	isHeap(a,n) ? printf("Yes") : printf("No");
	printf("\n");
	return 0;
}
