/*
     Logic: 
     
     Get the address and size of the variable. Typecast the address to char pointer. 
     Now loop for size of the variable and print the value at the typecasted pointer.
*/

#include <stdio.h> 
typedef unsigned char *byte_pointer; 

// Show bytes takes byte pointer as an argument and prints memory contents 
// from byte_pointer to byte_pointer + len

void show_bytes(byte_pointer start, int len)  
{ 
     int i; 
     for (i = 0; i < len; i++) 
           printf(" %.2x", start[i]); 
     printf("\n"); 
} 
  
void show_int(int x) 
{ 
     show_bytes((byte_pointer) &x, sizeof(int)); 
} 
  
void show_float(float x)  
{ 
     show_bytes((byte_pointer) &x, sizeof(float)); 
} 
  
void show_pointer(void *x)  
{ 
     show_bytes((byte_pointer) &x, sizeof(void *)); 
} 

int main() 
{ 
    int i = 1; 
    float f = 1.0; 
    int *p = &i; 
    
    show_float(f); 
    show_int(i); 
    show_pointer(p); 
    show_int(i); 

    return 0; 
}
