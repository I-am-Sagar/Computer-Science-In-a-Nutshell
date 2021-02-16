//2. References as function parameters

#include <iostream>

using namespace std;

void swap_c   (int* , int* );
void swap_cpp (int& , int& );

int main()
{
    int a = 10, b = 20;
    
    swap_c (&a, &b);
    cout << "a = " << a << ", b = " << b << endl;
    
    swap_cpp (a, b);
    cout << "a = " << a << ", b = " << b << endl;
    
    return 0;
}

void swap_c (int* p, int* q)
{
    int temp;
    
    temp = *p;
    *p = *q;
    *q = temp;
}

void swap_cpp (int& x, int& y)
{
    int temp;
    
    temp = x;
    x = y;
    y = temp;
}

