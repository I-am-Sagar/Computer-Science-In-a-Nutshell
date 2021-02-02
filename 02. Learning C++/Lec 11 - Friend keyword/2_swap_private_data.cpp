#include <iostream>
using namespace std;

// Forward declaration just because we are using class second 
// in class first before defining class second
class second;

class first
{
    int value1;
   public:
       void initialize (int a) { value1 = a; }
       void display() { cout << value1 << "\n"; }
       friend void exchange (first &, second &);
};

class second
{
    int value2;
   public:
       void initialize (int a) { value2 = a; }
       void display() { cout << value2 << "\n"; }
    // friend should be declared in both classes
       friend void exchange (first &, second &); 
};

void exchange (first &x, second &y)
{
    int temp = x.value1;
    x.value1 = y.value2;
    y.value2 = temp;
}

int main()
{
    first c1;
    second c2;
    
    c1.initialize(300);
    c2.initialize(500);
    
    cout << "Before swapping:\nvalue 1 = ";
    c1.display(); 
    cout << "value 2 = ";
    c2.display();
    
    exchange (c1, c2);
    
    cout << "After swapping:\nvalue 1 = ";
    c1.display(); 
    cout << "value 2 = ";
    c2.display();
    
    return 0;
}
