// 4. Multiplication Table

/* Question: Write a prog to print multiplication table of the form m x n = mn 
   (as we used to write in junior grades), where m and n are entered by the user. 
*/
  
#include<stdio.h>

int main()
{
    int m, n;
    
    printf("Enter the number whose multiplication table is required.\n");
    scanf("%d",&m);
    printf("\nEnter the limit upto which multiplication is required.\n");
    scanf("%d",&n);
    printf("\n");
    
    for(int i=1; i<=n; i++)
        printf("%d x %3d = %5d\n",m, i, m*i);

    return 0;
}
