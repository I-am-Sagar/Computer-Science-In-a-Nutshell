/*
    Suppose a try block doesn’t contain a direct call to a function that throws 
    an exception but that it calls a function that calls a function that throws 
    an exception. Execution still jumps from the function in which the exception 
    is thrown to the function that contains the try block and handlers. Look at 
    the throw_vs_return.png image in the same folder of this code.
    
    So from the image it is clear that return statement returns control to the 
    block back where the function was called whereas throw will jump directly 
    to try block without stopping in between the functions.
    
    The try block in main() catches both bad_hmean and bad_gmean exceptions, 
    and the try block in means() catches just the bad_hmean exception.
*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

/* ----------------------- Class declarations ------------------------------- */

class bad_hmean
{
    private:
        double v1;
        double v2;
    public:
        bad_hmean(double a = 0, double b = 0) : v1(a), v2(b) {}
        void message();
};

class bad_gmean
{
    public:
        double v1;
        double v2;
        bad_gmean(double a = 0, double b = 0) : v1(a), v2(b) {}
        const char * message();
};

class demo
{
    private:
        string word;
    public:
        demo (const string & str)
        {
            word = str;
            cout << "demo " << word << " created\n";
        }
        ~demo()
        {
            cout << "demo " << word << " destroyed\n";
        }
        void show() const
        {
            cout << "demo " << word << " lives!\n";
        }
};
    
/* ------------------------- Member declarations ---------------------------- */

inline void bad_hmean::message()
{
    cout << "hmean(" << v1 << ", " << v2 <<"): " << "invalid arguments: a = -b\n";
}

inline const char * bad_gmean::message()
{
    return "gmean() arguments should be >= 0\n";
}

/* ----------------------------- Main Code ---------------------------------- */

double hmean(double a, double b)
{
    if (a == -b)
        throw bad_hmean(a,b);
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b)
{
    if (a < 0 || b < 0)
        throw bad_gmean(a,b);
    return sqrt(a * b);
}

double means(double a, double b)
{
    double am, hm, gm;
    
    demo d2("found in means()");
    
    am = (a + b) / 2.0; 
    try
    {
        hm = hmean(a,b);
        gm = gmean(a,b);
    }
    catch (bad_hmean & bg) 
    {
        bg.message();
        cout << "Caught in means()\n";
        throw;
    }
    d2.show();
    return (am + hm + gm) / 3.0;
}

int main()
{

    double x, y, z;
    {
        demo d1("found in block in main()");
        cout << "Enter two numbers (both numbers negative to exit): ";
        while (cin >> x >> y)
        {
            try 
            { 
                z = means(x,y);
                cout << "The mean mean of " << x << " and " << y << " is " << z << endl;
                cout << "Enter next pair: ";
            }
            catch (bad_hmean & bg)
            {
                bg.message();
                cout << "Try again.\n";
                continue;
            }
            catch (bad_gmean & hg)
            {
                cout << hg.message();
                cout << "Values used: " << hg.v1 << ", " << hg.v2 << endl;
                cout << "Sorry, you don't get to play any more.\n";
                break;
            }
        }
        d1.show();
    }

    return 0;
}

/* Consider the following sample run:

        demo found in block in main() created
        Enter two numbers: 6 12
        demo found in means() created
        demo found in means() lives!
        demo found in means() destroyed
        The mean mean of 6 and 12 is 8.49509
        6 -6
        demo found in means() created
        hmean(6, -6): invalid arguments: a = -b
        Caught in means()
        demo found in means() destroyed
        hmean(6, -6): invalid arguments: a = -b
        Try again.
        6 -8
        demo found in means() created
        demo found in means() destroyed
        gmean() arguments should be >= 0
        Values used: 6, -8
        Sorry, you don't get to play any more.
        demo found in block in main() lives!
        demo found in block in main() destroyed
    
    Let’s trace through the course of the sample run shown in the preceding section. 
    First, as the demo constructor announces, an object is created in the block in main(). 
    Next, means() is called, and another demo object is created. The means() 
    function passes the values 6 and 12 on to hmean() and gmean(), and those 
    functions return values to means(), which calculates a result and returns it. 
    Before returning the result, means() invokes d2.show().
    After returning the result, means() terminates, and the destructor for d2 
    is called automatically: 
        demo found in means() lives!
        demo found in means() destroyed
        
    The next input cycle sends the values 6 and -6 to means(), and then means() 
    creates a new demo object and relays the values to hmean(). The hmean() 
    function then throws a bad_hmean exception, which is caught by the catch 
    block in means(), as is shown by the following output:
        hmean(6, -6): invalid arguments: a = -b
        Caught in means()

    The throw statement in this block then terminates means() and sends the 
    exception up to main(). The fact that d2.show() isn’t called demonstrates 
    that the execution of means() is terminated. 
    But note that the destructor for d2 is called:
        demo found in means() destroyed

    This illustrates an extremely important aspect of exceptions: As the program 
    unwinds the stack to reach where an exception is caught, it frees automatic 
    storage class variables on the stack. If a variable happens to be a class 
    object, then the destructor for that object is called. 
    
    Meanwhile, the rethrown exception reaches main(), where the appropriate 
    catch block catches and handles it:
        hmean(6, -6): invalid arguments: a = -b
        Try again.

    Now the third input cycle begins, with 6 and -8 sent on to means(). 
    Once again, means() creates a new demo object. 
    It passes 6 and -8 to hmean(), which processes them without a problem. 
    Then means() passes 6 and -8 to gmean(), which throws a bad_gmean exception. 
    Because means()) doesn’t catch bad_gmean exceptions, the exception is passed 
    on up to main(), and no further code in means() is executed.
    
    However, once again, as the program unwinds the stack, it frees local 
    automatic variables, so the destructor for d2 is called:
        demo found in means() destroyed

    Finally, the bad_gmean handler in main() catches the exception and 
    terminates the loop:
        gmean() arguments should be >= 0
        Values used: 6, -8
        Sorry, you don't get to play any more.

    Then the program terminates normally, displaying a few messages and 
    automatically calling the destructor for d1. If the catch block used, say, 
    exit(EXIT_FAILURE) instead of break, the program would terminate immediately, 
    so you wouldn’t see these messages:
        demo found in main() lives!
        
    However, you would still see this message:
        demo found in main() destroyed.
    Again, the exception mechanism would attend to freeing automatic variables 
    on the function stack.

*/
