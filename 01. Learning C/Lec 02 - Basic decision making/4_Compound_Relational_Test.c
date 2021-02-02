//4. Compound relational test - Leap year

/* Write a program to check whether the entered year is leap or not */

#include<stdio.h>

int main() 
{
    int year, rem4, rem100, rem400;
    
    printf("Enter the year to be tested\n");
    scanf("%i",&year);
    
    rem4 = year%4;
    rem100 = year%100;
    rem400 = year%400;
    
    if ((rem4 == 0 && rem100 != 0)|| rem400 == 0) 
    // && is logical operator ^ (and) and || is logical operator v (or).
        printf("It is a leap year.\n");
    else 
        printf("It is not a leap year.\n");
    return 0;
}
