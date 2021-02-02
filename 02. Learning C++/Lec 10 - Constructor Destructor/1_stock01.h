#ifndef STOCK01_H_
#define STOCK01_H_

#include <string>

class Stock
{
    private:
        std::string company;
        long shares;
        double share_value;
        double total_value;
        void set_total() { total_value = shares*share_value; }
    public:
        Stock(); //default constructor
        //Same as acquire function but it invokes automatically
        Stock(const std::string & co, long n = 0, double pr = 0.0); 
        ~Stock(); //noisy destructor
        
        void buy (long num, double price);
        void sell (long num, double price);
        void update (double price);
        void show();
};

#endif
