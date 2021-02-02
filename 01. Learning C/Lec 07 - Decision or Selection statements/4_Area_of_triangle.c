// 4. Area of Triangle

/* Question: Write a prog to calc the area of triangle, when 3 sides are entered 
   by the user, with the condition that the triangle is valid. */

#include<stdio.h>
#include<math.h>

int main()
{
    float a, b, c, s, area = 0;
    
    printf("Enter the three sides of triangle.\n");
    scanf("%f%f%f",&a, &b, &c);
    
    s = (a+b+c)/2;
    
    if((s-a<0) || (s-b<0) || (s-c<0) )
        printf("The triangle with given sides cannot be formed.\n");
    else
    {
        area = sqrt(s*(s-a)*(s-b)*(s-c));
        printf("The area of the given triangle is %f square units.\n", area);
    }
    
    return 0;
}
