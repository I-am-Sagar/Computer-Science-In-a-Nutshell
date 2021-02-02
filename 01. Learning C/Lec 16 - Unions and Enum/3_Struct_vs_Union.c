// C program to illustrate differences between structure and Union 

#include <stdio.h> 
#include <string.h> 
   
struct struct_example 
{ 
    int integer; 
    float decimal; 
    char name[20]; 
}; 

union union_example 
{ 
    int integer; 
    float decimal; 
    char name[20]; 
}; 
   
void main() 
{ 
    // creating variable for structure and initializing values
    struct struct_example s = {18, 38, "sagar"}; 
   
    // creating variable for union and initializing values 
    union union_example u = {18, 38, "sagar"}; 
   
           
    printf("Structure data:\n Integer: %d\n" 
           "Decimal: %.2f\n Name: %s\n", 
            s.integer, s.decimal, s.name); 
    printf("\nUnion data:\n Integeer: %d\n"
            "Decimal: %.2f\n Name: %s\n",  
            u.integer, u.decimal, u.name); 
   
    printf("\nsizeof structure : %d\n", sizeof(s)); 
    printf("sizeof union : %d\n", sizeof(u)); 
       
    printf("\nAccessing all members at a time:");  
    s.integer = 183; 
    s.decimal = 90; 
    strcpy(s.name, "Vishnu"); 
       
    printf("Structure data:\n Integer: %d\n "
            "Decimal: %.2f\n Name: %s\n", 
            s.integer, s.decimal, s.name); 
       
    u.integer = 183; 
    u.decimal = 90; 
    strcpy(u.name, "Vishnu"); 
       
    printf("\nUnion data:\n Integeer: %d\n "
            "Decimal: %.2f\n Name: %s\n", 
            u.integer, u.decimal, u.name); 
       
    printf("\nAccessing one member at time:"); 
       
    printf("\nStructure data:"); 
    s.integer = 240; 
    printf("\nInteger: %d", s.integer); 
       
    s.decimal = 120; 
    printf("\nDecimal: %f", s.decimal); 
       
    strcpy(s.name, "C programming"); 
    printf("\nName: %s\n", s.name); 
       
    printf("\nUnion data:"); 
    u.integer = 240; 
    printf("\nInteger: %d", u.integer); 
       
    u.decimal = 120; 
    printf("\nDecimal: %f", u.decimal); 
       
    strcpy(u.name, "C programming"); 
    printf("\nName: %s\n", u.name); 
       
    
    printf("\nAltering a member value:\n"); 
    s.integer = 1218; 
    printf("Structure data:\n Integer: %d\n "
            "Decimal: %.2f\n Name: %s\n", 
            s.integer, s.decimal, s.name); 
       
    u.integer = 1218; 
    printf("Union data:\n Integer: %d\n"
           " Decimal: %.2f\n Name: %s\n", 
            u.integer, u.decimal, u.name);  

    return 0;
}
