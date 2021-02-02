#include <iostream>
using namespace std;

//First version of template

template <class X>
void function (X a)
{
    cout << "Inside function one: " << a << endl;
}

template <class X, class Y>
void function (X a, Y b)
{
    cout << "Inside function two: " << a << " " << b << endl;
}

int main()
{
    function (10);
    function (10, 3.1415692);
    
    return 0;
}
