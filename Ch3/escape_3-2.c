#include <stdio.h>
#define MAXLEN 300
void escape(char s[], char t[]);

int main(void)
{
    char s[MAXLEN];
    char t[MAXLEN] = "\\hello world\\ \n \t\t\tThis is a \'testing\'\t\"string\"\n";
    for (int i = 0; i < MAXLEN; ++i)
        s[i] = '\0';
    escape(s,t);
    printf("%s\n", s);
    return 0;
}

void escape(char s[], char t[])
{
    int i, j;
    for (i = j = 0; t[i] != '\0'; ++i) {
        switch (t[i]) {
            case '\\':
                s[j++] = '\\';
                s[j++] = '\\';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\'':
                s[j++] = '\\';
                s[j++] = '\'';
                break;
            case '\"':
                s[j++] = '\\';
                s[j++] = '\"';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    }
}

