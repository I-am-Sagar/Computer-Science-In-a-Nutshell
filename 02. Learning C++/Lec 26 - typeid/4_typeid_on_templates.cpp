#include <iostream>
#include <typeinfo>
using namespace std;

template <class T>
class myclass
{	
    private:
        T a;
    public:
        myclass (T i) { a = i; }
};

int main()
{
    myclass<int> obj1(10), obj2(9);
    myclass<double> obj3(7.2);
    
    cout << "Type of obj1 is " << typeid(obj1).name() << endl;
    cout << "Type of obj2 is " << typeid(obj2).name() << endl;
    cout << "Type of obj3 is " << typeid(obj3).name() << endl;
    
    return 0;
}
