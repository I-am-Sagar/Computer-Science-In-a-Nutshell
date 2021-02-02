/*  Given an array of size n. The problem is to check whether
    the given array can represent the level order traversal
    of a Binary Search Tree or not.

    Input : arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10}
    Output : Yes
        For the given arr[] the Binary Search Tree is:
                   7
                 /   \
                4     12
               / \    /
              3   6  8
             /   /    \
            1   5     10

    Input : arr[] = {11, 6, 13, 5, 12, 10}
    Output : No
    The given arr[] do not represent the level order traversal of
    a BST.

    SOLUTION:
    The idea is to use a queue data structure. Every element of queue
    has a structure say NodeDetails which stores details of a tree node.
    The details are node’s data, and two variables min and max where min
    stores the lower limit for the node values which can be a part of the
    left subtree and max stores the upper limit for the node values which
    can be a part of the right subtree for the specified node in NodeDetails
    structure variable. For the 1st array value arr[0], create a NodeDetails
    structure having arr[0] as node’s data and min = INT_MIN and max = INT_MAX.
    Add this structure variable to the queue. This Node will be the root of
    the tree. Move to 2nd element in arr[] and then perform the following steps:

    1. Pop NodeDetails from the queue in temp.

    2. Check whether the current array element can be a left child of the
       node in temp with the help of min and temp.data values. If it can,
       then create a new NodeDetails structure for this new array element
       value with its proper ‘min’ and ‘max’ values and push it to the queue,
       and move to next element in arr[].

    3. Check whether the current array element can be a right child of the
       node in temp with the help of max and temp.data values. If it can,
       then create a new NodeDetails structure for this new array element
       value with its proper ‘min’ and ‘max’ values and push it to the queue,
       and move to next element in arr[].

    4. Repeat steps 1, 2 and 3 until there are no more elements in arr[] or
       there are no more elements in the queue.

    5. Finally, if all the elements of the array have been traversed then
       the array represents the level order traversal of a BST, else NOT.
*/

#include<bits/stdc++.h>
using namespace std;

struct NodeDetails {
    int data;
    int min, max;
};

// Main Logic of Code
bool isLevelOrderOfBST(int arr[], int n) {
    if (n == 0) return true;

    queue<NodeDetails> q;
    int i=0;
    NodeDetails newNode;
    newNode.data = arr[i++];
    newNode.min = INT_MIN;
    newNode.max = INT_MAX;
    q.push(newNode);
    while (i != n && !q.empty())         {
        NodeDetails temp = q.front();
        q.pop();

        if (i < n && (arr[i] < temp.data && arr[i] > temp.min)) {
            newNode.data = arr[i++];
            newNode.min = temp.min;
            newNode.max = temp.data;
            q.push(newNode);
        }
        if (i < n && (arr[i] > temp.data && arr[i] < temp.max)) {
            newNode.data = arr[i++];
            newNode.min = temp.data;
            newNode.max = temp.max;
            q.push(newNode);
        }
    }
    if (i == n) return true;

    return false;
}

/* -------------- MAIN DRIVER CODE ----------- */
int main() {
    int arr[] = {7, 4, 12, 3, 6, 8, 1, 5, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    if (isLevelOrderOfBST(arr, n))
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}