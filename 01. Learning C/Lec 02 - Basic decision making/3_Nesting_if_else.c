//3. Nesting of if-else

/* Question: Two numbers a and b are entered. Write a program to check whether 
    a is equal to or greater or lesser than b. */

#include <stdio.h>

int main()
{
    int number1, number2;
    printf("Enter two integers: \n");
    scanf("%d%d",&number1,&number2);

    if(number1 == number2)
    printf("Result: %d = %d",number1,number2);
    
    else
    {
        if (number1 > number2)
        printf("Result: %d > %d", number1, number2);
        else
        printf("Result: %d < %d",number1, number2);
    };
    return 0;
}
