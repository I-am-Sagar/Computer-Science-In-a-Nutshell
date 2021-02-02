// 2. Aligned Output

/* Question: Write a prog to generate table of triangular numbers from  to n, 
    where limit n is entered by user.*/

#include<stdio.h>

int main()
{
    int n, TriNum = 0;
    
    printf("Enter the limit of table of triangular numbers.\n");
    scanf("%d",&n);
    
    printf("TABLE OF TRIANGULAR NUMBERS\n\n");
    printf("  n        Sum from 1 to n\n");
    printf("------     -----------------\n");
    
    for(int i=1; i<=n; ++i)
    {
        TriNum += i;
        printf("%3i    %i\n",i,TriNum); 
        //The 3 with i does the work of alignment.Print with & without 3 & compare.
    }
    
    return 0;
}
