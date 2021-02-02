/*
    PROBLEM: Take a sequence of 2n real numbers as input. 
    Design an O(n log n) algorithm that partitions the numbers 
    into n pairs, with the property that the partition minimizes
    the maximum sum of a pair.

    For example, say we are given the numbers (1,3,5,9).
    The possible partitions are ((1,3),(5,9)), ((1,5),(3,9)) and ((1,9),(3,5)). 
    The pair sums for these partitions are (4,14), (6,12), and (10,8). 
    Thus the third partition has 10 as its maximum sum, which is the minimum 
    over the three partitions.

    ALGORITHM:
    1) Sort the set of 2n element (n log n)
    2) Now assign two pointers 
        Start: A[0]
        End:   A[2n-1]
        
        while (start < end)
            pair(start, end)
            start++
            end--
        EndLoop
*/

#include <bits/stdc++.h>
using namespace std;

/* Structure of Pair:

struct Pair {
    int first;
    int second;
}; 

*/

int main() {
    int N; 
    cin >> N;

    int* arr = new int[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    
    sort (arr, arr+N);

    /*  If you want to store pairs - 
        
        Pair* pair_array = new Pair[N/2];
        for (int i = 0; i < N/2; i++) {
            pair_array[i].first = arr[i];
            pair_array[i].second = arr[N-i];
        }
    */

    // Displaying formed Pairs
    for (int i = 0; i < N/2; i++) {
        cout << arr[i] << " " << arr[N-i-1] << endl;
    }
    return 0;
}