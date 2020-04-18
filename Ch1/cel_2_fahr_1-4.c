#include<stdio.h>

int main(void)
{
    int upper, lower, step;
    int fahr, celsius;
    upper = 300;
    lower = 0;
    step = 20;
    celsius = 0;
    printf("celsius     fahrenheit\n");
    while (celsius <= upper){
        fahr = (5 * celsius / 9) + 32;
        printf("%5d%14d\n", celsius, fahr);
        celsius += step;
    }

    return 0;
}     
