// 7. Showbits() function

#include <stdio.h>

void showbits(unsigned char);

int main()
{
    /* ------ Point 1 - Print binary of 1 byte character ----------------- */
    unsigned char num;
    
    printf("Enter a positive number less than 255: ");
    scanf ("%d", &num);
    
    printf("\nDecimal %d is same as binary ", num);
    showbits (num);
    
    /* ------ Point 2 - Print 1's complement of 1 byte character --------- */
    
    printf ("\nOne's complement of %d is ", num);
    showbits (~ num);
    
    /* ------ Point 3 - Left shift and right shift demonstration -------- */
    
    printf ("\nWhen left shifted by 3 it gives ");
    showbits (num << 3);
    printf ("\nWhen right shifted by 4 it gives ");
    showbits (num >> 4);

    return 0;
}

void showbits(unsigned char n)
{
    int i;
    unsigned char j, k, andmask;
    
    for (i = 7; i >= 0; i--)
    {
        j = i;
        andmask = 1 << j;
        k = n & andmask;
        if (k == 0)  printf("0");
        else   printf("1");
    }
}
