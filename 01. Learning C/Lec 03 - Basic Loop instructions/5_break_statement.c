//5. The Break statement

/* Question: Write a prog to check whether the num is prime or not. */

#include<stdio.h>

int main()
{
    int n, i;
    
    printf("Enter a positive integer: \n");
    scanf("%d",&n);
    
    for(i=2; i<=n-1; ++i)
    {
        if(n%i==0)
        {
            printf("%d is not a prime number.",n);
            break;
        }
    }
    if (i==n)
    printf("%d is a prime number.",n);
    
    return 0;
}
