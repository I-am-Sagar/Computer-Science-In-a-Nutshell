/*  PROBLEM:
    Given k sorted arrays of possibly different sizes,
    merge them and print the sorted output.

    Input: k = 3
      arr[][] = { {1, 3},
                  {2, 4, 6},
                  {0, 9, 10, 11}} ;
    Output: 0 1 2 3 4 6 9 10 11

    SOLUTION:
    A simple solution is to create an output array and and
    one by one copy all arrays to it. Finally, sort the
    output array using. This approach takes O(N*Logn N)
    time where N is count of all elements.

    An efficient solution uses Heap data structure.
    1. Create an output array.
    2. Create a min heap of size k and insert 1st element
       in all the arrays into the heap
    3. Repeat following steps while priority queue is not empty:
        a) Remove minimum element from heap (minimum is always at root)
           and store it in output array.
        b) Insert next element from the array from which the element is
           extracted. If the array doesn’t have any more elements,
           then do nothing.

    Time Complexity: O(N*logk)
*/

#include <bits/stdc++.h>
using namespace std;

// A pair of int and pair. First element is
// element and second pair stores index of 2D array
typedef pair<int, pair<int, int>> ppi;

// Main Logic
vector<int> mergeKArrays (vector<vector<int>> arr) {
    vector <int> output;

    // Create a min heap with k heap nodes. Every
    // heap node has first element of array
    priority_queue <ppi, vector<ppi>, greater<ppi>> pq;
    for (int i = 0; i < arr.size(); i++)
        pq.push({arr[i][0], {i, 0}});

    // Now one by one get the minimum element from min
    // heap and replace it with next element of its array
    while (!pq.empty()) {
        ppi curr = pq.top();
        pq.pop();

        int i = curr.second.first;   // array number
        int j = curr.second.second;   // index in array number

        output.push_back (curr.first);
        // next element belongs to same element as current
        if (j+1 < arr[i].size())
            pq.push({arr[i][j+1], {i, j+1}});
    }
    return output;
}

/* ----------------- MAIN DRIVER CODE ----------------- */
int main() {
    vector<vector<int> > arr{ { 2, 6, 12 },
                              { 1, 9 },
                              { 23, 34, 90, 200 } };

    vector<int> output = mergeKArrays(arr);

    cout << "Merged array is " << endl;
    for (auto x : output)
        cout << x << " ";
    cout << endl;

    return 0;
}