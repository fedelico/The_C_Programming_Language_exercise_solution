#include <stdio.h>

int main(void)
{
   int c;
   while ((c = getchar()) != EOF)
       printf("c == getchar() is %d\n", c == EOF);
   
   printf("Now c == getchar() is %d\nProgram terminating...\n", c == EOF);
   return 0;
}
