#include <stdio.h>
#include <stdlib.h>

int countBits(int n) {
	int count = 0;
	while(n) {
		count += n&1;
		n >>= 1;
	}
	return count;
}

int bitDifference(int a[], int n) {
	int i, j;
	int ans = 0;
	int diff;
	for (i=0;i<n;i++) {
		for (j=0;j<n;j++) {
			diff = a[i]^a[j];
			ans += countBits(diff);
		}
	}
	return ans;
}

int main() {
	int a[] = {1,2};
	int n = sizeof(a)/sizeof(a[0]);
	int res = bitDifference(a,n);
	printf("\nBit differences among pairs in arrays is: %d",res);
	printf("\n");
	return 0;
}			
