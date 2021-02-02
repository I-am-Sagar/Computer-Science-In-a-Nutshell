/*
    To overload an operator we need to define, a operator function. 
    An operator function has the following form, 
        return-type operator# (argument-list) { definition }  
    Note that there is no space between symbol and keyword operator.
    
    Let's say we make an operator function for '+' to add two classes, 
    say sid and sara. 

    Then following statement,
        sum = sid + sara;
    will be equivalent to, sum = sid.operator+(sara);
    Similarly, sum = sara + sid; will invoke sum = sara.operator+(sid);

    The former one invokes the function and later one acts as argument. 
    
    This works okay until both are of same class. Problem comes when one of 
    the two is constant.
        multiply = sara*2;
    is fine because that's same as, multiply = sara.operator*(2); but the 
    following won't work because 2 cannot invoke a function: 
        multiply = 2*sara;

    We will discuss the solution of this problem later, for now we are just 
    overloading '+' operator to get started. The following code will add two 
    times, 2 hrs 30 min + 2 hrs 40 min = 5 hrs 10 min and not 4 hrs 70 min. 
    Similarly -, *, / and % are also overloaded.
*/

#ifndef TIME1_H_
#define TIME1_H_

class Time
{
    private:
        int hours;
        int minutes;
    public:
        Time();
        Time(int h, int m = 0);
        Time operator+ (const Time & t) const;
        Time operator- (const Time & t) const;
        Time operator* (double n) const;
        Time operator/ (double n) const;
        Time operator% (const Time & t) const;
        void Show() const;
};

#endif
