#include <stdio.h>
#include <stdlib.h>
#define INT_MIN -2147483648

int maxProfit(int a[], int n) {
	int profit = INT_MIN;
	for (int i=0;i<n;i++)
		for(int j=i+1;j<n-1;j++) {
			if ((a[j]-a[i])>profit)
				profit = a[j] - a[i];
		}
	if (profit < 0)
		return 0;
	return profit;
}

int main() {
	int a[] = {7,6,4,3,1};
	int n = sizeof(a)/sizeof(a[0]);
	int profit = maxProfit(a, n);
	printf("Max profit %d\n",profit);
	return 0;
}
