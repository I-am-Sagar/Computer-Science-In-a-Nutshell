/*
    By default, cout fills unused parts of a field with spaces.You can use the 
    fill() member function to change that. 
    For example, the following call changes the fill character to an asterisk:
        
        cout.fill('*');
*/

#include <iostream> 
using namespace std;

int main()
{
    cout.fill ('*');
    const char * staff[2] = { "Waldo Whipsnade", "Wilmarie Wooper"};
    long bonus[2] = {900, 1350};
    
    for (int i = 0; i < 2; i++)
    {
        cout << staff[i] << ": $";
        cout.width(7);
        cout << bonus[i] << "\n";
    }
    
    return 0;
}

// Note that, unlike the field width, the new fill character stays in effect 
// until you change it
