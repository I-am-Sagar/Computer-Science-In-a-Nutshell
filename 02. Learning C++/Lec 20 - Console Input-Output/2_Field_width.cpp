/*
    The width() method affects only the next item displayed, and the field width 
    reverts to the default value afterward. 
    
    For example, consider the following statements:
        cout << '#';
        cout.width(12);
        cout << 12 << "#" << 24 << "#\n";

    Because width() is a member function, you have to use an object 
    (cout, in this case) to invoke it. 
    The output statement produces the following display:
    #  12#24#

    The 12 is placed in a field 12 characters wide at the right end of the field. 
    This is called right-justification.
    
    C++ never truncates data, so if you attempt to print a seven-digit value in 
    a field with a width of two, C++ expands the field to fit the data.
    
    The method has these prototypes:
        
        int width();
        int width(int i);
*/

#include <iostream>
using namespace std;

int main()
{
    int w = cout.width(30);
    cout << " Default field width = " << w << " :\n";
    
    cout.width(5);
    cout << "N" << ":";
    
    cout.width(8);
    cout << "N*N" << ":\n";
    
    for (long i = 1; i <= 100; i *= 10)
    {
        cout.width(5);
        cout << i;
        cout.width(8);
        cout << i * i << "\n";
    }
    
    return 0;
}

/*
    w has the value 0. This is because cout.width(30) returns the previous field 
    width, not the width to which it was just set. The fact that w is 0 means 
    that zero is the default field width. Because C++ always expands a field to 
    fit the data, this one size fits all. 
*/
