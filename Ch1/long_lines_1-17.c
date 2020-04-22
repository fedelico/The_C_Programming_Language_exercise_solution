#include <stdio.h>
#define MAXLEN 500
#define UPPER 80
int get_line(char line[], int lim);

int main(void)
{
    char line[MAXLEN];
    int len = 0;
    for (int i = 0; i < MAXLEN; ++i)
        line[i] = '\0';
  
    while ((len = get_line(line, MAXLEN)) > 0){
        if (len > UPPER)
            printf("%s", line);
    }
    return 0;
}


int get_line(char line[], int lim)
{
    int i, c;
    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;

    if (c == '\n')
        line[i++] = '\n';
    line[i] = '\0';
    return i;
}
