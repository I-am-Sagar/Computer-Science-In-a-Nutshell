/*
    In the previous example we threw and caught string. But generally, on 
    exceptions, we throw and catch objects. The reason being, string when 
    caught by catch block is same as it was written if exception occured. 
    But an object when threw by exception, can carry information with it 
    and inside catch block we may get more information about why and how 
    exception occured.
    
    Also in catch block we may keep a number of possible ways to handle 
    different exceptions by using multiple catch statements after a try 
    block and based on the object been thrown, it will get passed to 
    appropiate catch statement. 
*/

#include <iostream>
#include <cmath>
using namespace std;

/* --------------------------- Mean Classes ------------------------ */
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

/* -------------------------- Member Functions ---------------------------- */

inline void bad_hmean::message()
{
    cout << "hmean(" << v1 << ", " << v2 <<"): " << "invalid arguments: a = -b\n";
}

inline const char * bad_gmean::message()
{
    return "gmean() arguments should be >= 0\n";
} 
/* ------------------------- Main Code ------------------------------------- */

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
    return std::sqrt(a * b);
}

int main()
{
    double x, y, z;
    cout << "Enter two numbers: ";

    while (cin >> x >> y)
    {
        try 
        {
            z = hmean(x,y);
            cout << "Harmonic mean of " << x << " and " << y << " is " << z << endl;
            cout << "Geometric mean of " << x << " and " << y << " is " << gmean(x,y) << endl;
            cout << "Enter next set of numbers <q to quit>: ";
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

    return 0;
}

/*
    If exception occured, say in hmean(), values of a and b are passed to 
    constructor of class bad_hmean. This will make a temporary class object 
    of class bad_hmean. This will be passed to try block and then it will search 
    for catch block which can take object of class bad_hmean as parameter. 
    Similarly when gmean will throw bad_gmean as object, catch statement which 
    can take bad_gmean object will be executed.
    
    One point to notice is that the bad_hmean handler uses a continue statement, 
    whereas the bad_gmean handler uses a break statement.Thus, bad input to 
    hmean() leads the program to skip the rest of the loop and start the next 
    loop cycle. But bad input for gmean() terminates the loop.
    This illustrates how a program can determine which exception is thrown 
    (by the exception type) and tailor the response to the exception.

    A second point to notice is that the bad_gmean design illustrates techniques 
    that are different from what bad_hmean uses. In particular, bad_gmean uses 
    public data and a method that returns a C-style string.
*/
