#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int max(int a, int b) {
	return a>b?a:b;
}

int robHouse(int a[], int n) {
	int currMax = 0;
	int prevMax = 0;
	for (int i=0;i<n;i++) {
		int temp = currMax;
		currMax = max(a[i]+prevMax, currMax);
		prevMax = temp;
	}
	return currMax;
}

int main() {
	int a[] = {2,7,9,3,1};
	int n = sizeof(a)/sizeof(a[0]);
	printf("Max Robber can rob %d\n",robHouse(a,n));
	return 0;
}
	
