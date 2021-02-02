//3. Line oriented input - get()

#include <iostream>

using namespace std;

int main()
{
    const int arraysize = 20;
    
    char name[arraysize], fruit[arraysize];
    
    cout << "Enter your name: ";
    cin.get(name, arraysize).get();
    
    cout << "Enter your favourite fruit: ";
    cin.get(fruit, arraysize).get();
    
    cout << "Wow " << name << "! Even my favourite fruit is " << fruit << ".\n";
    return 0;
}

/* NOTES ON GET FUNCTION:

    There are many variants of get(), of which one used is similar to getline(). 
    Here get() function differs from getline() function in following way:
       
    getline() reads to the end of the line, reads the new line character, 
    terminates the string and discard that newline character and leaves the 
    input queue after clearing it. 
       
    get() reads the new line character, reads the new line character, 
    terminates the string but leaves that newline character as it is in input 
    queue without discarding it.
    
    So when we have a function call like this,
    
        cin.get(name, arraysize);
        cin.get(fruit, arraysize); // a problem
    
    Because the first call leaves the newline character in the input queue, 
    that newline character is the first character the second call sees.
    Thus, get() concludes that it's reached the end of line without having found 
    anything to read.
    
    Fortunately there is one get() function variant which has no arguments. 
    It reads the single next character and so it can be used to dispose of 
    the newline character. So the sequence becomes,
    
        cin.get(name, arraysize);
        cin.get();
        cin.get(fruit, arraysize);
    
    A better way is to concatenate (join) the two class member functions as,
    
        cin.get(name, arraysize).get();
    
    Now lets understand why is above statement possible?
    
    -> First cin.get(name, arraysize) is invoked. It does its job. 
       Now every function has a return type unless its return type is void. 
       The function cin.get(name, arraysize) returns the cin object, which is 
       then used to invoke the get() function. 
       Thus above statement is equivalent to making two separate calls to cin.get(). 
       Because of this even the following statement is also possible, 
    
        cin.getline(name, arraysize).getline(fruit, arraysize);
        
    The reason there exists two such functions to read line is because get() was 
    introduced earlier in older implementations and later a little simpler version 
    called getline() was introduced. However since get() provides many variants 
    as compared to getline(), its use never ceased. 

*/
