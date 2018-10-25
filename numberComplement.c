#include <stdio.h>

int numComplement(int num) {
	int cpy = num;
	cpy |= (cpy >> 1);
	cpy |= (cpy >> 2);
	cpy |= (cpy >> 4);
	cpy |= (cpy >> 8);
	cpy |= (cpy >> 16);

	return (cpy^num) & cpy;
}

int main() {
	int num = 1;
	int oneCmp = numComplement(num);
	printf("One's Complement of %d: %d", num, oneCmp);
	printf("\n");
	return 0;
} 
