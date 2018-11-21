#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool containZero(int n) {
	char str[10];
	//itoa(n, str, 10);
	sprintf(str, "%d", n);
	for (int i=0;i<strlen(str);i++)
		if (str[i] == '0')
			return 1;
	return 0;
}

bool selfDividing(int n) {
	if (containZero(n))
		return 0;
	int rem;
	int quo;
	while (n > 0) {
		rem = n % 10;
		if (n%rem != 0)
			return 0;
		n = n/10;
	}
	return 1;
}

int main() {
	int n = 23;
	printf("%s", selfDividing(n)?"True":"False");
	printf("\n");
	return 0;
}		
