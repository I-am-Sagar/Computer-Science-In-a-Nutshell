/*
    Many exception classes have been made available in C++. The header file 
    exception.h defines an exception class which is used as base class of other 
    exception classes. One virtual member function is named what(), and it 
    returns a string, the nature of which is implementation dependent. 
    However, because this method is virtual, you can redefine it in a 
    class derived from exception:
    
    #include <exception>

    class bad_hmean : public std::exception
    {
        public:
            const char * what() { return "bad arguments to hmean()"; }
            ...
    };

    class bad_gmean : public std::exception
    {
        public:
            const char * what() { return "bad arguments to gmean()"; }
            ...
    };
    
    If you don’t want to handle these derived exceptions differently from one 
    another, you can catch them with the same base-class handler:
    
    try { ... }
    catch(std::exception & e)
    {
        cout << e.what() << endl;
        ...
    }
    
    The current C++ way to handle memory allocation problems with new is to 
    have new throw a bad_alloc exception. The new header includes a declaration 
    for the bad_alloc class which is publically derived from exception class. 
    If the exception is caught, the program displays the implementation-dependent 
    message returned by the inherited what() method and terminates early. 
    In this case, the what() method returns the string 
    "std::bad_alloc" 
*/

#include <iostream>
#include <new>
#include <cstdlib> 
using namespace std;

struct Big
{
    double stuff[20000];
};

int main()
{
    Big * pb;
    try 
    {
        cout << "Trying to get a big block of memory:\n";
        pb = new Big[1000000]; // 160,000,000,000 bytes = 149 GBs
        cout << "Got past the new request:\n";
    }
    catch (bad_alloc & ba)
    {
        cout << "Caught the exception!\n";
        cout << ba.what() << endl;
        exit(EXIT_FAILURE);
    }
    cout << "Memory successfully allocated\n";
    pb[0].stuff[0] = 4;
    cout << pb[0].stuff[0] << endl;
    delete [] pb;
    return 0;
}
