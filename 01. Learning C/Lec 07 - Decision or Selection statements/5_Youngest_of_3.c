// 5. Youngest of 3 - Part 1

/* Question: If ages of A, B, C are entered, write a prog to determine the 
   youngest of 3. */

#include<stdio.h>

int main()
{
    int A, B, C;
    
    printf("Enter the ages of A, B and C.\n");
    scanf("%d%d%d",&A, &B, &C);
    
    if(A<B)
    {
        if(A<C)
        printf("A is the youngest.\n");
        else 
        printf("C is the youngest.\n");
    }
    else
    {
        if(B<C)
        printf("B is the youngest.\n");
        else
        printf("C is the youngest.\n");
    }
    
    return 0;
}
