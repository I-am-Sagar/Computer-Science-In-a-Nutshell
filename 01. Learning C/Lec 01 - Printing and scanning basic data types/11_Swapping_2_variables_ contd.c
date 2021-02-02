//11. Swapping data of 2 variables - contd.

/* Question: Write the program to interchange the values of 2 variables. */

#include<stdio.h>
// #include<conio.h>

int main() {
    int a, b;
    
    printf("Enter the values of a and b.\n");
    scanf("%d%d",&a,&b);
    
    a = a + b;
    b = a - b;
    a = a - b;
    
    printf("Values after interchanging - %i,%i.\n",a,b);
 // getch();
    return 0;
}

/* Here we have used '+' and '-' to swap 2 variables without using third variable.

There are other methods as well to swap 2 variables without using third variable.

METHOD 1: Use Multiplication and Division
    int x = 10, y = 5; 
    x = x * y; // x now becomes 50 
    y = x / y; // y becomes 10 
    x = x / y; // x becomes 5 

The multiplication and division based approach doesn’t work if one of the numbers 
is 0 as the product becomes 0 irrespective of the other number.

Both Arithmetic solutions may cause arithmetic overflow. If x and y are too large, 
addition and multiplication may go out of integer range.

(You can skip this. We have covered this in Bitwise operators section later on.)
METHOD 2: Use Bitwise XOR 
    int x = 10, y = 5; 
    // Swap 'x' (1010) and 'y' (0101) 
    x = x ^ y; // x now becomes 15 (1111) 
    y = x ^ y; // y becomes 10 (1010) 
    x = x ^ y; // x becomes 5 (0101) 

Here are some fun, one liner swaps:
    a += b – (b = a);
    b = (a + b) – (a = b); 
    a ^= b ^= a ^= b; 

*/
