/*
    The bank asks us to develop two classes - Saving account and Overdraft 
    account. Saving account is the basic account and Overdraft account is-a 
    Saving account with additional feature viz. if a user writes a cheque 
    larger (but not too large) than his current account balance, the bank 
    will clear the cheque and the extra amount will become the overdraft loan 
    taken by the bearer (the person who payed the cheque and not the one who 
    received). 
    
    So these are the features which Saving account class should have:
    
        Client name;
        Account number;
        Current balance;
    
        Function to create an account;
        Function to deposit money in the account;
        Function to withdraw money from the account;
        Function to display account information;
    
    For overdraft account, bank wants all features of saving account as well 
    as additional items of information:
    
        Upper limit to the Overdraft protection   
        (default value by bank is $500, but it may be different for someone)

        An interest rate charged over overdraft loans 
        (default value by bank is 11.125%, but it may also change)

        The overdraft amount currently owed to bank
    
    No additional functions are required but two functions are needed to be 
    implemented differently:
    
        The withdrawing function has to incorporate overdraft protection 
        for the Overdraft account

        The display function has to show the additional information

    You may call first class as Saving and other class as Overdraft.
    
    You may be thinking that why there isn't a function to pay the Overdraft loan. 
    This is the way how banks work. The account keeps track of how much the 
    customer owes the bank (overdraft loans plus interest).The user cannot pay 
    off this amount through a regular deposit orthrough a transfer from another 
    account. Instead, he or she must pay in cash to a special bank officer, 
    who will, if necessary, seek out the customer. When the debt is paid, the 
    account can reset the amount owed to 0.
    
    The feature is an unusual way for a bank to do business, but it has the 
    fortunate side effect of keeping the programming problem simpler.
*/

#ifndef BANK_H_
#define BANK_H_
#include <string>

class Saving
{
    private:
        std::string fullName;
        long acctNum;
        double balance;
    public:
        Saving (const std::string &s = "Nullbody", long an = -1, double bal = 0.0);
        virtual ~Saving() { }
        
        void Deposit (double amt);
        virtual void Withdraw (double amt);
        double Balance () const;
        virtual void ViewAcct() const;
};

class Overdraft : public Saving
{
    private:
        double maxLoan;
        double rate;
        double owesBank;
    public:
        Overdraft (const std::string & s = "Nullbody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.11125);
        Overdraft (const Saving & ba, double ml = 500, double r = 0.11125);
        
        virtual void ViewAcct()const;
        virtual void Withdraw(double amt);
        void ResetMax(double m) { maxLoan = m; }
        void ResetRate(double r) { rate = r; };
        void ResetOwes() { owesBank = 0; }
};

#endif

/*
    1. Both the classes, declare ViewAcct and Withdraw methods as 'virtual' 
       because they will behave differently in derived class and base class. 
       If we don't use virtual, we can still access the particular method 
       version by determining which object is invoking the function. However 
       problem will come when we will use reference or pointers of the object 
       to invoke the function. Because when 'virtual' is not used, function will 
       be called on the basis of what type of pointer is invoking ViewAcct().
       But when 'virtual' is used, function will be called on basis of what type 
       of object is the pointer pointing to. Here is how program will behave if 
       we dont use virtual. 
       
       //Without declaring methods as virtual
       Saving domnic ("Domnic D'Souza", 11245, 4183.45);
       Overdraft martin ("Martin Luther", 12118, 2529.20);
       
       Saving & acc1 = domnic;
       Saving & acc2 = martin;
       acc1.ViewAcct();   // use Saving::ViewAcct()
       acc2.ViewAcct();   // use Saving::ViewAcct()
       
       //With declaring methods as virtual
       Saving domnic ("Domnic D'Souza", 11245, 4183.45);
       Overdraft martin ("Martin Luther", 12118, 2529.20);
       
       Saving & acc1 = domnic;
       Saving & acc2 = martin;
       acc1.ViewAcct();   // use Saving::ViewAcct()
       acc2.ViewAcct();   // use Overdraft::ViewAcct()
       
       Converting a derived-class reference or pointer to a base-class 
       reference or pointer is called upcasting, and it is always allowed for 
       public inheritance without the need for an explicit type cast. This rule 
       is part of expressing the is-a relationship.
       
       An Overdraft object is a Saving object in that it inherits all the data 
       members and member functions of a Saving object. Therefore, anything that 
       you can do to a Saving object, you can do to a Overdraft object. So a 
       function designed to handle a Saving reference can, without fear of 
       creating problems, perform the same acts on a Overdraft object. The same 
       idea applies if you pass a pointer to an object as a function argument. 
       Upcasting is transitive. That is, if you derive a OverdraftPlus class 
       from Overdraft, then a Saving pointer or reference can refer to a 
       Saving object, a Overdraft object, or a OverdraftPlus object.
       
    2. The fourth point is that the base class declares a virtual destructor.
       This is to make sure that the correct sequence of destructors is called 
       when a derived object is destroyed. To create the derived class, it is 
       necessary first base class should be created. And for destroying derived 
       class, it is necessary first derived class is destroyed and then base 
       class.
       
       The order of constructor destructor is shown in 4_constructor_destructor.cpp
*/
