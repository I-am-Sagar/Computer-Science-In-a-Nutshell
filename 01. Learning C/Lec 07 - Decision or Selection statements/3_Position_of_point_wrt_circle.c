// 3. Position of point wrt circle

/* Question: Write a prog that determines whether the point is inside, on or 
   outside the circle; where point, centre and radius of circle are entered by 
   user. */
   
#include<stdio.h>
#include<math.h>

int main()
{
    float x1, y1, x, y, r;
    float d1, d2, d;
    
    printf("Enter the point to be checked.\n");
    scanf("%f%f",&x1, &y1);
    printf("Enter the centre of circle.\n");
    scanf("%f%f",&x,&y);
    printf("Enter the radius of the circle.\n");
    scanf("%f",&r);
    
    d1 = pow(x-x1, 2.0);
    d2 = pow(y-y1, 2.0);
    d = sqrt(d1 + d2);
    
    if(d < r)
        printf("\nThe point lies inside the circle at distance %f units from centre.\n",d);
    else if(d == r)
        printf("\nThe point lies on the circle.\n");
    else 
        printf("\nThe point lies outside the circle at distance %f units from centre.\n",d);
    
    return 0;
}
