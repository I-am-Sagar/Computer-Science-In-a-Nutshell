// Following function removes elements from array starting from 
// 'start index' to 'end index' and then compacts the array.

#include <iostream>
using namespace std;

template <class X> 
void compact (X* items, int count, int start, int end)
{
    int i;
    
    for (i = end + 1; i < count; i++, start++)
        items[start] = items[i];
    
    while (start < count)
    {
        items[start] = (X) 0;
        start++;
    }
}

int main()
{
    int nums[7] = {0, 1, 2, 3, 4, 5, 6};
    char str[18] = "Generic Functions";
    
    int i;
    
    cout << "Uncompacted array: " ;
    for (i = 0; i < 7; i++)
        cout << nums[i] << " " ;
    cout << endl;
    
    cout << "Uncompacted string: ";
    for (i = 0; i < 18; i++)
        cout << str[i] << " " ;
    cout << endl;
    
    compact (nums, 7, 2, 4);
    compact (str, 18, 6, 10);
    
    cout << "Compacted array: ";
    for (i = 0; i < 7; i++)
        cout << nums[i] << " " ;
    cout << endl;
    
    cout << "Compacted string: ";
    for (i = 0; i < 18; i++)
        cout << str[i] << " " ;
    cout << endl;
    
    return 0;
}
