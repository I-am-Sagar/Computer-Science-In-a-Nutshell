//2. The Modulus operator

#include <stdio.h>

int main()
{
    /* ---------------------- Point 1 - Working --------------------- */
    
    int x = 56, y = 13;
    printf ("%d %d\n", x%y, y%x);   
    // Can be used only with integers and chars
    
    /* ---------------- Point 2 - Sign of Remainder ----------------- */
    
    int c1 = -5, c2 = 5, d1 = 2, d2 = -2;
    printf("\n%d %d\n", c1%d1, c2%d2);  
    // The sign of remainder is always same as the sign of the numerator
    
    /* ------------------ Point 3 - Example ------------------------- */
    
    /* Question: Ask 2 integers from user a and b, and write a program to 
       find next number from 'a' which is perfectly divided by 'b' . */
    
    int a, b, Nextmultiple;
    printf("\nEnter the integer which you have to round off to next multiple: ");
    scanf ("%d", &a);
    printf("\nEnter your divisor: ");
    scanf ("%d", &b);
    
    Nextmultiple = a - a%b + b;
    printf("\nThe multiple of %d next to %d is %d.\n", b, a, Nextmultiple);
    
    return 0; 
}
