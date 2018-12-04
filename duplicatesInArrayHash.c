#include <stdio.h>
#include <stdlib.h>
#define MAX 256

void duplicates(int a[], int n) {
	int hash[MAX] = {0};
	for (int i=0;i<n;i++) {
		if (hash[a[i]] == 1)
			printf("%d ",a[i]);
		hash[a[i]] = 1;
	}
}

int main() {
	int a[] = {1, 2, 3, 1, 3, 6, 8};
	int n = sizeof(a)/sizeof(a[0]);
	duplicates(a,n);
	printf("\n");
	return 0;
}
