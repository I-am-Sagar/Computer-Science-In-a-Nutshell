/*  PROBLEM:
    There are given n ropes of different lengths, we need
    to connect these ropes into one rope. The cost to connect
    two ropes is equal to sum of their lengths. We need to
    connect the ropes with minimum cost.

    For example if we are given 4 ropes of lengths 4, 3, 2 and 6.
    We can connect the ropes in following ways:
    1) First connect ropes of lengths 2 and 3. Now we have
       three ropes of lengths 4, 6 and 5.
    2) Now connect ropes of lengths 4 and 5. Now we have two
       ropes of lengths 6 and 9.
    3) Finally connect the two ropes and all ropes have connected.

    Total cost for connecting all ropes is 5 + 9 + 15 = 29.
    This is the optimized cost for connecting ropes. Other ways
    of connecting ropes would always have same or more cost.

    For example, if we connect 4 and 6 first (we get three
    strings of 3, 2 and 10), then connect 10 and 3 (we get two
    strings of 13 and 2). Finally we connect 13 and 2.
    Total cost in this way is 10 + 13 + 15 = 38.

    If we observe the above problem closely, we can notice that
    the lengths of the ropes which are picked first are included
    more than once in total cost. Therefore, the idea is to connect
    smallest two ropes first and recur for remaining ropes.

    Let there be n ropes of lengths stored in an array len[0..n-1]
    1) Create a min heap and insert all lengths into the min heap.
    2) Do following while number of elements in min heap is not one.
        a) Extract the minimum and second minimum from min heap
        b) Add the above two extracted values and insert the added
           value to the min-heap.
        c) Maintain a variable for total cost and keep incrementing
           it by the sum of extracted values.
    3) Return the value of this total cost.
*/

#include <bits/stdc++.h>
using namespace std;

// Main Logic
int minCost (int arr[], int n) {
    priority_queue <int, vector<int>, greater<int>> pq (arr, arr+n);
    int res = 0;
    while (pq.size() > 1) {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();
        res += first+second;
        pq.push(first+second);
    }
    return res;
}

/* -------------- MAIN DRIVER CODE ---------------- */
int main() {
    int len[] = { 4, 3, 2, 6 };
    int size = sizeof(len) / sizeof(len[0]);
    cout << "Total cost for connecting ropes is " << minCost(len, size) << endl;
    return 0;
}