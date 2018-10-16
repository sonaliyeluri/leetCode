#include <stdio.h>
#include <stdlib.h>

#define N 20

int duplicateNumber(int a[], int n) {
	int temp;
	int s[N] = {0};
	for (int i=0;i<n;i++) {
		temp = a[i];
		if(s[temp] == 1)
			return a[i];
		s[temp] = 1;
	}
	return 0;
}

int main() {
	int a[] = {1,3,4,5,7,8,3};
	int n = sizeof(a)/sizeof(a[0]);
	printf("Duplicate Number in array %d\n",duplicateNumber(a,n));
	return 0;
}
