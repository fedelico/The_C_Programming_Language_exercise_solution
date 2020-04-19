#include <stdio.h>

int main(void)
{
    short nb;
    int c;
    for (nb = 0; (c = getchar()) != EOF;){
        if (c == ' '){

            if (nb == 0){
                putchar(c);
                nb++;
            }
        }
        else{
            nb = 0;
            putchar(c);
        }
    }
    return 0;
}
