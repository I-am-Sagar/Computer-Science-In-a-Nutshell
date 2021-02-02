//Below program counts the number of characters inserted by the user

#include <iostream>
using namespace std;

int main()
{
    char ch;
    int count = 0;
    
    cout << "Enter characters; enter # to quit: \n";
    cin >> ch;
    //cout << "I am right.\n";
    
    //Here stopping character is known as 'Sentinel character'
    while (ch != '#')
    {
        cout << ch;
        ++count;
        cin >> ch;
    }
    
    cout << endl << count << " characters read.\n";
    return 0;
}

/*
On first this seems counter-intutive to have cout and cin in single while loop. 
This creates an effect that computer will read one character and before reading 
other character it will print the previous character first. However thats not 
the case.

In this when first cin is used the one outside the for loop, it takes the whole 
string and keeps that in buffer. Now it reads character from that buffer one by 
one and puts it on the screen. This fact can be demonstrated by using a cout 
statement just before the while statement. Thus we say, input of cin is buffered 
i.e. characters typed are not sent to the program until user hits enter.

Problem is, while reading char values, just as when reading other data types, 
cin skips over spaces and newline characters. The spaces in the input are not 
echoed. Now what if I have to count the whitespaces as well.... 
cin.get(char) will come to the rescue.
*/
