#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search(int a[], int low, int high, int key) {
	int mid;
	if (low < high) {
		mid = (low+high)/2;
		if (a[mid] == key)
			return mid;
		else if (key > a[mid])
			return search(a, mid+1, high, key);
		else
			return search(a, low, mid-1, key);
	}
	return -1;
}

int main() {
	int a[] = {1,3,5,6};
	int n = sizeof(a)/sizeof(a[0]);
	int index = search(a, 0, n-1, 7);
	int i;
	int flag = 0;
	if (index == -1) {
		for (i=0;i<n;i++)
			if (7 < a[i]){
				flag = i;
				break;
			}
		printf("Insert position of element: %d",flag);
	}
	else
		printf("Position of element is %d",index);
	printf("\n");
	return 0;
}	
