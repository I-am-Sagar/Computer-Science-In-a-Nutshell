#include <iostream>
#include <stdlib.h> //library for qsort, C way
#include <algorithm> //library for sort, C++ way
using namespace std;

//Compare function for qsort
int compare1 (const void *a, const void *b) {
    return ( *(int*)a < *(int*)b );
}

//Compare function for sort
bool compare2 (int i, int j) {
    return (i > j);
}

int main()
{
    int data1[] = {32, 71, 12, 45, 26};
    int data2[] = {32, 71, 12, 45, 26};
    
    int size1 = sizeof(data1)/sizeof(data1[0]);
    int size2 = sizeof(data2)/sizeof(data2[0]);
    
    //qsort(base pointer, number of elements, size of data type, comparison function pointer);
    qsort (data1, size1, sizeof(int), compare1); 

    //sort(base pointer, end pointer, function pointer);
    sort (data2, data2 + size2, compare2);
    
    for (int i = 0; i < size1; i++)
        cout << data1[i] << " ";
    cout << endl;
    
    for (int i = 0; i < size2; i++)
        cout << data2[i] << " ";
    cout << endl;

    return 0;
}

/*
    NOTES:
    
    1) We need to provide qsort/sort the comparison function. 
       Because when qsort or sort was made in library, they didn't know what 
       type of data is to be sorted. The reason why compare argument was 
       provided is because, lets say we need to sort array of strings, or array 
       of structs, etc. In this case, relational operators aren't sufficient for 
       comparison. So it is the responsibility of the user to provide this 
       function.
      
    2) There is a convention difference in qsort and sort. See how compare1 for 
       qsort uses less than sign and compare2 for sort uses greater than sign. 
       Both sort in descending order.
       
    3) In sort() if we dont give third parameter i.e. compare parameter which is 
       allowed in C++ because of default parameters in C++, then sort() 
       automatically sorts the array in ascending order.
*/
