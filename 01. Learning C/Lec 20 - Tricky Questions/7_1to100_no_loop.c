#include <stdio.h> 
 
void printNos(unsigned int n) 
{ 
    if(n > 0) 
    { 
        printNos(n - 1); 
        printf("%d ", n); 
    } 
    return; 
} 

int main() 
{ 
    printNos(100); 
    printf ("\n");
    return 0; 
} 

