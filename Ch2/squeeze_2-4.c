#include <stdio.h>
void squeeze(char s1[], char s2[]);
int contain(char s[], char c);

int main(void)
{
    char words[6][20] = {"", "abc", "a", "djaldfksdj;fl", "Cdk", "cbg"};
    char s[6][20] = {"abc", "b", "a", "jazz", "fff", "cbg"};
    for (int i = 0; i < 6; ++i){
        printf("%s is squeezed into ", words[i]);
        squeeze(words[i], s[i]);
        printf("%s\n", words[i]);
    }
    return 0;
}

void squeeze(char s1[], char s2[])
{
    int i, j;
    i = j = 0;
    do{
        if (!contain(s2, s1[i]))
            j++;
    }while ((s1[j] = s1[++i]) != '\0');
}

int contain(char s[], char c)
{
    for (int i = 0; s[i] != '\0'; ++i)
        if (s[i] == c)
            return 1;
    return 0;
}



