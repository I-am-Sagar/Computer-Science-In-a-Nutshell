/*  PROBLEM:
    Given an array of n numbers and a positive integer k.
    The problem is to find k numbers with most occurrences,
    i.e., the top k numbers having the maximum frequency.
    If two numbers have same frequency then the larger number
    should be given preference. The numbers should be displayed
    in decreasing order of their frequencies. It is assumed that
    the array consists of k numbers with most occurrences.

    SOLUTION:

    Method 1: Use Hashing
    Using hash table, we create a frequency table which stores
    the frequency of occurrence of each number in the given array.
    In the hash table we define (x, y) tuple, where x is the
    key (number) and y is its frequency in the array. Now we
    traverse this hash table and create an array freq_arr[] which
    stores these (number, frequency) tuples. Sort this freq_arr[]
    on the basis of the conditions defined in the problem statement.
    Now, print the first k numbers of this freq_arr[].

    Time Complexity: O(d*logd) and Space Complexity: O(d) where
    d is the number of distinct elements.

    Method 2: Use Heap
    We create a frequency table which stores the frequency of occurrence
    of each number in the given array. In the hash table we define (x, y) tuple,
    where x is the key (number) and y is its frequency in the array.
    Now we traverse this hash table and create an array freq_arr[] which stores
    these (number, frequency) tuples. Sort this freq_arr[] on the basis of the
    conditions defined in the problem statement. Now, print the first k numbers
    of this freq_arr[].

    Time Complexity: O(k*logd) and Space Complexity: O(d) where
    d is the number of distinct elements.

    Both the methods have been implemented below.
*/

#include <bits/stdc++.h>
using namespace std;

// Comparison function to sort the freq_arr[]
bool compare1 (pair<int, int> p1, pair<int, int> p2) {
    // If frequencies are same, higher number gets precedence
    if (p1.second == p2.second)
        return p1.first > p2.first;
    // Sort on the basis of decreasing order of frequencies
    return (p1.second > p2.second);
}

struct compare2 {
    bool operator() (pair<int, int> p1, pair<int, int> p2) {
        if (p1.second == p2.second)
            return p1.first < p2.first;
        return p1.second < p2.second;
    }
};

// Function to print the k numbers with most occurrences
void kMostFrequent1 (int arr[], int n, int k) {
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
        m[arr[i]]++;
    // Store the elements of m in the vector 'freq_arr'
    vector <pair<int, int>> freq_arr (m.begin(), m.end());
    sort (freq_arr.begin(), freq_arr.end(), compare1);

    cout << k << " numbers with most occurrences are:\n";
    for (int i = 0; i<k; i++)
        cout << freq_arr[i].first << " ";
    cout << endl;
}

void kMostFrequent2 (int arr[], int n, int k) {
    unordered_map <int, int> m;
    for (int i = 0; i < n; i++)
        m[arr[i]]++;

    vector <pair<int, int>> freq_arr (m.begin(), m.end());
    priority_queue <pair<int, int>, vector<pair<int, int>>, compare2> pq(m.begin(), m.end());

    cout << k << " numbers with most occurrences are:\n";
    for (int i = 1; i<= k; i++) {
        cout << pq.top().first << " ";
        pq.pop();
    }
    cout << endl;
}

/* ---------------- MAIN DRIVER CODE ----------------- */
int main() {
    int arr[] = {3, 1, 4, 4, 5, 2, 6, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;
    kMostFrequent1(arr, n, k);
    kMostFrequent2(arr, n, k);
    return 0;
}