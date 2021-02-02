// Video Link: https://www.youtube.com/watch?v=ka0tlCl7hwI

/* PROBLEM: Check if two binary trees are:
    a) Equal, when they are identical
    b) Similar, when they have same structure (irrespective of data)
    c) None of the above two options
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

/* ------------------- IDENTICAL BINARY TREES ------------------ */
bool isIdentical (Node* a, Node* b) {
    // Check if both trees are empty
    if (a == NULL && b == NULL)
        return true;

    // If both are not empty and their data is equal, compare left and right
    if (a!=NULL && b!=NULL && a->data == b->data)
     return isIdentical(a->left, b->left) && isIdentical(a->right, a->right);

    // If we reached here, means one child is empty in one tree and not in other
    return false;
}

/* -------------------- SIMILAR BINARY TREES ------------------ */
bool isSimilar (Node* a, Node* b) {
    // If both are empty
    if (a == NULL && b == NULL)
        return true;

    // If both are not empty, compare left and right
    if (a!=NULL && b!=NULL)
        return isSimilar(a->left, b->left) && isSimilar(a->right, b->right);

    // If we reached here, means one child is empty in one tree and not in other
    return false;
}

/* ---------------- MAIN DRIVER CODE ---------------- */
int main() {
    struct Node* root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(8);
    root1->left->left = new Node(2);
    root1->left->right = new Node(4);

    struct Node* root2 = new Node(5);
    root2->left = new Node(3);
    root2->right = new Node(8);
    root2->left->left = new Node(2);
    root2->left->right = new Node(4);

    if (isIdentical(root1, root2))
        cout << "Both BTs are identical\n";
    else if (isSimilar(root1, root2))
        cout << "Both BTs are similar\n";
    else
        cout << "Both BTs are different\n";

    return 0;
}