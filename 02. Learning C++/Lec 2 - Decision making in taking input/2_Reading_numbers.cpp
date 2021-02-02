// Following code calculates the average weight of given fishes

#include <iostream>
using namespace std;
const int Max = 6;

int main()
{
    double fish[Max];
    
    cout << "Please enter the weights of your fish.\n";
    cout << "You may enter up to " << Max
         << " fish <q to terminate>.\n";
    cout << "fish #1: ";
    int i = 0;
    
    while (i < Max && cin >> fish[i])
        if (++i < Max)
            cout << "fish #" << i + 1 << ": ";
    
    double total = 0.0;
    
    for (int j = 0; j < i; j++)
        total += fish[j];
    
    if ( i==0)
        cout << "No fish\n";
    else
        cout << total/i << " = average weight of " << i << " fish.\n";
    
    return 0;
}

/* 
    PROBLEM:
    
    What happens if the user responds by entering a word instead of a number? 
    Followings things will happen:
    
        The mismatched input will be left in the input queue. An error flag is 
        set in the cin object. The call to the cin method, will return false 
        after type conversion of cin.
        
    Another thing to note is, when i < Max condition becomes false, && does not 
    calculate the remaining terms once the fate of the condition is decided. 
    So the rest statements are not executed.

    What to do to solve the problem? Three things...
    
    a) Reset cin to accept the new value
    b) Get rid of the bad input
    c) Prompt the user to try again
    
    These improvements have been done in the next code. 
    (Sorry Mario, code is in another file!!!)
*/
