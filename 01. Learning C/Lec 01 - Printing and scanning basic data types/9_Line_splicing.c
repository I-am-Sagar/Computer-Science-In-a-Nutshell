//9. Line splicing

#include <stdio.h>

int main() {
    //Line splicing\
    printf("Hello"); printf(" World\n"); 
    printf("You directly see this!\n");
    
    return 0;
}

/* EXPLANATION: 

Whenever at the end of the single-line comment line, we use backslash (\), then 
the next line of that comment is also treated as comment, no matter how many 
statements are written on it.

*/
