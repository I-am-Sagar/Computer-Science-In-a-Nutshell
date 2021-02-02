/*  PROBLEM:
    Given a Binary Node and a node. The task is to search and
    check if the given node exits in the binary tree or not.
    If it exists, print YES otherwise print NO.

    SOLUTION:
    The idea is to use any of the tree traversals to traverse
    the tree and while traversing check if the current node
    matches with the given node. Print YES if any node matches
    with the given node and stop traversing further and if
    the tree is completely traversed and none of the node
    matches with the given node then print NO.
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

// Function to traverse in Preorder and check if node exists
bool ifNodeExists (Node* root, int key) {
    if (root == NULL)   return false;
    if (root->data == key)    return true;
    bool res1 = ifNodeExists(root->left, key);
    bool res2 = ifNodeExists(root->right, key);
    return (res1||res2);
}

/* ----------------- MAIN DRIVER CODE ------------------ */
int main() {
    struct Node* root = new Node(0);
    root->left = new Node(1);
    root->left->left = new Node(3);
    root->left->left->left = new Node(7);
    root->left->right = new Node(4);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right = new Node(2);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    int key = 4;

    if (ifNodeExists(root, key))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}