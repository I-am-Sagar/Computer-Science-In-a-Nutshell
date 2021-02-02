/*
    The setf() function has two prototypes.The first one is, 
    fmtflags setf (fmtflags);
    Here fmtflags is typedef of bitmask type. The bitmask type is a data type 
    which is used to store individual bit values.
    
    Example: Say in binary, variable1 = 00001, variable2 = 00010, variable5 = 10000, etc. 
    When we pass these constants to setf() function as fmtflag, setf() knows 
    which bit is HIGH and based on it, it will ON or OFF particular formatting 
    characteristic of cout. Then why not passing values like 2, 4, etc. 
    This is because we don't know which bits are supposed to be high and which 
    are suppossed to be low, for a particular characteristic to work. 
    So constant can even be, 01011. 
    
    So the ones who knew the values of these constants and how these affect the 
    output of ostream cout object, defined in the class itself as const.

    --------------------------------------------------------------------------------------------------
    |  Constant            |                Meaning                                                  |
    |-------------------------------------------------------------------------------------------------
    | ios_base::showpoint  | Shows trailing zeros, if exist, upto which precision value is set.      |
    | ios_base::showbase   | Shows 0 prefix to octal numbers and Ox prefix to hexadecimal numbers    |
    | ios_base::uppercase  | Use uppercase letters for hex output and use E for exponential notation | 
    | ios_base::showpos    | Use + before positive numbers                                           |
    --------------------------------------------------------------------------------------------------
    
    The second prototype is  fmtflags setf(fmtflags , fmtflags );
    
    --------------------------------------------------------------------------------------
    | Second Argument         |     First Argument   |      Meaning                      |
    --------------------------------------------------------------------------------------
    |   ios_base::basefield   | ios_base::dec        |  Use base 10.                     |
    |                         | ios_base::oct        |  Use base 8.                      |
    |                         | ios_base::hex        |  Use base 16.                     |
    |                         |                      |                                   |
    |  ios_base::floatfield   | ios_base::fixed      | Use fixed-point notation.         |
    |                         | ios_base::scientific | Use scientific notation.          |
    |                         |                      |                                   |
    |  ios_base::adjustfield  | ios_base::left       | Use left-justification.           |
    |                         | ios_base::right      | Use right-justification.          |
    |                         | ios_base::internal   | Left-justify sign or base prefix, |
    |                         |                      |   and right-justify value.        |
    --------------------------------------------------------------------------------------
*/

#include <iostream>
#include <cmath> 
using namespace std;
int main()
{
    int temperature = 63;
    cout << "Today's water temperature: ";
    
    cout.setf(ios_base::showpos);   // show plus sign
    cout << temperature << endl;

    cout << "For our programming friends, that's\n";
    cout << hex << temperature;   // use hex

    cout.setf(ios_base::uppercase);  // use uppercase in hex
    cout.setf(ios_base::showbase);   // use 0X prefix for hex
    cout << " or " << temperature << endl;
    
    cout.setf(ios_base::left, ios_base::adjustfield); //Left Justification
    cout.precision(3);
    
    cout << "Left Justification:\n"; 
    long n;
    for (n = 1; n <= 41; n+= 10)
    {
        cout.width(4);
        cout << n << "|";
        cout.width(12);
        cout << sqrt(double(n)) << "|\n";
    }
    
    cout.setf(ios_base::internal, ios_base::adjustfield); //Internal Justification
    cout << "Internal Justification:\n";
    for (n = 1; n <= 41; n+= 10)
    {
        cout.width(4);
        cout << n << "|";
        cout.width(12);
        cout << sqrt(double(n)) << "|\n";
    }
    
    cout.setf(ios_base::right, ios_base::adjustfield); //Right Justification
    cout.setf(ios_base::fixed, ios_base::floatfield); 
        
    cout << "Right Justification:\n";
    for (n = 1; n <= 41; n+= 10)
    {
        cout.width(4);
        cout << n << "|";
        cout.width(12);
        cout << sqrt(double(n)) << "|\n";
    }
    
    return 0;
}

/* For input methods of cin, we have already discussed get, getline, 
    EOF condition, etc. in Lecture 21 and 22.*/ 
