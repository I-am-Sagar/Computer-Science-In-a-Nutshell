//6. More on char

/* Characters are defined as single entities inside the single quotes 
   (both pointing leftwards). */

#include <stdio.h>
#include <limits.h>

int main() {
    /* --------------- Point 1 - Character and its ASCII value -------------- */

    char first = 'a', second = ';', third = '9', fourth = '\n';  
    //'10' is not a character but '1' and '0' are
    char FIRST = 97, SECOND = 59, THIRD = 57, FOURTH = 10;
    
    printf(" %c %c %c %c\n", first, second, third, fourth);
    printf("\n %d %d %d %d\n", first, second, third, fourth);
    
    printf(" %c %c %c %c\n", FIRST, SECOND, THIRD, FOURTH);
    printf("\n %d %d %d %d\n", FIRST, SECOND, THIRD, FOURTH);
    
    /* --------------------- Point 2 - Size and Limits -----------------------*/
    
    printf("\n SIZE = %d, MIN = %d, MAX = %d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
    
    /* ------------------- Point 3 - Character Arithmetic --------------------*/
    
    char ch1 = 125, ch2 = 11;
    
    char ch3 = ch1 + ch2;           // data overflows and cycles again
    
    printf("\n %c %d\n", ch3, ch3);
    printf("\n %c\n", ch3 - ch2 - 5);

    return 0;
}

/* At least the ranges of character sets in terms of ASCII codes must be 
   remembered:
 
        ASCII value  |  Characters
    --------------------------------------------
        0   -   47      |     special symbols
        48  -   57      |       0 - 9
        58  -   64      |     special symbols
        65  -   90      |       A - Z
        91  -   96      |     special symbols
        97  -   122     |       a - z
        123 -   255     |     special symbols
        
*/
