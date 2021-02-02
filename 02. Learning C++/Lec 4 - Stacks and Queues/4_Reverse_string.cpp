#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

int main()
{
    char str[10] = "ABCDEF";
    stack <char> s;
    int i;
    
    for ( i = 0; i < strlen(str); i++)
        s.push(str[i]);
    
    cout << "Reversed string: ";
    
    while (!s.empty())
    {
        cout << s.top();
        s.pop();
    }
    cout << endl;
    
    return 0;
}
