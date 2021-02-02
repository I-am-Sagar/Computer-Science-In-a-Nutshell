// Video link: https://www.youtube.com/watch?v=gm8DUJJhmY4&t=438s

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

// Main Logic
void preOrder (Node* node) {
    if (node == NULL) return;
    cout << node->data << " ";
    preOrder (node->left);
    preOrder (node->right);
}

void inOrder (Node* node) {
    if (node == NULL) return;
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

void postOrder (Node* node) {
    if (node == NULL)   return;
    postOrder(node->left);
    postOrder(node->right);
    cout << node->data << " ";
}

/* ---------------- MAIN DRIVER CODE ---------------- */
int main() {
    struct Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);

    cout << "\nPreorder traversal of binary tree is \n";
    preOrder(root);

    cout << "\nInorder traversal of binary tree is \n";
    inOrder(root);

    cout << "\nPostorder traversal of binary tree is \n";
    postOrder(root);

    return 0;
}
