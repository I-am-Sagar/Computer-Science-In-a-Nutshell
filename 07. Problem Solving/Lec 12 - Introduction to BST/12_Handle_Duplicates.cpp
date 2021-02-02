/*  In a BST, all keys in left subtree of a key must be
    smaller and all keys in right subtree must be greater.
    So a BST by definition has distinct keys.

    How to allow duplicates where every insertion inserts
    one more key with a value and every deletion deletes
    one occurrence?

    The idea is to augment every tree node to store count
    together with regular fields like key, left and right
    pointers. Insertion of keys 12, 10, 20, 9, 11, 10, 12, 12
    in an empty BST would create following:

              12(3)
           /        \
        10(2)      20(1)
       /    \
    9(1)   11(1)

    This approach has following advantages over above simple approach.

    1) Height of tree is small irrespective of number of duplicates.
       Note that most of the BST operations (search, insert and delete)
       have time complexity as O(h) where h is height of BST.
       So if we are able to keep the height small, we get advantage
       of less number of key comparisons.

    2) Search, Insert and Delete become easier to do. We can use same
       insert, search and delete algorithms with small modifications.
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int key;
    int count;
    Node *left, *right;
    Node (int x) {
        this->count = 1;
        this->key = x;
        this->left = this->right = NULL;
    }
};

void inorder(Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d(%d) ", root->key, root->count);
        inorder(root->right);
    }
}

Node* insert(Node* root, int key) {
    if (root == NULL) {
        Node* temp = new Node(key);
        return temp;
    }

    if (key == root->key) {
        (root->count)++;
        return root;
    }

    if (key < root->key)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);

    return root;
}

Node* minValueNode(Node* root) {
    Node* current = root;
    while (current->left != NULL)
        current = current->left;
    return current;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)   return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else {
        if (root->count > 1) {
            (root->count)--;
            return root;
        }

        if (root->left == NULL) {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            struct Node *temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

/* ----------------- MAIN DRIVER CODE ----------------- */
int main() {
    Node *root = NULL;
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 9);
    root = insert(root, 11);
    root = insert(root, 10);
    root = insert(root, 12);
    root = insert(root, 12);

    printf("Inorder traversal of the given tree \n");
    inorder(root);

    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 12\n");
    root = deleteNode(root, 12);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 9\n");
    root = deleteNode(root, 9);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    return 0;
}
