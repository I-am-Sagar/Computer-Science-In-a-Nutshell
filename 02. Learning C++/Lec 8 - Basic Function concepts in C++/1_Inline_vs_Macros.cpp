#include <iostream>
using namespace std;
#define SQUARE(x) x*x
inline int Square(int x) {return x*x;}


int main()
{
    int a = 3, b, c;
    b = SQUARE(a+1);    // Pitfall
    c = SQUARE(++a);    // Pitfall
    
    cout << a << " " << b << " " << c << endl;
    
    a = 3;
    b = Square(a+1);
    c = Square(++a);
    
    cout << a << " " << b << " " << c << endl;
    
    return 0;
}

/*
    Macors and inline both are expanded at the place of the call.
    
    Advantage of Macro:
        - They are faster than inline but may cause error if not used properly
        - Their isnt any type checking so they are general. We can write max, 
          swap, etc. with macros.
        
    Advantages of inline:
        - It has a slightly less but yet a good efficiency
        - Type checking is robust. So to write general functions, we need to 
          use templates (to be studied later).
        - Compiler can report errors if available in inline function as it is 
          available to compiler.
    
    Caution:
        - Inline is just a suggestion to compiler. If the function is large 
          enough then compiler may not expand the code at the call place because 
          that might take more time than actually running the code as function.
        - Inline functions cannot be recursive.
        - Inline functions cannot be overloaded.
*/
