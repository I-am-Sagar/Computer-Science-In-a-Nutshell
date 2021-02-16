//1. Introduction to string class

#include <iostream>
#include <string.h>
#include <string>
using namespace std;

int main()
{ 
    // creating an empty array string
    char str1[20];     
    // creating an empty string object 
    string str2;       
    
    // initializing the array string
    char str3[20] = "Eagle";
    // initializing the string object     
    string str4 = "Frog";
        
    cout << "Enter a terrestial animal: ";
    cin >> str1;
    
    cout << "Enter a aquatic animal: ";
    cin >> str2; 
    
    /* str2 object resizes itself as per the input. 
    One has not to worry about above 20 letter input then.
    This makes string objects safer to use rather than strings 
    as array of characters. */      
    
    cout << "\nHere is the list : \n"
         << "Terrestial animal: " << str1 << endl
         << "Aquatic animal: " << str2 << endl
         << "Volucrine animal: " << str3 << endl
         << "Amphibian animal: " << str4 << endl;
    
    cout << "\nThe third letter of " << str1 << " is " << str1[2] 
         << " and that of " << str2 << " is " << str2[2] << ".\n";
    
    /* We can access a particular letter of string object 
       similar to array notation. */
    
    /* char str5[20]; str5 = str1; This is an invalid statement. 
       We cannot assign one array string to other.
       For this to get done we use, 
           
           strcpy (str5, str1);       // copy str1 to str5
       
       However following statements are valid: */
       
    string str5; 
    str5 = str2;
    
    cout << str5 << " and " << str2 << " are same.\n\n";
    
    /* For concatenation we need to use library functions for C-type strings. 
       In following steps we concatenate c-strings str1 and str3 and store the 
       result in str6. */
    
    char str6[40];
    //First copy the contents of str1 to str6
    strcpy (str6, str1);  
     //Append the contents of str2 to str6 which already contains str1
    strcat (str6, str3); 
    
    cout << str1 << " and " << str3 << " together make " << str6 << ".\n";
    
    /* However, concatenation seems much meaningful and easy when used string objects. */
    
    string str7;
    str7 = str2 + str4;
    
    cout << str2 << " and " << str4 << " together make " << str7 << ".\n";
    
    /* We find the length of C-string and string object in the following way. */
    
    int len1 = strlen (str1);
    int len2 = str2.size();
    
    cout << "\nThe length of " << str1 << " and " << str2 << " is " 
         << len1 << " and " << len2 << " respectively.\n";
    
    return 0;
}
