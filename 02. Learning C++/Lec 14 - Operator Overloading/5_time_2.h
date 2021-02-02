#ifndef TIME2_H_
#define TIME2_H_

class Time
{
    private:
        int hours;
        int minutes;
    public:
        Time();
        Time(int h, int m = 0);
        
        Time operator+(const Time & t) const;
        Time operator-(const Time & t) const;
        Time operator*(double n) const;
        //This will invoke above operator function
        friend Time operator*(double m, const Time & t) { return t * m; }  
        friend std::ostream & operator<<(std::ostream & os, const Time & t);
};

#endif

//The whole header is same with just inclusion of overloading prototype of <<
