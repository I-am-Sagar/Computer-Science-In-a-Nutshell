//lower_bound returns the first element in the range which has a value not less than 'x'
//upper_bound returns the first element in the range which has a value greater than 'x'

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int data[] = {15, 5, 10, 20, 20, 23, 42, 45};
    int size = sizeof(data)/sizeof(data[0]);
    int key = 20;
    
    for (int i = 0; i < size; i++)
        cout << data[i] << " ";
    cout << endl;
    
    sort(data, data + size);
    
    int* p = lower_bound (data, data + size, key);
    int* q = upper_bound (data, data + size, key);
    
    //lower_bound (base pointer, end pointer, key)
    //upper_bound (base pointer, end pointer, key)
    cout << *p << endl
         << *q << endl;
    
    return 0;
}

