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

        Time operator-- ();  //Prefix -- overloading
        Time operator-- (int); //Postfix -- overloading
};

void Time::display()
{ cout << hours << " hours, " << minutes << " minutes" << endl; }

Time Time:: operator-- ()
{
    --minutes;
    
    if(minutes < 0) 
    {
        --hours;
            minutes += 60;
      }
      return Time(hours, minutes);
}
    
Time Time::operator-- (int)
{
    minutes--;
    if(minutes < 0) 
    {
        hours--;
            minutes += 60;
      }
      return Time(hours, minutes);
}

int main() 
{
   Time T1(11, 01), T2(10,40);
 
   --T1;    //Calls overloaded prefix operator                    
   T1.display();       
   --T1;                   
   T1.display();        
 
   T2--;                //Calls overloaded postfix operator 
   T2.display();         
   T2--;                   
   T2.display();        
   return 0;
}
