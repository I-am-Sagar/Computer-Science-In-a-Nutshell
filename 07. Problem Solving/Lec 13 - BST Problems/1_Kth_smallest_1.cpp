/*  PROBLEM:
    Given root of BST and K as input, find K-th
    smallest element in BST.

    SOLUTION:

    Method 1 - Using inorder traversal
    Inorder traversal of BST retrives elements of tree
    in the sorted order. The inorder traversal uses stack
    to store to be explored nodes. The idea is to keep
    track of popped elements which participate in order
    statistics.

    Time complexity: O(n)
    Space complexity: O(n)
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;
    Node(int x) {
        this->data = x;
        this->left = this->right = NULL;
    }
};

// Auxiliary Function
Node* insert(struct Node* node, int key) {
    if (node == NULL) {
        Node* temp = new Node(key);
        return temp;
    };

    if (key < node->data)
        node->left  = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);

    return node;
}

// Main Logic
int kthSmallest (Node* root, int k) {
    stack<Node*> s;
    int count = 0;
    Node* ptr = root;
    s.push(ptr);
    while (ptr->left) {
        s.push(ptr->left);
        ptr = ptr->left;
    }
    while (++count < k) {
        Node* temp = s.top()->right;
        s.pop();
        if(temp) {
            s.push(temp);
            while (temp->left) {
                s.push(temp->left);
                temp = temp->left;
            }
        }
    }
    return s.top()->data;
}

/* -------------------- MAIN DRIVER CODE ------------------ */
int main() {
    Node *root = NULL;
    root = insert(root, 5);
    root = insert(root, 1);
    root = insert(root, 10);
    root = insert(root,  0);
    root = insert(root,  4);
    root = insert(root,  7);
    root = insert(root,  9);

    int k = 4;

    int kth_smallest = kthSmallest(root, k);

    cout << kth_smallest << endl;

    return 0;
}