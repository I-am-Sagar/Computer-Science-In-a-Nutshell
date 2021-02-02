/*  We know that we cannot construct a unique BT from
    only its pre and post order traversals. We need some
    additional information. One such additional information
    could be - the type of BT.

    PROBLEM:
    Given two arrays that represent preorder and postorder
    traversals of a full binary tree, construct the binary tree.
    Remember a Full Binary Tree is a binary tree where every
    node has either 0 or 2 children.

    SOLUTION:
    Let us consider the two given arrays as
    pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7} and
    post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};

    In pre[], the leftmost element is root of tree. Since the tree
    is full and array size is more than 1. The value next to 1 in
    pre[], must be left child of root. So we know 1 is root and 2
    is left child. How to find the all nodes in left subtree?

    We know 2 is root of all nodes in left subtree. All nodes before
    2 in post[] must be in left subtree. Now we know 1 is root,
    elements {8, 9, 4, 5, 2} are in left subtree, and the
    elements {6, 7, 3} are in right subtree.

                      1
                    /   \
    {8, 9, 4, 5, 2}     {6, 7, 3}

    We recursively follow the above approach and get the following tree.

                  1
                /   \
               2     3
             /  \   /  \
            4    5 6    7
           / \
          8   9
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

// Auxiliary Function
void printInorder (Node* node)  {
    if (node == NULL)
        return;
    printInorder(node->left);
    cout<<node->data<<" ";
    printInorder(node->right);
}

// Main Logic
Node* constructTreeUtil (int pre[], int post[], int* preIndex, int l, int h, int size) {
    if (*preIndex >= size || l > h)  return NULL;

    // first node in preorder traversal is root. So take the
    // node at preIndex from preorder, make it root and
    // increment preIndex
    Node* root = new Node(pre[*preIndex]);
    (*preIndex)++;

    // If the current subarray has only 1 element left, no need to recurr
    if (l == h) return root;

    // Search the next element of pre[] in post[]
    int i;
    for (i = l; i <= h; ++i)
        if (pre[*preIndex] == post[i])
            break;

    // Use the index of element found in postOrder to divide postOrder
    // array in two parts - left and right subtree
    if (i <= h) {
        root->left = constructTreeUtil(pre, post, preIndex, l, i, size);
        root->right = constructTreeUtil(pre, post, preIndex, i+1, h, size);
    }
    return root;
}

Node* constructTree (int pre[], int post[], int size) {
    int preIndex = 0;
    return constructTreeUtil(pre, post, &preIndex, 0, size-1, size);
}

/* --------------------- MAIN DRIVER CODE -------------------- */
int main () {
    int pre[] = {1, 2, 4, 8, 9, 5, 3, 6, 7};
    int post[] = {8, 9, 4, 5, 2, 6, 7, 3, 1};
    int size = sizeof( pre ) / sizeof( pre[0] );

    Node *root = constructTree(pre, post, size);

    cout << "Inorder traversal of the constructed tree: \n";
    printInorder(root);

    return 0;
}

/*  ADDITIONAL POINT:
    Given two arrays that represent Preorder traversals of a
    full binary tree and its mirror tree, we need to write a
    program to construct the binary tree using these two Preorder
    traversals.

    Input : preOrder[] = {1,2,4,5,3,6,7}
            preOrderMirror[] = {1,3,7,6,2,5,4}

    Output :          1
                    /    \
                   2      3
                 /   \   /  \
                4     5 6    7


    SOLUTION:
    Notice carefully, the reverese of the preorder traversal of the
    mirror tree is the postorder traversal of original tree.

    We can now construct the tree from preorder and postorder traversals
    as above.
*/