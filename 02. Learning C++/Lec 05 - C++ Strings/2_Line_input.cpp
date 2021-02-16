//2. Line oriented input - getline()

#include <iostream>

using namespace std;

int main()
{
    const int arraysize = 20;
    
    char name[arraysize], fruit[arraysize];
    
    cout << "Enter your name: ";
    cin.getline(name, arraysize); 
    
    cout << "Enter your favourite fruit: ";
    cin.getline(fruit, arraysize);
    
    cout << "\nWow " << name << "! Even my favourite fruit is " << fruit << ".\n";
    return 0;
}

/* FEW POINTS ABOUT GETLINE:

The basic syntax of getline function is - 

    a) getline ( char* , stream_size, char delim);
        
        char *      -  It is the name of the target i.e. the array name, 
                       where the input line is to be held.
        stream_size -  It is the limit of the characters to be read. 
                       If this is 20, the function reads no more than 19 characters.
        char delim  -  It is the delimitation character which tells the function 
                       to stop reading further input after reaching this character.
    
One can miss the last argument but the initial two are compulsory. 
If any one the initial two arguments is missed, compiler will give an error

    [Error] no matching function for call to 'std::basic_istream<char>::getline()'
    
    b) getline ( char* , stream_size);
    
If the input of string is more than stream_size, the string will overflow leaving 
its some part in the input queue and again user won't be able to respond to the 
fruit input prompt. 

*/
