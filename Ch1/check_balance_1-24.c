#include <stdio.h>
#define MAXSIZE 500
#define MAXLEN 500
typedef enum status {
    SINGLE_QUOTE,
    DOUBLE_QUOTE,
    MULTILINE_COMMENT,
    ONELINE_COMMENT,
    OTHERS
}status;

int get_line(char line[], int lim);

int main(void)
{
    char stack[MAXSIZE], line[MAXLEN];
    int line_num[MAXSIZE];
    int i, nl, len, stack_len;
    status state = OTHERS;
    for (i = 0; i < MAXSIZE; ++i){
        stack[i] = line[i] =  '\0';
        line_num[i] = 0;
    }
    for (nl = stack_len = 0, state = OTHERS; (len = get_line(line, MAXLEN)) > 0; ++nl){
        for (i = 0; i < len+1; ++i){
            switch (line[i]){
                case '\'':
                    if (state == OTHERS){
                        stack[stack_len++] = '\'';
                        state = SINGLE_QUOTE;
                    }
                    else if (state == SINGLE_QUOTE && ((i-2 > 0 && line[i-2] == '\\') || line[i-1] != '\\')){
                        stack[--stack_len] = '\0';
                        state = OTHERS;
                    }
                    break;
                case '\"':
                    if (state == OTHERS){
                        stack[stack_len++] = '\"';
                        state = DOUBLE_QUOTE;
                    }
                    else if (state == DOUBLE_QUOTE && ((i-2 > 0 && line[i-2] == '\\') || line[i-1] != '\\')){
                        stack[--stack_len] = '\0';
                        state = OTHERS;
                    }
                    break;
                case '/':
                    if (state == OTHERS && i < len && line[i+1] == '*'){
                        stack[stack_len++] = '/';
                        stack[stack_len++] = '*';
                        i++;
                        state = MULTILINE_COMMENT;
                    }
                    else if (state == OTHERS && i < len && line[i+1] == '/'){
                        i++;
                        state = ONELINE_COMMENT;
                    }
                    break;
                case '*':
                    if (state == MULTILINE_COMMENT && i < len && line[i+1] == '/'){
                        stack[--stack_len] = '\0';
                        stack[--stack_len] = '\0';
                        i++;
                        state = OTHERS;
                    }
                    break;
                case '\n':
                    if (state == ONELINE_COMMENT)
                        state = OTHERS;
                    break;
                case '(':
                    if (state == OTHERS)
                        stack[stack_len++] = '(';
                    break;
                case ')':
                    if (state == OTHERS){
                        if (stack_len > 0 && stack[stack_len - 1] == '(')
                            stack[--stack_len] = '\0';
                        else{
                            printf("Unmatched closing parenthesis at line %d\n", nl);
                            return 1;
                        }
                    }
                    break;
                case '[':
                    if (state == OTHERS)
                        stack[stack_len++] = '[';
                    break;
                case ']':
                    if (state == OTHERS){
                        if (stack_len > 0 && stack[stack_len - 1] == '[')
                            stack[--stack_len] = '\0';
                        else{
                            printf("Unmatched closing bracket at line %d\n", nl);
                            return 1;
                        }
                    }
                    break;
                case '{':
                    if (state == OTHERS)
                        stack[stack_len++] = '{';
                    break;
                case '}':
                    if (state == OTHERS){
                        if (stack_len > 0 && stack[stack_len -1] == '{')
                            stack[--stack_len] = '\0';
                        else{
                            printf("Unmatched closing curly brace at line %d\n", nl);
                            return 1;
                        }
                    }
                default:
                    break;
            }

        }

    }
    if (stack_len != 0){
        printf("Unmatched opening symbol at line %d\n",line_num[0]);
        printf("stack: %s\n", stack);
        return 1;
    }
    printf("Pairing symbols all matched\n");
    return 0;
}

int get_line(char line[], int lim)
{
    int i, c;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
        line[i] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}
