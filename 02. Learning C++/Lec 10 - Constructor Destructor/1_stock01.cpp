#include <iostream>
#include "1_stock01.h"

Stock :: Stock()
{
    std::cout << "Default constructor called.\n";
    company = "no name";
    share_value = 0.0;
    total_value = 0.0;
}

//Overloaded constructor
Stock:: Stock (const std:: string & co, long n, double pr)    
{
    std::cout << "Parametrized constructor called of << " << co << "\n";
    company = co;
    
    if (n < 0)
    {
        std:: cout << "Number of shares cant be negative.\n" << company << " shares set to 0.\n";
        shares = 0;
    }
    else 
        shares = n;
    share_value = pr;
    set_total();
}

Stock :: ~Stock()
{
    std::cout << "Bye! " << company << "\n";
}

void Stock:: buy (long num, double price)
{
    if (num < 0)
         std::cout << "Number if shares cant be negative.\nTransaction is aborted.\n";
     else 
     {
         shares += num;
         share_value = price;
         set_total();
     }
}

void Stock:: sell(long num, double price)
{
    using std::cout;
    if (num < 0)
        cout << "Number of shares sold can't be negative.\nTransaction is aborted.\n";
     else if (num > shares)
         cout << "You cant sell more than you have.\nTransaction is aborted.\n";
     else 
     {
         shares -= num;
         share_value = price;
         set_total();
     }
}

void Stock :: show()
{
    std::cout << "Company: " << company << "\n"
            << "Shares: " << shares << "\n"
            << "Share Price: " << share_value << "\n"
            << "Total Worth: " << total_value << "\n";
}


/*
    Characteristics of Constructors:
    
    a) They should be declared only in public section.
    b) They do not have return types, not even void.
    c) They cannot be inherited, but a derived class can call the base class constructor.
    d) They can have default arguments.
    e) We cannot refer to their address.
    f) They cannot be virtual.
    
    The parameter of a constructor can be of any type except that of the class 
    to which it belongs. 
    
    class A
    {
        public:
            A(A);
    }; is illegal.
    
    However a constructor can accept the reference to its own class as parameter. 
    Thus the statement
    
    class A
    {
        public:
            A(&A);
    }; is valid.

    Such a constructor is called copy-constructor.
    
*/