#include<iostream> 
#include<vector> 
#include<algorithm>
using namespace std; 

//To sort on basis of column, we need to provide driver function
bool sortcol0 (const vector <int> &v1, const vector <int> &v2)
{	return v1[0] < v2[0];	}			//The number 0 in [] denotes 1st column
 
bool sortcol1 (const vector <int> &v1, const vector <int> &v2)
{	return v1[1] < v2[1];	}			//The number 1 in [] denotes 2nd column

bool sortcol2 (const vector <int> &v1, const vector <int> &v2)
{	return v1[2] < v2[2];	}			//The number 2 in [] denotes 3rd column

int main() 
{ 
    
    vector< vector<int> > vect{{3, 5, 1}, 
                               {4, 8, 6}, 
                               {7, 2, 9}}; 

    for (int i=0; i<vect.size(); i++) 			//Printing 2D vector
    { 
        for (int j=0; j<vect[i].size() ;j++) 
            cout << vect[i][j] << " "; 
        cout << endl; 
    } 
    cout << endl;

    int m = vect.size();						//Number of rows
    int n = vect[0].size();						//Number of columns
    
    sort(vect[0].begin(), vect[0].end()); 		//Sorting first row
    
    cout << "Sorting first row in ascending order:\n"; 
    for (int i=0; i<m; i++) 
    { 
        for (int j=0; j<n ;j++) 
              cout << vect[i][j] << " "; 
          cout << endl; 
    }
    cout << endl;
    
    sort(vect.begin(), vect.end(),sortcol1);	//Sorting will be done on basis of 2nd column
    
    cout << "Sorting second column in ascending order:\n"; 
    for (int i=0; i<m; i++) 
    { 
        for (int j=0; j<n ;j++) 
              cout << vect[i][j] << " "; 
          cout << endl; 
    }
    cout << endl;
    
    sort(vect[2].rbegin(), vect[2].rend());		//Sorting third row in descending order	
    
    cout << "Sorting third row in descending order:\n"; 
    for (int i=0; i<m; i++) 
    { 
        for (int j=0; j<n ;j++) 
              cout << vect[i][j] << " "; 
          cout << endl; 
    }
    cout << endl;
    
    cout << "Sorting third column in descending order:\n"; 
    sort(vect.rbegin(), vect.rend(),sortcol2);	//Sorting 3rd column in descending order
    
    for (int i=0; i<m; i++) 
    { 
        for (int j=0; j<n ;j++) 
              cout << vect[i][j] << " "; 
          cout << endl; 
    }
    cout << endl;
    
    return 0; 
} 

