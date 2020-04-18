#include <stdio.h>

int main(void)
{
    int upper, lower, step;
    float fahr, celsius;
    upper = 300;
    lower = 0;
    step = 20;
    fahr = 0;
    printf("Fahrenheit    Celsius\n"); // Header for the temperature table
    while(fahr <= upper){
        celsius = (5.0/9.0) * fahr - 32.0;
        printf("%6.0f%14.2f\n", fahr, celsius);
        fahr += step;
    }
    
    return 0;
}
