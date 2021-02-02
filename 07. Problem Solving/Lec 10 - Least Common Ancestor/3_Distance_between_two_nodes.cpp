/*  PROBLEM:
    Find the distance between two keys in a binary tree.
    Distance between two nodes is the minimum number of
    edges to be traversed to reach one node from other.

    SOLUTION:
    We first find LCA of two nodes. Then we find distance
    from LCA to two nodes.
*/

#include <bits/stdc++.h>
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

// Utility function that returns pointer to LCA
Node* findLCA (Node* root, int n1, int n2) {
    if (root == NULL)   return root;
    if (root->data == n1 || root->data == n2)
        return root;

    Node* left_lca = findLCA (root->left, n1, n2);
    Node* right_lca = findLCA (root->right, n1, n2);

    if (left_lca != NULL && right_lca != NULL)
        return root;

    if (left_lca != NULL)
        return findLCA(root->left, n1, n2);
    return findLCA (root->right, n1, n2);
}

// Utility function that returns level of key k
// if it is present in the tree, or else returns -1
int findLevel(Node *root, int k, int level) {
    if(root == NULL) return -1;
    if(root->data == k) return level;

    int left = findLevel(root->left, k, level+1);
    if (left == -1)
       return findLevel(root->right, k, level+1);
    return left;
}

// Main logic
int findDistance(Node* root, int a, int b) {
    Node* lca = findLCA(root, a , b);

    int d1 = findLevel(lca, a, 0);
    int d2 = findLevel(lca, b, 0);
    return d1 + d2;
}

/* -------------- MAIN DRIVER CODE -------------- */
int main() {
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    cout << "Dist(4, 5) = " << findDistance(root, 4, 5);
    cout << "\nDist(4, 6) = " << findDistance(root, 4, 6);
    cout << "\nDist(3, 4) = " << findDistance(root, 3, 4);
    cout << "\nDist(2, 4) = " << findDistance(root, 2, 4);
    cout << "\nDist(8, 5) = " << findDistance(root, 8, 5);
    cout << endl;
    return 0;
}

