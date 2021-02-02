// 2. Strings and pointers

#include <iostream>
#include <cstring>
using namespace std;


int main()
{
    char* string = "Sagar";

    //It is a pointer and stores the address of a character
    char* p;
    
    for (int i = 0; i < strlen(string); i++) 
    {
        //p stores the address of each letter as loop runs
        p = &string[i];

        // So this should print address of each letter as loop runs
        // But the output is different
        cout << p << " ";
    }
    cout << endl;
    
    //Correct way to print address of characters of a string
    for (int i = 0; i < strlen(string); i++) 
    {
        p = &string[i];  
        cout << (void*)p << " "; 
    }
    cout << endl;
    
    //Another correct way to print address of characters of a string
    //p now stores the address of 0th element of string
    p = string;    
    for (int i = 0; i < strlen(string); i++) 
    {
        // See how use of printf here becomes more intutive, easier and safer 
        // than typecasting
        printf ("%#x ", p); 
        p++;
    }
    cout << endl;
    
    //Correct way of printing each letter of a string
    for (int i = 0; i < strlen(string); i++) 
    {
        p = &string[i]; 
        //Use 'value-of' operator to tell compiler what you want
        cout << *p << " ";
    }
    cout << endl;
    
    return 0;
}
