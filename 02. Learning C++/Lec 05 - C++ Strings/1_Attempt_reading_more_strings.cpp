// 1. Attempt to read more than one string

#include <iostream>

using namespace std;

int main()
{
    const int arraysize = 20;
    
    char name[arraysize], fruit[arraysize];
    
    cout << "Enter your name: ";
    cin >> name;
    
    cout << "Enter your favourite fruit: ";
    cin >> fruit;
    
    cout << "\nWow " << name << "! Even my favourite fruit is " << fruit << ".\n";
    return 0;
}

/*  PROBLEM WITH THIS PROGRAM:

If we give name like "Jude Rosario", we did not get a chance to even to respond 
to the desert prompt. Instead an immediate output is seen showing, 
    
    Wow Jude! Even my favourite fruit is Rosario.

The problem lies in how cin determines the user has finished inputting the string. 
Since we cannot put a null character from keyboard, cin assumes termination of 
string input whenever a whitespace is entered. This means cin reads just one 
word when it gets input for a character array.

After it reads this word, cin automatically adds the terminating null character 
when it places the string into the array. Though a null character is automatically 
added once the whitespace is used, the user is allowed to enter data untill he 
presses enter key. This leads name[] reading Jude and leaving the poor Rosario 
still sitting in the input queue which got stored in fruit[]. The cin allows 
user to input data only when input queue is empty or the data is in no way 
compatible with the variable in which it could be stored. 

This is serious issue often when program asks the user to enter a city and the 
user responds with New Delhi, Sao paulo, El Salvador, San Jose, etc.

*/
