/*
    A static data member exists before any object of the class is created. 
    For example in the following code, a is both - public and static. 
    It shows that a can be accessed from main without creating an object of 
    the class.
    
    Also, static member variables can be used to keep a track of the number 
    of objects of a particular class type that are in existence.
*/

#include <iostream>
using namespace std;

class Counter
{
    public:
        static int a;
        static int count;
        
        Counter() {count++;}
         ~Counter() {count--;}
};

int Counter::a;
int Counter::count;

void test()
{
    Counter temp;
    cout << "Objects in existence: " << Counter::count << "\n";
}

int main()
{
    Counter::a = 100;  //Initializing a before any object is created
    cout << "The initial value of a: " << Counter::a << endl;
    
    Counter x;
    cout << "The value of a after object is created: " << x.a << endl;
    
    cout << "Objects in existence: " << Counter::count << "\n";
    test();
    cout << "Objects in existence: " << Counter::count << "\n";
    
    return 0;
}
