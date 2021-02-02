// 7. Reverse digits

/* Write a prog to reverse a number and check it is a palindrome or not.*/

#include<stdio.h>

int main()
{
    int n, reversedInteger = 0, remainder, originalInteger;

    printf("Enter an integer to be reversed: ");
    scanf("%d", &n);

    originalInteger = n;

    while( n!=0 )
    {
        remainder = n%10;
        reversedInteger = reversedInteger*10 + remainder;
        n /= 10;
    }
    printf("The reverse of entered integer is %d.\n",reversedInteger);
    if (originalInteger == reversedInteger)
        printf("%d is a palindrome.", originalInteger);
    else
        printf("%d is not a palindrome.", originalInteger);
        
    return 0;
}
