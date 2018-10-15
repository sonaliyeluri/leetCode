#include <stdio.h>
#include <string.h>

void swap (char *x, char *y) {
	char temp = *x;
	*x = *y;
	*y = temp;
}

char* reverseString(char* s) {
	int n = strlen(s);
	for (int i=0;i<n/2;i++)
		swap(&s[i], &s[n-1-i]);
	return s;
}

int main() {
	char s[] = "A man, a plan, a canal: Panama";
	char *ptr;
	ptr= &s;
	printf("String before reversing %s\n",s);
	ptr = reverseString(s);
	printf("String after reversing %s\n",s);
	return 0;
} 
