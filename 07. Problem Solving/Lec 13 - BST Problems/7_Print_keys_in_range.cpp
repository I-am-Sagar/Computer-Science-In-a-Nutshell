/*  PROBLEM:
    Given two values k1 and k2 (where k1 < k2) and a root
    pointer to a Binary Search Tree. Print all the keys of
    tree in range k1 to k2. i.e. print all x such that
    k1<=x<=k2 and x is a key of given BST.

    SOLUTION:

    Approach 1: Using Inorder Traversal
    1) If value of root’s key is greater than k1, then
       recursively call in left subtree.
    2) If value of root’s key is in range, then print
       the root’s key.
    3) If value of root’s key is smaller than k2, then
       recursively call in right subtree.
    Time Complexity: O(n)
    Space Complexity: O(n)

    Approach 2: Using Morris Inorder Traversal
    The logic remains the same as above. Only the
    space complexity will improve to O(1).

    We have implemented Morris Inorder solution below.
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;
    Node(int x) {
        this->data = x;
        this->left = this->right = NULL;
    }
};

// Auxiliary Function
Node* insert(struct Node* node, int key) {
    if (node == NULL) {
        Node* temp = new Node(key);
        return temp;
    };

    if (key < node->data)
        node->left  = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);

    return node;
}

// Main logic
void rangeTraversal (Node* root, int n1, int n2) {
    if (!root)  return;

    Node* curr = root;
    while (curr != NULL) {
        if (curr->left == NULL) {
            if (curr->data <= n2 && curr->data >= n1)
                cout << curr->data << " ";
            curr = curr->right;
        }
        else {
            Node* pre = curr->left;
            while (pre->right != NULL && pre->right != curr)
                pre = pre->right;
            if (pre->right == NULL) {
                pre->right = curr;
                curr = curr->left;
            }
            else {
                pre->right = NULL;
                if (curr->data <= n2 && curr->data >= n1)
                    cout << curr->data << " ";
                curr = curr->right;
            }
        }
    }
}

/* ------------------ MAIN DRIVER CODE ----------------- */
int main() {
    Node* root = NULL;
    root = insert (root, 4);
    insert (root, 2);
    insert (root, 7);
    insert (root, 1);
    insert (root, 3);
    insert (root, 6);
    insert (root, 10);

    rangeTraversal(root, 4, 9);
    cout << endl;
    return 0;
}