// 3. Nesting For Loop 1 - Triangular Number

/* Question: Program should ask 5 times the user a number of which 
    triangular number is to be calculated. */

#include<stdio.h>

int main() 
{
    int n, num, TriNum, counter;
    
    // Initialization can be done outside the for loop.
    counter = 1;
    // Neither initialization nor increment is done in for loop, then too 2 
    // semicolons are compulsory.
    for( ; counter<=5 ; ) 
    {
        printf("What triangular number do you want?\n");
        scanf("%i",&num);
        
        TriNum=0;
        for(n=1; n<=num; ++n)
            TriNum += n;
        printf("Triangular Number is %i.\n\n",TriNum);

        ++counter;      // Incrementation is done within the loop.
    }
    return 0;
}
