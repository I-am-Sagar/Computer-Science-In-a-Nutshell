// No Video Link

/* PROBLEM: Given a binary tree and a key, insert the key into the binary tree
            at first position available in level order.

    APPROACH:

    The idea is to do iterative level order traversal of the given tree using queue.
    If we find a node whose left child is empty, we make new key as left child of the node.
    Else if we find a node whose right child is empty, we make new key as right child.
    We keep traversing the tree until we find a node whose either left or right is empty.
*/

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

void levelOrder (Node* current) {
    if (current == NULL)   return;
    queue<Node*> q;
    q.push(current);
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

// Main Logic
void insertNode (Node* root, int key) {
    queue<Node*> q;
    q.push(root);

    // Do a level order traversal until we find empty place
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        if (!(current->left)) {
            current->left = new Node(key);
            break;
        }
        else
            q.push(current->left);

        if (!(current->right)) {
            current->right = new Node(key);
            break;
        }
        else
            q.push(current->right);
    }
}

/* ---------------- MAIN DRIVER CODE ---------------- */
int main() {
    Node* root = new Node(10);
    root->left = new Node(11);
    root->left->left = new Node(7);
    root->right = new Node(9);
    root->right->left = new Node(15);
    root->right->right = new Node(8);

    cout << "Level order traversal before insertion:";
    levelOrder(root);

    int key = 12;
    insertNode(root, key);

    cout << endl;
    cout << "Level order traversal after insertion:";
    levelOrder(root);

    return 0;
}