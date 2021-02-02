//4. Fibonacci numbers - Recursion

#include <stdio.h>

int fib(int);

int main()
{
    int n;
    printf("Enter the n to find nth Fibonacci number: ");
    scanf("%d", &n);
    
    printf("\nFibonacci(%d) = %d\n", n, fib(n));
    return 0;
}

int fib(int m)
{
    if (m == 0) 
        return 0;
    else if (m == 1) 
        return 1;
    else 
        return ( fib(m-1) + fib(m-2) );
}

/* NOTE:
    
    As the recursion goes deep and deep, it becomes time consuming even for 
    computer to calculate the result. Even for Fibonacci(45) we have to wait 
    alot of time (11 seconds). So we consider here, after n = 45, this program 
    is not that good.
*/
