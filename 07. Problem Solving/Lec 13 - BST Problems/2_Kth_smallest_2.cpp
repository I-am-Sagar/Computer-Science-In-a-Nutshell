/*  The idea is to maintain rank of each node. We can
    keep track of elements in a subtree of any node
    while building the tree. Since we need K-th smallest
    element, we can maintain number of elements of left
    subtree in every node.

    Assume that the root is having N nodes in its left
    subtree. If K = N + 1, root is K-th node.
    If K < N, we will continue our search (recursion)
    for the Kth smallest element in the left subtree
    of root. If K > N + 1, we continue our search in
    the right subtree for the (K – N – 1)-th smallest
    element. Note that we need the count of elements
    in left subtree only.

    Time complexity: O(h) where h is height of tree.
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

// Utility Function that returns number of nodes
int num (Node* root) {
    if (root == NULL)
        return 0;
    return (num(root->left) + num(root->right) + 1);
}

// Main Logic
int kthSmallest (Node* root, int k) {
    int nodes_in_left = num(root->left);
    if (nodes_in_left == k-1)
        return root->data;
    else if (nodes_in_left > k-1)
        return kthSmallest(root->left, k);
    else
        return kthSmallest(root->right, k-nodes_in_left-1);
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