#include <stdio.h>
#define N 20

int main (int num)
{
    if (num <= N && printf("%d ", num) && main(num+1))
    {
    }
}

/* There is an iterative way also which uses while loop.

#include<stdio.h> 
#define N 10 
  
int main(int num, char *argv[]) 
{ 
    while (num <= N && printf("%d ", num) && num++)  
    { 
    }  
}

*/
