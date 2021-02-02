#include <iostream>
#include "3_tv.h"

int main()
{
    using std::cout;

    Tv s1;
    
    cout << "Initial settings for 1\" TV:\n";
    
    s1.settings();
    s1.onoff();
    s1.chanup();
    
    cout << "\nAdjusted settings for 1\" TV:\n";
    s1.settings();

    Remote t;
    t.set_chan(s1, 10);
    t.volup(s1);
    t.volup(s1);

    cout << "\n1\" settings after using remote:\n";
    s1.settings();

    Tv s2(Tv::On);
    s2.set_mode();
    t.set_chan(s2,28);

    cout << "\n2\" settings:\n";
    s2.settings();

    return 0;
}
