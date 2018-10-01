#include <stdio.h>
#include <string.h>

void swap(char *a, char *b) {
	char temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void permute(char *s, int l, int r) {
	int i;
	if (l == r)
		printf("%s\n",s);
	else {
		for(i=l;i<=r;i++){
			swap((s+l),(s+i));
			permute(s,l+1,r);
			swap((s+l),(s+i));
		}
	}
}

int main() {
	char s[] = "ABCD";
	int len = strlen(s);
	permute(s,0,len-1);
	return 0;
}	
