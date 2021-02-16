//5. References with a structure

#include <iostream>
#include <string>

using namespace std;

struct player
{
    string name;
    int attempts;
    int baskets;
    float percent;
};

void display (const player&);
void set_percent (player&);
player& together (player&, const player&);

int main()
{
    //partial initialization of structure - remaining members set to 0
    player one = {"One", 15, 13};
    player two = {"Two", 16, 10};
    player three = {"Three", 9, 7};
    player four = {"Four", 9, 5};
    player five = {"Five", 14, 6};
    
    player team = {"CBA", 0, 0};
    player dup;   // no initialization
    
    set_percent(one);
    display(one);
    together (team, one);
    display(team);
    
    // use return value as argument
    display(together(team, two));
    together (together(team, three), four);
    display(team);
    
    // use return value in assignment
    dup = together (team, five);
    cout << "\nDisplaying team:\n";
    display (team);
    cout << "\nDisplaying dup after assignment: \n";
    display (dup);
    set_percent (four);
    
    // ill-advised assignment
    together (dup, five) = four;
    cout << "\nDisplaying dup after ill-advised assignment: \n";
    display (dup);
    
    return 0;
}

void display (const player &ft)
{
    cout << "Name: " << ft.name << "\n";
    cout << "\tAttempts: " << ft.attempts << "\t";
    cout << "Baskets: " << ft.baskets << "\t";
    cout << "Percentage: " << ft.percent << endl;
}

void set_percent (player &ft)
{
    if (ft.attempts != 0)
        ft.percent = 100.0f* (float)ft.baskets/(float)ft.attempts;
    else
        ft.percent = 0;
}

player& together(player& target, const player& source)
{
    target.attempts += source.attempts;
    target.baskets += source.baskets;
    set_percent(target);
    return target; 
}

/* NOTES ON ABOVE PROGRAM:

   1) The first function call is set_percent(one); 
         The alternative C kind approach is to use pointers.
   
      set_percent(&one);    // Function call
      
      void set_percent (player* ft)
      {
          if( ft-> attempts != 0)
                ft-> percent = 100.0f * (float)ft-> baskets/(float)ft-> attempts;
          else
                ft-> percent = 0;
      }
    
   2) The next function call is display(). Since this function displays the 
      value without altering them, one could have passed this by value, but 
      passing by reference is much more economical in time and memory because 
      there is no copy created.
    
   3) Next function is together() which returns a structure by reference. 
      If the return type were declared player instead of player&, he same return 
      statement i.e. return target; would return a copy of target. But since the 
      return type is a reference, so that means the return value is the original 
      team object first passed to together(). Therefore the net effect of 
      
        display ( together(team, two) );
    
      is the same as that of following:
      
        together(team, two);
        display(team);
     
      Similarly, together ( together(team, three), four);  is same as:
      
        together(team, three);
        together(team, four);
        
   4) Finally there is one ill-suggested assignment, together(dup, five) = four;
   
        together(dup, five);
        dup = four;
    
    
    There are two main reasons for using reference arguments:
    
        1. To allow you to alter a data object in the calling function
        2. To speed up a program by passing a reference instead of an entire 
              data object (more important)
    
    A function uses passed data without modifying it:
    
        1. If the data object is small, such as built in data type or a 
           small structure, PASS IT BY VALUE.
        2. If the data object is array, the only choice we have is, USE A POINTER.
        3. If the data object is good sized structure, USE CONST POINTER or CONST REFERENCE. 
           You save time and space needed to copy a structure or a class design.
        4. If the data object is class object, USE CONST REFERENCE. Thus, the standard way to 
           pass class object arguments by reference.
    
    A function modifies data in the calling function:
    
        1. If the data object is built-in type, USE A POINTER. 
        2. If the data object is an array, the only choice is USE A POINTER.
        3. If the data object is structure, USE REFERENCE OR POINTER.
           4. If the data object is class object, USE A REFERENCE.
    
*/
