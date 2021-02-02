//7. The Odd Loop - Y/N

/* Write a prog which should calc the factorial the number of times user needs. */

#include<stdio.h>

int main()
{
    int Num, i;
    long long int fact = 1;
    char flag;
    
    flag = 'y';
    while ((flag=='y')||(flag=='Y'))
    {
        printf("\nEnter the number whose factorial you want.\n");
        scanf("%d",&Num);
        
        for(i=1; i<=Num; i++) {fact = fact*i;}
        
        printf("The factorial of %d is %lld.\n", Num, fact);
        
        printf("\nDo you want to calculate factorial again? 'Yes'/'N'o\n");
        scanf(" %c", &flag);
    }
    return 0;
}
