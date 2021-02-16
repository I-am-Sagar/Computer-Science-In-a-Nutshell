#include <iostream>
//EOF is C macro so this should be included to use it
#include <stdio.h>
using namespace std;

int main()
{
    int ch;
    int count = 0;
    
    cout << "Enter characters: \n";
    
    while ((ch = cin.get()) != EOF)
    {
        cout.put(char(ch));
        ++count;
    }
    cout << endl << count << " characters read.\n";
    return 0;
}

/*

The earlier version of cin.get() was like this, 

    char ch;
    cin.get(ch);
    while (!cin.fail())
    {
        cout << ch;
        ++count;
        cin.get(ch);
    }

The another version of cin.get() is like this,

    // for type compatibility with EOF value
    int ch;   
    ch = cin.get();
    // Again 'Ctrl + D' is the same EOF condition
    while (ch != EOF) 
    {
        cout.put(char(ch));
        ++count;
        ch = cin.get();
    }
    
Following are the differences between 2 versions of cin.get() although both do 
same work, but in slightly different manner:

----------------------------------------------------------------------------------
    Property           |  cin.get(ch)                    | ch = cin.get()        |
----------------------------------------------------------------------------------
Method of conveying    | Assign to argument ch           | Use function return   |
input character        |                                 | value to assign to ch |
----------------------------------------------------------------------------------
Function return value  | An object 'cin' of class        | int value             |
for char input         | 'istream' (typecasted to true)  |                       |
----------------------------------------------------------------------------------
Function return value  | An object 'cin' of class        | EOF                   |
at EOF                 | 'istream' (typecasted to false) |                       |
----------------------------------------------------------------------------------

*/
