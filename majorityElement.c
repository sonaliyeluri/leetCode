#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int left, int mid, int right) {
	int i, j, k, nl, nr;
	nl = mid - left + 1;
	nr = right - mid;
	int l[nl], r[nr];
	for (i=0;i<nl;i++)
		l[i] = a[left+i];
	for (j=0;j<nr;j++)
		r[j] = a[mid+1+j];
	i = 0;
	j = 0;
	k = left;
	while (i < nl && j < nr) {
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
	if (left < right) {
		int mid = left + (right - left)/2;
		mergeSort(a, left, mid);
		mergeSort(a, mid+1, right);
		merge(a, left, mid, right);
	}
}

int majorityElement(int a[], int n) {
	mergeSort(a, 0, n-1);
	return a[n/2];
}

int main() {
	int a[] = {2,2,1,1,1,2,2};
	int n = sizeof(a)/sizeof(a[0]);
	printf("Majority element in array: %d\n", majorityElement(a, n));
	for (int i=0;i<n;i++)
		printf("%d ", a[i]);
	printf("\n");
	return 0;
}
