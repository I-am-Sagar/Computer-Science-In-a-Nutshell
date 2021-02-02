// 8. Primes 

/* Question: Write a prog to print all primes form 1 to N, where N is entered 
   by the user. Also print the total number of primes in that range. */

#include<stdio.h>
  
int main()
{
    int N, i, j, count;
     
    printf("To print all prime numbers between 1 to N.\n\n");
    printf("Enter the value of N.\n");
    scanf("%d",&N);
  
    printf("Prime numbers between %d to %d\n\n", 1, N);
     
    for(i = 2; i <= N; i++)
    {
        for(j = 2; j <= i-1; j++)
        {
            if(i%j == 0)
            break;
        }
          
        if(j == i)
        {   printf("%d\n",i);
            count += 1;
        }
    }
    printf("\nThe number of primes from 1 to %d are %d.\n",N, count);

   return 0;
}
