/*  PROBLEM:
    Given a binary tree in which each node element contains a number.
    Find the maximum possible sum from one leaf node to another.

    SOLUTION:
    The idea is to maintain two values in recursive calls
    1) Maximum root to leaf path sum for the subtree rooted under current node.
    2) The maximum path sum between leaves (desired output).

    For every visited node X, we find the maximum root to leaf sum in left and
    right subtrees of X. We add the two values with X->data, and compare the
    sum with maximum path sum found so far.
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left, *right;
        Node (int data) {
            this->data = data;
            this->left = this->right = NULL;
        }
};

// Main Logic
int maxPathSumUtil (Node* root, int &result) {
    if (root == NULL)   return 0;
    if (!root->left && !root->right) return root->data;

    // Find maximum root to leaf sums in left and right subtrees
    int lsum = maxPathSumUtil(root->left, result);
    int rsum = maxPathSumUtil(root->right, result);

    // If both left and right children exist
    if (root->left && root->right) {
        // Update result if needed
        result = max(result, lsum + rsum + root->data);
        // Return maxium possible value for root being on one side
        return max(lsum, rsum) + root->data;
    }
    // If any of the two children is empty,
    // return root sum for root being on one side
    return (!root->left)? (rsum + root->data):( lsum + root->data);
}

int maxPathSum(struct Node *root) {
    int res = INT_MIN;
    maxPathSumUtil(root, res);
    return res;
}

/* --------------- MAIN DRIVER CODE ------------------ */
int main() {
    Node *root = new Node(-15);
    root->left = new Node(5);
    root->right = new Node(6);
    root->left->left = new Node(-8);
    root->left->right = new Node(1);
    root->left->left->left = new Node(2);
    root->left->left->right = new Node(6);
    root->right->left = new Node(3);
    root->right->right = new Node(9);
    root->right->right->right= new Node(0);
    root->right->right->right->left= new Node(4);
    root->right->right->right->right= new Node(-1);
    root->right->right->right->right->left= new Node(10);
    cout << "Max pathSum of the given binary tree is " << maxPathSum(root) << endl;
    return 0;
}