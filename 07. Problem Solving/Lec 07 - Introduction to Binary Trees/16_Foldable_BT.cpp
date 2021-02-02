// Video Link: https://www.youtube.com/watch?v=DxUFjEn8ul0

/* PROBLEM: Given a binary tree, find out if the tree can be folded or not.

A tree can be folded if left and right subtrees of the tree are structure wise
mirror-image of each other. An empty tree is considered as foldable. */

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node (int data) {
        this->data = data;
        left = right = NULL;
    }
};

/* ------------------------ FOLDABLE BT ----------------------- */

// A utility function that checks if trees with roots as 'a' and 'b'
// are structure-wise mirror of each other.
bool isFoldableUtil(Node* a, Node* b) {
    // If both, left and right subtrees are NULL, return true
    if (a==NULL && b==NULL) return true;
    // If one of the subtree is NULL and other is not, return false
    if (a==NULL || b==NULL) return false;

    // Otherwise check for left and right subtrees
    return isFoldableUtil(a->left, b->right) && isFoldableUtil(a->right, b->left);
}

bool isFoldable(Node* root) {
    if (root == NULL)   return true;
    return isFoldableUtil(root->left, root->right);
}

/* ---------------- MAIN DRIVER CODE ---------------- */
int main(void) {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);

    if (isFoldable(root) == true)
        cout << "BT is foldable.\n";
    else
        cout << "BT is not foldable.\n";

    return 0;
}