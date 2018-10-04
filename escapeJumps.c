#include <stdio.h>
#include <stdlib.h>

int escape (int x, int y, int n, int heights[]) {
	int jumps = 0;
	int i;
	for (i=0;i<n;i++) {
		if (heights[i] <= x) {
			jumps++;
			continue;
		}
		int h = heights[i];
		while (h > x){
			jumps++;
			h = h - (x - y);
		}
		jumps++;
	}
	return jumps;
}

int main() {
	int heights[] = {11, 10, 10, 9};
	int x = 10;
	int y = 1;
	int n = sizeof(heights)/sizeof(heights[0]);
	int jumps = escape(x, y, n, heights);
	printf("Jumps required to %d walls: %d", n, jumps);
	printf("\n");
	return 0;
}
