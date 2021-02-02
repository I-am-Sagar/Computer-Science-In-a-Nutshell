/*  PROBLEM:
    Given values of two values n1 and n2 in a BST, find LCA.
    You may assume that both the values exist in the tree.

    SOLUTION:
    The main idea of the solution is, while traversing from
    top to bottom, the first node n we encounter with value
    between n1 and n2, i.e., n1 < n < n2 or same as one of
    the n1 or n2, is LCA of n1 and n2 (assuming that n1 < n2).

    So just recursively traverse the BST in, if node’s value
    is greater than both n1 and n2 then our LCA lies in left
    side of the node, if it’s is smaller than both n1 and n2,
    then LCA lies on right side. Otherwise root is LCA
    (assuming that both n1 and n2 are present in BST).
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
Node* lca (Node* root, int n1, int n2) {
    if (root == NULL) return NULL;

    if (root->data > n1 && root->data > n2)
        return lca(root->left, n1, n2);

    if (root->data < n1 && root->data < n2)
        return lca(root->right, n1, n2);

    return root;
}

/* -------------------- MAIN DRIVER CODE ------------------ */
int main() {
    Node *root               = new Node(20);
    root->left               = new Node(8);
    root->right              = new Node(22);
    root->left->left         = new Node(4);
    root->left->right        = new Node(12);
    root->left->right->left  = new Node(10);
    root->left->right->right = new Node(14);

    int n1 = 10, n2 = 14;
    Node *t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d.\n", n1, n2, t->data);

    n1 = 14, n2 = 8;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d.\n", n1, n2, t->data);

    n1 = 10, n2 = 22;
    t = lca(root, n1, n2);
    printf("LCA of %d and %d is %d \n", n1, n2, t->data);

    return 0;
}

/*  ADDITIONAL POINT:

    The above solution requires O(h) extra space in function
    call stack for recursive function calls. We can avoid
    extra space using iterative solution.

    Node* lca(Node* root, int n1, int n2) {
        while (root != NULL) {
            if (root->data > n1 && root->data > n2)
                root = root->left;
            else if (root->data < n1 && root->data < n2)
                root = root->right;
            else
                break;
        }
        return root;
    }
*/