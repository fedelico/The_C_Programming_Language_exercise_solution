#include <stdio.h>

int main(void)
{
    long nb, nt, nl;
    int c;
    for (nb = nt = nl = 0; (c = getchar()) != EOF;){
        switch (c){
            case ' ':
                nb++;
                break;

            case '\t':
                nt++;
                break;

            case '\n':
                nl++;
                break;

            default:
                break;
        }
    }
    printf("RESULTS:\n Blanks:%5ld\n Tabs:%7ld\n Lines:%6ld\n", nb, nt, nl);
    return 0;
}
