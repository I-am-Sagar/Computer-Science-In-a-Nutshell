#include <iostream>
#include <stack>
#include <stdlib.h>
using namespace std;

int main()
{
    stack <int> s;
    
    int option, val, topmost, popped, sized;
    
    do 
    {
        cout << "\n1.PUSH\n2.POP\n3.TOP\n4.SIZE\n5.EXIT\n";
        cin >> option;
        
        switch (option)
        {
            case 1:
                cout << "Enter the value to be pushed: ";
                cin >> val;
                s.push(val);
                break;
            
            case 2:
                if (s.empty())
                    cout << "Underflow" << endl;
                else
                {
                    popped = s.top();
                    s.pop();
                    cout << popped << " popped out of stack.\n";
                }
                break;
            
            case 3:
                topmost = s.top();
                cout << topmost << " is top element." << endl;
                break;
                
            case 4:
                sized = s.size();
                cout << "Size of stack is " << sized << endl;
                break;
                
            case 5:
                exit (0);
            
            default:
                cout << "Invalid option.\n";
                
        }
    }
    while (option != 5);
    
    return 0;
}
