/*
    Vectors are dynamic arrays. The size of the array can be changed during run time. 
    Here are 4 ways in which we can define vector:
    
    vector <int> v;			 //creates zero-length integer vector
    vector <int> v(5);		 //creates int vector of 5 elements. Note the use of () and not []
    vector <char> v(5, 'x'); //initializes a 5-element char vector with each element as 'x'
    vector <int> v2(v1);	 //creates a vector v2 from vector v1 i.e. they will be copies of each other
*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //First declaration
    vector <int> g1;
    int i, temp;
    
    //Taking input in vector
    for (i = 0; i < 5; i++)
    {
        cout << "Element #" << i << " ";
        cin >> temp;
        g1.push_back(temp);
    }
    
    //Printing vector contents Method 1 - Using array notation
    for (i = 0; i < g1.size(); ++i)
        cout << g1[i] << " ";
    cout << endl;
    
/* ------------------------------------------------------------------------- */
    //Second declaration
    vector <int> g2(5);
        
    //Overflow doesn't affect here
    for (i = 0; i < 6; i++)
    {
        cout << "Element #" << i << " ";
        cin >> temp;
        g2.push_back(temp);
    }
    
    vector<int> :: const_iterator j;
    //Printing vector contents Method 2 - Using constant iterator, TIP1
    for (j = g2.begin(); j != g2.end(); j++)
        cout << *j << " ";
    cout << endl;
    
    //C++11 gives the 'auto' facility. Printing the contents in reverse manner
    for (auto k = g2.rbegin(); k != g2.rend(); k++)
        cout << *k << " ";				//TIP2
    cout << endl;
    
/* -------------------------------------------------------------------------- */	
    vector <int> g3(6);
    
    //Overflow doesn't affect here
    for (i = 0; i < 6; i++)
    {
        cout << "Element #" << i << " ";
        //This avoids trailing zeros issue
        cin >> g3[i];
    }
    
    for (i = 0; i < g3.size(); ++i)
        cout << g3[i] << " ";
    cout << endl;
    
/* -------------------------------------------------------------------------- */
    //Fourth Declaration
    vector <int> g4(g3);
    
    for (i = 0; i < g4.size(); ++i)
        cout << g4[i] << " ";
    cout << endl;
    
    return 0;
}

/*
    1. Iterators are somewhat like pointers. They help us accessing data stored 
       in template classes like vectors, maps, lists, etc. All containers have 
       some common functions like begin(), end(), size(), etc. The function 
       called begin(), returns an iterator pointing to the beginning of the 
       container. We can access the element by dereferencing (by using *) the 
       iterator just like pointer.
       
       To request an iterator appropriate for a particular STL templated class, 
       we use
       
       std::class_name<template_parameters>::iterator name
       
       where name is the name of the iterator variable you wish to create and 
       the class_name is the name of the STL container you are using, and the 
       template_parameters are the parameters to the template used to declare 
       objects that will work with this iterator.
       
       For instance, if you had an STL vector storing integers, you could create
       an iterator for it as follows:

        std::vector<int> myIntVector;
        std::vector<int>::iterator myIntVectorIterator;

       So we can use iterator as, 
       
           vector<int> myIntVector;
        vector<int>::iterator myIntVectorIterator;

        // Add some elements to myIntVector
        myIntVector.push_back(1);
        myIntVector.push_back(4);
        myIntVector.push_back(8);

        for(myIntVectorIterator = myIntVector.begin(); myIntVectorIterator != myIntVector.end(); myIntVectorIterator++)
        {
                cout<<*myIntVectorIterator<<" ";
                //Should output 1 4 8
        }
    
    2. The reason we get trailing zeros in the output is because, when we created 
       the template of size 5, all of the elements got initialized with '0' and 
       when we pushed back the new elements, they were added above those 5 zeros. 
*/
