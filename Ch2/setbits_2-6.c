#include <stdio.h>
unsigned setbits(unsigned x, int p, int n, int y);
unsigned getbits(unsigned x, int p, int n);

int main(void)
{
    printf("number %d tranformed into %d\n", 17, setbits(17, 2, 1, 1));
    return 0;
}

unsigned setbits(unsigned x, int p, int n, int y)
{
    return (x & ~(~(~0 << n) << (p-n+1))) | (getbits(y, n-1, n) << (p-n+1));
}

unsigned getbits(unsigned x, int p, int n)
{
    return x >> (p-n+1) & (~(~0 << n));
}
