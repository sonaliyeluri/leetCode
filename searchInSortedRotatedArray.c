#include <stdio.h>
#include <stdlib.h>

int search(int a[], int low, int high, int key) {
	if (low > high)
		return -1;
	int mid = (low+high)/2;
	if (a[mid] == key)
		return mid;
	if (a[low] <= a[mid]) {
		if (key >= a[low] && key <= a[mid])
			return search(a, low, mid-1, key);
		else
			return search(a, mid+1, high, key);
	}
	if (key >= a[mid] && key <= a[high])
		return search(a,mid-1, high, key);
	return search(a, low, mid+1, key);
}

int main() {
	int a[] = {4, 5, 6, 7, 8, 9, 1, 2, 3};
	int n = sizeof(a)/sizeof(a[0]);
	int index = search(a,0,n-1,8);
	printf("Index of 8 is %d\n",index);
	return 0;
}
