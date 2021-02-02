/*  PROBLEM:
    Given Inorder and Preorder traversals of a binary tree,
    print Postorder traversal.

    Example:

    Input:
    Inorder traversal in[] = {4, 2, 5, 1, 3, 6}
    Preorder traversal pre[] = {1, 2, 4, 5, 3, 6}

    Output:
    Postorder traversal is {4, 5, 2, 6, 3, 1}

    SOLUTION:
    When given two traversals (one of which is Inorder),
    we can find the third traversal without actually creating
    the tree.

    The idea is, root is always the first term in preorder and
    must be last in postorder traversal.
    Now to find boundaries of left and right subtrees in pre[]
    and in[], we search root in in[]. All elements before root
    belong to left subtree and all elements after root belong
    to right subtree.
    We will now use above properties recursively on subtrees.
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left, *right;
        Node (int data) {
            this->data = data;
            this->left = this->right = NULL;
        }
};

// Utility function to search x in arr[]
int search (int arr[], int x, int n) {
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}

// Main Logic
void printPostOrder (int in[], int pre[], int n) {
    // First element in pre is root, search it in in[]
    int root = search(in, pre[0], n);
    // If left subtree is not empty, print left subtree
    if (root != 0)
        printPostOrder(in, pre+1, root);
    // If right subtree is not empty, print right subtree
    if (root != n-1)
        printPostOrder(in+root+1, pre+root+1, n-root-1);
    // Print root
    cout << pre[0] << " ";
}

/* --------------- MAIN DRIVER CODE ---------------- */
int main() {
    int in[] = { 4, 2, 5, 1, 3, 6 };
    int pre[] = { 1, 2, 4, 5, 3, 6 };
    int n = sizeof(in) / sizeof(in[0]);
    cout << "Postorder traversal: " << endl;
    printPostOrder(in, pre, n);
    cout << endl;
    return 0;
}