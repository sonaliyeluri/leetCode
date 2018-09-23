#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int countPrimeSetBits(int L, int R) {
    int count = 0, i;
    for (i=L;i<=R;i++) {
        int flag = 1;
        int count_bits = 0;
        while (i) {
            count_bits += i&1;
            i >>= 1;
        }
        int n = pow(count_bits,0.5);
        for (i=2;i<n;i++) {
            if (count_bits%i == 0) {
                flag = 0;
            }
        }
        if (flag == 1)
            count += 1;
    }
    return count;
}

int main() {
	int count = countPrimeSetBits(842, 888);
	printf("%d\n", count);
}
