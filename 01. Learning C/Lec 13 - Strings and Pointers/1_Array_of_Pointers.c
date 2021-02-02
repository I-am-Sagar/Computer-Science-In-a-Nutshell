// 1. Array of Pointers

// This is the array of pointers where each pointer points to a character array 
// somewhere in the memory.

#include <stdio.h>

int main()
{
    char *n[] = {"Sanjay", "Amol", "Sivaramkrishnan", "Sameer", "Rahul"};
    
    int i;
    char *t;
    
    for (i = 0; i <= 4; i++)
        printf ("%s ", n[i]);
    printf ("\n");
    
    t = n[2];
    // With one swap, we interchanged two names
    n[2] = n[3];
    n[3] = t;
    
    for (i = 0; i <= 4; i++)
        printf ("%s ", n[i]);
    printf ("\n");
        
    //Predict the output of this printf statement
    printf (2 + 3%2 + "Mechanical");
    printf ("\n");
    
    return 0;
}
