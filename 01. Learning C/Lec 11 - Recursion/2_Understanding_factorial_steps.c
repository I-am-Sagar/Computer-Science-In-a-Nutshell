//2. Understanding factorial steps

#include <stdio.h>

int fact (int);

int main()
{
    int m, n;
    
    printf("Enter the number whose factorial is to be calculated: ");
    scanf("%d", &n);
    
    m = fact(n); 
    printf("\nFact(%d) = %d\n", n, m);
    return 0;
}

int fact (int i)
{
    int m = 1;
    
    printf ("\n In fact i = %d and m = %d\n", i, m);
    
    if(i>1)  m = i*fact(i-1);
    
    printf ("\n Out fact i = %d and m = %d\n", i, m);
    
    return m;
}

/* BETTER VERSION OF FACTORIAL PROGRAM: 

    int fact (int i)
    {
        if (i==1) return 1;
        else return (i*fact(i-1));
    }
*/
