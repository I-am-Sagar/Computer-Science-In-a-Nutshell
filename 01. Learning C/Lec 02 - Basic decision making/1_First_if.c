//1. Using 'if' for 1st time

/* Question: While purchasing certain items, a discount of 10% is offered if the 
   quantity purchased is more than 10. If quantity and price per item is entered 
   through keyboard, program should calc the total expenses. */
   
#include <stdio.h>

int main() {
    int Q, dis = 0;
    float P, Expenses;
    
    printf("Enter quantity and price per item\n");
    scanf("%d%f",&Q, &P);
    
    if(Q>10)
    dis = 10;
    
    Expenses = Q*P - (Q*P*dis/100);
    printf("The total expenses are %f\n",Expenses);
    return 0;
}

/*  Here dis = 0 in initial step is important, because if not initialized, 
    it contains some unpredictable garbage value 
*/
