// Video Link: https://www.youtube.com/watch?v=86g8jAQug04

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data) {
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// Main Logic
void levelOrder (Node* root) {
    // If the tree is empty, we can simply return
    if (root == NULL)   return;

    // If tree is not empty, we will need Queue
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        cout << current->data << " ";
        q.pop();

        if (current->left != NULL)
            q.push(current->left);
        if (current->right != NULL)
            q.push(current->right);
    }
}

/* ---------------- MAIN DRIVER CODE ---------------- */
int main() {
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "Level Order traversal of binary tree is \n";
    levelOrder(root);
    return 0;
}