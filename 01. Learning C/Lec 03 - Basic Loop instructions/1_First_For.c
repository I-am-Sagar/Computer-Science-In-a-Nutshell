//1. Using For Loop for first time - Triangular number

/* Question: Write a program to calculate the triangular number. */

#include <stdio.h>

int main()
{
    int n, TriNum = 0, x;
    
    printf("Enter the number of which Triangular Number is to be calculated.\n");
    scanf("%i",&n);
    
    for(x=0; x<=n; x++)
        TriNum += x;
    
    printf("The triangular number at %i is %i.\n",n,TriNum);
    
    return 0;
}

/* SYNTAX: 

   for(initialization ; condition; increment or decrement)
   { do this;
     and this;
     and this; } 
*/
