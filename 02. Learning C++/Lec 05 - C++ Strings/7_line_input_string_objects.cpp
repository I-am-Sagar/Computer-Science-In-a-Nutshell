//2. Line oriented input for string objects
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name, address;
    
    cout << "Enter your name: ";
    getline(cin, name);   
    
    cout << "Enter your address: ";
    getline(cin, address);
    
    cout << "Name: " << name << endl
         << "Address: " << address << endl;
    
    return 0;
}

/* NOTE ON GETLINE():

   There is no dot notation, which indicates that this variant of getline() 
   is not a class member function. 
   
    Following is the prototype declaration of getline() function when used 
    with string objects: 
   
          istream&  getline(istream& is, string& str, char delim);

    Here again the third parameter of char delim is optional. 
    When third argument is missed, the function by default considers 
    '\n' character as the delimitation character. Now lets understand a 
    bit of the working of this getline variant. 
    
    There is a class called 'istream' or input stream defined in the header 
    iostream which works related to the input of data streams (flow of bytes).
    cin is the object of this istream class. When cin is passed by reference as 
    a parameter, there is a copy of cin formed with the name of 'is'.

    Since 'is' is a copy of 'cin', it is able to perform every task that could 
    be performed by cin. So in the function definition, the stream is extracted 
    from 'is', as in main() the streams are extracted using cin. So any 
    statements in function like, 
    
        is >> variable_name; 
     
    becomes a valid statment where variable with variable_name get its data from 
    the input stream is. 
    
    The next parameter is the string object's name. Again a copy of that name 
    as 'str' is made of the original parameter as 'name' or 'address' in this 
    case. So the statement like,
        
        is >> str; 
    
    means that the str string object collects/extracts the string data (data 
    stream) from the input stream is. Since str is the copy of the original 
    parameter in function call, say name was the string object passed, so the 
    data collected in str automatically gets copied into name. 
    
    The return type of the function is the reference of the istream class, 
    which means it returns the object of the class istream by reference, not by 
    value. This allows 'Function chaining'. 
    
    Refer return by reference for further information. 
*/
