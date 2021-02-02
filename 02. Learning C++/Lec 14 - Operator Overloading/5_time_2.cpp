#include <iostream>
#include "5_time_2.h"

Time :: Time ()
{
    hours = minutes = 0;
}

Time :: Time (int h, int m)
{
    hours = h;
    minutes = m;
}

Time Time :: operator+ (const Time & t) const
{
    Time result;
    result.minutes = minutes + t.minutes;
    result.hours = hours + t.hours + result.minutes/60;
    result.minutes %= 60;
    return result;
}

Time Time :: operator- (const Time & t) const
{
    Time result;
    int tot1, tot2;
    tot1 = t.minutes + 60*t.hours;
    tot2 = minutes + 60*hours;
    result.minutes = (tot2 - tot1) %60;
    result.hours = (tot2 - tot1) / 60;
    return result;
}

Time Time :: operator* (double mult) const
{
    Time result;
    long totalminutes = hours*mult*60 + minutes*mult;
    result.hours = totalminutes/60;
    result.minutes = totalminutes % 60;
    return result;
}

std::ostream & operator<<(std::ostream & os, const Time & t)
{
    os << t.hours << " hours, " << t.minutes << " minutes";
    return os;
}
