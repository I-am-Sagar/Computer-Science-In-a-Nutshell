// 15. Angstrom number - Upto a given limit

/* Write a prog to print Angstrom numbers between two intervals. */

#include<stdio.h>
#include<math.h>

int main()
{
    int low, high, i, temp1, temp2, remainder, Numofdigits = 0, sum = 0;

    printf("Enter the lower and higher limit of the interval: ");
    scanf("%d %d", &low, &high);
    printf("Armstrong numbers between %d and %d are: \n", low, high);

    for(i = low + 1; i < high; ++i)
    {
        temp1 = i;
        temp2 = i;
        
        // number of digits calculation
        while (temp1 != 0)      
        {
            temp1 /= 10;
            ++Numofdigits;
        }

        // result contains sum of nth power of its digits
        while (temp2 != 0)    
        {
            remainder = temp2 % 10;
            sum += pow(remainder, Numofdigits);
            temp2 /= 10;
        }

        // checks if number i is equal to the sum of nth power of its digits
        if (sum == i)     
            printf("%d\n", i);

        // resetting the values to check Armstrong number for next iteration
        Numofdigits = 0;   
        sum = 0;
    }
    return 0;
}
