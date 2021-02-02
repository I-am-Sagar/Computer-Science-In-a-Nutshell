/*
    printf() function returns the number of characters printed. 
    
    Now 'width field' in printf() can be used to find the sum of two numbers. 
    We can use ‘*’ which indicates the minimum width of output. For example, 
    in the statement “printf(“%*d”, width, num);”, the specified ‘width’ is 
    substituted in place of *, and ‘num’ is printed within the minimum width specified. 
    
    If number of digits in ‘num’ is smaller than the specified ‘width’, the output 
    is padded with blank spaces. If number of digits are more, the output is 
    printed as it is (not truncated). 
    
    In the following program, add() returns sum of x and y. It prints 2 spaces 
    within the width specified using x and y. So total characters printed is 
    equal to sum of x and y. That is why add() returns x+y.
    
    The output is seven spaces followed by “Sum = 7”. We can avoid the leading 
    spaces by using carriage return.
*/

#include<stdio.h> 
  
int add1 (int x, int y) 
{
    return printf("%*c%*c", x, ' ', y, ' '); 
}

int add2(int x, int y) 
{ 
    return printf("%*c%*c", x, '\r', y, '\r'); 
}

int main()
{
    printf ("%d\n%d\n", add1(3, 4), add2(3, 4));
    return 0;
}

/* 
    We cant solve similar subtraction tricky question without operator.
*/
