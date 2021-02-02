// Video Link: https://www.youtube.com/watch?v=vpMe2aZM6Kg

/*  PROBLEM:
    Given a Binary Tree, find the maximum (or minimum) element in it.

    SOLUTION:
    Traverse the given tree and for every node return maximum of 3 values:
    1) Node’s data.
    2) Maximum in node’s left subtree.
    3) Maximum in node’s right subtree.
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

// Auxiliary Functions
int max (int a, int b) {
    return (a>b ? a : b);
}

// Main Logic
int findMaxRec (Node* root) {
    // Base case
    if (root == NULL)   return INT_MIN;

    int res = root->data;
    int lres = findMaxRec(root->left);
    int rres = findMaxRec(root->right);

    return max(res, max(lres, rres));
}

int findMaxItr(Node* root) {
    if (root == NULL)   return INT_MIN;

    Node* temp = NULL;
    int max = INT_MIN;

    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp->data > max)
            max = temp->data;

        if (temp->left) q.push(temp->left);
        if (temp->right) q.push(temp->right);
    }
    return max;
}

/* ------------------- MAIN DRIVER CODE ---------------- */
int main() {
    Node*NewRoot = NULL;
    Node *root = new Node(2);
    root->left = new Node(7);
    root->right = new Node(5);
    root->left->right = new Node(6);
    root->left->right->left = new Node(1);
    root->left->right->right = new Node(11);
    root->right->right = new Node(9);
    root->right->right->left = new Node(4);

    cout << findMaxRec(root) << endl;
    cout << findMaxItr(root) << endl;

    return 0;
}