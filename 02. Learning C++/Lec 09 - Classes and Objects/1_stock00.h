#ifndef STOCK00_H_
#define STOCK00_H_

#include <string>

class Stock 
{
    private:
        std:: string company;
        long shares;
        double share_value;
        double total_value;
        void set_total() { total_value = shares*share_value; }
    public:
        void acquire (const std:: string & co, long n, double pr);
        void buy (long num, double price);
        void sell (long num, double price);
        void update (double price);
        void show();
};  //note semicolon in end

#endif
