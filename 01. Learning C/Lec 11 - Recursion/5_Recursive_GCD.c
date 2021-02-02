//5. GCD - recursion

#include <stdio.h>

int gcd (int, int);

int main()
{
    int a, b;
    
    printf("Enter two numbers whose GCD is to be found: ");
    printf("\na = ");
    scanf("%d", &a);
    printf("b = ");
    scanf("%d", &b);
    
    printf("\nGCD of %d and %d is %d.\n", a, b, gcd(a, b));
    return 0;
}

int gcd(int a, int b)
{
    if (b == 0) return a;
    else return gcd(b, a%b);
}
