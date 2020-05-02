#include <stdio.h>
int any(char s1[], char s2[]);
int contain(char s2[], char c);

int main(void)
{
    char *words[6] = {"", "a", "abc", "fdsaeogjdladf", "2019", "fdajf2398gjbdjlw"};
    char *s[6] = {"abc", "a", "b", "", "degfbda1", "w"};
    for (int i= 0; i < 6; ++i)
        printf("%s find match at position %d\n", words[i], any(words[i], s[i]));
    return 0;
}

int any(char s1[], char s2[])
{
    int i;
    for (i = 0; s1[i] != '\0'; ++i)
        if (contain(s2, s1[i]))
            return i;
    return -1;

}

int contain(char s2[], char c)
{
    for (int i = 0; s2[i] != '\0'; ++i)
        if (s2[i] == c)
            return 1;
    return 0;
}
