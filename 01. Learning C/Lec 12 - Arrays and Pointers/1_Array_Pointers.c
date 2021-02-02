// 1. Array Pointers

#include <stdio.h>

int main()
{
    int a[][4] = { 7, 2, 6, 1,
                   9, 3, 4, 5, 
                   10, 12, 16, 18 };
    
    printf ("%u\n", a);      
    printf ("%d\n", *a);      
    printf ("%u %u %u\n", a+0, a+1, a+2);
    printf ("%d %d %d\n", *(a+0), *(a+1), *(a+2));
    printf ("%d %d %d\n", a[0], a[1], a[2]);
    printf ("%d %d %d\n", a[0]+1, a[1]+2, a[2]+3);
    printf ("%d %d %d\n", *(a[0]+1), *(a[1]+2), *(a[2]+3));
    printf ("%d %d %d\n", a[0][1], a[1][2], a[2][3]);
    
    return 0;
}
     
/*
    Note: Name acts as pointer to 0th element
        2-D array is an array of 1D arrays
*/
