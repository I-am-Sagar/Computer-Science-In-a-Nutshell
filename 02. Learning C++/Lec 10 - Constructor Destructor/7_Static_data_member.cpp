/*
    When we declare a member variable with static, you are telling compiler that 
    only one copy of that variable will exist and all the class objects will 
    share that variable. Generally member variable is different for every 
    different object and is accessed as object_name.variable_name, but now all 
    objects will use same variable. 
    
    When you declare a static data member within a class, you are not defining 
    it i.e. you are not allocating storage for it. Instead, you must provide a 
    global definition for it elsewhere, outside the class. This is done by 
    redeclaring the static variable using the scope resolution operator to 
    identify the class to which it belongs. This causes storage for the variable 
    to be allocated.
    
    Remember that class declaration is simply a logical construct that does not 
    have physical reality. What are real, are objects.
*/

#include <iostream>
using namespace std;

class shared 
{ 
    private:
        static int a;
        int b;
    public:
        void set (int i, int j) { a = i;  b = j; }
        void show();
};

// defines a, when not initialized the default value of a is taken as zero
int shared :: a; 

void shared :: show ()
{
    cout << "This is static a: " << a
         << "\nThis is non-static b: " << b << endl;
}

int main()
{
    shared x, y;
    
    x.set (1, 1);
    x.show();
    
    y.set (2, 2);
    y.show();
    
    // Here a has been changed because it is shared between x and y
    x.show(); 
    
    return 0;
}
