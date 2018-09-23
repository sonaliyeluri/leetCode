#include<stdio.h>
#include<stdlib.h>
int* twoSum(int* a, int size, int target)
{
	int temp,i;
	int b[2];
	int *ptr;
	ptr=b;
	if((a[0]+a[size-1])==target)
	{
		b[0]=0;
		b[1]=size-1;
		return ptr;
	}
	else
	{
		for(i=0;i<size-1;i++)
		{
			temp=a[i]+a[i+1];
			if(temp==target)
			{
				b[0]=i;
				b[1]=i+1;
				return ptr;
			}
		}
		printf("\nThere are no numbers which sums to %d in array",target);
		return NULL;
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
	ptr=twoSum(p,size,target);
	if(ptr != NULL)
		printf("\n%d %d\n",*ptr,*(ptr+1));
}

