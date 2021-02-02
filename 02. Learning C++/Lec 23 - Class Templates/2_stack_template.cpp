#include <iostream>
#include <string>
#include <cctype>
#include "1_stack_template.h"
using namespace std;

int main()
{
    Stack <string> st; //creates empty string stack
    char ch;
    
    string purchase_order;
    
    cout << "A. add a purchase order\nB. complete a purchase order\nC. quit\n";
    
    while (cin>>ch && toupper(ch) != 'C')
    {
        while (cin.get() != '\n')
            continue;
        
        if (!isalpha(ch))
        {
            cout << "\a";
            continue;
        }
        
        switch (ch)
        {
            case 'A':
            case 'a':  
                cout << "Enter a purchase order number: ";
                cin>> purchase_order;
                
                if (st.isfull())
                    cout << "Sorry! We have maximum orders now!" << endl;
                else
                    st.push(purchase_order);
                
                break;
                
            case 'B':
            case 'b':
                if (st.isempty())
                    cout << "Sorry! No purchase order to complete" << endl;
                else 
                { st.pop(purchase_order);
                    cout << "PO #" << purchase_order << " completed\n";
                    break;
                }
        }
        cout << "A. add a purchase order\nB. complete a purchase order\nC. quit\n";
    }
    return 0;
} 
