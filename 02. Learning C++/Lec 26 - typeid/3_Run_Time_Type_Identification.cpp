#include <iostream>
#include <typeinfo>
using namespace std;

class Mammal
{
    public:
        virtual bool lay_eggs() { return false; }
};

class Cat: public Mammal
{	};

class Platypus: public Mammal
{
    public:
        bool lay_eggs()	{ return true; }
};

class Dog: public Mammal
{	};

//A factory for objects derived from Mammal
Mammal *factory()
{
    switch (rand()%3)
    {
        case 0: return new Dog;
        case 1: return new Cat;
        case 2: return new Platypus;
    }
    return 0;
}

int main()
{
    //Pointer to base class
    Mammal *ptr;
    int i;
    int c = 0, d = 0, p = 0;
    
    //generate and count objects
    for (i = 0; i < 10; i++)
    {
        ptr = factory();
        cout << "Object is " << typeid(*ptr).name();
        cout << endl;
        
        if (typeid(*ptr) == typeid(Dog)) d++;
        if (typeid(*ptr) == typeid(Cat)) c++;
        if (typeid(*ptr) == typeid(Platypus)) p++;
    }
    
    cout << endl;
    cout << "Dogs: " << d << endl
         << "Cats: " << c << endl
         << "Platypus: " << p << endl;
    
    return 0;
}

/*
    The specific type of object created is determined by the outcome of a 
    call to rand(). Since we are generating objects at random, there is no 
    way in advance what type of object will be generated. Since any type of 
    mammal may be generated by call to factory(), the program replies upon 
    typeid to determine which type of object has actually been made.
*/
