//2. Attempt to return two values from function

/* Write a prog to calc sum and product of three numbers entered by the user. */

#include<stdio.h>

int sumproduct(int, int, int, int);

int main()
{
    int a, b, c, sum, product;
    
    printf("Enter 3 integers to be summed and multiplied.\n");
    scanf("%d %d %d",&a, &b, &c);
    
    sum = sumproduct(a, b, c, 1);
    product = sumproduct(a, b, c, 2);
    printf("\nThe sum is %d and the product is %d.\n",sum, product);
    
    return 0;
}

int sumproduct(int x, int y, int z, int code)
{
    if (code == 1)
        return (x+y+z);
    else
        return (x*y*z);
}

/*  We will see this same sumproduct function while discussing pointers - 
    where we will return two values from a function without using code like 
    1 or 2 in some way. 
*/
