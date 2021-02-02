#include <iostream>
#include <string>
using namespace std;

string version1 (const string &s1, const string &s2) //OK format
{
    string temp;
    temp = s2 + s1 + s2;
    return temp;
}

const string &version2 (string &s1, const string &s2) // has side effect
{
    s1 = s2 + s1 + s2;
    return s1;
}

/*
const string & version3 (string &s1, const string &s2) //Run time error
{
    string temp;
    temp = s2 + s1 + s2;
    return temp;

}
*/

int main()
{
    string input, copy, result;
    
    cout << "Enter a string: ";
    getline(cin, input);
    copy = input;
    result = version1 (input, "###");
    cout << "Your input string: " << input << endl;
    cout << "Your string enhanced: " << result << endl;
    
    result = version2 (input, "***");
    cout << "Your input string: " << input << endl;
    cout << "Another enhanced way: " << result << endl;
    //We need to reset the input string to copy as string was modified in version2
    input = copy; 
    
    /*
    result = version3 (input, "@@@");
    cout << "Another enhanced way: " << result << endl;
    */
    
    return 0;
}

/* Explanation;

    1. Version 1 is the most straighforward one. We use const which means 
       this function cannot change the value of parameters. Both formal 
       paramters (s1 and s2) are const string & type, but the actual parameters 
       (input and "***") are type of string and const char* respectively. So how 
       is it possible that program accepts passing a pointer to char argument 
       to a string reference?

       String class defines a char*-to-string conversion which makes possible to 
       initialize the string object using C-string.
       
    2. Version 2 doesn't create a temporary string and modifies original one. 
       Because s1 is the reference to object inout, we should return it as 
       reference only. However since s1 is reference to input, changing s1 also 
       changes original input, which is the side-effect.
       
    3. If you want to keep original input as it is, and use temp, we get a 
       run-time error, as we are returning a reference to a variable declared 
       locally inside version 3. This function compiles with a warning, but the 
       program crashes when attempting to execute the function. The program is 
       trying to refer to memory viz. no longer in use.
*/
