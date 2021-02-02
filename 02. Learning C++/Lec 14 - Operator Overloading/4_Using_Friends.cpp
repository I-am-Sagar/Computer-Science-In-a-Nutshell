/*
    We discussed earlier that, multiply = 3*object_name; 
    won't call any operator function. The solution to this is to make 
    operator function a non-member function. A non-member function is 
    not invoked by objects. As this non-member function need to access 
    the private data of class objects, we need to declare this function 
    as friend to the class.
*/ 
#include <iostream>
using namespace std;

class Time
{
    private:
        int hours;
        int minutes;
    public:
    Time ()
    {
        hours = minutes = 0;
    }

    Time (int h, int m)
    {
        hours = h;
        minutes = m;
    }

    //Arguments have to be in order in which they will occur in expression
    friend Time operator* (double m, const Time &t); 
    void show ();
};

Time operator* (double m, const Time &t)
{
    Time result;
    long totalminutes = t.hours*m*60 + t.minutes*m;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}

void Time :: show ()
{
    cout << "Hours = " << hours << ", minutes = " << minutes << endl;
}

int main()
{
    Time t1 (2, 30), t2;
    
    cout << "Initial Time: " << endl;
    t1.show();
    
    t2 = 2*t1;
    cout << "Final time: " << endl;
    t2.show();

    return 0;
}

/*
    Till now we have been using show() method to print contents of time. 
    Wouldn't it be great if we could overload '<<' operator, so that the 
    statement cout << object_name; prints out the contents of that object? 
    
    Actually '<<' is a heavily overloaded operator. It was initially a bitwise 
    left shift operator in C. But overloading it, C++ makers made it a output 
    tool. However thats bit difficult and we will understand how to do that in 
    two steps.
    
    STEP 1:
    
    Imagine cout << time_object as a statement where '<<' is operating between 
    two class objects, cout: an object of ostream class and time_object: object 
    of time class. Now if we keep the operator function a member of time class, 
    we need to write the statement as,
    
        time_object << cout; 
    
    However this may be confusing, so we define operator as non-member friend 
    function of Time class. So the function will be,
    
        void operator<< (ostream & os, const Time & t)
        {
            os << t.hours << " hours, " << t.minutes << " minutes";
        }
        
    Note: Here operator function is friend to Time class. But it takes ostream 
    class object as well as time class object as arguments. So it may feel that 
    the function shoule be friend of both. Now if you see in the code, the 
    function accesses the private members of time class only and uses ostream 
    class object as whole. Because of this we need not declare operator function 
    as friend of ostream class and tinker with ostream definition.
    
    STEP 2:
    
    The above code will work well with cout << time_object; but will fail when 
    used with redefined '<<' as given below;
    
        cout << "Trip time: " << time << endl;
    
    To understand this, we need to see how cout works. First the parenthesis 
    is executed. 
        
        (cout << "Trip time: ") << time << endl;
    
    This will invoke the overloaded operator function which returns the ostream 
    class object. Now this object has all properties of cout. So the resulting 
    statement after execution of above parenthesis becomes, 
        
        cout << time << endl;
    
    In this way, we should also return ostream object in our function so that 
    it can work with redefined << as well. Here we return the reference to an 
    ostream object because the program passes the reference to ostream object 
    as argument so we should also return the program the reference of ostream 
    object. 
    
        ostream & operator<< (ostream & os, const Time & t)
        {
            os << t.hours << " hours, " << t.minutes << " minutes";
            return os;
        }
    
THIS OVERLOADING OF << IS IMPLEMENTED IN THE NEXT PROGRAM.

*/
