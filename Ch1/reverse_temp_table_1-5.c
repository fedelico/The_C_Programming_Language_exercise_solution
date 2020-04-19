#include <stdio.h>

int main(void)
{
    int fahr;
    printf("Fahrenheit     Celsius\n");
    for (int fahr = 300; fahr >= 0; fahr -= 20){
        printf("%7d%14.2f\n", fahr, (5.0/9.0) * fahr - 32);
    }
    return 0;
}
