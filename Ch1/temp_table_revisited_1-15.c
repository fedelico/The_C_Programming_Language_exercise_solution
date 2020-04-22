#include <stdio.h>
#define UPPER 300
#define LOWER 0
#define STEP 20
float f2c(int fahr); // convert fahrenheit to celsius

int main(void)
{
    int fahr;
    printf("fahrenheit   Celsius\n");
    for (fahr = LOWER; fahr <= UPPER; fahr += STEP)
        printf("%6d%14.2f\n", fahr, f2c(fahr));

    return 0; 
}

float f2c(int fahr)
{
    return (5.0/9.0) * (fahr - 32);
}

