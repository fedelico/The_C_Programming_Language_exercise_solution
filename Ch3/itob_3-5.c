#include <stdio.h>

void itob(int n, char s[], int base);
void reverse(char s[], int len);

int main(void)
{
    int a[10] = {1,12,123,-123,4531,12345,0,483,972,10};
    char s[10];
    for (int i = 0; i < 10; ++i)
        s[i] = '\0';
    for (int i = 0; i < 10; ++i){
        itob(a[i], s, 16);
        printf("value %d->%s\n", a[i], s);
    }
    return 0;
}

void itob(int n, char s[], int base)
{
    char digits[36] = {'0','1','2','3','4','5','6','7','8','9',
                       'A','B','C','D','E','F','G','H','I','J',
                       'K','L','M','N','O','P','Q','R','S','T',
                       'U','V','W','X','Y','Z'};
    int sign = 1;
    int i = 0;

    if (base < 2 || base > 36){
        printf("Can't convert number to base less than 2 or more than 36\n");
        return;
    }
    if (n < 0){
        sign = -1;
        n = -n;
    }
    do {
        s[i++] = digits[n % base];
    }while ((n /= base) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s, i);
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
