#include <stdio.h>
#include <stdlib.h>

long convertCharToNum(char* num) {
    int i = 0;
    long res = 0;
    while (num[i] != '\0') {
        res = res*10+(num[i]-'0');
        i++;
    }
    return res;
}

char* convertNumToChar(long num) {
    char res[1000];
    int i=0;
    int temp;
    while(num > 0) {
        temp = num%10;
        num = num/10;
        res[i] = temp +'0';
        i++;
    }
    res[i] = '\0';
    return res;
}

char multiply(char *num1, char *num2) {
    long n1, n2;
    long product;
    n1 = convertCharToNum(num1);
    n2 = convertCharToNum(num2);
    product = n1 * n2;
    printf("Product %ld\n",product);
    char res;
    res = product+'0';
   // char *ptr;
   //ptr = res;
   // ptr = convertNumToChar(product);
    return res;
}

int main() {
    char num1[] = "2";
    char num2[] = "3";
    char res;
    res = multiply(num1, num2);
    printf("%c",res);
    return 0;
}
