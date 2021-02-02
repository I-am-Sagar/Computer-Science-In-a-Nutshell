/*  PROBLEM:
    Convert the given BT into DLL. The order of
    nodes in DLL should be same as inorder traversal
    of the BT.

    SOLUTION:
    The idea is to do inorder traversal of the binary tree.
    While doing inorder traversal, keep track of the previously
    visited node in a variable say prev. For every visited node,
    make it next of prev and previous of this node as prev.
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

// Auxiliary Function
void printList(Node *node) {
    while (node!=NULL) {
        cout << node->data << " ";
        node = node->right;
    }
    cout << endl;
}

// Main Logic
void BTtoDLL (Node* root, Node** head) {
    if (root == NULL)   return;

    static Node* prev = NULL;

    BTtoDLL(root->left, head);

    if (prev == NULL)
        *head = root;
    else {
        root->left = prev;
        prev->right = root;
    }
    prev = root;

    BTtoDLL(root->right, head);
}

/* -------------- MAIN DRIVER CODE ----------------- */
int main() {
    Node *root        = new Node(10);
    root->left        = new Node(12);
    root->right       = new Node(15);
    root->left->left  = new Node(25);
    root->left->right = new Node(30);
    root->right->left = new Node(36);

    Node *head = NULL;
    BTtoDLL(root, &head);

    printList(head);

    return 0;
}