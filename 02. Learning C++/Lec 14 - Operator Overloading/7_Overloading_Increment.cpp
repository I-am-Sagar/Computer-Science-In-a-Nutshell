#include <iostream>
using namespace std;

class Time 
{
    private:
        int hours;
        int minutes;
    public:
        Time() { hours = minutes = 0; }
        Time(int h, int m) { hours = h; minutes = m; }
        
        void display();

        Time operator++ ();  //Prefix ++ overloading
        Time operator++ (int); //Postfix ++ overloading
};

void Time::display()
{ cout << hours << " hours, " << minutes << " minutes" << endl; }

Time Time::operator++ ()
{
    ++minutes;
    
    if(minutes >= 60) 
    {
        ++hours;
            minutes -= 60;
      }
      return Time(hours, minutes);
}
    
Time Time::operator++ (int)
{
    minutes++;
    if(minutes >= 60) 
    {
        ++hours;
            minutes -= 60;
      }
      return Time(hours, minutes);
}

int main() 
{
   Time T1(11, 59), T2(10,40);
 
   ++T1;    //Calls overloaded prefix operator                    
   T1.display();       
   ++T1;                   
   T1.display();        
 
   T2++;                //Calls overloaded postfix operator 
   T2.display();         
   T2++;                   
   T2.display();        
   return 0;
}

/*
    Notice that, the dummy int argument is used to distinguish between postfix 
    and prefix. Why does this work?
    
    We know that, prefix is ++variable;  and postfix is  variable++; Now, 
    
        result = variable1 # variable2; 
    
    where # is overloaded operator, is actually 
    
        result = variable1.operator# (variable2);
        
    When we use prefix notation, operator comes first and then comes variable. 
    Now ofcourse we cant write two variables after ++ operator. So when compiler
    encounters prefix notation, it thinks, the call to overloaded operator is 
    over and there is one variable which invoked the call. So now it will search 
    the overloaded function which has one invoker and one operator function
    without any argument.
    
    When we use postfix notation, variable comes first and then comes operator. 
    So when compiler encounters postfix, it sees the invoker and then the 
    operator. The last thing which compiler has read is now not the variable 
    but the operator. So we fool the compiler by providing a dummy argument viz. 
    just a data type with no value nothing. Now imagine if there were some value 
    to the argument int, of course the only way to keep that value in function 
    call would be after operator, as said earlier I cant keep two values after 
    operator. So it calls the operator function with dummy argument. 
    
    In other words you can say, when operator function has some argument, 
    the only call viz. valid is when the compiler has last seen the operator 
    and not the variable. So this eliminates the first function choice of the 
    compiler.  
*/
