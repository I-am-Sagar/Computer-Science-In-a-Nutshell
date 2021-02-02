/*  PROBLEM:
    Given a BST, modify it so that all greater values
    in the given BST are added to every node.

    For example, consider the following BST:
              50
           /      \
         30        70
        /   \      /  \
      20    40    60   80

    The above tree should be modified to following

              260
           /      \
         330        150
        /   \       /  \
      350   300    210   80

    SOLUTION:

    Approach 1:
    Find sum of all nodes greater than the current node and
    add this sum to current node. Repeat this process for every
    node of BST. Time Complexity: O(n^2)

    Approach 2:
    If we do reverse Inorder traversal of BST, we get all nodes
    in decreasing order. We do reverse Inorder traversal and
    keep track of the sum of all nodes visited so far,
    we add this sum to every node.
    Time complexity: O(n)
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

void inorder(Node *root)  {
    if (root != NULL)  {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

// Main Logic
void modifyBSTutil (Node*root, int *sum) {
    if (root == NULL)   return;
    modifyBSTutil (root->right, sum);
    *sum += root->data;
    root->data = *sum;
    modifyBSTutil(root->left,sum);
}

void modifyBST (Node* root) {
    int sum = 0;
    modifyBSTutil(root, &sum);
}

/* -------------------- MAIN DRIVER CODE ---------------- */
int main() {
    Node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    modifyBST(root);

    inorder(root);
    cout << endl;

    return 0;
}