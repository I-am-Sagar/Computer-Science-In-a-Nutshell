// Video Link: https://www.youtube.com/watch?v=7yXBnlHZ0tY

/* PROBLEM: Given a binary tree, check whether it is a mirror of itself. */

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

/* -------------------- SYMMETRIC BT -------------------- */
bool isMirrorUtil(Node* a, Node* b){
    if (a == NULL && b == NULL) return true;
    if (a && b && a->data == b->data)
        return isMirrorUtil(a->left, b->right) && isMirrorUtil(a->right, b->left);
    return false;
}

bool isMirrorRec(Node* root) {
    return isMirrorUtil(root, root);
}

bool isMirrorItr(Node* root) {
    if (root == NULL) return true;

    queue <Node*> q;
    // Add root to queue two times, so that we can check if either
    // one child alone is Null or not.
    q.push(root);
    q.push(root);

    Node *leftNode, *rightNode;
    while (!q.empty()) {
        leftNode = q.front();
        q.pop();
        rightNode = q.front();
        q.pop();

        // If both - left and right children exists but have different
        // values, return false
        if (leftNode->data != rightNode->data)
            return false;

        // Push left child of left subtree node and right child of
        // right subtree node in queue
        if (leftNode->left && rightNode->right) {
            q.push(leftNode->left);
            q.push(rightNode->right);
        }
        // If one child is present and other is null, return false
        // as tree is not symmetric
        else if (leftNode->left || rightNode->right)
            return false;

        // Push right child of left subtree and left child
        // of right subtree
        if (leftNode->right && rightNode->left) {
            q.push(leftNode->right);
            q.push(rightNode->left);
        }
        // If only one child is present, tree is asymmetric
        else if (leftNode->right || rightNode->left)
            return false;
    }
    return true;
}

/* ---------------- MAIN DRIVER CODE ---------------- */
int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    //This will check if our both functions are working
    if(isMirrorRec(root) && isMirrorItr(root))
        cout << "The given tree is Symmetric.\n";
    else
        cout << "The given tree is not Symmetric.\n";
    return 0;
}