/* If we need to handle C strings in stacks, we need to create stack of char pointers.

INCORRECT METHODS TO DECLARE THE STACK OF POINTERS:

    Stack <char*> str;
       
    a) Lets replaces string p; with char* p; but this approach fails immediately 
       because merely creating a pointer doesn't create space to hold the input 
       strings. The program will compile possibly but will crash when 
       cin >> *p; is tried.
       
    b) If we use X p[40]; then after replacing X with char, we get p of type 
       char* with space 40. But the pop method with array will not work;
       
       template <class Type>
       bool Stack<Type>::pop(Type & item)
       {
        if (top > 0)
        {
            item = items[--top];
            return true;
        }
        else
        return false;
       }
       
       First, the reference variable item has to refer to an lvalue of some sort, 
       not to an array name. 
       Second, the code assumes that you can assign to item. Even if item could 
       refer to an array, you can’t assign to an array name.
       
     c) If we use char * po = new char[40]; This allocates space for input 
        as well as po is a variable and hence compatible with code of pop(). 
        There is only one po variable, and it always points to the same memory 
        location. True, the contents of the memory change each time a new string 
        is read, but every push operation puts exactly the same address onto the 
        stack. 
        
        So when you pop the stack, you always get the same address back, and it 
        always refers to the last string read into memory. In particular, the 
        stack is not storing each new string separately as it comes in, and 
        it serves no useful purpose.
        
        One way to use a stack of pointers is to have the calling program 
        provide an array of pointers, with each pointer pointing to a different 
        string. 
        
        For this code we are using the 'new' header file created with name 
        4_stack_template_2.h
*/

#include <iostream>
#include <cstdlib> //For rand() and srand()
#include <ctime>  //For time()
#include "4_stack_template_2.h"
using namespace std;
const int Num = 10;

int main()
{
    srand (time (0)); //randomize rand
    
    cout << "Enter stacksize: ";
    int stacksize;
    cin >> stacksize;
    
    Stack <const char*> st (stacksize);
    
    const char * in[Num] = {
        " 1: Hank Gilgamesh", " 2: Kiki Ishtar",
        " 3: Betty Rocker", " 4: Ian Flagranti",
        " 5: Wolfgang Kibble", " 6: Portia Koop",
        " 7: Joy Almondo", " 8: Xaverie Paprika",
        " 9: Juan Moore", "10: Misha Mache"
    };

    const char * out[Num];
    
    int processed = 0;
    int nextin = 0;
    
    while (processed < Num)
    {
        if (st.isempty())
            st.push(in[nextin++]);
        else if (st.isfull())
            st.pop(out[processed++]);
        else if (rand() % 2 && nextin < Num) // 50-50 chance
            st.push(in[nextin++]);
        else
            st.pop(out[processed++]);
    }
    for (int i = 0; i < Num; i++)
        cout << out[i] << endl;
        
    return 0;
}
