//2. Using if-else for first time

/* Question: 

The basic salary of company is 12,000 per month. If the employee is having 
experience less than or equal to 4 years, they get the basic salary, 50% of 
salary as bonus and 5,000 as yearly expenses. If the experience is more than 4 
years, they would get basic salary, 100% of salary as bonus and 6,000 as yearly 
expenses. If the number of years of experience is entered through keyboard, 
write a prog to calc their annual income. 
*/
   
#include <stdio.h>

int main()  {
    float Noy, Sal = 12000, Expenses, bonus, AnnIncome;
    
    printf("Enter the number of years of experience\n");
    scanf("%f",&Noy);

    // The order of these conditional operators should be remembered to use 
    // them only as <=, >=, != and not in reverse order.	
    if (Noy <= 4) {
        bonus = 6000;
        Expenses = 5000;
    }
    else {
        bonus = 12000;
        Expenses = 6000;
    };
    AnnIncome = 12*Sal + bonus + Expenses;
    printf("The annual income is %f\n",AnnIncome);
    
    return 0;
}
