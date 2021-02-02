/*  PROBLEM: Given an array of numbers, say arr = {54, 546, 60, 548},
    print the largest number possible number using the array elements.
    For Eg. In this case, output should be - 6054854654.

    Note how sorting alone can't solve this problem as we need 60 before 548. 
    The kind of sorting we need is lexicographic sorting. (Lexicon means Dictionary.
    So we are taking about sorting of numbers from left to right like words.)
    
*/

#include <bits/stdc++.h>
using namespace std;

// Auxiliary Function 
void printArray(int arr[], int n) { 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    cout << endl;
} 

// Comparison function to sort numbers in lexicographic way
bool my_compare (int a, int b) {
    string temp1 = to_string(a).append(to_string(b));
    string temp2 = to_string(b).append(to_string(a));
    
    return (temp1 > temp2);
}

/* ------------------- MAIN DRIVER CODE --------------- */
int main()
{
    int arr[] = {1, 34, 98, 9, 548, 76, 4};
    int number = sizeof(arr)/sizeof(arr[0]);
    
    sort (arr, arr+number, my_compare);
    printArray (arr, number);
    
    return 0;
}
