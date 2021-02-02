// Fine the sum of digits of a number in single line

#include <stdio.h>


int sumDigits(int no) 
{ 
   return no == 0 ? 0 : no%10 + sumDigits(no/10) ; 
} 
  
int main(void) 
{ 
    printf("%d\n", sumDigits(687)); 
    return 0; 
} 

