#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char difference(char *s, char *t) {
	int sum1 = 0;
	int sum2 = 0;
	char res;
	for(int i=0;i<strlen(s);i++)
		sum1 = sum1 + s[i];
	for(int i=0;i<strlen(t);i++)
		sum2 = sum2 + t[i];
	res = abs(sum1-sum2);
	return res;
}

int main() {
	char s[] = "abcd";
	char t[] = "abcde";
	printf("Difference character between %s and %s: %c", s, t, difference(s,t));
	printf("\n");
	return 0;
}
