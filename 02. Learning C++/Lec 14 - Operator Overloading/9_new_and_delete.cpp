#include <iostream>
#include <stdlib.h>
using namespace std;

void* operator new (size_t n)
{
    cout << "Overloaded new" << endl;
    void *ptr;
    ptr = malloc (n);   //allocates memory
    return ptr;
}

void operator delete (void* p)
{
    cout << "Overloaded delete" << endl;
    free(p);
}

int main()
{
    int *p = new int;
    *p = 30;
    
    cout << "The value is " << *p << endl;
    delete p;
    
    return 0;
}

/*
    FLOW OF CODE:
    
    We start from main. The first line invokes the new operator function. 
    Here are no classes and hence new operator function is not invoked by 
    any object. Now, new operates here not on a variable but on a data-type. 
    The argument of the new operator function takes size of data_type and 
    stores it in n. 
    
    Remember point #1 - The first argument of overloaded function of new 
    should always be size_t. 
    
    Now the compiler performs the task to convert the data type and send the 
    its size in bytes which gets stored in 'n'. Inside the operator new 
    function, we are dynamically allocating memory (this is what new does) 
    but by C method i.e. using malloc. 
    
    Pointer ptr points to the memory of n bytes now. Since pointer ptr does 
    not know what type of data it is pointing to in n bytes, is it int, or 
    float, or something else, the ptr pointer is declared as void*. Now we have 
    to return this pointer to main so that this memory could be accessed by 
    pointer p in main. Since ptr is declared as void*, return type of new 
    operator function will also be void*. But the pointer ptr is received 
    by pointer p which is declared as int*. Now this conversion is also done 
    by compiler.
    
    The data stored in that memory is now 30. We print the value and then delete. 
    This calls delete operator function. 
    
    Remember point #2 - The only argument which we should pass to overloaded 
    function of delete is void *.
    
    This frees the memory pointed by p, allocated by malloc. Program ends.
*/
