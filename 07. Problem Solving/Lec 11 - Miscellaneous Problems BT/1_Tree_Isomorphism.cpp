/*
Write a function to detect if two trees are isomorphic. Two trees are called
isomorphic if one of them can be obtained from other by a series of flips,
i.e. by swapping left and right children of a number of nodes. Any number of
nodes at any level can have their children swapped. Two empty trees are
isomorphic.

For example, following two trees are isomorphic with following sub-trees flipped:
2 and 3, NULL and 6, 7 and 8.

                1                                   1
               / \                                 / \
              2   3                               3   2
            /  \  /                               \  /  \
           4   5  6                               6 4    5
              / \                                       / \
             7   8                                     8   7

APPROACH:
We simultaneously traverse both trees. Let the current internal nodes of two
trees being traversed be n1 and n2 respectively. There are following two
conditions for subtrees rooted with n1 and n2 to be isomorphic.

1) Data of n1 and n2 is same.
2) One of the following two is true for children of n1 and n2
……a) Left child of n1 is isomorphic to left child of n2 and right child of n1
     is isomorphic to right child of n2.
……b) Left child of n1 is isomorphic to right child of n2 and right child of n1
     is isomorphic to left child of n2.
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

/* Given a binary tree, print its nodes in reverse level order */
bool isIsomorphic(Node* n1, Node *n2) {
    // Both roots are NULL, trees isomorphic by definition
    if (n1 == NULL && n2 == NULL)
        return true;

    // Exactly one of the n1 and n2 is NULL, trees not isomorphic
    if (n1 == NULL || n2 == NULL)
        return false;

    if (n1->data != n2->data)
        return false;

    // There are two possible cases for n1 and n2 to be isomorphic
    // Case 1: The subtrees rooted at these nodes have NOT been "Flipped".
    // Both of these subtrees have to be isomorphic, hence the &&
    // Case 2: The subtrees rooted at these nodes have been "Flipped"
    return
    (isIsomorphic(n1->left,n2->left) && isIsomorphic(n1->right,n2->right)) || \
    (isIsomorphic(n1->left,n2->right) && isIsomorphic(n1->right,n2->left));
}

/* ---------------- MAIN DRIVER CODE ------------- */
int main() {
    // Let us create trees shown in above diagram
    struct Node *n1 = new Node(1);
    n1->left = new Node(2);
    n1->right = new Node(3);
    n1->left->left = new Node(4);
    n1->left->right = new Node(5);
    n1->right->left = new Node(6);
    n1->left->right->left = new Node(7);
    n1->left->right->right = new Node(8);

    struct Node *n2 = new Node(1);
    n2->left = new Node(3);
    n2->right = new Node(2);
    n2->right->left = new Node(4);
    n2->right->right = new Node(5);
    n2->left->right = new Node(6);
    n2->right->right->left = new Node(8);
    n2->right->right->right = new Node(7);

    if (isIsomorphic(n1, n2) == true)
        cout << "Yes";
    else
        cout << "No";

    return 0;
}
