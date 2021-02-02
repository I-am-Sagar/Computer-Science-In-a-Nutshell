// 6. Fib - Limit of term given

/* Question: Write a prog that prints Fibonacci series upto a certain limit, 
   limit being entered by user. */

#include<stdio.h>

int main()
{
    int t1 = 0, t2 = 1, nextTerm = 0, n;
    
    printf("Enter the limit upto which Fibonacci series is to be printed: ");
    scanf("%d", &n);
    printf("Fibonacci Series:\n %d\n %d\n ", t1, t2);

    nextTerm = t1 + t2;
    while(nextTerm <= n)
    {
        printf("%d\n ",nextTerm);
        t1 = t2;
        t2 = nextTerm;
        nextTerm = t1 + t2;
    }
    
    return 0;
}
