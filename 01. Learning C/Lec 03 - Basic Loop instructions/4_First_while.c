//4. Using While loop for first time - Triangular Number

/* Question: Write a program to calculate the triangular number. */

#include <stdio.h>

int main()
{
    int n, TriNum = 0, num;
    
    printf("Enter the number of which Triangular Number is to be calculated.\n");
    scanf("%i",&n);
    
    num = 0;
    while (num<=n)
    {
       TriNum += num;
       ++num;
    }
    printf("The triangular number at %i is %i.\n",n,TriNum);

    return 0;
}

/* SYNTAX: 
   initialization;
   while (condition)
   { 
     do this;
     and this;
     and this; 
     
     Incrementation
    } 
*/
