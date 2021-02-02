#include <stdio.h>

int main() 
{ 
    char result[50]; 
    float num = 23.34; 
    sprintf(result, "%f", num); 
    printf("\nThe string for the num is %s.\n", result); 
    return 0;
} 

