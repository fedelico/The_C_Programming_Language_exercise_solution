#include <stdio.h>
#define MAXLEN 500

int get_line(char line[], int lim);
void reverse(char line[], int len);
void swap(char*, char*);

int main(void)
{
    char line[MAXLEN];
    int len;
    for (int i = 0; i < MAXLEN; ++i)
        line[i] = '\0';

    while ((len = get_line(line, MAXLEN)) > 0){
        reverse(line, len);
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

void reverse(char line[], int len)
{
    int end = len - 1;
    int i, j;
    if (line[end] == '\n')
        end--;
    for (i = end, j = 0; i > end/2; i--, j++)
        swap(&line[i], &line[j]);
}

void swap(char* c1, char* c2)
{
    char tmp;
    tmp = *c1;
    *c1 = *c2;
    *c2 = tmp;
}

