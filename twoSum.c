#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void twoSum(int* a, int size, int target) {
	int i, temp;
	//int *res = malloc(2*sizeof(int));
	int s[MAX] = {0};
	for (i=0;i<size;i++) {
		temp = target - a[i];
		if (temp >= 0 && s[temp] == 1) {
			printf("Numbers that sum to %d is (%d, %d)\n",target, temp, a[i]);
			return;
		}
		s[a[i]] = 1;
	}
}


int main()
{
	int a[4],i;
	int *p;
	p=a;
	int *ptr;
	printf("\nEnter Elements to array..\n");
	for(i=0;i<4;i++)
	{
	 	scanf("%d", &a[i]);
	}
	printf("\nEnter target value: ");
	int target;
	scanf("%d",&target);
	int size=(sizeof(a))/sizeof(a[0]);
	twoSum(p,size,target);
	//if(ptr != NULL)
	//	printf("\n%d %d\n",*ptr,*(ptr+1));
	return 0;
}

