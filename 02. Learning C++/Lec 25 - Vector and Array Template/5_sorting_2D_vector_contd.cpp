/*
    A 2D Vector can also have rows with different number of columns. 
    This property is unlike the 2D Array in which all rows have same number of columns.
*/

// C++ code to demonstrate sorting of 2D vector on basis of no. of columns in ascending order 
#include<iostream> 
#include<vector> 
#include<algorithm> 
using namespace std; 

// Driver function to sort the 2D vector on basis of no. of columns
bool sizecom(const vector<int>& v1, const vector<int>& v2) 
{ 	return v1.size() < v2.size(); 	}		//for descending order just flip the < sign to > 

int main() 
{
    // Initialization of 2D Array 
    vector< vector<int> > vect{{1, 2}, 
                       {3, 4, 5}, 
                       {6}};

    cout << "The Matrix before sorting is:\n"; 
    for (int i=0; i<vect.size(); i++) 
    {  
        //loop till that particular size of that row
        for (int j=0; j<vect[i].size() ;j++)
            cout << vect[i][j] << " "; 
        cout << endl; 
    }
    
    sort(vect.begin(), vect.end(), sizecom); 

    cout << "The Matrix after sorting is:\n"; 
    for (int i=0; i<vect.size(); i++) 
    {  
        for (int j=0; j<vect[i].size() ;j++) 
            cout << vect[i][j] << " "; 
        cout << endl; 
    } 

    return 0; 
} 
