//8. Decimal to binary - Recursion

/* METHOD: Lets say the number is 10. Steps 1 to 4 - problem decomposition 
    and 5 to 9 - problem recomposition

1. a) 10 % 2 will give 0 + 10*(pass 10/2 to next step)
2. b) 5 % 2 will give 1 + 10*(pass 5/2 to next step)
3. c) 2 % 2 will give 0 + 10*(pass 2/2 to next step)
4. d) 1 % 2 will give 1 + 10*(pass 1/2 to next step)
5. e) 0 and condition fails, return 0
6. d) 1 + 10*0 = 1, return 1
7. c) 0 + 10*1 = 10, return 10
8. b) 1 + 10*10 = 101, return 101
9. a) 0 + 10*101 = 1010, return 1010.

Ans. 1010

*/

#include <stdio.h>

long long int findBinary(int);

int main()
{
    int n;
    long long int m;
    printf("Enter the number to find its Binary: ");
    scanf ("%d", &n);
    m = findBinary(n);
    printf ("\nThe binary of %d is %lld.\n", n, m);
    
    return 0;
}

 long long int findBinary(int decimal)
{
    long long int m;
    if (decimal == 0) m = 0ll;
    else m = decimal%2ll +10ll*(findBinary(decimal/2ll));
    
    return m;
}

/* NOTE:

    Due to limit of long long int, the maximum decimal number to which 
    this conversion takes place is 524287. 
*/
