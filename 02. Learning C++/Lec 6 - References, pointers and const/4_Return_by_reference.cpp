//4. Return by reference

#include <iostream>

using namespace std;

int& max (int& , int& );

int main()
{
    int a , b;
    
    cout << "Enter two integers : ";
    cin >> a >> b;
    
/* There might arise a situation where you want to do some manipulations with 
    the larger integer value, but we don't know whether 'a' gets a value bigger
    than b or vice versa. So we can use a function call as lvalue, if we return 
    by reference. Here the following statement sets the larger value to -1. */
    
    max(a,b) = -1;
    cout << "The larger value will be set to -1: ";
    cout << "a = " << a << ", b = " << b << endl;
    
    return 0;
}

int& max (int &x, int &y)
{
    if (x>y)
        return x;
    else
        return y;
}
