// 5. Fib - Number of terms given

/* Question: Write a prog to print Fibonacci series where number of terms 
   is entered by the user. */

#include<stdio.h>

int main()
{
    int i, n, t1 = 0, t2 = 1, nextTerm;

    printf("Enter the number of terms of Fibonacci series: ");
    scanf("%d", &n);

    printf("Fibonacci Series: \n\n");

    for (i = 1; i <= n; ++i)
    {
        printf("%d \n", t1);
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;
    }
    return 0;
}

/* Explain cycle of int by showing 48th term is negative. */
