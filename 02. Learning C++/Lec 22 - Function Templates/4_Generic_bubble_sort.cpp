#include <iostream>
using namespace std;

template <class X>
//Pointer to array to be sorted, number of items in array
void bubble (X* items, int count)
{
    int a, b;
    X t;
    
    for (a = 1; a < count; a++)
        for (b = count-1; b >= a; b--)
            if (items[b-1] > items [b])
            {
                t = items[b-1];
                items[b-1] = items[b];
                items[b] = t;
            }
}

int main()
{
    int array1[7] = {7, 5, 4, 3, 9, 8, 6};
    double array2[8] = {4.3, 2.5, -0.9, 100.2, 3.0, 88.4, -13.5, 50.0};
    
    int i;
    
    cout << "Unsorted int array: ";
    for (i = 0; i < 7; i++)
        cout << array1[i] << ", " ;
    cout << endl;
    
    cout << "Unsorted double array: ";
    for (i = 0; i < 8; i++)
        cout << array2[i] << ", " ;
    cout << endl;
    
    bubble (array1, 7);
    bubble (array2, 8);
    
    cout << "Sorted int array: ";
    for (i = 0; i < 7; i++)
        cout << array1[i] << ", " ;
    cout << endl;
    
    cout << "Sorted double array: ";
    for (i = 0; i < 8; i++)
        cout << array2[i] << ", " ;
    cout << endl;
    
    return 0;
}
