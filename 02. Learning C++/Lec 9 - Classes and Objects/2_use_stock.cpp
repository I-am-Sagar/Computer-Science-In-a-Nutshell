#include <iostream>
#include "1_stock00.h"

int main()
{
    Stock fluffy;
    
    fluffy.acquire ("NanoSmart", 20, 12.50);
    fluffy.show();
    fluffy.buy(15, 18.125);
    fluffy.show();
    fluffy.sell(400, 20.00);
    fluffy.show();
    fluffy.buy(30000, 40.125);
    fluffy.show();
    fluffy.sell(20000, 50.000);
    fluffy.show();
    
    return 0;
}

/*
    Compile using command "g++ 1_stock00.cpp 2_usestock.cpp -o 2_usestock"
    
    This compiles both files and make object files of both. Then linker 
    links the object files and makes one executable.
*/
