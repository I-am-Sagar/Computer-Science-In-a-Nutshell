/* 
PROBLEM:
    Given a random integer array A of size N. Find and print the pair of elements 
    in the array which sum to 0. Array A can contain duplicate elements.

    While printing a pair, print the smaller element first.

    That is, if a valid pair is (6, -6) print "-6 6". 
    There is no constraint that out of 5 pairs which have to be printed in 1st line. 
    You can print pairs in any order, just be careful about the order of elements 
    in a pair. 

INPUT :
    Line 1 : Integer N (Array size)
    Line 2 : Array elements (separated by space)

OUTPUT :
    Line 1 : Pair 1 elements (separated by space)
    Line 2 : Pair 2 elements (separated by space)
    Line 3 : and so on

Sample Input:
    5
    2 1 -2 2 3
Sample Output :
    -2 2
    -2 2
*/

#include <bits/stdc++.h>
using namespace std;

void PairSum(int *arr, int n) {
    
    int sum = 0;
    
    unordered_map<int, int> m;
    
    for (int i = 0; i < n; i++) {
        int rem = sum-arr[i];
        if (m.find(rem) != m.end()) {
            int count = m[rem];
            
            for (int j = 0; j < count; j++) {
                int first, second;
                
                if (rem < arr[i]) {
                    first = rem; 
                    second = arr[i];
                }
                else { 
                    first = arr[i]; 
                    second = rem;
                }
                cout << first << " " << second << endl;
            }
        }
        m[arr[i]]++;
    }
}

int main()
{
    int n;
    int arr [100000];
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    PairSum(arr, n);
    return 0;
}
