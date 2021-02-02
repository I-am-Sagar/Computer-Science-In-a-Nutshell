#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int data[] = {32, 71, 56, 12, 28};
    int size = sizeof(data)/sizeof(data[0]);
    
    //replace (base pointer, end pointer, replace what, replace with);
    replace (data, data + size, 28, 98);
    
    for (int i = 0; i < size; i++)
        cout << data[i] << " ";
    cout << endl;
    
    return 0;
}
