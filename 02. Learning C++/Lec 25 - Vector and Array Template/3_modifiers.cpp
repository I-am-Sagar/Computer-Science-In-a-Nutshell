/*
    assign() 		– It assigns new value to the vector elements by replacing old ones
    push_back() 	– It push the elements into a vector from the back
    pop_back() 		– It is used to pop or remove elements from a vector from the back.
    insert() 		– It inserts new elements before the element at the specified position
    erase() 		– It is used to remove elements from a container from the specified position or range.
    swap() 			– It is used to swap the contents of one vector with another vector of same type and size.
    clear() 		– It is used to remove all the elements of the vector container
    emplace() 		– It extends the container by inserting new element at position
    emplace_back() 	– It is used to insert a new element into the vector container, the new element is added to the end of vector
*/

// C++ program to illustrate the 
// Modifiers in vector 
#include <iostream> 
#include <vector> 
using namespace std; 

int main() 
{ 
    vector<int> v; 

    v.assign(5, 10); 						// fill the array with 10 five times 

    cout << "The vector elements are: "; 
    for (int i = 0; i < v.size(); i++) 
        cout << v[i] << " "; 

    v.push_back(15); 						// inserts 15 to the last position 
    int n = v.size(); 
    cout << "\nThe last element is: " << v[n - 1]; 
 
    v.pop_back();						// removes last element 
    
    cout << "\nThe vector elements are: "; 
    for (int i = 0; i < v.size(); i++) 
        cout << v[i] << " "; 

    v.insert(v.begin(), 5); 				// inserts 5 at the beginning 

    cout << "\nThe first element is: " << v[0]; 

    v.erase(v.begin()); 					// removes the first element 

    cout << "\nThe first element is: " << v[0]; 

    v.emplace(v.begin(), 5); 				// inserts at the beginning 
    cout << "\nThe first element is: " << v[0]; 

    v.emplace_back(20); 					// Inserts 20 at the end 
    n = v.size(); 
    cout << "\nThe last element is: " << v[n - 1]; 

    v.clear(); 							// erases the vector 
    cout << "\nVector size after erase(): " << v.size(); 
 
    vector<int> v1, v2; 					// two vector to perform swap
    v1.push_back(1); 
    v1.push_back(2); 
    v2.push_back(3); 
    v2.push_back(4); 

    cout << "\n\nVector 1: "; 
    for (int i = 0; i < v1.size(); i++) 
        cout << v1[i] << " "; 

    cout << "\nVector 2: "; 
    for (int i = 0; i < v2.size(); i++) 
        cout << v2[i] << " "; 

    v1.swap(v2);						// Swaps v1 and v2  

    cout << "\nAfter Swap \nVector 1: "; 
    for (int i = 0; i < v1.size(); i++) 
        cout << v1[i] << " "; 

    cout << "\nVector 2: "; 
    for (int i = 0; i < v2.size(); i++) 
        cout << v2[i] << " ";
    cout << endl; 
        
    return 0;
} 
