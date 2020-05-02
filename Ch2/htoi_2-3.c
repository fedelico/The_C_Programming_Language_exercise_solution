#include <stdio.h>
#include <ctype.h>
#define MAXLEN 100
#define BASE 16

int htoi(char hex[]);

int main(void)
{
    char *nums[5] = {"1", "01", "0xff", "0X0011","CAC"};
    for (int i = 0; i < 5; ++i)
        printf("%s converted into %d\n", nums[i], htoi(nums[i]));
    return 0;
}

int htoi(char hex[])
{
    unsigned int i, result, digit;
    i = result = 0;
    if (hex[0] == '0' && tolower(hex[1]) == 'x')
        i += 2;
    for (;hex[i] != '\0'; ++i){
        if (isupper(hex[i]))
            digit = (hex[i] - 'A') + 10;
        else if (islower(hex[i]))
            digit = (hex[i] - 'a') + 10;
        else if (isdigit(hex[i]))
            digit = (hex[i] - '0');
        else{
            printf("INVALID HEX STRING: THE STRING SHOULD CONTAINS ONLY ALPHABETS AND NUMBERS\n");
            return -1;
        }
        result = result * BASE + digit; 
    }
    return result;
}

