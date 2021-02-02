/*  PROBLEM:
    Given the binary Tree and the two nodes say ‘a’ and ‘b’,
    determine whether the two nodes are cousins of each other
    or not.
    Two nodes are cousins of each other if they are at same
    level and have different parents.

    SOLUTION:
    The idea is to find level of one of the nodes. Using the
    found level, check if ‘a’ and ‘b’ are at this level.
    If ‘a’ and ‘b’ are at given level, then finally check
    if they are not children of same parent.
*/

#include <bits/stdc++.h>
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

// Recursive function to check if two Nodes are siblings
int isSibling(Node *root, Node *a, Node *b) {
    if (root==NULL)  return 0;
    return ((root->left==a && root->right==b)|| (root->left==b && root->right==a)|| \
        isSibling(root->left, a, b)|| isSibling(root->right, a, b));
}

// Recursive function to find level of Node 'ptr' in a binary tree
int level(Node *root, Node *ptr, int lev) {
    if (root == NULL) return 0;
    if (root == ptr)  return lev;

    // Return level if Node is present in left subtree
    int l = level(root->left, ptr, lev+1);
    if (l != 0)  return l;
    // Else search in right subtree
    return level(root->right, ptr, lev+1);
}

// Returns 1 if a and b are cousins, otherwise 0
int isCousin( Node *root, Node *a, Node *b) {
    //1. The two Nodes should be on the same level in the binary tree.
    //2. The two Nodes should not be siblings (means that they should
    // not have the same parent Node).
    if ((level(root,a,1) == level(root,b,1)) && !(isSibling(root,a,b)))
        return 1;
    else return 0;
}

/* --------------- MAIN DRIVER CODE ------------- */
int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(15);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);

    Node *Node1,*Node2;
    Node1 = root->left->left;
    Node2 = root->right->right;

    isCousin(root,Node1,Node2)? printf("Yes\n"): printf("No\n");

    return 0;
}
