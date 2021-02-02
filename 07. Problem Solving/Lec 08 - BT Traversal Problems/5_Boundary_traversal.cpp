// Video Link: https://www.youtube.com/watch?v=7yFf4nKsamU

/*  PROBLEM:
    Given a binary tree, print boundary nodes of BT in
    anti-clockwise direction starting from the root.

    For example, for the following tree:
                     20
                    /  \
                  8     22
                /   \     \
               4   12      25
                  /  \
                10    14

    Output: 20 8 4 10 14 25 22

    We break the problem in 3 parts:
    1. Print the left boundary in top-down manner.
    2. Print all leaf nodes from left to right, which can again be
       sub-divided into two sub-parts:
        2.1 Print all leaf nodes of left sub-tree from left to right.
        2.2 Print all leaf nodes of right subtree from left to right.
    3. Print the right boundary in bottom-up manner.

    We need to take care of one thing that nodes are not printed again.
    e.g. The left most node is also the leaf node of the tree.
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

// Utility functions to be used in main logic

/* A simple function to print leaf nodes of a binary tree */
void printLeaves(Node* root) {
    if (root == NULL)   return;
    printLeaves(root->left);
    if (!(root->left) && !(root->right))
        cout << root->data << " ";
    printLeaves(root->right);
}

/* Function to print all left boundary nodes in Top-Down manner,
   except a leaf node. */
void printLeftBoundary (Node* root) {
    if (root == NULL)   return;
    // To ensure top-down, print the node before calling for left subtree
    if (root->left) {
        cout << root->data << " ";
        printLeftBoundary(root->left);
    }
    else if (root->right) {
        cout << root->data << " ";
        printLeftBoundary(root->right);
    }
}

/* Function to print all right boundary nodes in Bottom-up manner,
   except a leaf node. */
void printRightBoundary (Node* root) {
    if (root == NULL)   return;
    // for bottom-up, call for right subtree first and then print the node
    if (root->right) {
        printRightBoundary(root->right);
        cout << root->data << " ";
    }
    else if (root->left) {
        printLeftBoundary(root->left);
        cout << root->data << endl;
    }
}

// Main Logic
void boundaryTraversal (Node* root) {
    if (root == NULL)   return;
    cout << root->data << " ";
    printLeftBoundary(root->left);
    printLeaves(root->left);
    printLeaves(root->right);
    printRightBoundary(root->right);
    cout << endl;
}

/* --------------- MAIN DRIVER CODE --------------- */
int main() {
    // Let us construct the tree given in the above diagram
    Node* root = new Node(20);
    root->left = new Node(8);
    root->left->left = new Node(4);
    root->left->right = new Node(12);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    root->right = new Node(22);
    root->right->right = new Node(25);

    boundaryTraversal(root);

    return 0;
}