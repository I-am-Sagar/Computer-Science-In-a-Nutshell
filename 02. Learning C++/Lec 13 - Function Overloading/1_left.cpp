/*
    Two functions with name 'left' are overloaded. 
    One function gives first 'n' characters of string and 
    the second function gives first 'n' digits of number. 
    
    Writing the integer version of function is difficult because 
    in integer we dont have the benefit of storing each digit in its 
    own array element. 
    
    So we follow this approach:
        1. First count the number of digits by dividing the number each time 
           by 10 till the number becomes zero. Store the ans in digits.
        2. Lets say we want to return first 'n' digits, so we will loop dividing 
           the number by 10 for "digits - n" times.
*/

#include <iostream>
using namespace std;

unsigned long left (unsigned long number, unsigned n);
//For character string, in default, it will give first letter of string
char* left (const char* str, int n = 1);    

int main() 
{
    char* trip = "Paris!!!";
    unsigned long int num = 12345678; 
    
    int i;
    char* temp;
    
    for (i=1; i < 10; i++)
    {
        cout << left(num, i) << endl;
        temp = left (trip, i);
        cout << temp << endl;
    }
    
    return 0;
}

unsigned long left (unsigned long number, unsigned n)
{
    unsigned digits = 1;
    unsigned long temp = number;
    
    if ( n == 0 || number == 0)
        return 0;
    
    while ( temp /= 10)
        digits++;
    
    if (digits > n)
    {
        n = digits - n;
        while (n--)
            number /= 10;
        return number;
    }
    else
        // If n > digits, return whole number
        return number;   
}

char* left (const char* str, int n)
{
    if (n<0)
        n = 0;
    char* p = new char[n+1];
    
    int i;
    for (i = 0; i < n && str[i]; i++)
        p[i] = str[i];   
    
    while (i <= n)
        //set rest of the string as null
        p[i++] = '\0';   
    
    return p;
} 
