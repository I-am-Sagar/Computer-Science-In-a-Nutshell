// Video Link: https://www.youtube.com/watch?v=qH6yxkw0u78

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* newNode (int data) {
    Node* new_node = new Node;
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return (new_node);
}

/* ---------------- MAIN DRIVER CODE ---------------- */
int main() {
    // Create Root Node
    Node* root = newNode(1);

    // Attach left and right children
    root->left = newNode(2);
    root->right = newNode(3);

    /*        1
            /   \
          2       3
        /   \    /  \
       NULL NULL NULL NULL
    */
    return 0;
}