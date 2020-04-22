#include <stdio.h>
#define MAXLEN 500
#define TRUE 1
#define FALSE 0
int get_line(char line[], int lim);
void trim_end(char line[], int len);

int main(void)
{
    char line[MAXLEN];
    int len;
    while ((len = get_line(line, MAXLEN)) > 0){
        trim_end(line, len);
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
        line[i++] = c;

    line[i] = '\0';
    return i;
}

void trim_end(char line[], int len)
{
    int i, new_line;
    new_line = FALSE;
    for (i = len-1; i >= 0 && (line[i] == '\n' || line[i] == ' ' || line[i] == '\t'); i--)
        if (line[i] == '\n')
            new_line = TRUE;
    if (new_line)
        line[++i] = '\n';
    line[i+1] = '\0';
}

