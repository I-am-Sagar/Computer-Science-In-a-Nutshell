/*
    We can grant a non-member function access to the private and 
    protected members of a class by using friend. 
*/

#include <iostream>
using namespace std;

class myclass 
{
    private:
        int a, b;
    public:
        myclass ()
        { a = 0; b = 0; }
        
        myclass(int i, int j)
        { a = i; b = j; }
        
        ~myclass () { }
        
        friend int sum (myclass x);
};

int sum (myclass x)
{
    return x.a + x.b;
}

int main()
{ 
    myclass n(3, 4);    //Implicit call
    myclass m = myclass(5, 6);  //Explicit call
    
    cout << sum(n) << endl
         << sum(m) << endl;
    
    return 0;
}

/*
    IMPORTANT CHARACTERISTICS  OF FRIEND:
    
    1. It is not in the scope of the class to which it has been defined. 
       Hence see, we have not used scope resolution operator (::) to define sum. 
       So we cannot call the function using the object of the class but as 
       normal function object.
       
    2. Also because of this it cannot access object members directly, we have 
       to use object.member_name.
    
    3. It can be declared in public or private without affecting its meaning.

    4. Member function of one class can be friend function of another class. 
       In such cases, they are defined using the scope resolution operator as 
       shown:
       
       class X
       {
            .... 
            ....
            int function1 ();
            ....
       };
       
       class Y
       {
            ....
            ....
            friend int X:: function1();
            ....
       };
       
       The function1() is member of class X and friend of class Y.
*/
