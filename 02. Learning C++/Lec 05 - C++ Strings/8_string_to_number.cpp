// In this code, we will use inbuilt string functions to convert strings to 
// numbers and vice-versa.

#include <iostream>
#include <string>
using namespace std;

int main()
{
    cout << "Converting numebers to string:\n";
    
    int num1 = 586;
    float num2 = 65.655;
    double num3 = 3.1415692;
    
    string str1 = to_string(num1);
    string str2 = to_string(num2);
    string str3 = to_string(num3);
    
    cout << "num1 as string becomes " << str1 << endl
         << "num2 as string becomes " << str2 << endl
         << "num3 as string becomes " << str3 << endl;
    
    cout << "\nConverting string to numbers:\n";
    
    string stri = "56";
    string strf = "3.142 sagar";
    string strd = "3.1415926535912019";
    
    //stoi(), stof(), stod() are C++11 functions
    int numi = stoi (stri);     
    float numf = stof (strf);
    double numd = stod (strd);
    
    cout << "stri as number becomes " << numi << endl
         << "strf as number becomes " << numf << endl
         << "strd as number becomes " << numd << endl;
    
    return 0;
}
