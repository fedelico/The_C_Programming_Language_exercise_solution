#include <stdio.h>
#include <ctype.h>
#define MAXLEN 200
void extend(char s[], int *pos, char start, char end);
void expand(char s1[], char s2[]);

int main(void)
{
    char *lines[8] = {"", "0-8", "---0-3-7-9---", "-a-zr-v", "-a-b-c-d-e5-8", "-1-58-9","0123---"," "};
    char s2[MAXLEN];
    int i;
    for (i = 0; i < MAXLEN; ++i)
        s2[i] = '\0';
    for (i = 0; i < 8; ++i){
        expand(lines[i], s2);
        printf("%s is expanded to %s\n", lines[i], s2);
    }
    return 0;
}

void expand(char s1[], char s2[])
{
    int i, j;
    int pos;// record the position of the last executed right operend
    for (i = 0; s1[i] == ' ' || s1[i] == '-'; ++i)
        s2[i] = s1[i];
    for (j = i; s1[i] != '\0'; ++i){
        if (s1[i] == '-'){
            if (isupper(s1[i-1]) && isupper(s1[i+1]) && s1[i-1] < s1[i+1])
                extend(s2, &j, s1[i-1], s1[i+1] && s1[i-1] < s1[i+1]);
            else if (islower(s1[i-1]) && islower(s1[i+1]) && s1[i-1] < s1[i+1])
                extend(s2, &j, s1[i-1], s1[i+1]);
            else if (isdigit(s1[i-1]), isdigit(s1[i+1]) && s1[i-1] < s1[i+1])
                extend(s2, &j, s1[i-1], s1[i+1]);
            else
                s2[j++] = s1[i];
        }
        else
            s2[j++] = s1[i];
    }
    s2[j] = '\0';
}

void extend(char s[], int *pos, char start, char end)
{
    for (int c = start + 1; c < end; ++c)
        s[(*pos)++] = c;
}
