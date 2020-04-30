#include <stdio.h>

void itoa(int n, char s[], int width);
void reverse(char s[], int len);

int main(void)
{
    int a[6] = {1, 0, 23, 23456, -1, -1234};
    char s[10];
    for (int i=0; i < 10; ++i)
        s[i] = '\0';
    for (int i = 0; i < 6; ++i){
        itoa(a[i], s, 3);
        printf("value %d is->%s\n", a[i], s);
    }
    return 0;

}

void itoa(int n, char s[], int width)
{
    int i = 0;
    int sign;
    if (n < 0){
        sign = -1;
        n = -n;
    }
    do {
        s[i++] = '0' + (n % 10);
        n /= 10;
    }while(n != 0);
    if (sign < 0)
        s[i++] = '-';
    while (width > i)
        s[i++] = ' ';

    reverse(s, i);
    s[i] = '\0';
}

void reverse(char s[], int len)
{
    int temp;
    for (int i = 0; i < len/2; ++i){
        temp = s[i];
        s[i] = s[len-1-i];
        s[len-1-i] = temp;
    }
}


