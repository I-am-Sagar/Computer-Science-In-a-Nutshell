#include <iostream>
#include <stdlib.h>  //library for bsearch, C way
#include <algorithm> //library for binary_search, C++ way
using namespace std;

//Compare function for bsearch
int compare1 (const void *a, const void *b) 
{
    if ( *(int*)a < *(int*)b ) return  -1;
    if ( *(int*)a == *(int*)b ) return  0;
    if ( *(int*)a > *(int*)b ) return  1;
}

//No need of compare function for binary_search

int main()
{
    int data1[] = {32, 71, 12, 45, 26};
    int data2[] = {32, 71, 12, 45, 26};
    
    int size1 = sizeof(data1)/sizeof(data1[0]);
    int size2 = sizeof(data2)/sizeof(data2[0]);
    
    int key = 12;
    
    
    //bsearch(address of element to be found, base pointer, number of elements, 
    //        size of data type, comparison function pointer);
    sort (data1, data1+size1);
    if ( bsearch(&key, data1, size1, sizeof(int), compare1))
        cout << "Element found!" << endl;
    else
        cout << "Element not found!" << endl; 

    //binary_search (base pointer, end pointer, element to be found)
    sort (data2, data2 + size2);
    if ( binary_search (data2, data2 + size2, key))
        cout << "Element found!" << endl;
    else
        cout << "Element not found!" << endl; 
    
    for (int i = 0; i < size1; i++)
        cout << data1[i] << " ";
    cout << endl;
    
    for (int i = 0; i < size2; i++)
        cout << data2[i] << " ";
    cout << endl;

    return 0;
}
