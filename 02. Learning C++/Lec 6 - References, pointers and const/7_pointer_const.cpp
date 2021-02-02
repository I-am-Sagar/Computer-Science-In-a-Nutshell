#include <iostream>
using namespace std;

int main()
{
    int age1 = 39;
    int age2 = 40;
    //pointer pointing to constant data
    const int *pt = &age1; 
    cout << *pt << endl;
    pt = &age2;
    cout << *pt << endl;
    /* So following statements are invalid:
    
    *pt += 1;
    cin >> *pt;
    
    However the above declaration means pointer sees data as constant and 
    we cannot change the value of age using pointer.
    *pt = 40; is an invalid statement but, age = 40; statement is valid 
    because age is not defined as const.
    
    */
    const float g_earth = 9.809;
    const float *pe = &g_earth;  //VALID
    cout << *pe << endl;
    
    const float g_moon = 1.630;
    //float *pm = &g_moon;   INVALID
    
    int price = 32;
    int * const cost = &price;
    // Using cost = &(some other variable) is not valid now 
    
    return 0;
}

/*
    We can use const keyword with pointers in two ways:
        a) Making a pointer point to constant data and prevent that pointer 
           to change the pointed data. In this case pointer may point to some 
           other data later on, but data remains constant.
        b) Making a constant pointer point to data and prevent that pointer 
           pointing to some other data then. In this case data may change, 
           but memory cell to which pointer is pointing remains constant.
           
    The idea of knowing whether a is used or b in declaration, is to put a 
    partition in place of *. If the const keyword is on side of data type, 
    its a pointer pointing to const data. And if the const keyword is on side 
    of variable name (pointer name), the pointer is const.
    
    Suppose you have array of const data:
        const int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
        
    The prohibition against assigning the address to constant array means that 
    you cannot pass that array as argument to function by using a non-constant 
    formal argument.
*/
