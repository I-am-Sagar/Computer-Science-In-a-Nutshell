// 6. Youngest of 3 - Part 2

#include<stdio.h>

int main()
{
    int A, B, C;
    printf("Enter the age of A: ");
    scanf("%d",&A);
    printf("Enter the age of B: ");
    scanf("%d",&B);
    printf("Enter the age of C: ");
    scanf("%d",&C);
    
    if ((A!=B) && (B!=C) && (C!=A))
    {
        if((A<B) && (A<C))
            printf("A is the youngest.\n");
        else if((B<A) && (A<C))
            printf("B is the youngest.\n");
        else if((C<A) && (C<B))
            printf("C is the youngest.\n");
    }
    if ((A==B)||(B==C)||(C==A))
    {
        if((A==B) && (B!=C))
        {
            if(B<C)
                printf("A and B both are equal and younger than C.\n");
            else
                printf("C is the youngest.\n");
        }
        else if((A==C) && (A!=B))
        {
            if(A<B)
                printf("A and C both are younger than B.\n");
            else
                printf("B is the youngest.\n");
        }
        else if((B==C) && (B!=A))
        {
            if(C<A)
                printf("B and C both are younger than A.\n");
            else
                printf("A is the youngest.\n");
        }
    }
    return 0;
}
