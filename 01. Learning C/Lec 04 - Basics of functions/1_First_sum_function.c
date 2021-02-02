//1. Creating our first function - Sum

/* Write a prog to sum three numbers using functions. */

#include<stdio.h>

// This is called - 'Function Prototype Declaration'. Here we just pre-declare
// our function. 
int sum(int, int, int);          

int main()
{
    int a, b, c, addition;
    
    printf("Enter three integers to be summed.\n");
    scanf("%d %d %d",&a,&b,&c);
    
    // This is called - 'Function call'. Here we use our function.
    // a, b, c are called actual arguments.
    addition = sum(a, b, c);       
    printf("\nThe sum is %d.\n",addition);
    
    return 0;
}

// This is called - 'Function definition/header'. Here we write the actual 
// body of the function. 
// int x, int y and int z are called formal arguments.
int sum(int x, int y, int z)       
{
    int s;
    s = x + y + z;
    // Returned value will be collected by function 
    // sum(a,b,c) in main and get assigned to 'addition'
    return (s);        
}
