/* The idea behind not using sentinel character is to use EOF condition instead. 
    What's that now???

    C++ input facilities co-operate with the operating system to detect when 
    input reaches the END OF FILE and return the info back to the program. 
    In many OSes, including Windows, Linux, Unix, Mac...(sab to aa gaya), 
    keyboard inputs can take place of files and files can take place of keyboard 
    inputs.
    
    a) eg. File taking place of Keyboard input
    
    Assume you are working on Windows, and you gotta program called 'program.exe'. 
    You can run this program and give the input ,say the list of integers, from 
    the keyboard. But if you have a list of integers in file 'data.txt', you can 
    give program this data using command prompt with following command 
    (here '<' is called redirection).

    program < data
    
    b) eg. Keyboard input taking place of File
    
    If on command line, I have to stop the file, either I will have to wait for 
    file to execute completely or press 'Ctrl + Z' in case of Windows and 
    'Ctrl + D' in case of Unix, Linux and Mac. This is done because if the file 
    in command line, due to some error, is not able to reach the end, there 
    should be a way to tell the OS that file has ended. This is done by keyboard 
    here.
    
    Now EOF is detected by 2 bits, one is eofbit and other is failbit. 

    eofbit becomes true if end of file has been detected successfully and 
    false otherwise. 

    failbit becomes true if there is failure in EOF due to crashing, force 
    stopping or some other reason.
    
    eofbit is detected by cin.eof() function.
    cin.fail() function returns true when either cin.eof() is true 
    (as return type of these functions is 'bool') or failbit is 1.
    
    So our EOF condition is, while (cin.fail() == false);
*/
#include <iostream>
using namespace std;

int main()
{
    char ch;
    int count = 0;
    
    cout << "Enter characters: \n";
    cin.get(ch);
    
    while (cin.fail() == false)
    {
        cout << ch;
        ++count;
        cin.get(ch);
    }
    cout << endl << count << " characters read.\n";
    return 0;
}

