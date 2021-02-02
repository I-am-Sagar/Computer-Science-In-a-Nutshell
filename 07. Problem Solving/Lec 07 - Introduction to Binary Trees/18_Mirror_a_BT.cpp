//Video Link: https://www.youtube.com/watch?v=FtdyIHBaKjc

/* PROBLEM: Convert a BT into its mirror BT. */

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

void inOrder(struct Node* node) {
    if (node == NULL)
        return;
    inOrder(node->left);
    cout << node->data << " ";
    inOrder(node->right);
}

/* -------------------- MIRROR A BT ----------------------- */
void mirrorRec (Node* root) {
    if (root == NULL)   return;
    else {
        Node* temp;
        mirrorRec(root->left);
        mirrorRec(root->right);

        // Swap the pointers
        temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}

void mirrorItr (Node* root) {
    if (root == NULL)   return;

    queue<Node*> q;
    q.push(root);

    // Do BFS(level order), and while doing so, swap left and right children
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        swap(current->left, current->right);

        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

/* ---------------- MAIN DRIVER CODE ---------------- */
int main() {
    struct Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);

    cout << "Inorder traversal of the constructed tree is: \n";
    inOrder(root);
    cout << endl;

    mirrorRec(root);

    cout << "Inorder traversal of the mirror tree is: \n";
    inOrder(root);
    cout << endl;

    mirrorItr(root);

    cout << "Inorder traversal of the original tree is: \n";
    inOrder(root);
    cout << endl;

    return 0;
}