#include <stdio.h>

int max(int a, int b) {
	return a>b?a:b;
}

int distance(int a[], int n) {
	int k = 0;
	int ans = 0;
	for (int i=0;i<n;i++) {
		if(a[i] == 1)
			k = 0;
		else {
			k++;
			ans = max(ans,(k+1)/2);
		}
	}
	for (int i=0;i<n;i++) {
		if (a[i] == 1) {
			ans = max(ans, i);
			break;
		}
	}
	for (int i=n-1;i>=0;i--) {
		if(a[i] == 1) {
			ans = max(ans, n-1-i);
			break;
		}
	}
	return ans;
}

int main() {
	int a[] = {1,0,0,0};
	int n = sizeof(a)/sizeof(a[0]);
	printf("Maximum distance to closest Person %d", distance(a, n));
	printf("\n");
	return 0;
}
