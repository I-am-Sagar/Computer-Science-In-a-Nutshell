/*
PROBLEM: Ayush loves the characters ‘a’, ‘s’, and ‘p’. He got a string of 
    lowercase letters and he wants to find out how many times characters 
    ‘a’, ‘s’, and ‘p’ occurs in the string respectively. Help him find it out. 

INPUT:
    First line contains an integer denoting length of the string.
    Next line contains the string.

Sample Input:
    6
    aabsas
Sample output:
    3 2 0
*/

#include<bits/stdc++.h>
using namespace std;

void printCharFreq (string str) {
    
    map <char, int> m;
    map <char, int> :: iterator itr;
    
    for (int i = 0; i < str.length(); i++)
        m[str[i]]++;
    
    char character[] = {'a','s','p'};
    bool printed = false;
    
    /* Here 'first' and 'second' are inbuilt variables which are used
    to access the 'key' and 'mapped value' respectively. They are 
    accessed by using arrow operator. */

    for (int i = 0; i < 3; i++) {

        for (itr = m.begin(); itr != m.end(); itr++)
            if (itr -> first == character[i]) {
                cout << itr -> second << " ";
                printed = true;
                break;
            }

        if (!printed)
            cout << 0 << " ";
        
        printed = false;
    }
    
    cout << endl;
}


int main()
{
    int n;
    cin >> n;
    
    string str;
    //getline(cin, str);
    cin >> str;
    printCharFreq (str);
    return 0;
}
