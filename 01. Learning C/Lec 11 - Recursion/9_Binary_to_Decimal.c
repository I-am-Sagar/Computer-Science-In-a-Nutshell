// 9. Binary to Decimal Conversion

/*
    LOGIC: Lets say the binary number is num = 1010.
    
    1. dec(1010) = 1*2^3 + 0*2^2 + 1*2^1 + 0*2^0 = 2(1*2^2 + 0*2^1 + 1*2^0) + 0 = 2*dec(101) + 0
    2. dec(101)  = 2*dec(10) + 1
    3. dec(10)   = 2*dec(1) + 0
    4. dec(1)    = 1
    
*/

#include <stdio.h>

int findDecimal(long long int);

int main()
{
    int n;
    long long int m;
    printf("Enter the binary to find its decimal: ");
    scanf ("%lld", &m);
    n = findDecimal(m);
    printf ("\nThe decimal of %lld is %d.\n", m, n);
    
    return 0;
}

int findDecimal(long long int binary)
{
    if (binary == 1) return 1;
    else return (2*findDecimal(binary/10) + binary%10);
}
