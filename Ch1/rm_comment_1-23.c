#include <stdio.h>
#define ON 1 //indicate whether character is in between quotes
#define OFF 0

#define MAXLEN 500

#define ONELINE 1 //indicate whether character is in a one line comment , multi-line comment or not
#define MULTI_LINE 2
#define OUT 0

int get_line(char line[], int lim);
void clean_buffer(char buffer[], int size);

int main(void)
{
    /* This program removes all comments in C programs
     *
     */
    int len, i, j, detection, state;
    char line[MAXLEN], out_line[MAXLEN];
    clean_buffer(line, MAXLEN);
    clean_buffer(out_line, MAXLEN);
    detection = ON;
    state = OUT;
    while ((len = get_line(line, MAXLEN)) > 0){
        clean_buffer(out_line, MAXLEN);
        for (i = j = 0; i < len+1; ++i){
            if (state == OUT && line[i] == '\"' && (i == 0 || (i > 0 && line[i-1] != '\\'))){
                if (detection == ON)
                    detection = OFF;
                else
                    detection = ON;
                out_line[j++] = line[i];
            }
            else if (state == OUT && line[i] == '/'){
                if (i < len && line[i+1] == '*' && detection == ON)
                    state = MULTI_LINE;
                else if (i < len && line[i+1] == '/' && detection == ON)
                    state = ONELINE;
                else
                    out_line[j++] = line[i];
            }
            else if (state == MULTI_LINE && i < len){
                if (line[i] == '*' && line[i + 1] == '/'){
                    i++;
                    state = OUT;
                }
            }
            else if (line[i] == '\n'){
                if (state == OUT)
                    out_line[j++] = line[i];

                else if (state == ONELINE){
                    out_line[j++] = line[i];
                    state = OUT;
                }
            }
            else if (state == OUT)
                out_line[j++] = line[i];
        }
        printf("%s", out_line);
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

void clean_buffer(char line[], int size)
{
    for (int i = 0; i < size; ++i)
        line[i] = '\0';
}
