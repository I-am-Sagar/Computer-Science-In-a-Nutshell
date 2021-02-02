#include <iostream>
#include <typeinfo>
using namespace std;

class myclass1 {  };
class myclass2 {  };

int main()
{
    int i, j;
    int* k;
    float f;
    char c;
    char* p;
    myclass1 ob1;
    myclass2 ob2;
    
    cout << "The type of i is: " << typeid(i).name() << endl; 
    cout << "The type of k is: " << typeid(k).name() << endl;
    cout << "The type of f is: " << typeid(f).name() << endl;
    cout << "The type of c is: " << typeid(c).name() << endl;
    cout << "The type of p is: " << typeid(p).name() << endl;
    
    cout << "The type of ob1 is: " << typeid(ob1).name() << endl;
    cout << "The type of ob2 is: " << typeid(ob2).name() << endl;
    
    if (typeid(i) == typeid(j))
        cout << "i and j are of same types\n";
    
    if (typeid(ob1) == typeid(ob2))
        cout << "ob1 and ob2 are of same type\n";
    else
        cout << "ob1 and ob2 are of different types\n";
    
    return 0;
}
