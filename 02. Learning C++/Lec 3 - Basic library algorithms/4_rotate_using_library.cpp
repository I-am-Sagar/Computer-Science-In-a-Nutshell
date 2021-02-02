#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int data[] = {32, 71, 56, 12, 28};
    int size = sizeof(data)/sizeof(data[0]);
    
    //rotate (base pointer, partition pointer, end pointer);
    rotate (data, data + 2, data + 5);
    
    for (int i = 0; i < size; i++)
        cout << data[i] << " ";
    cout << endl;
    
    return 0;
}

/* rotate functions takes data + 2 (partition pointer) to data + 5 (end pointer), 
   and right/circularly rotates the array till data + 2 (partition pointer) comes 
   to the start of the array and becomes first element.
*/
