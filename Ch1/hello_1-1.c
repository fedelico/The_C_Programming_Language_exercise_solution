#include <stdio.h> //commenting out this line will produce "incompatible implicit declaration of built-in function ‘printf’" error

int main(void) //commenting out this line will produce "expected identifier or ‘(’ before ‘{’ token" error
{//commenting out this line will produce "expected declaration specifiers before ‘printf’ 'return' and } token" errors

    printf("hello world\n"); //commenting out this line won't produce any error
    return 0; //commenting out this line won't produce any error

}//commenting out this line will produce "expected declaration or statement at end of input" error
