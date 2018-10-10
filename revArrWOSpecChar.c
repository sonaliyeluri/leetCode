#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *x, char *y) {
	char temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

int isAlphabet(char ch) {
	return((ch >= 'A' && ch <= 'Z')||(ch >= 'a' && ch <= 'z'));
}

void reverse(char str[]) {
	int l, r;
	l = 0;
	r = strlen(str)-1;
	while (l < r) {
		if(!isAlphabet(str[l]))
			l++;
		else if(!isAlphabet(str[r]))
			r--;
		else {
			swap(&str[l], &str[r]);
			l++;
			r--;
		}
	}
}

int main() {
	char str[] = "a,bc$@ef";
	printf("%s\n",str);
	reverse(str);
	printf("%s\n",str);
	return 0;
}
