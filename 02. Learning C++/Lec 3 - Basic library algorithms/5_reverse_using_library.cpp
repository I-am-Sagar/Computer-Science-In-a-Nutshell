#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int data[] = {32, 71, 56, 12, 28};
    int size = sizeof(data)/sizeof(data[0]);
    
    for (int i = 0; i < size; i++)
        cout << data[i] << " ";
    cout << endl;
    
    //reverse (base pointer, end pointer);
    reverse (data, data + size);
    
    for (int i = 0; i < size; i++)
        cout << data[i] << " ";
    cout << endl;
    
    return 0;
}

