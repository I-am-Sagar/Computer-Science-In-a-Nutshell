#include <iostream>
using namespace std;

template <class X>
void Swap (X &a, X &b)
{
    X temp;
    temp = a; 
    a = b;
    b = temp;
    cout << "Inside template Swap" << endl;
}

// This overrides the generic version of Swap() for ints
void Swap (int &a,int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    cout << "Inside the explicit overloaded function" << endl;
}

int main()
{
    int i = 10, j = 20;
    double x = 10.1, y = 23.3;
    char a = 'x', b = 'y';
    
    cout << "Before Swapping: " << endl
         << i << " " << j << endl
         << x << " " << y << endl
         << a << " " << b << endl;
    
    Swap (i, j);
    Swap (x, y);
    Swap (a, b);
    
    cout << "After Swapping: " << endl
         << i << " " << j << endl
         << x << " " << y << endl
         << a << " " << b << endl;
    
    return 0;
}

/*
So if comes a situation that we want a generic function for ints, floats, doubles, etc. 
but not for char. We want the function for chars to behave differently than 
generic function. So even that is possible by making an Explicit overloading for 
char version. So we can then too go for generics.
    
Suppose we have a template, 

template <class T>
void function (T a, T b)
{	...	}

Now in this template all the general operations are assumed to be true. 

a = b; is assumed to be true but this does not work if a and b are arrays.
a > b; does not work if a and b are arrays, structs, objects, etc. Even if 
       a and b are addresses in case of arrays, it will compare the addresses
       and not the contents. So this is not warned at compile time or 
       even at run-time. 
a*b;   is not valid if a and b are pointers, arrays, structs, objects, etc.

So in such cases we must provide 
"Explicit overloaded/specialized versions of generic function" for 
user-defined and derived datatypes.

*/
