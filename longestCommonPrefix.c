#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_MAX 2147483647

int findMinLen(char strs[][7], int n) {
	int len = INT_MAX;
	for (int i=0;i<n;i++)
		if(len > strlen(strs[i]))
			len = strlen(strs[i]);
	return len;
}

int isPrefix (char strs[][7], char ch, int i, int n) {
	int flag = 1;
	for(int j=0;j<n;j++)
		if (strs[j][i] != ch)
			flag = 0;
	return flag?1:0;
}

char *commonPrefix (char strs[][7], int n) {
	int len = findMinLen(strs,n);
	int prefix;
	char res[len];
	int j = 0;
	char ch;
	for (int i=0;i<len;i++) {
		ch = strs[0][i];
		prefix = isPrefix(strs,ch,i,n);
		if (prefix == 1){
			res[j] = ch;
			j++;
		}
		if (i == 0 && prefix != 1)
			return "";
	}
	res[j] = '\0';
	return res;
}	

int main() {
	char strs[][7] = {"flower","flow","float"};
	printf("Common Prefix %s",commonPrefix(strs,3));
	printf("\n");
	return 0;
}  
