#include <iostream>
using namespace std;

class code
{
    int id;
   public:
       code () { }
       code (int a) {id = a;}
       code (code &x)  //Copy constructor
       {
           id = x.id;
           cout << "Copy constructor called" << endl;
       }
       
       void display ()
       {
           cout << id << endl;
       }
};

int main()
{
    code A(100);
    code B(A);  //copy constructor called
    code C = A;  //copy constructor called by overloaded assignment operation
    
    code D;   //D is declared and not defined
    D = A;   //copy constructor not called
    
     A.display();
     B.display();
     C.display();
     D.display();
    
    return 0;
}

/*
    When no copy constructor is provided, or it is not used, 
    compiler provides its own copy constructor.
*/
