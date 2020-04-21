#include <stdio.h>
#define MAXLEN 100
#define INWORD 1
#define OUTWORD 0
#define UPPER 50

int main(void)
{
    long word_lens[MAXLEN];
    long max_len, word_len, plot_height;
    int c, i, state;
    
    for (i = 0; i < MAXLEN; ++i) //initialize array
        word_lens[i] = 0;

    for (state = OUTWORD, word_len = 0; (c = getchar()) != EOF;){ //collect words frequencies
        if (c == ' ' || c == '\t' || c == '\n'){
            if (state == INWORD){
                word_lens[word_len - 1]++;
                word_len = 0;
            }    
            state = OUTWORD;
        }
        else{
            word_len++;
            state = INWORD;
        }
    }

    for (i = max_len = 0; i < MAXLEN; ++i) //obtain plot height
        if (word_lens[i] > max_len)
            max_len = word_lens[i];
    plot_height = (max_len <= UPPER)? max_len + 1 : UPPER; //the height of the plot should not exceed upperbound
    
    for (i = 0; i < plot_height; ++i){ //draw the plot
        for (int j = 0; j < MAXLEN; ++j){
            if ((i == (plot_height - word_lens[j] - 1) || (i == 0 && word_lens[j] > plot_height)) &&
               word_lens[j] > 0)
                printf("%3ld ", word_lens[j]);
            
            else if (word_lens[j] > 0){
                if (i >= (plot_height - word_lens[j]))
                    printf(" #  ");
                else
                    printf("    ");
            }
        }
        putchar('\n');
    }

    for (i = 0; i < MAXLEN; ++i)
        if (word_lens[i] > 0)
            printf("%3d ", i+1);
    putchar('\n');
    return 0;
}
      
