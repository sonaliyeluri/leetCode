#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

int top = -1;
int a[MAX];
	
void push(char ch) {
	if (top == MAX-1) {
		printf("Overflow\n");
		return;
	}
	top++;
	a[top] = ch;
}

char pop() {
	char ch;
	if(top == -1) {
		printf("Underflow\n");
		return '\0';
	}
	else {
		ch = a[top];
		top--;
	}
	return ch;
}

char *type(char *s) {
	int i = 0;
	char ch;
	while(s[i] != '\0') {
		if (s[i] != '#')
			push(s[i]);
		else 
			ch = pop();
		i++;
	}
	if (top != -1) {
		i = 0;
		while(top != -1) {
			s[i] = pop();
			i++;
		}
		s[i] = '\0';
	}
	else 
		s[0] = '\0';
	printf("%s\n",s);
	return s;
}

bool backspace(char *s1, char *s2) {
	return !strcmp(type(s1),type(s2));
}

int main() {
	char s1[] = "a#c";
	char s2[] = "b";
	if (backspace(s1, s2) == true)
		printf("true\n");
	else
		printf("false\n");
	return 0;
}
	
