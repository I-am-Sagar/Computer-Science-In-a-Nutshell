#include<iostream> 
using namespace std; 
  
// A function with default arguments, it can be called with  
// 2 arguments or 3 arguments or 4 arguments. 
int sum(int x, int y, int z=0, int w=0) 
{ 
    return (x + y + z + w); 
} 
  

int main() 
{ 
    cout << sum(10, 15) << endl; 
    cout << sum(10, 15, 25) << endl; 
    cout << sum(10, 15, 25, 30) << endl; 
    return 0; 
}

/* IMP POINTS:

    Default arguments are different from constant arguments as constant 
    arguments can’t be changed whereas default arguments can be overwritten 
    if required.
   
    Default arguments are overwritten when calling function provides values 
    for them. For example, calling of function sum(10, 15, 25, 30) 
    overwrites the value of z and w to 25 and 30 respectively.
    
    During calling of function, arguments from calling function to called 
    function are copied from left to right. Therefore, sum(10, 15, 25) will 
    assign 10, 15 and 25 to x, y and z. Therefore, default value is used for w only.
    
    Once default value is used for an argument in function definition, all 
    subsequent arguments to it must have default value. It can also be stated 
    as default arguments are assigned from right to left. For example, the 
    following function definition is invalid as subsequent argument of default 
    variable z is not default.
*/
