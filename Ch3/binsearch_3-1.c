#include <stdio.h>
int binsearch(int num, int v[], int len);

int main(void)
{
    int v1[5] = {1, 23, 75, 81, 103};
    int v2[6] = {0, 5, 123, 578, 666, 1028};
    int v3[1] = {1};
    int *v = NULL;
    printf("v1->23 at position %d\n", binsearch(23, v1, 5));
    printf("v2->103 at position %d\n", binsearch(103, v2, 6));
    printf("v1->76 at position %d\n", binsearch(76, v1, 5));
    printf("v3->1 at position %d\n", binsearch(1, v3, 1));
    printf("v1->75 at position %d\n", binsearch(75, v1, 5));
    printf("v->75 at position %d\n", binsearch(75, v, 0));

    return 0;
}

int binsearch(int num, int v[], int len)
{
    int upper, lower, i;
    upper = len -1;
    lower = 0;
    while (upper - lower > 1){
        i = (upper + lower) / 2;
        if (v[i] > num)
            upper = i-1;
        else
            lower = i;
    }
    if (len > 0 && v[upper] == num)
        return upper;
    else if (len > 0 && v[lower] == num)
        return lower;
    else
        return -1;
}
