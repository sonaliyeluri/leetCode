#include <stdio.h>
#include <stdbool.h> 

bool rectangle(int rec1[], int n1, int rec2[], int n2) {
	return !((rec1[2]<=rec2[0]) || (rec1[3]<=rec2[1]) || (rec1[1]>=rec2[3]) || (rec1[0]>=rec2[2]));
}

int main() {
	int rec1[] = {0,0,1,1};
	int rec2[] = {1,0,2,1};
	int n1 = sizeof(rec1)/sizeof(rec1[0]);
	int n2 = sizeof(rec2)/sizeof(rec2[0]);
	if (rectangle(rec1, n1, rec2, n2) == true)
		printf("true\n");
	else
		printf("false\n");
	return 0;
}
