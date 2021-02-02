// 10. Binary to dec conversion

/* Write a C prog that converts binary number to its equivalent decimal number. */

#include<stdio.h>

int main()
{
    long long int binary, temp;
    int decimal = 0, digit, base = 1;
    
    printf("Enter the binary number.\n");
    scanf("%lld",&binary);
    
    temp = binary;
    
    while(binary>0)
    {
        digit = binary%10;
        decimal = decimal + digit*base;
        binary = binary/10;
        base = base*2;
    }
    printf("The decimal equivalent of %lld is %d.\n",temp, decimal);
    
    return 0;
}
