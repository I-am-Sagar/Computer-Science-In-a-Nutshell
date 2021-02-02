//7. Sum of digits - Recursion

/* METHOD: Let the number be 12345. Steps 1 to 6 is problem decomposition and 
   7 to 11 is problem recomposition

1. a) 12345 % 10 will give 5 + (send 12345/10 to next step)
2. b) 1234 % 10 will give 4 + (send 1234/10 to next step)
3. c) 123 % 10 will give 3 + (send 123/10 to next step)
4. d) 12 % 10 will give 2 + (send 12/10 to next step)
5. e) 1 % 10 will give 1 + (send 1/10 to next step)
6. f) 0 --> condition failed, return 0
7. e) 1 + 0 = 1, return 1
8. d) 2 + 1 = 3, return 3
9. c) 3 + 3 = 6, return 6
10. b) 4 + 6 = 10, return 10
11. a) 5 + 10 = 15, return 15. 

Answer = 15.

*/

#include <stdio.h>

int sum_of_digits (int);

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    printf("\nSum of digits of %d is %d.\n", num, sum_of_digits(num));
    return 0;
}

int sum_of_digits (int n)
{
    if (n == 0) return 0;       // Base condition
    else return (n%10 + sum_of_digits (n/10));  // Recursive condition
}
