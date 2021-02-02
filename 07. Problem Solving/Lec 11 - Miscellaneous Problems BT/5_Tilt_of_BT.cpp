/*
Given a binary tree, return the tilt of the whole tree. The tilt of a tree node
is defined as the absolute difference between the sum of all left subtree node
values and the sum of all right subtree node values. Null nodes are assigned
tilt to be zero. Therefore, tilt of the whole tree is defined as the sum of
all nodes’ tilt.

Input :
    1
   / \
  2   3
Output : 1
Explanation:
Tilt of node 2 : 0
Tilt of node 3 : 0
Tilt of node 1 : |2-3| = 1
Tilt of binary tree : 0 + 0 + 1 = 1

Input :
    4
   / \
  2   9
 / \   \
3   5   7
Output : 15
Explanation:
Tilt of node 3 : 0
Tilt of node 5 : 0
Tilt of node 7 : 0
Tilt of node 2 : |3-5| = 2
Tilt of node 9 : |0-7| = 7
Tilt of node 4 : |(3+5+2)-(9+7)| = 6
Tilt of binary tree : 0 + 0 + 0 + 2 + 7 + 6 = 15

APPROACH:
The idea is to recursively traverse tree. While traversing, we keep track of
two things, sum of subtree rooted under current node, tilt of current node.
Sum is needed to compute tilt of parent.

*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Recursive function to calculate Tilt of whole tree
int traverse(Node* root, int* tilt) {
    if (!root)
        return 0;

    // Compute tilts of left and right subtrees
    // and find sums of left and right subtrees
    int left = traverse(root->left, tilt);
    int right = traverse(root->right, tilt);

    // Add current tilt to overall
    *tilt += abs(left - right);

    // Returns sum of nodes under current tree
    return left + right + root->data;
}

// Driver function to print Tilt of whole tree
int Tilt(Node* root) {
    int tilt = 0;
    traverse(root, &tilt);
    return tilt;
}

/* ---------------- MAIN DRIVER CODE --------------- */
int main() {
    Node* root = NULL;
    root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(9);
    root->left->left = new Node(3);
    root->left->right = new Node(8);
    root->right->right = new Node(7);
    cout << "The Tilt of whole tree is " << Tilt(root) << endl;
    return 0;
}
