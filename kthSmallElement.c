#include <stdio.h>

void merge(int a[], int left, int mid, int right) {
	int nl, nr, i, j, k;
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
	while (i<nl) {
		a[k] = l[i];
		i++;
		k++;
	}
	while (j<nr) {
		a[k] = r[j];
		j++;
		k++;
	}
}

void mergeSort (int a[], int left, int right) {
	if (left < right) {
		int mid = left+(right-left)/2;
		mergeSort(a, left, mid);
		mergeSort(a, mid+1, right);
		merge(a, left, mid, right);
	}
}

int main() {
	int a[] = {7, 10, 4, 3, 20, 15};
	int n = sizeof(a)/sizeof(a[0]);
	printf("Enter value of k to find kth smallest element in array: ");
	int k;
	scanf("%d",&k);
	mergeSort(a, 0, n-1);
	printf("%drd smallest element in array : %d", k, a[k-1]);
	printf("\n");
	return 0;
} 

