/*  PROBLEM:
    Given a BT, write a function that returns the size of
    the largest subtree which is also a BST. If the complete
    BT is BST, then return the size of the whole tree.

    SOLUTION:
    The idea of solution is somewhat similar to previous
    question.

    A Tree is BST if following is true for every node x:
    a) The largest value in left subtree (of x) is
       smaller than value of x.
    b) The smallest value in right subtree (of x) is
       greater than value of x.

    We traverse tree in bottom up manner. For every traversed node,
    we return maximum and minimum values in subtree rooted with it.
    If any node follows above properties, return the size of subtree
    rooted at this node.

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

struct Info {
    int size;   // size of subtree
    int max;    // max value of subtree
    int min;    // min value of subtree
    int ans;    // size of largest BST
    bool isBST; // If subtree is BST
};

// Main logic, which returns the Information
// about the size of largest subtree which is BST
Info largestBST (Node* root) {
    // if the tree is empty or has lone node
    if (root == NULL)
        return {0, INT_MIN, INT_MAX, 0, true};
    if (root->left == NULL && root->right == NULL)
        return {1, root->data, root->data, 1, true};

    // Recurr for left and right subtrees
    Info l = largestBST(root->left);
    Info r = largestBST(root->right);

    // Create a return variable
    Info ret;
    ret.size = 1 + l.size + r.size;

    // If whole tree rooted under current node is BST
    if (l.isBST && r.isBST && l.max < root->data && r.min > root->data) {
        ret.min = min (l.min, min(r.min, root->data));
        ret.max = max (r.max, max(l.max, root->data));

        // Update answer for tree rooted under current node 'root'
        ret.ans = ret.size;
        ret.isBST = true;
    }
    // If whole tree is not BST, return maximum of left and right subtrees
    ret.ans = max(l.ans, r.ans);
    ret.isBST = false;

    return ret;
}

/* --------------- MAIN DRIVER CODE -------------- */
int main() {
    Node *root = new Node(60);
    root->left = new Node(65);
    root->right = new Node(70);
    root->left->left = new Node(50);
    printf("Size of the largest BST is %d\n", largestBST(root).ans);
    return 0;
}
