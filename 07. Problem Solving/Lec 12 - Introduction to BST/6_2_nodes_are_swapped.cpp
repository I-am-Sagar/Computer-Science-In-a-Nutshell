/*  PROBLEM:
    Since inorder traversal of BST is always a sorted array,
    the problem can be reduced to a problem where two elements
    of a sorted array are swapped. There are two cases that we
    need to handle:

    1. The swapped nodes are not adjacent in the inorder
       traversal of the BST.

    For example, Nodes 5 and 25 are swapped in 3 5 7 8 10 15 20 25.
    The inorder traversal of the given tree is 3 25 7 8 10 15 20 5.

    If we observe carefully, during inorder traversal, we find node
    7 is smaller than the previous visited node 25. Here save node 25
    (previous node). Again, we find that node 5 is smaller than the
    previous node 20. This time, we save node 5 (current node).
    Finally swap the two node’s values.

    2. The swapped nodes are adjacent in the inorder traversal of BST.

    For example, Nodes 7 and 8 are swapped in 3 5 7 8 10 15 20 25.
    The inorder traversal of the given tree is 3 5 8 7 10 15 20 25.

    We will maintain three pointers, first, middle and last.
    When we find the first point where current node value is smaller
    than previous node value, we update the first with the previous
    node & middle with the current node. When we find the second point
    where current node value is smaller than previous node value,
    we update the last with the current node.

    In case 2, we will never find the second point. So, last pointer
    will not be updated. After processing, if the last node value is null,
    then two swapped nodes of BST are adjacent.

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

// Auxiliary Functions
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void printInorder(Node* root){
    if (root == NULL)
        return;
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

// Main Logic
void correctBSTUtil(Node* root, Node** first, Node** middle, Node** last, Node** prev ) {
    if(root) {
        correctBSTUtil( root->left, first, middle, last, prev );

        if (*prev && root->data < (*prev)->data) {
            if ( !*first ) {
                *first = *prev;
                *middle = root;
            }
            else
                *last = root;
        }
        *prev = root;

        correctBSTUtil( root->right, first, middle, last, prev );
    }
}

void correctBST(Node* root) {
    Node *first, *middle, *last, *prev;
    first = middle = last = prev = NULL;

    correctBSTUtil( root, &first, &middle, &last, &prev);

    if(first && last)
        swap( &(first->data), &(last->data) );
    else if(first && middle)
        swap( &(first->data), &(middle->data) );
}

/* ------------------ MAIN DRIVER CODE ----------------- */
int main() {
    Node *root = new Node(6);
    root->left        = new Node(10);
    root->right       = new Node(2);
    root->left->left  = new Node(1);
    root->left->right = new Node(3);
    root->right->right = new Node(12);
    root->right->left = new Node(7);

    printf("Inorder Traversal of the original tree: \n");
    printInorder(root);

    correctBST(root);

    printf("\nInorder Traversal of the fixed tree: \n");
    printInorder(root);
    cout << endl;

    return 0;
}