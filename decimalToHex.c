#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *toHex(int num) {
	char hex[100];
	int rem;
	int i = 0;
	while (num != 0) {
		rem = num%16;
		num = num/16;
		if (rem < 10)
			hex[i] = 48 + rem;
		else
			hex[i] = 87 + rem;
		i++;
	}
	hex[i] = '\0';
	char *str = malloc(sizeof(strlen(hex)*sizeof(char)));
	str = hex;
	return str;
}

int main() {
	int n = -1;
	char hex[100];
	strcpy(hex, toHex(n));
	printf("%s",hex);
	printf("\n");
	return 0;
}		
