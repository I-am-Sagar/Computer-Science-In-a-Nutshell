/*
    size()     		- returns the number of elements in the vector
    max_size() 		- returns the maximum number of elements which could be stored in the vector
    capacity() 		- returns the size of the storage space currently allocated to the vector
    empty()    		- returns whether the vector is empty or not
    resize(n)  		- resizes the vector size to hold n elements
    reserve(n) 		- Requests that the vector capacity be at least enough to contain n elements
    shrink_to_fit()   - Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.
*/

#include <iostream> 
#include <vector> 
using namespace std; 

int main() 
{ 
    vector<int> g1; 

    for (int i = 1; i <= 5; i++) 
        g1.push_back(i); 

    cout << "Size : " << g1.size(); 
    cout << "\nCapacity : " << g1.capacity(); 
    cout << "\nMax_Size : " << g1.max_size(); 

    // resizes the vector size to 4 
    g1.resize(4); 

    // prints the vector size after resize() 
    cout << "\nSize : " << g1.size(); 

    // checks if the vector is empty or not 
    if (g1.empty() == false) 
        cout << "\nVector is not empty"; 
    else
        cout << "\nVector is empty"; 

    // Shrinks the vector 
    g1.shrink_to_fit(); 
    cout << "\nVector elements are: "; 
    for (auto it = g1.begin(); it != g1.end(); it++) 
        cout << *it << " "; 
        
    g1.reserve(25);
    cout << "Size : " << g1.size(); 
    cout << "\nCapacity : " << g1.capacity(); 
    cout << endl;

    return 0; 
} 

