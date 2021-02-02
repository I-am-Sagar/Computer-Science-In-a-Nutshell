// This is the enhanced version of last code which calculated "number of 
// characters in given input"

#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    cout << "Enter text for analysis:\n(Use 'Ctrl + D' to stop the input) " << endl;
    
    char ch;
    
    int whitespaces = 0, digits = 0, chars = 0, punct = 0, others = 0;
    
    cin.get(ch);
    
    while (!cin.fail())
    {
        if (isalpha(ch))
            chars++;
        else if (isdigit(ch))
            digits++;
        else if (isspace(ch))
            whitespaces++;
        else if (ispunct(ch))
            punct++;
        else 
            others++;
        
        cin.get(ch);
    }
    
    cout << chars << " letters, "
         << whitespaces << " whitespaces, "
         << digits << " digits, "
         << punct << " punctuations and "
         << others << " other symbols.\n";
    return 0;
}

/* Some other functions belonging to this library:

    a) isblank() returns true if the argument is a space or tab (not including newline and tabs)
    b) isupper() returns true if the argument is a uppercase letter
    c) islower() returns true if the argument is a lowercase letter
    d) tolower() converts the argument in lower case
    e) toupper() converts the argument in upper case
*/
