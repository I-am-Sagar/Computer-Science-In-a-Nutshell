#include <iostream>
using namespace std;

// To recieve an address we need pointer 
void array_decay1 (int *p)
{
    cout << "Size of array when passed by pointer: " << sizeof (p) << endl;
}

//To recieve the address of pointer pointing to array, we need pointer which points to array
void array_decay2 (int (*p)[7])
{
    cout << "Size of array when passed by pointer to pointer: " << sizeof (p) << endl;
}
    
void array_decay3 (int *p)
{
    cout << "Size of array when passed by reference: " << sizeof (p) << endl;
}
    
int main()
{
    //Note extra comma at end wont cause any error
    int a[7] = {1, 2, 3, 4, 5, 6, 7, };
    
    cout << "Actual size of array is " << sizeof(a) << endl;
    
    array_decay1 (a);		//a is the address of first element of the array
    array_decay2 (&a);		//&a passes the address of pointer a, which points to first element of the array
    array_decay3 (a);		//Pass by reference	
        
    return 0;
}

/*
    The loss of type and size of array is called array decay. When we pass the 
    array, we actually pass the pointer. The size of pointer is 8 bytes 
    irrespective of what it is pointing in a 64-bit machine. 
    
    Because array has been decayed to a pointer, there is now nothing like array. 
    This pointer will access the memory addresses and give the values even if the 
    array ends. This is the reason we need to provide the size of array in the 
    form of number of elements as a parameter.
*/
