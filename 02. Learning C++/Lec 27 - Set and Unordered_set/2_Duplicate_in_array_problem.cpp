/* We are given an array of size n which contains 0 to n-2 integers.
   This means there will be one element which will be present twice 
   and rest all numbers will be present atleast once. For e.g.,
   
   array[5] = {0, 2, 1, 2, 3} 
   
   You need to print the duplicate number. Assume there will always be an duplicate.

   (In this question, I have used set. You may use unordered_set as well.
   I have used unordered_set in the next problem.)
*/

#include <bits/stdc++.h>
using namespace std;

int duplicate (int arr[], int n) {
    set <int> s;
    set <int> :: iterator itr;

    for (int i = 0; i < n; i++) {
        // This is the condition to find an element in set
        if (s.find(arr[i]) != s.end())
            return arr[i];
        else
            s.insert (arr[i]);
    }

    // If no duplicate is found, return INT_MIN
    return INT_MIN; // But we will never reach this condition as there is always an duplicate
}

int main() {
    int arr[6] = {0 ,3, 2, 4, 1, 2};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << duplicate(arr, size) << endl;
    return 0;
}
