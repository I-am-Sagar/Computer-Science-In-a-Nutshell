//1. Allocating memory with new

#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    // C programming way of dynamic memory allocation - also valid in C++
    int *p = (int*)malloc(sizeof(int));
    *p = 5;
    float *q = (float*)malloc(sizeof(float));
    *q = 3.141592;
    
    cout << *p << " " << *q << endl;
    free(p);
    free(q);
    
    //C++ way of Dynamic memory allocation with new and delete
    int *x = new int(5);
    float *y = new float(3.141592);
    //Giving value in the next step
    int* z = new int;  
    *z = 10;
    
    cout << *x << " " << *y << " " << *z << endl;
    delete x;
    delete y; 
    delete z;
    
    //Use of new operator which is a look alike of malloc()
    int *a = (int*) operator new (sizeof(int));
    *a = 5;
    float *b = (float*) operator new (sizeof(float));
    *b = 3.141592;
    
    cout << *a << " " << *b << endl;
    operator delete (a);
    operator delete (b);

    return 0;
}

/* NOTES ON DYNAMIC MEMORY ALLOCATION:

  1. In C, memory is allocated using a function called malloc(). We need to 
     provide the size for allocation as an argument. The return type of the 
     malloc function is void*. To understand why void*, assume if it was int*. 
     
     That means the function would return a pointer pointing to integer. 
     But what if the user wants to allocate a memory for a float, then the 
     return type should be a pointer to a float. Since the data type is 
     unpredictable at first, the return type is POINTER TO AN UNKNOWN DATA TYPE. 
     Hence the void pointer should be appropiately type casted to get perfect 
     pointer. Function free() is used to release the allocated memory.
 
  2. In C++, memory is allocated using a 'new' keyword. Like in C, the memory 
     allocation can be done in two steps as follows:
        
        int *x = new int;    // allocate space for int
        *x = 10;      // store a value there
    
     But unlike C, C++ provides a way to create a space and store a value in 
     one step. Keyword 'delete' frees the allocated space.

  3. There is a major difference between using 'new' and 'malloc lookalike new' 
     and same with the delete. But it is disscussed at a very later stage. 
     That major difference occurs when we try to operate them on classes. 
     As far as built-in types are considered, one can assume both work in a 
     same manner. 
      
  4. One should not free a block of memory that is already been freed. This 
     will cause a run-time error causing the program to stop in between. 
     C++ Standard says the result of such an attempt is undefined i.e. anything 
     erroneous can happen with the program. 
       
        int *x = new int;   // OK
        delete x;    // OK
        delete x;   // Now not OK
        
  5. One should not use delete to free memory, which was created by declaring 
     ordinary variables and not allocated by new. This will again cause 
     run-time error causing the program to stop in between. Again behaviour of 
     this error is also undefined, so consequences could be anything.
  
        int x = 5;   // OK
        int *p = &x;   // OK
        delete p;    // Not OK, memory not allocated by new

*/