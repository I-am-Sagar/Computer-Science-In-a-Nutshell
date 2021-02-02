#include <iostream>
#include "1_stock01.h"

int main()
{
    using std::cout;
    
    Stock stock1 ("Nanosmart", 12, 20.0);
    stock1.show();
    
    Stock stock2 ("Buff Objects", 2, 2.0);
    stock2.show();
    
    cout << "Assigning stock1 to stock2: \n";
    stock2 = stock1;

    cout << "Showing results: \n";
    stock1.show();
    stock2.show();
    
    cout << "Using a constructor to reset an object: \n";
    stock1 = Stock ("Nifty Foods", 10, 50.0);  //Temp object. TIP1
    cout << "Revised stock1: \n";
    stock1.show();
    cout << "Done\n";

    return 0;
}

/* 
    TIP 1:
    
    The stock1 object already exists.Therefore, instead of initializing stock1, 
    this statement assigns new values to the object. It does so by having the 
    constructor create a new, temporary object and then copying the contents 
    of the new object to stock1.Then the program disposes of the temporary object, 
    invoking the destructor.
*/
