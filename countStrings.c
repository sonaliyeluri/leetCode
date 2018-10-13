#include <stdio.h>
#include <stdlib.h>

int countStr(int n, int bCount, int cCount) {
	if (bCount<0 || cCount<0)
		return 0;
	if (n == 0)
		return 1;
	if (bCount == 0 && cCount == 0)
		return 1;
	int res = countStr(n-1, bCount, cCount);
	res += countStr(n-1, bCount-1, cCount);
	res += countStr(n-1, bCount, cCount-1);
	return res;
}

int main() {
	int n = 3;
	printf("No of Strings can be formed = %d",countStr(3,1,2));
	printf("\n");
	return 0;
}
