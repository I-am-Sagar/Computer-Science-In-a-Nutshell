/*
    Harmonic mean of a and b is given by 2ab/(a+b). But if a == -b, we get 
    Divide by zero problem. Modern compilers handle division by zero by 
    generating a special floating-point value that represents infinity; 
    cout displays this value as Inf, inf, INF, or similar.
*/
#include <iostream>
using namespace std;

double hmean(double a, double b);

int main()
{
    double x, y, z;
    cout << "Enter two numbers: ";
    
    while (cin >> x >> y)
    {
        try 
        { 
            z = hmean(x,y); 
        }
        catch (const char * s)
        {
            cout << s << endl;
            cout << "Enter a new pair of numbers: ";
            continue;
        }
        cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
        cout << "Enter next set of numbers <q to quit>: ";
    }
    
    return 0;
}


double hmean(double a, double b)
{
    if (a == -b)
        throw "bad hmean() arguments: a = -b not allowed";
    return 2.0 * a * b / (a + b);
}

/*
    If any statement in try block leads to an exception being thrown, the catch 
    blocks after this block will handle the exception.

    The catch block looks a bit like a function definition, but it’s not. The 
    keyword catch identifies this as a handler, and char * s means that this 
    handler matches a thrown exception that is a string.This declaration of s 
    acts much like a function argument definition in that a matching thrown 
    exception is assigned to s. Also, if an exception does match this handler, 
    the program executes the code within the braces. If a program completes 
    executing statements in a try block without any exceptions being thrown, 
    it skips the catch block or blocks after the try block and goes to the 
    first statement following the handlers.
    
    Let’s trace through the events in the sample run that occur after the 
    values 10 and -10 are passed to the hmean() function. The if test causes 
    hmean() to throw an exception. This terminates execution of hmean(). 
    Searching back, the program determines that hmean() was called from within
    a try block in main(). It then looks for a catch block with a type that 
    matches the exception type. The single catch block present has a char * 
    parameter, so it does match. Detecting the match, the program assigns the 
    string "bad hmean() arguments: a = -b not allowed" to the variable s. 
    Next, the program executes the code in the handler. First, it prints s, 
    which is the caught exception. Then it prints instructions to the user to 
    enter new data. Finally, it executes a continue statement, which causes 
    the program to skip the rest of the while loop and jump to its beginning 
    again.
*/
