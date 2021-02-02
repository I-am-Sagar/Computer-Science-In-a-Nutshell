/*  PROBLEM:
    Suppose we are given a binary tree and we need to check
    whether it is a sum tree or not, how would you do that?

    Following tree is an example of sumtree:
                  26
                /    \
               10     3
             /    \    \
            4      6    3

    A simple solution is - Get the sum of nodes in left subtree
    and right subtree. Check if the sum calculated is equal to
    root’s data. Also, recursively check if the left and
    right subtrees are SumTrees.

    int sum (Node *root) {
        if(root == NULL)
            return 0;
        return sum(root->left) + root->data + sum(root->right);
    }

    bool isSumTree (Node* root) {
        int ls, rs;

        // If node is NULL or it's a leaf node
        // then return true
        if(node == NULL || (node->left == NULL && node->right == NULL))
            return true;

        // Get sum of nodes in left and right subtrees
        ls = sum(node->left);
        rs = sum(node->right);

        // If the node and both of its children satisfy the
        // property return 1 else 0
        if((node->data == ls + rs) && isSumTree(node->left) && isSumTree(node->right))
            return true;

        return false;
    }

    Time Complexity: O(n^2) in worst case. Worst case occurs for a skewed tree.

    The above method uses sum() to get the sum of left and right subtrees.
    We can find sum directly using following observations:
    1. If a node is leaf node, return the value of the node.
    2. If the node is not a leaf node, then sum of subtree rooted
       with this node is twice the value of this node.

    Time Complexity: O(n) even in worst case.
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};

// Utility function to check if a node is leaf or not
bool isLeaf (Node* node) {
    if (node == NULL)   return false;
    if (node->left == NULL && node->right == NULL)
        return true;
    return false;
}

// Main Logic
bool isSumTree (Node* root) {
    if (root == NULL || isLeaf(root))
        return true;

    int left_sum, right_sum;

    if (isSumTree(root->left) && isSumTree(root->right)) {
        // Get the sum of nodes in left subtree
        if (root->left == NULL)
            left_sum = 0;
        else if (isLeaf(root->left))
            left_sum = root->left->data;
        else
            left_sum = 2*(root->left->data);

        // Get the sum of nodes in right subtree
        if (root->right == NULL)
            right_sum = 0;
        else if (isLeaf(root->right))
            right_sum = root->right->data;
        else
            right_sum = 2*(root->right->data);

        return (root->data == left_sum+right_sum);
    }
    return false;
}

/* ------------------- MAIN DRIVER CODE ------------------ */
int main() {
    Node *root  = new Node(26);
    root->left         = new Node(10);
    root->right        = new Node(3);
    root->left->left   = new Node(4);
    root->left->right  = new Node(6);
    root->right->right = new Node(3);

    if(isSumTree(root))
        printf("The given tree is a SumTree.\n");
    else
        printf("The given tree is not a SumTree.\n");

    return 0;
}