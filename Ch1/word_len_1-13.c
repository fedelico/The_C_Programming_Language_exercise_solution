#include <stdio.h>
#define MAXLEN 100
#define INWORD 1
#define OUTWORD 0

int main(void)
{
    long word_lens[MAXLEN];
    long word_len;
    short state;
    int c, i;
    for (i = 0; i < MAXLEN; ++i)
        word_lens[i] = 0;
    for (state = OUTWORD, word_len = 0; (c = getchar()) != EOF;){
        if (c == ' ' || c == '\t' || c == '\n'){
            if (state == INWORD){
                word_lens[word_len-1]++;
                word_len = 0;
            }
            state = OUTWORD;
        }
        else {
            state = INWORD;
            word_len++;
        }
    }
    for (i = 0; i < MAXLEN; ++i){
        if (word_lens[i] != 0){
            printf("%3d|", i + 1);
            for (int j = 0; j < word_lens[i]; ++j){
                if (j > 100){
                    printf("...");
                    break;
                }
                putchar('#');
            }
            printf(" %ld\n", word_lens[i]);
        }
    }

    return 0;
}


    
