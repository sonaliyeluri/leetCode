#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int left, int mid, int right) {
	int i, j, k, nl, nr;
	nl = mid-left+1;
	nr = right-mid;
	int l[nl], r[nr];
	for (i=0;i<nl;i++)
		l[i] = a[left+i];
	for (j=0;j<nr;j++)
		r[j] = a[mid+1+j];
	i = 0;
	j = 0;
	k = left;
	while (i<nl && j<nr) {
		if (l[i] < r[j]) {
			a[k] = l[i];
			i++;
		}
		else {
			a[k] = r[j];
			j++;
		}
		k++;
	}
	while (i < nl) {
		a[k] = l[i];
		i++;
		k++;
	}
	while (j < nr) {
		a[k] = r[j];
		j++;
		k++;
	}
}

void mergeSort(int a[], int left, int right) {
	if(left < right) {
		int mid = left+(right-left)/2;
		mergeSort(a, left, mid);
		mergeSort(a, mid+1, right);
		merge(a, left, mid, right);
	}
}

void printArray(int a[], int n) {
	for (int i=0;i<n;i++) 
		printf("%d ",a[i]);
	printf("\n");
}

void printDuplicates(int a[], int n) {
	for (int i=0;i<n-1;i++) 
		if(a[i] == a[i+1]){
			printf("%d ",a[i]);
			i++;
		}
	printf("\n");
}

int main() {
	int a[] = {4,3,2,7,5,8,2,5,3,1,8};
	int n = sizeof(a)/sizeof(a[0]);
	printArray(a,n);
	mergeSort(a,0,n-1);
	printf("Printing elements after Sorting..\n");
	printArray(a,n);
	printf("Printing Duplicate elements in array..\n");
	printDuplicates(a,n);
	return 0;
}	
