#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int data[] = {12, 32, 71, 56, 12, 28, 28, 12};
    int size = sizeof(data)/sizeof(data[0]);
    int key = 12;
    
    for (int i = 0; i < size; i++)
        cout << data[i] << " ";
    cout << endl;
    
    // count (base pointer, end pointer, key) returns the number 
    // of occurences of key in array
    cout << count (data, data + size, key) << endl;
    
    return 0;
}

