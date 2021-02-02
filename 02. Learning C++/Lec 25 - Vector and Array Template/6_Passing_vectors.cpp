#include<iostream> 
#include <vector>
using namespace std; 
 
// The vect here is a copy of vect in main(), PASS BY VALUE
void func1(vector<int> vect)
{	vect.push_back(30); 	} 

// This vect is reference copy of vect in main(), PASS BY REFERENCE
void func2(vector<int> &vect)
{ 	vect.push_back(30); 	} 

int main() 
{ 
    vector<int> vect; 
    vect.push_back(10); 
    vect.push_back(20); 

    func1(vect); 

    // Vect remains unchanged even after function call
    for (int i=0; i<vect.size(); i++) 
        cout << vect[i] << " "; 
    cout << endl;
    
    func2(vect);

    for (int i=0; i<vect.size(); i++) 
        cout << vect[i] << " "; 
    cout << endl;		
    
    return 0; 
} 

/*
    If we do not want a function to modify a vector, we can pass it as a const reference.
    void func(const vector<int> &vect) { ... code ...};
*/ 
