// 12. Smallest number of notes

/* Question: Consider a currency system in which notes of denominations 
   [1, 2, 5, 10, 20, 50, 100] are available. If sum of Rs. N is entered through 
   the keyboard, program should calc the smallest number of notes that would 
   make Rs. N 
*/
   

#include <stdio.h>

int main() 
{
    int N, n1, n2, n5, n10, n20, n50, n100, Notes;
    
    printf("Enter the amount\n");
    scanf("%d",&N);
    
    n100 = N%100;
    printf("Number of 100's notes = %i\n",(int)N/100);
    n50 = n100%50;
    printf("Number of 50's notes = %i\n",(int)n100/50);
    n20 = n50%20;
    printf("Number of 20's notes = %i\n",(int)n50/20);
    n10 = n20%10;
    printf("Number of 10's notes = %i\n",(int)n20/10);
    n5 = n10%5;
    printf("Number of 5's notes = %i\n",(int)n10/5);
    n2 = n5%2;
    printf("Number of 2's notes = %i\n",(int)n5/2);
    n1 = n2%1;
    printf("Number of 1's notes = %i\n",(int)n2/1);
    
    // Using '\', you can split the long code lines into 2 lines in C/C++
    Notes = (int)N/100 + (int)n100/50 + (int)n50/20 + \
            (int)n20/10 + (int)n10/5 + (int)n5/2 + (int)n2/1;
    printf("The smallest number of notes that make %i are %i\n",N,Notes);
    
    return 0;
}
