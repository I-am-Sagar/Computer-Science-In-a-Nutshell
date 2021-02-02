#include <iostream>
#include <typeinfo>
using namespace std;

class Mammal
{
    public:
        //Mammal is polymorphic
        virtual bool lay_eggs() {return false;};
};

class Cat : public Mammal 
{	};

class Platypus : public Mammal 
{
    public:
        bool lay_eggs () { return true; };
};


int main()
{
    Mammal *p, AnyMammal;
    
    Cat cat;
    Platypus platypus;
    
    p = &AnyMammal;		//TIP
    cout << "*p is pointing to an object of type " << typeid(*p).name() << endl;
    
    p = &cat;
    cout << "*p is pointing to an object of type " << typeid(*p).name() << endl;
    
    p = &platypus;
    cout << "*p is pointing to an object of type " << typeid(*p).name() << endl;
    
    return 0;
}

/*TIP: 
    p is pointer of type Mammal. We know p can point to all the classes with 
    is-a relationship. 
    Now to what type of class object is p pointing is decided at run-time, 
    because of keyword 'virtual'. 
    If we comment out the keyword 'virtual', 
        
        p is pointing to an object of type class Mammal
        p is pointing to an object of type class Mammal
        p is pointing to an object of type class Mammal
*/
