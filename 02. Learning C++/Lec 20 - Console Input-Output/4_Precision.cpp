/*
    The precision default for C++, as you’ve seen, is 6. The precision() member 
    function lets you select other values. For example, the following statement 
    causes cout to set the precision to 2: 
    cout.precision(2);
    
    We have seen, numbers like 22.40 will print as 22.4. i.e. the trailing zeros 
    are omitted even if we set precision to 4. And sometimes we need those 
    trailing zeros, eg. price like 24.40 looks better than 24.4. There is not a 
    special function to do that, but we can use setf() function which controls 
    several formatting features. 
    
    Class also defines several constants that can be used as arguments to this 
    function. For example, when the argument constant is ios_base::showpoint, 
    the setf() manipulates cout such that trailing zeros are shown.
*/

#include <iostream>
using namespace std;

int main()
{
    float price1 = 20.40;
    float price2 = 1.9 + 8.0/9.0;
    
    cout << price1 << " " << price2 << endl;
    
    cout.precision(0);
    cout << price1 << " " << price2 << endl;
    
    cout.precision(1);
    cout << price1 << " " << price2 << endl;
    
    cout.precision(2);
    cout << price1 << " " << price2 << endl;
    
    cout.precision(4);
    cout << price1 << " " << price2 << endl;
    
    cout.setf(ios_base::showpoint);
    cout << price1 << " " << price2 << endl;
    
    ios init(NULL);   //Method to reset the cout manipulators to default
        cout.copyfmt(init);
    cout << price1 << " " << price2 << endl;
    
    return 0;
}

