#include <stdio.h>
#include <stdlib.h>

void findTriplets(int a[], int n) {
	int found = 0;
	int noTriplets = 0;
	for (int i=0;i<n-2;i++) 
		for(int j=i+1;j<n-1;j++)
			for(int k=j+1;k<n;k++)
				if(a[i]+a[j]+a[k] == 0)
					noTriplets++;
	printf("No.of Triplets with sum zero: %d",noTriplets);
}
				
int main() {
	int a[] = {0, -1, 2, -3, 1};
	int n = sizeof(a)/sizeof(a[0]);
	findTriplets(a,n);
	printf("\n");
	return 0;
} 
