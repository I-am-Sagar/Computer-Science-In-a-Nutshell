/*  PROBLEM:
    Given that integers are being read from a data stream.
    Find median of all the elements read so far starting
    from the first integer till the last integer. This is
    also called Median of Running Integers. The data stream
    can be any source of data, example: a file, an array of
    integers, input stream etc.

    Input: 5 10 15
    Output: 5 7.5 10

    Explanation: Given the input stream as an array of integers
    [5,10,15]. We will now read integers one by one and print the
    median correspondingly. So, after reading first element 5,
    median is 5. After reading 10,median is 7.5 After reading 15,
    median is 10.

    SOLUTION:
    The idea is to use max heap and min heap to store the elements
    of higher half and lower half. Max heap and min heap can be
    implemented using priority_queue in C++ STL.

    Algorithm:
    1. Create two heaps - a max heap to maintain elements of lower half
       and a min heap to maintain elements of higher half at any point.
    2. Take initial median as 0.
    3. For every newly read element, insert it into either max heap or
       min heap and calulate the median based on the following conditions:
        a) If the size of max heap is greater than size of min heap and
           the element is less than previous median then pop the top
           element from max heap and insert into min heap and insert the
           new element to max heap else insert the new element to min heap.
           Calculate the new median as average of top of elements of both
           max and min heap.
        b) If the size of max heap is less than size of min heap and the
           element is greater than previous median then pop the top element
           from min heap and insert into max heap and insert the new element
           to min heap else insert the new element to max heap. Calculate the
           new median as average of top of elements of both max and min heap.
        c) If the size of both heaps are same. Then check if current is less
           than previous median or not. If the current element is less than
           previous median then insert it to max heap and new median will be
           equal to top element of max heap. If the current element is greater
           than previous median then insert it to min heap and new median will
           be equal to top element of min heap.

    Time Complexity: O(n*Log n)
    Space Complexity : O(n)
*/

#include <bits/stdc++.h>
using namespace std;

// Main logic
void medianOfRunningIntegers (double arr[], int n) {
    // max heap to store the smaller half elements
    priority_queue <double> s;
    // min heap to store the greater half elements
    priority_queue<double,vector<double>,greater<double> > g;

    double med = arr[0];
    s.push(arr[0]);
    cout << med << endl;

    for (int i=1; i < n; i++) {
        double x = arr[i];
        // case1 (left side heap has more elements)
        if (s.size() > g.size()) {
            if (x < med) {
                g.push(s.top());
                s.pop();
                s.push(x);
            }
            else
                g.push(x);
                med = (s.top() + g.top())/2.0;
        }
        // case2 (both heaps are balanced)
        else if (s.size()==g.size()) {
            if (x < med) {
                s.push(x);
                med = (double)s.top();
            }
            else {
                g.push(x);
                med = (double)g.top();
            }
        }
        // case 3 (right side heap has more elements)
        else {
            if (x > med) {
                s.push(g.top());
                g.pop();
                g.push(x);
            }
            else
                s.push(x);
            med = (s.top() + g.top())/2.0;
        }
        cout << med << endl;
    }
}

/* ------------- MAIN DRIVER CODE ---------- */
int main() {
    // stream of integers
    double arr[] = {5, 15, 10, 20, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    medianOfRunningIntegers (arr, n);
    return 0;
}