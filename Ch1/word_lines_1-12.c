#include <stdio.h>
#define INWORD 1
#define OUTWORD 0

int main(void)
{
    int c;
    short state;
    for (state = OUTWORD; (c = getchar()) != EOF;){
        if (c == '\n'){
            if (state == INWORD)
                putchar(c);
            state = OUTWORD;
        }
        
        else if (c == ' ' || c == '\t'){
            if (state == INWORD)
                putchar('\n');
            state = OUTWORD;
        }

        else{
            state = INWORD;
            putchar(c);
        }
    }
    return 0;
}

