#include <stdio.h>
#define my_sizeof(type) (char*)(&type+1)-(char*)(&type)
 
int main() 
{ 
    double x; 
    printf("%d\n", my_sizeof(x)); 
    
    return 0; 
} 

