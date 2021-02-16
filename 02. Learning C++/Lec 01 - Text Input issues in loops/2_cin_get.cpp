#include <iostream>
using namespace std;

int main() {
    char ch;
    int count = 0;
    
    cout << "Enter characters, enter # to quit: \n";
    cin.get(ch);
    
    while (ch != '#') // '#' as sentinel character
    {
        cout << ch;
        ++count;
        cin.get(ch);
    }
    cout << endl << count << " characters read.\n";
    return 0;
}

/*
In C, we used to pass address of variables for input and 
here we are passing the variable. How?

In C++, inside iostream header file, the function cin.get(char &ch) 
receives the variable parameters as references and surely
not by value. We will see more about references in later section.
*/
