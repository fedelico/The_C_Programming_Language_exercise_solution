#include <stdio.h>
unsigned invert(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, int y);
unsigned getbits(unsigned x, int p, int n);

int main(void)
{
    printf("%d gets inverted to %d\n", 12, invert(12, 2, 2));
    printf("%d gets inverted to %d\n", 26, invert(26, 4, 3));
    return 0;
}

unsigned invert(unsigned x, int p, int n)
{
    return setbits(x, p, n, getbits(~x, p, n));
}

unsigned setbits(unsigned x, int p, int n, int y)
{
    return (x & ~(~(~0 << n) << (p-n+1))) | (getbits(y, n-1, n) << (p-n+1));
}

unsigned getbits(unsigned x, int p, int n)
{
    return x >> (p-n+1) & ~(~0 << n);
}
