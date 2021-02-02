//3. Returning float values

/* Write a prog to calc the squares of decimal values using functions. */

#include<stdio.h>

// If we define function before calling in main(), we don't need to give prototype.
float square(float x)    
{
    float y;
    y = x*x;
    printf("%f  ",y);
    return (y);
}

int main()
{
    float a, b;
    
    a = square(1.5);
    b = square(2.5);
    
    printf("\n%f  %f",a, b);
    
    return 0;
}
