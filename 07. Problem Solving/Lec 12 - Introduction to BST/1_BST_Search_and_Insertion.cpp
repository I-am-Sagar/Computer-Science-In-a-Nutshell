/*
    Binary Search Tree (BST) is a BT which has the
    following properties:

    1. The left subtree of a node contains only nodes with
       keys lesser than the node’s key.
    2. The right subtree of a node contains only nodes with
       keys greater than the node’s key.
    3. The left and right subtree each must also be a BST.
    4. There are no duplicate nodes.

    Searching a key in BST:
    To search a given key in Binary Search Tree, we first
    compare it with root, if the key is present at root,
    we return root. If key is greater than root’s key,
    we recur for right subtree of root node. Otherwise
    we recur for left subtree.

    Inserting a key in BST:
    A new key is always inserted at leaf. We start searching
    a key from root till we hit a leaf node. Once a leaf node
    is found, the new node is added as a child of the leaf node.

         100                               100
        /   \        Insert 40            /   \
      20     500    --------->          20     500
     /  \                              /  \
    10   30                           10   30
                                              \
                                              40
    Time Complexity:
    The worst case time complexity of search and insert operations is O(h)
    where h is height of Binary Search Tree. In worst case, we may have
    to travel from root to the deepest leaf node. The height of a skewed
    tree may become n and the time complexity may become O(n).
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};

// A utility function to do inorder traversal of BST
void inorder (Node* root) {
    if (root == NULL)	return;
    inorder (root->left);
    cout << root->data << " ";
    inorder (root->right);
}

// Logic to search a key in BST
Node* search (Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (root->data < key)
        return search(root->right, key);
    else
        return search(root->left, key);
}

// Logic to insert a key in BST
Node* insert (Node* root, int key) {
    // If tree is empty, make a new node and return
    if (root == NULL) {
        Node* temp = new Node(key);
        return temp;
    }
    // Otherwise recurr down for the subtrees
    if (root->data < key)
        root->right = insert (root->right, key);
    else
        root->left = insert(root->left, key);

    return root;
}

/* -------------------- MAIN DRIVER CODE --------------- */
int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    inorder(root);
    cout << endl;

    Node* ptr = search(root, 40);
    if (ptr != NULL)
        cout << "Key is present.\n";
    else
        cout << "Key is not present.\n";

    return 0;
}

/*	ADDITIONAL POINT:

    It is always better to go for Iterative approach if
    we don't get any performance improvements in using
    recursion. Here is an iterative search function for BST:

    bool iterativeSearch(struct Node* root, int key) {
        while (root != NULL) {

            if (key > root->data)
                root = root->right;
            else if (key < root->data)
                root = root->left;
            else
                return true;
        }
        return false;
    }

    Here is an iterative insert function for BST:

    void insertNode(Node* root, int x) {
        Node *p = root, *q = NULL;

        while (p != NULL) {
            q = p;
            if (p -> data < x)
                p = p -> right;
            else
                p = p -> left;
        }

        if (q == NULL)
            p = new Node(x);
        else {
            if (q -> data < x)
                q -> right = new Node(x);
            else
                q -> left = new Node(x);
        }
    }
*/
