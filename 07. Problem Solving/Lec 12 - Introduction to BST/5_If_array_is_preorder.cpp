/*  Given an array of numbers, return true if given array can
    represent preorder traversal of a BST, else return false.

    SOLUTION:

    Simple Solution:
    Do following for every node pre[i] starting from first one:

    Find the first greater value on right side of current node.
    Let the index of this node be j.
        a) All values after the above found greater value are
           greater than current node.
        b) Recursive calls for the subarrays pre[i+1..j-1] and
           pre[j+1..n-1] also return true.
    Return true if above conditions hold or else return false.

    Time Complexity: O(n^2)

    Efficient Solution:
    The idea is to use a stack. This problem is similar to
    Next Greater Element problem. Here we find next greater
    element and after finding next greater, if we find a
    smaller element, then return false.

    1. Create an empty stack.
    2. Initialize root as INT_MIN.
    3. Do following for every element pre[i]
        a) If pre[i] is smaller than current root, return false.
        b) Keep removing elements from stack while pre[i] is greater
           then stack top. Make the last removed item as new root
           (to be compared next).
           At this point, pre[i] is greater than the removed root
           (That is why if we see a smaller element in step a),
            we return false)
        c) push pre[i] to stack (All elements in stack are in decreasing
           order)

    Time Complexity: O(n)

    Below is the implementation of efficient solution.
*/

#include<bits/stdc++.h>
using namespace std;

bool isPreBST (int pre[], int n) {
    stack<int> s;
    int root = INT_MIN;

    for (int i = 0; i < n; i++) {
        if (pre[i] < root)
            return false;
        while (!s.empty() && s.top()<pre[i]) {
            root = s.top();
            s.pop();
        }
        s.push(pre[i]);
    }
    return true;
}

/* ------------------ MAIN DRIVER CODE ------------ */
int main() {
    int pre1[] = {40, 30, 35, 80, 100};
    int n = sizeof(pre1)/sizeof(pre1[0]);
    isPreBST(pre1, n)? cout << "True\n": cout << "False\n";

    int pre2[] = {40, 30, 35, 20, 80, 100};
    n = sizeof(pre2)/sizeof(pre2[0]);
    isPreBST(pre2, n)? cout << "True\n": cout << "False\n";

    return 0;
}