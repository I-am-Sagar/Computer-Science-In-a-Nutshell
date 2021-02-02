/*
    1. Like Static data member, Static function members also does not depend 
       on the objects for them to be called. They could be called by using 
       class name and scope resolution operator. Now member function of class 
       can access data members. As class is just a blue print of objects, and 
       not real entity, using static functions to access the members before 
       objects being created would be wrong. So Static member functions of 
       class can only call other static members of class. 
    
    2. Static member function does not have a this pointer.
    
    For example following program fails in compilation with error - 
    'this' is unavailable for static member functions.
    
    #include<iostream> 
    class Test 
    {  
        static Test * fun() 
        { return this; // compiler error} 
    }; 

    int main() 
    { 
        getchar(); 
        return 0; 
    } 
    
    3. Static member function cannot be declared as const.
    
*/

#include<iostream> 
using namespace std; 

class demo 
{  
    private:
        static char* s;     
    public: 
        static void printMsg() 
        {  cout << s << endl;  } 
}; 

char* demo::s  = "Hello World";

int main() 
{ 
    demo::printMsg(); 
} 

