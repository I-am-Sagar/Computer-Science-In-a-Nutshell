// 11. sinx series

/* Question: Write a prog to calculate the sinx series upto the nth term, 
    where x and n would be entered by user. Note: x is in radians. */

#include<stdio.h>

int main()
{
    int n, i = 1, j, Denominator;
    float x, sum = 0, Numerator, Term;
    
    printf("Enter the value of x in sin(x) series.\n");
    scanf("%f", &x);
    printf("How many terms of the series should be summed?\n");
    scanf("%d", &n);
    
    while(i<=n)
    {
        j = 2*i - 1;
        Numerator=1;
        Denominator=1;
        for(int k=1; k<=j; k++)
        {
            Denominator = Denominator*k;
            Numerator=Numerator*x;
        }
        Term = Numerator/Denominator;
        
        (i%2==0)?(sum=sum-Term):(sum=sum+Term);
        i++;
    }
    printf("The required sum is %f.\n",sum);
    
    return 0;
}
