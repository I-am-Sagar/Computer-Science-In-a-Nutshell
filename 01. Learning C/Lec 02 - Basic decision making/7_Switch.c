//7. The switch statement

/* Write a program that implements switch to make a simple calculator. */

#include<stdio.h>

int main()
{
    float num1, num2;
    int option;
    
    printf("Enter the first number:  ");
    scanf(" %f",&num1);
    printf("Enter the second number:  ");
    scanf(" %f",&num2);

    printf("\nEnter the your option:\n");
    printf("1-Addition.\n2-Substraction.\n3-Multiplication.\n4-Division.\n5-Exit.\n");
    scanf("%d",&option);
        
    switch(option)
    {
        case 1:
            printf("\nAddition of %f and %f is: %f\n", num1, num2, num1+num2);
            break;
            
        case 2:
            printf("\nSubstraction of %f and %f is: %f\n", num1, num2, num1-num2);
            break;
            
        case 3:
            printf("\nMultiplication of %f and %f is: %f\n", num1, num2, num1*num2);
            break;  
            
        case 4: 
            if(num2 == 0)  
                printf("Oops!!! Can't Divide by zero.\n");
            else
                printf("\n Division of %f  and %f is:  %f", num1, num2, num1/num2);
            break;
        
        case 5: 
            //You can also use exit(0) function available in stdlib.h library
            return 0;
            
        default: 
            printf("\nI hope you can see options!\n");
    }
    return 0;
}
