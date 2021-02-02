/*
    Suppose you would like to manage a mixture of Saving and Overdraft accounts. 
    It would be nice if you could have a single array that holds a mixture of 
    Saving and Overdraft objects, but that’s not possible. Every item in an 
    array has to be of the same type. However, you can create an array of 
    pointers-to-Saving. 
    
    In that case, every element is of the same type, but because of the public 
    inheritance model, a pointer-to-Saving can point to either a Saving or a 
    Overdraft object. Thus, in effect, you have a way of representing a 
    collection of more than one type of object with a single array. 
    This is polymorphism.
    
    However the virtual functions reduces compiler speed, execution time, 
    takes more memory as compiler has to maintain list of all virtual methods, 
    etc. So they must be only when in derived class we have to redefine 
    the base class function.
*/

#include <iostream>
#include "2_bank.h"
const int CLIENTS = 3;
using namespace std;

int main()
{
    Saving  s1 ("Magnus Carlsen", 381299, 4000.00);
    Overdraft   o1 ("Vishy Anand", 382288, 3000.00);
    
    s1.ViewAcct();
    cout << endl;
    
    o1.ViewAcct();
    cout << endl;
    cout << "Depositing $1000 into Vishy's Account:\n";
    o1.Deposit(1000.00);
    cout << "New balance: $" << o1.Balance() << endl;
    
    cout << "Withdrawing $4200 from the Magnus' Account:\n";
    s1.Withdraw(4200.00);
    cout << "Magnus' account balance: $" << s1.Balance() << endl << endl;
    
    /* --------------- Demonstrating array of Saving pointers --------------- */
    
    Saving * p_clients[CLIENTS];
    string temp;
    long tempnum;
    double tempbal;
    char kind;
    
    for (int i = 0; i < CLIENTS; i++)
    {
        cout << "Enter client's name: ";
        getline(cin,temp);
        cout << "Enter client's account number: ";
        cin >> tempnum;
        cout << "Enter opening balance: $";
        cin >> tempbal;
        cout << "Enter 1 for Saving Account or 2 for Overdraft Account: ";
        while (cin >> kind && (kind != '1' && kind != '2'))
            cout <<"Enter either 1 or 2: ";
        
        if (kind == '1')
            p_clients[i] = new Saving(temp, tempnum, tempbal);
        else
        {
            double tmax, trate;
            cout << "Enter the overdraft limit: $";
            cin >> tmax;
            cout << "Enter the interest rate as a decimal fraction: ";
            cin >> trate;
            
            p_clients[i] = new Overdraft(temp, tempnum, tempbal, tmax, trate);
        }
        
        while (cin.get() != '\n')
        continue;
    }
    cout << endl;
    
    for (int i = 0; i < CLIENTS; i++)
    {
        p_clients[i]->ViewAcct();
        cout << endl;
    }
    
    for (int i = 0; i < CLIENTS; i++)
    {
        delete p_clients[i]; // free memory
    }
        
    return 0;
}
