#include <iostream>
#include "2_bank.h"
using namespace std;

/* ------------------------------ Saving methods ---------------------------- */
Saving::Saving(const string & s, long an, double bal)
{
    fullName = s;
    acctNum = an;
    balance = bal;
}

void Saving::Deposit(double amt)
{
    if (amt < 0)
        cout << "Negative deposit not allowed; Deposit is cancelled.\n";
    else
        balance += amt;
}

void Saving::Withdraw(double amt)
{
    if (amt < 0)
        cout << "Withdrawal amount must be positive; Withdrawal canceled.\n";
    else if (amt <= balance)
        balance -= amt;
    else
        cout << "Withdrawal amount of $" << amt << " exceeds your balance.\n" << "Withdrawal canceled.\n";
}

double Saving::Balance() const
{ return balance; }

void Saving::ViewAcct() const
{
    cout << "Client: " << fullName << endl;
    cout << "Account Number: " << acctNum << endl;
    cout << "Balance: $" << balance << endl;
}

/* ---------------------------- Overdraft Methods --------------------------- */

Overdraft::Overdraft(const string & s, long an, double bal, double ml, double r) : Saving(s, an, bal)
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

// uses copy constructor provided by compiler
Overdraft::Overdraft(const Saving & ba, double ml, double r) : Saving(ba) 
{
    maxLoan = ml;
    owesBank = 0.0;
    rate = r;
}

// redefine how ViewAcct() works
void Overdraft::ViewAcct() const   
{
    // display base portion. If we dont use scope resolution, it will become recursive call
    Saving::ViewAcct();    
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout << "Loan Rate: " << 100 * rate << "%\n";
}

// redefine how Withdraw() works
void Overdraft::Withdraw(double amt)  
{

    double bal = Balance();
    if (amt <= bal)
        Saving::Withdraw(amt);
    else if ( amt <= bal + maxLoan - owesBank)
    {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;
        Deposit(advance);
        Saving::Withdraw(amt);
    }
    else
    cout << "Credit limit exceeded. Transaction cancelled.\n";
}
/*
    Derived class has not any access to private data members of base class 
    though it is publically derived. So the way to access data for initialization 
    is to use constructors and the way to get the values of the variables, we will 
    use function methods of base class. 
    
    The technique that derived-class constructors use to initialize base-class private 
    data is the member initializer list syntax. The member initializer list syntax 
    passes base-class information to a base-class constructor and then uses the 
    constructor body to initialize the new data items added by the Overdraft class.
*/
