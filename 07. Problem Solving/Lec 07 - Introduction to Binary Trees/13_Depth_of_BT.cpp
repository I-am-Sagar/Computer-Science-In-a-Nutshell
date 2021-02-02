// Video Link: https://www.youtube.com/watch?v=_pnqMz5nrRs

/* PROBLEM: Given a binary tree, find height of it. */

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

//Main Logic
int heightRecursive(Node* root) {
    if (root == NULL)   return 0;
    return (max(heightRecursive(root->left), heightRecursive(root->right)) + 1);
}

int heightIterative(Node* root) {
    if (root == NULL)   return 0;
    queue<Node*> q;
    q.push(root);

    Node* front = NULL;
    int height = 0;
    while (!q.empty()) {
        int size = q.size();
        while(size--) {
            front = q.front();
            q.pop();
            if (front->left)    q.push(front->left);
            if (front->right)   q.push(front->right);
        }
        height++;
    }
    return height;
}

/* ---------------- MAIN DRIVER CODE ---------------- */
int main() {
    struct Node* root = new Node(10);
    root->left = new Node(11);
    root->left->left = new Node(7);
    root->left->right = new Node(12);
    root->right = new Node(9);
    root->right->left = new Node(15);
    root->right->right = new Node(8);

    cout << heightRecursive(root) << endl;
    cout << heightIterative(root) << endl;
    return 0;
}