#ifndef ACCTABC_H_
#define ACCTABC_H_
#include <iostream>
#include <string>

class AcctABC   // Abstract Base Class
{
    private:
        std::string fullName;
        long acctNum;
        double balance;
    protected:
        const std::string & FullName() const {return fullName;}
        long AcctNum() const {return acctNum;}
    public:
        AcctABC(const std::string & s = "Nullbody", long an = -1, double bal = 0.0);
        virtual ~AcctABC() {}
        
        void Deposit(double amt) ;
        double Balance() const {return balance;};
        virtual void Withdraw(double amt) = 0;  // pure virtual function
        virtual void ViewAcct() const = 0;   // pure virtual function
};

class Saving :public AcctABC
{
    public:
        Saving (const std::string & s = "Nullbody", long an = -1, double bal = 0.0) : AcctABC(s, an, bal) { }
        virtual ~Saving() {}

        virtual void Withdraw(double amt);
        virtual void ViewAcct() const;
};

class Overdraft : public AcctABC
{
    private:
        double maxLoan;
        double rate;
        double owesBank;
    public:
        Overdraft(const std::string & s = "Nullbody", long an = -1, double bal = 0.0, double ml = 500, double r = 0.10);
        Overdraft(const Saving & ba, double ml = 500, double r = 0.1);
        virtual void ViewAcct()const;
        virtual void Withdraw(double amt);
        void ResetMax(double m) { maxLoan = m; }
        void ResetRate(double r) { rate = r; };
        void ResetOwes() { owesBank = 0; }
};

#endif
