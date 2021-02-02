#include<iostream> 
#include<array>
using namespace std; 

int main() 
{ 
    array<int,6> ar = {1, 2, 3, 4, 5, 6}; //Initializing the array class
    array<int,6> ar1 = {7, 8, 9, 10, 11, 12}; 

    cout << "The array elemets are: "; // Printing array elements using at() 
    for ( int i=0; i<6; i++) 
        cout << ar.at(i) << " "; 
    cout << endl;

    cout << "The array elements are: ";  // Printing array elements using operator[] 
    for ( int i=0; i<6; i++) 
        cout << ar[i] << " "; 
    cout << endl;
    
    cout << "First element of array is : " << ar.front() << endl;
    cout << "Last element of array is : " << ar.back() << endl;  	 
    cout << "The number of array elements is : " << ar.size() << endl; 	
    cout << "Maximum elements array can hold is : " << ar.max_size() << endl;
     
    ar.swap(ar1); 
    
    cout << "The first array elements after swapping are : "; 
       for (int i=0; i<6; i++) 
            cout << ar[i] << " "; 
        cout << endl; 
    
        cout << "The second array elements after swapping are : "; 
        for (int i=0; i<6; i++) 
            cout << ar1[i] << " "; 
        cout << endl; 

    ar1.empty() ? cout << "Array empty": cout << "Array not empty"; 
        cout << endl; 	
        
    return 0; 
}

/*
    Advantages of array class over C-style arrays:
    
    a) Array classes knows its own size, whereas C-style arrays lack this property. 
       So when passing to functions, we don’t need to pass size of Array as a separate parameter.
    b) With C-style array there is more risk of array being decayed into a pointer. 
       Array classes don’t decay into pointers
    c) Array classes are generally more efficient, light-weight and reliable than C-style arrays
*/	

