#include <iostream>
#include "5_time_2.h"
using namespace std;

int main()
{
    Time t1 (3, 25);
    Time t2 (2, 48);
    Time temp;
    
    cout << "t1 = " << t1 << " and t2 = " << t2 << endl;
    cout << "t1 + t2 = " << t1 + t2 << endl;
    cout << "t1 - t2 = " << t1 - t2 << endl;
    
    temp = t1 + t2;
    cout << "2*(t1 + t2) = " << 2*temp << endl;
    
    return 0;
}
