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
    
    //*max_element (base pointer, end pointer)
    //*min_element (base pointer, end pointer)
    cout << *max_element (data, data + size) << endl
         << *min_element (data, data + size) << endl;
    
    return 0;
}

