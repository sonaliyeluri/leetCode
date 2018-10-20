#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isomorphicStrings(char *s1, char *s2) {
	int m = strlen(s1);
	int n = strlen(s2);
	if (m != n)
		return false;
	bool marked[256] = {false};
        int map[256];
        memset(map, -1, sizeof(map));
	for(int i=0;i<m;i++) {
		if (map[s1[i]] == -1) {
			if(marked[s2[i]] == true)
				return false;
			marked[s2[i]] = true;
			map[s1[i]] = s2[i];
		}
		else if (map[s1[i]] != s2[i])
			return false;
	}
	return true;
}

int main() {
	char s1[] = "paper";
	char s2[] = "title";
	if (isomorphicStrings(s1, s2) == true)
		printf("Isomorphic Strings\n");
	else
		printf("Not Isomorphic Strings\n");
	return 0;
}
	
