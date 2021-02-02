// 2. Collinearity of 3 points

/* Question: Write a prog to determine whether given 3 points by user are 
   collinear or not. */

#include<stdio.h>

int main()
{
    float x1, y1, x2, y2, x3, y3, a, b;
    
    printf("Enter first point in ordered pair (x,y):");
    scanf("%f%f",&x1,&y1);
    printf("Enter second point in ordered pair (x,y):");
    scanf("%f%f",&x2,&y2);
    printf("Enter third point in ordered pair (x,y):");
    scanf("%f%f",&x3,&y3);
    
    a = (x2-x1)/(y2-y1);
    b = (x3-x1)/(y3-y1);
    
    if(a==b)
        printf("The given points are collinear.");
    else
        printf("The given points are non-collinear.");
    
    return 0;
}
