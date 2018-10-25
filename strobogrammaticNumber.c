#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isStrobogrammatic(char *num) {
	int n = strlen(num);
	int l = 0;
	int r = n-1;
	while (l <= r) {
		if (num[l] == num[r]) {
			if (num[l] != '1' && num[l] != '0' && num[l] != '8')
				return false;
		}
		else {
			if ((num[l] != '6' || num[r] != '9') && (num[l] != '9' && num[r] != '6'))
				return true;
		}
		l++;
		r--;
	}
	return true;
}

int main() {
	char s1[2] = "88";
	printf("%s - %d\n",s1, isStrobogrammatic(s1));
	//char s2[2] = "22";
	//printf("%s - %d\n",s2, isStrobogrammatic(s2));
	//char s3[3] = "101";
	//printf("%s - %d\n",s3, isStrobogrammatic(s3));
	char s4[3] = "609";
	printf("%s - %d\n",s4, isStrobogrammatic(s4));
	//char s5[3] = "818";
	//printf("%s - %d\n",s5, isStrobogrammatic(s5));
	return 0;
}
