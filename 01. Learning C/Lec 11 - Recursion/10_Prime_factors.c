// 10. Prime Factors

/*
    LOGIC: 
    
     1. The for loop, for( a = 2; a <= x; a++ ) keeps incrementing the counter, 'a'. 
         We use it to divide the number that user entered.
     2. The if condition, if( x % a == 0 ) checks if the number is divisible by the 
         current value of the counter 'a'. 
     3. If that is the case, we print the number 'a' and call our function prime 
         recursively, but this time with a value 'x/a'.
*/

#include <stdio.h>

void primeFactors (int x)
{
    int a; 
    for (a = 2; a <= x; a++)
        if (x%a == 0)
        {
            printf ("%d ", a);
            primeFactors (x/a);
            
            break;
        }
}

int main()
{
    int number;
    
    printf("Enter the number: ");
    scanf("%d", &number);
    
    primeFactors (number);
    printf ("\n");
    
    return 0;
}
