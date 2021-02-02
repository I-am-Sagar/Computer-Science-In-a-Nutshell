//1. Reference variables

#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    // b is the reference of a now. Statement int& b = a; is also valid
    int &b = a;   
    // making a reference variable 'c' of a reference variable 'b'
    int& c = b;   
    
    // a, b and c have same memory (data as well as location).
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
    cout << "&a = " << &a << ", &b = " << &b << ", &c = " << &c << endl;
    
    // Changing a produces change in b and c
    a++;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
    
    // Changing b produces change in a and c
    b++;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
    
    // Changing c produces change in a and b
    c++;
    cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
    
    return 0;
}

/* NOTES ON REFERENCE VARIABLE:

    1) Reference variables must be initialized when they are declared. 
        This means following statements are invalid: 
    
        int &b; b = a;       OR   int &b;   &b = a;     // invalid
    
    2) Reference variables cannot be initialized with constants. 
        Because if the following statement, 
       
        int &i = 5;          // invalid
        
       is allowed, then we know i store a constant 5, then the subsequent 
       statement like 
        
        i = 10; 
     
       would mean that we are trying to allocate the value 10 to a constant 
       value 5, which is absurd. So initializing reference variables with 
       constants is not allowed. However if we make a restriction to i that 
       after initializing it with constant no attempt will be made to change 
       its value, then the statement is not erroneous. So the following 
       statement is valid: 
       
        const int &i = 5;    // valid
    
    3) Reference variables cannot be initialized with expressions. 
        Because the expressions evaluate to a constant result. 
    
        int &i  =  j + k;      // invalid
        const int &i = j + k;  // valid
    
    4) The following reference is allowed:
        
        int x;         // uninitialized variable
        int *p = &x;   // pointer pointing to integer x
        int &m = *p;
        
       The above set of declarations causes m to refer to x which is pointed 
       to by the pointer p.
    
*/
