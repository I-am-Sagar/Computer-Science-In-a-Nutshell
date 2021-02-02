#include <iostream>
#include <cstring>
using namespace std;

//Fill the array of size n bytes with value setval
void* operator new[] (size_t n, char setval) 
{
    void* t = operator new(n);
    memset (t, setval, n);
    return t;
}

void operator delete[] (void *s)
{
    delete (s);
}

int main()
{
    //Allocate array of 10 char elements and fill each element by '#'
    char *t = new ('#') char[10];
    
    cout << "p = " << &t << endl;
    
    for (int i = 0; i < 10; i++)
        cout << t[i];
    cout << endl;
    
    delete [] t;
    
    return 0;
}
