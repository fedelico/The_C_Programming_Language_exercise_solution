#include <stdio.h>
#define TABSTOP 4

int main(void)
{
    int n_space, c;
    n_space = 0;
    while ((c = getchar()) != EOF){
        if (TABSTOP == 1)
            putchar(c);

        else if (c == ' '){
            n_space++;

            if (n_space == TABSTOP){
                putchar('\t');
                n_space = 0;
            }
        }
        else{
            for (int i = 0; i < n_space; ++i)
                putchar(' ');

            n_space = 0;
            putchar(c);
        }
    }
    return 0;
}
