#include <stdio.h>
#define MAXLEN 1000
int get_line(char line[], int lim);
void copy(char from[], char to[]);

int main(void)
{
    char longest[MAXLEN], line[MAXLEN];
    int max_len, len;
    len = max_len = 0;
    for (int i = 0; i < MAXLEN; ++i) //initialize 2 strings
        longest[i] = line[i] = '\0';

    while ((len = get_line(line, MAXLEN)) > 0){
        if (len > max_len){
            copy(line, longest);
            max_len = len;
        }
    }
    printf("Longest Line: %sLength: %d\n", longest, max_len);
    return 0;
}

int get_line(char line[], int lim)
{
    int c, i, end;
    for (i = 0; (c = getchar()) != EOF && c != '\n'; ++i){
        if (i < lim-1){
            end = i + 1;
            line[i] = c;
        }
        else
            end = lim-1;
    }
    if (c == '\n'){
        if (i < lim-1){
            end++;
            line[i] = c;
        }
        ++i;
    }

    line[end] = '\0';
    return i;
}

void copy(char from[], char to[]) //assume the sizeof from is bigger than sizeof to
{
    int i = 0;
    for (i = 0; (to[i] = from[i]) != '\0'; ++i);
}


