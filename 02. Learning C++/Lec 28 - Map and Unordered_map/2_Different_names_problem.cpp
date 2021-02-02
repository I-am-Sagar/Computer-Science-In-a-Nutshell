/* 

PROBLEM: In Little Flowers Public School, there are many students with same 
    first names. You are given a task to find the students with same names. 
    You will be given a string comprising of all the names of students and you 
    have to tell the name and count of those students having same. 
    
    If all the names are unique, print -1 instead.
    
    Note: We don't have to mention names whose frequency is 1. 

INPUT: The only line of input will have a string ‘str’ with space separated 
first names of students.

TEST CASES:

    Input 1:
        Abhishek harshit Ayush harshit Ayush Iti Deepak Ayush Iti
    Output 1:
        harshit 2
        Ayush 3
        Iti 2
    
    Input 2:
        Abhishek Harshit Ayush Iti
    Output 2:
        -1
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector <string> names;
    string str;
    
    // Once all names are entered, Press Ctrl + Z and then hit enter
    while (cin >> str){
        names.push_back(str);
    }
  
    map <string, int> m;
    map <string, int> :: iterator itr;
    
    for (auto i = names.begin(); i != names.end(); i++)
        m[*i]++;
    
    bool found = false;
    
    for (itr = m.begin(); itr != m.end(); itr++){
        if (itr -> second > 1) {
            cout << (itr -> first) << " " << (itr -> second) << endl;
            found = true;
        }  
    }
    
    if (!found)
        cout << -1 << endl;
    
    return 0;
}