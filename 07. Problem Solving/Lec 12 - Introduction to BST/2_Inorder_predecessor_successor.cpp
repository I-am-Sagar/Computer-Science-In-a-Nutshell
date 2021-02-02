/*  PROBLEM:
    Given a BST, find the inorder successor and predecessor
    of a given key. In case the given key is not found,
    then return two values within which the key will lie.

    SOLUTION:
    Here is an recursive algorithm which does this task:

    1. If root is NULL, return.
    2. If key is found, then
        a) If it's left subtree is not NULL, then
           predecessor will be the rightmost child
           of left subtree or that left child itself.
        b) If it's right subtree is not NULL, then
           successor will be the leftmost child of
           right subtree or that right child itself.
        Return.
    3.  If key is smaller than root,
        a) set the successor as root and search
           recursively into left subtree
        Else
        b) set the predecessor as root and search
           recursively into right subtree
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

// Auxiliary function to build a BST
Node* insert (Node* root, int key) {
    if (root == NULL) {
        Node* temp = new Node(key);
        return temp;
    }
    if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

// Main Logic
void findPreSuc (Node* root, Node* &pre, Node* &suc, int key) {
    if (root == NULL)   return;

    if (root->data == key) {
        if (root->left != NULL) {
            Node* temp = root->left;
            while (temp->right)
                temp = temp->right;
            pre = temp;
        }
        if (root->right != NULL) {
            Node* temp = root->right;
            while (root->left)
                temp = temp->left;
            suc = temp;
        }
        return;
    }

    if (root->data > key) {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    else {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
}

/* ---------------- MAIN DRIVER CODE ---------------- */
int main() {
    int key = 65;

    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    Node* pre = NULL;
    Node* suc = NULL;
    findPreSuc (root, pre, suc, key);

    if (pre!=NULL)
        cout << "Predecessor: " << pre->data << endl;
    else
        cout << "No predecessor.\n";

    if (suc!=NULL)
        cout << "Successor: " << suc->data << endl;
    else
        cout << "No successor.\n";

    return 0;
}