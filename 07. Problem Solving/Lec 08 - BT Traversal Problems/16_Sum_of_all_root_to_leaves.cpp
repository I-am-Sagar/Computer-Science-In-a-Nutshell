/*  PROBLEM:
    Given a binary tree, where every node value is a digit from 1-9.
    Find the sum of all the numbers which are formed from root to leaf paths.

    For example consider the following Binary Tree:
                6
              /   \
             3     5
           /   \     \
          2     5     4
               / \
              7   4

    There are 4 leaves, hence 4 root to leaf paths:
        Path                    Number
        6->3->2                   632
        6->3->5->7               6357
        6->3->5->4               6354
        6->5>4                    654
    Answer = 632 + 6357 + 6354 + 654 = 13997

    Output: 13997

    SOLUTION:
    The idea is to do a preorder traversal of the tree.
    In the preorder traversal, keep track of the value calculated
    till the current node, let this value be val. For every node,
    we update the val as val*10 plus node’s data.
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
int treePathsSumUtil(Node *root, int val)  {
    if (root == NULL) return 0;

    val = (val*10 + root->data);
    if (root->left==NULL && root->right==NULL)
        return val;
    return treePathsSumUtil(root->left, val) + treePathsSumUtil(root->right, val);
}

int treePathsSum(Node *root)  {
    return treePathsSumUtil(root, 0);
}

/* --------------- MAIN DRIVER CODE --------------- */
int main() {
    Node *root = new Node(6);
    root->left = new Node(3);
    root->right = new Node(5);
    root->left->left = new Node(2);
    root->left->right = new Node(5);
    root->right->right = new Node(4);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    cout<<"Sum of all paths is "<<treePathsSum(root) << endl;
    return 0;
}
