#include <stdio.h>
#define MAXLEN 100
int get_line(char line[], int lim);

int main(void)
{
    char line[MAXLEN];
    for (int i = 0; i < MAXLEN; ++i)
        line[i] = '\0';
    while (get_line(line, MAXLEN) > 0)
        printf("%s", line);
    return 0;
}

int get_line(char line[], int lim)
{
    //rewrite the for loop in get_line function without using && || operators
    int i,c;
    for (i = 0; i < lim-1; ++i){
        if ((c = getchar()) != '\n'){
            if (c != EOF)
                line[i] = c;
            else
                break;
        }
        else{
            line[i++] = '\n';
            break;
        }
    }
    line[i] = '\0';
    return i;
}
