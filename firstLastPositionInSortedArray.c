#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binarySearch(int a[], int low, int high, int key) {
	int mid;
	if (low < high) {
		mid = (low+high)/2;
		if (a[mid] == key)
			return mid;
		else if (key > a[mid])
			return binarySearch(a, mid+1, high, key);
		else
			return binarySearch(a, low, mid-1, key);
	}
	return -1;
}

int* searchRange(int a[], int n, int key) {
	int *ptr = malloc(2*sizeof(int));
	ptr[0] = -1;
	ptr[1] = -1;
	int temp = binarySearch(a, 0, n-1, key);
	if (temp != -1) {
		if (a[temp] == a[temp-1]) {
			ptr[0] = temp-1;
			ptr[1] = temp;
		}
		else if (a[temp] == a[temp+1]){
			ptr[0] = temp;
			ptr[1] = temp+1;
		}
	}
	return ptr;
}

int main() {
	int a[] = {};
	int n = sizeof(a)/sizeof(a[0]);
	int res[2];
	int *ptr;
	ptr = res;
	ptr = searchRange(a,n,7);
	printf("First and Last position of elements in Sorted array: [%d, %d]", *(ptr+0), *(ptr+1));
	printf("\n");
	return 0;
}
			
	
	
