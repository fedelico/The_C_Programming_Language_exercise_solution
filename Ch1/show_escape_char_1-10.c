#include <stdio.h>

int main(void)
{
    /* It seems that it's impossible to detect backspace in a terminal with cooked mode turned on. Other libraries or functions are needed to do that
     * see https://stackoverflow.com/questions/4363309/how-to-check-for-the-backspace-character-in-c
     * and https://stackoverflow.com/questions/3167733/ignore-backspace-key-from-stdin*/

    int c;
    while ((c = getchar()) != EOF){
        switch (c){
            case '\t':
                putchar('\\');
                putchar('t');
                break;

            case '\\':
                putchar('\\');
                putchar('\\');
                break;

            case '\n':
                putchar('\\');
                putchar('n');
                putchar('\n');
                break;

            default:
                putchar(c);
                break;
        }
    }
    return 0;
}
