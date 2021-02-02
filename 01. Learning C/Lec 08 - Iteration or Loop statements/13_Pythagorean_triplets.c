// 13. Generate Pythagorean Triplets

/* Write a prog to generate list of pythagorean triplets upto a certain limit, 
   limit being entered by the user.*/

#include<stdio.h>

int main ()
{
    int a, b, c=0, limit, m, n, count = 0;
    
    printf("Enter the limit upto which pythagorean triplets are to be generated.\n");
    scanf("%d",&limit);
    
    m = 2;
    while (c < limit)
    {
        for (n = 1; n < m; ++n)
        {
            a = m*m - n*n;
            b = 2*m*n;
            c = m*m + n*n;
 
            if (c > limit)
                break;
 
            printf("%2d %2d %2d\n", a, b, c);
        
            if( a == m*m - n*n && b == 2*m*n && c == m*m + n*n)
                count += 1;
        }
        m++;
    }
    printf("\nThere are %d pythagorean triplets within the limit.\n",count);
    
    return 0;
}
