// No Video Link

/* PROBLEM: Given a binary tree, delete a node from it by making sure that tree
            shrinks from the bottom (i.e. the deleted node is replaced by bottommost
            and rightmost node).

    Delete 10 in below tree:
           10
         /    \
        20     30
    Output:
           30
         /
        20


    Delete 20 in below tree:
           10
         /    \
        20     30
                \
                40
    Output :
           10
         /   \
        40    30

    APPROACH:
        1. Starting at root, find the deepest and rightmost node in binary tree and node
            which we want to delete.
        2. Replace the deepest rightmost node’s data with node to be deleted.
        3. Then delete the deepest rightmost node.

    Note:
        We can also replace node’s data that is to be deleted with any node whose
        left and right child points to NULL but we only use deepest node in order to maintain
        the balance of a binary tree.
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

void inOrder(struct Node* temp) {
    if (!temp)
        return;
    inOrder(temp->left);
    cout << temp->data << " ";
    inOrder(temp->right);
}

// Main Logic
void deleteDeepest (Node* root, Node* delete_node) {
    queue <Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        if (current == delete_node) {
            current = NULL;
            delete (delete_node);
            return;
        }

        if (current->right)
            if (current->right == delete_node) {
                current->right = NULL;
                delete (delete_node);
                return;
            }
            else
                q.push(current->right);

        if (current->left)
            if (current->left == delete_node) {
                current->left = NULL;
                delete (delete_node);
                return;
            }
            else
                q.push(current->left);
    }
}

void deletion (Node* root, int key) {
    queue<struct Node*> q;
    q.push(root);

    struct Node *current;
    struct Node *key_node = NULL;

    // Do level order traversal to find deepest
    // node(temp) and node to be deleted (key_node)
    while (!q.empty()) {
        current = q.front();
        q.pop();

        if (current->data == key)
            key_node = current;

        if (current->left)
            q.push(current->left);

        if (current->right)
            q.push(current->right);
    }

    int x = current->data;
    deleteDeepest(root, current);
    key_node->data = x;
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

    cout << "Inorder traversal before deletion : ";
    inOrder(root);

    int key = 11;
    deletion(root, key);

    cout << endl;
    cout << "Inorder traversal after deletion : ";
    inOrder(root);

    return 0;
}