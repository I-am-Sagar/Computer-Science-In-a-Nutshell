#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a1("Hello ");                        //Constructor a
    string a2 = "Hello ";                        //Usual method
    cout << a1 << " " << a2 << endl;            
    
    string b1 (10, '$');                        //Constructor b, no usual method for this
    cout << b1 << endl;
    
    string c1(a1);                              //Constructor c
    string c2 = a2;                              //Usual method
    cout << c1 << " " << c2 << endl;
    
    char* s = "Worldly";
    string d1(s, 5);                        //Constructor d, no usual method
    string d2(s, 10);                        //Constructor d with limit exceeded
    cout << d1 << " " << d2 << endl;
    
    string str = "My name is Anthony.";
    string e1 (str, 5, 10);                        //Constructor e, no usual method
    string e2 (str, 5, 25);                        //Constructor e with limit exceeded
    cout << e1 << " " << e2 << endl;
    
    return 0;
}

/*      LIST OF OVERLOADED CONSTRUCTORS:

    a) string (const char* s)       -> Initializes string object with NBTS(Null Byte Terminated String) pointed to by s
    b) string (size_type n, char c) -> Initializes a string with n elements each being character c
    c) string (const string &s)     -> Initializes a string object to the string object of s (Copy constructor)
    d) string (const char* s, size_type n) -> Initializes a string object pointed to by s and continues for n characters even if
                          it exceeds null character
    e) string (const string &s, size_type pos, size_type n) -> Initializes a string object to string object str, starting at
                        position pos in s going upto end of s or using n characters, whatever comes first
*/
