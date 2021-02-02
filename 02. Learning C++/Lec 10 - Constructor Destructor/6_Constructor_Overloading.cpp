/*
    The initial value of the objects can be provided at run time. 
    Consider the long term deposit scheme working in commercial banks.
    The banks provide different interest rates for different principal 
    amounts as well as for different periods of investments.
*/

#include <iostream>
using namespace std;

class Fixed_deposit
{
    long int P_amount;
    int Years;
    float Rate;
    float R_value;  //Return value of amount
   public:
       Fixed_deposit() {};
       Fixed_deposit(long int p, int y, float r);
       Fixed_deposit(long int p, int y, int r);
       void display();
};

Fixed_deposit :: Fixed_deposit (long int p, int y, float r = 0.12)
{
    P_amount = p;
    Years = y;
    R_value = P_amount;
    for (int i = 1; i <= y; i++)
        R_value = R_value*(1.0+r);
    
    cout << P_amount << " " << Years << " " << r << endl;
}

Fixed_deposit :: Fixed_deposit (long int p, int y, int r)
{
    P_amount = p;
    Years = y;
    Rate = r;
    R_value = P_amount;
    for (int i = 1; i <= y; i++)
        R_value = R_value*(1.0+float(r)/100);
        
    cout << P_amount << " " << Years << " " << r << endl;
}

void Fixed_deposit :: display (void)
{
    cout << "\n" 
         << "Principal Amount: " << P_amount << endl
         << "Return value: " << R_value << endl;
}

int main()
{
    Fixed_deposit FD1, FD2, FD3;
    long int p;
    int y;
    float r; 
    int R;
    
    cout << "Enter principal amount, period, interest rate on 100: ";
    cin >> p >> y >> R;
    FD1 = Fixed_deposit (p, y, R);
    
    cout << "Enter principal amount, period, interest in decimal: ";
    cin >> p >> y >> r;
    FD2 = Fixed_deposit (p, y, r);
    
    cout << "Enter principal amount and period: ";
    cin >> p >> y;
    FD3 = Fixed_deposit (p, y);
    
    cout << "\n1. Deposit 1: \n";
    FD1.display();
    cout << "\n2. Deposit 2: \n";
    FD2.display();
    
    cout << "\n3. Deposit 3: \n";
    FD3.display();
    
    return 0;
}

/*
    If a class is defined with a destructor without a construtor, 
    the compiler compiles it without the error. For every class, 
    compiler can provide its default constructor and destructor. 
    So if the constructor is missing, it will use its own constructor 
    but destructor which is provided by user will be used.
*/
