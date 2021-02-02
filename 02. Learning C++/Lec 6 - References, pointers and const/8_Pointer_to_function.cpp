#include <iostream>
using namespace std;

//Various functions with same prototypes
const double *f1 (const double ar[], int n);
const double *f2 (const double [], int);
const double *f3 (const double* , int);

int main()
{
    double av[] = {1112.3, 1542.6, 2227.9}; 
    
    // Pointer to the function f1
    // Just replace function name with (*pt)
    const double *(*p1) (const double*, int) = f1;
    // C++11 way, auto pointer name = function name. 
    // Compiler get to know about signature automatically
    auto p2 = f2; 
    
    cout << "Using pointers to a function" << endl;
    cout << "Address value: " << endl;
    cout << (*p1)(av,3) << " : " << *(*p1)(av,3) << endl
         << p2(av,3) << " : " << *p2(av, 3) << endl;
         
    // pa is the array of function pointers. 
    // Auto doesn't work with list initialization. 
    // It works only with single value.
    const double *(*pa[3])(const double*, int) = {f1, f2, f3};
    // pb is the pointer to the first element of pa
    auto pb = pa;
    // pre-C++11 version of above definition is: const double *(**pb)(const double*, int) = pa;
    
    cout << "Using the array of function pointers: " << endl;
    cout << "Address value: " << endl;
    for (int i= 0; i < 3; i++)
        cout << pa[i](av,3) << " : " << *pa[i](av,3) << endl;
        
    cout << "Using pointer to a pointer to a function: " << endl;
    cout << "Address value: " << endl;
    for (int i = 0; i < 3; i++)
        cout << pb[i](av,3) << " : " << *pb[i](av,3) << endl;
    
    cout << "Using pointer to array of function pointers: " << endl;
    cout << "Address value: " << endl;
    auto pc = &pa;
    //pre-C++11 version of above definition is: const double *(*(*pc)[3]) (const double*, int) = &pa;
    for (int i = 0; i < 3; i++)
        cout << (*pc)[i](av,3) << " : " << *(*pc)[i](av,3) << endl;
    
    cin.get();
    return 0;
}

const double *f1 (const double *ar, int n)
{
    return ar;
}
const double *f2 (const double *ar, int n)
{
    return ar + 1;
}
const double *f3 (const double *ar, int n)
{
    return ar + 2;
}

/* 
    Return type of function + argument it takes = signature of function.
*/
