#include <stdio.h>
#define TABSTOP 4
int main(void)
{
    int c;
    while ((c = getchar()) != EOF){
        if (c == '\t'){
            for (int i = 0; i < TABSTOP; ++i)
                putchar(' ');
        }
        else 
            putchar(c);
    }
    return 0;
}
