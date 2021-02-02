//6. The Continue statement

/* Question: Program to print odd or even numbers upto the limit n entered by 
   the user. */

#include <stdio.h>
 
int main()
{
    int N, counter;
    char flag;
    
    printf("Enter the last limiting number.\n");
    scanf("%d",&N);
    printf("What to print- 'E'ven or 'O'dd?\n");
    scanf(" %c",&flag);
    printf("\n");
    
    if( flag=='E' || flag == 'e') 
    {
        for(counter=1; counter <= N; counter++)
        {
            if(counter%2 == 1)
            continue;
        
        printf("%d\n",counter);
        }
    }
    if( flag=='O' || flag == 'o')
     {
        for(counter=1; counter <= N; counter++)
        {
            if(counter%2 == 0)
            continue;
        
        printf("%d\n",counter);
        }
    }
    
    return(0);
}
