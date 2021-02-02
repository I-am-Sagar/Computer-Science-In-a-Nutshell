// 14. Angstrom Numbers

/* Question: Write a prog to check whether the number is an Angstrom number or not. */

#include <stdio.h>
#include <math.h>

int main()
{
    int number, originalNumber, remainder, result = 0, n = 0;

    printf("Enter an integer to be checked: ");
    scanf("%d", &number);

     originalNumber = number;
    
    while (originalNumber != 0)
    {
        originalNumber /= 10;
        ++n;
    }

    originalNumber = number;

    while (originalNumber != 0)
    {
        remainder = originalNumber%10;
        result += pow((float)remainder, n);
        originalNumber /= 10;
    }

    if(result == number)
        printf("%d is an Armstrong number.", number);
    else
        printf("%d is not an Armstrong number.", number);

    return 0;
}
