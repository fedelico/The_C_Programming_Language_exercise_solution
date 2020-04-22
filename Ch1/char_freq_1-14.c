#include <stdio.h>
#define ALPHA_LEN 26
#define MAXWIDTH 100
int main(void)
{
    long char_table[ALPHA_LEN];
    int c;
    for (int i = 0; i < ALPHA_LEN; ++i)
        char_table[i] = 0;

    while ((c = getchar()) != EOF){
        if (c >= 'A' && c <= 'Z')
            char_table[c - 'A']++;
        else if (c >= 'a' && c <= 'z')
            char_table[c - 'a']++;

    }
    for (int i = 0; i < ALPHA_LEN; ++i){
        printf("%c|", 'a' + i);
        for (int j = 0; j <= char_table[i]; ++j){
            if (j == char_table[i])
                printf("%ld", char_table[i]);
            else if (j == MAXWIDTH && char_table[i] > MAXWIDTH){
                printf("...%ld", char_table[i]);
                break;
            }
            else
                putchar('#');
        }
        putchar('\n');
    }
    return 0;
}
