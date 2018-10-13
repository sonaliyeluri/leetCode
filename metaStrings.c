#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int areMetaStrings(char* str1, char* str2) {
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	if(len1 != len2)
		return 0;
	int i;
	int prev = -1;
	int curr = -1;
	int count = 0;
	for(i=0;i<len1;i++) {
		if(str1[i] != str2[i]) {
			count++;
			if(count > 2)
				return 0;
			prev = curr;
			curr = i;
		}
	}
	return (count==2 && (str1[prev]==str2[curr]) && (str1[curr]==str2[prev]));
}

int main() {
	char str1[] = "converse";
	char str2[] = "conscrve";
	int isMeta = areMetaStrings(str1, str2);
	if (isMeta == 1)
		printf("True\n");
	else
		printf("False\n");
	return 0;
}		
