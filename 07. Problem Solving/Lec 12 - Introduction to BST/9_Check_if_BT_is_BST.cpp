/*  PROBLEM:
    Given a BT, check if it's a BST or not.

    SOLUTION:

    The first idea that comes to mind is - to write a
    recursive function which checks if the left node
    is smaller than the current node and right node is
    greater. If yes return true, else return false.

    However this approach is wrong as above approach
    will give true for the following BT which is not
    a BST because '4' lies in the left subtree of '3'.

                3
              /   \
             2     5
            / \
           1   4

    The correct idea is - look each node only once.


        isBST (Node* root, Node* left, Node* right);

    that traverses down the tree keeping track of
    the narrowing min and max allowed values as
    it goes down. Finally compare max and min
    with the root.

    Time Complexity: O(n)
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

// Main Logic
bool isBST (Node* root, Node* l = NULL, Node* r = NULL) {
    if (root == NULL)   return true;

    if (l != NULL and root->data <= l->data)
        return false;

    if (r != NULL and root->data >= r->data)
        return false;

    return isBST(root->left, l, root) && isBST(root->right, root, r);
}

/* ------------ MAIN DRIVER CODE ----------- */
int main() {
    Node *root = new Node(3);
    root->left        = new Node(2);
    root->right       = new Node(5);
    root->left->left  = new Node(1);
    root->left->right = new Node(4);

    if (isBST(root,NULL,NULL))
        cout << "Is BST\n";
    else
        cout << "Not a BST\n";

    return 0;
}
