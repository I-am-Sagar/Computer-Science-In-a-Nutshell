/*
Factor Tree is an intuitive method to understand the factors of a number.
It shows how all the factors are been derived from the number. It is a special
diagram where you find the factors of a number, then the factors of those
numbers, etc until you can’t factor anymore. The ends are all the prime factors
of the original number.

Input : v = 48
Output : Root of below tree
   48
   /\
  2  24
     /\
    2  12
       /\
      2  6
         /\
        2  3

The factor tree is created recursively as follows:

1. We start with a number and find the minimum divisor possible.
2. Then, we divide the parent number by the minimum divisor.
3. We store both the divisor and quotient as two children of the parent number.
4. Both the children are sent into function recursively.
5. If a divisor less than half the number is not found, two children are stored
   as NULL.

*/

#include<bits/stdc++.h>
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

// Constructs factor tree for given value and stores
// root of tree at given reference.
void createFactorTree(struct Node **node_ref, int v) {
    (*node_ref) = new Node(v);
    // the number is factorized
    for (int i = 2 ; i < v/2 ; i++) {
        if (v % i != 0)
            continue;
        // If we found a factor, we construct left and right subtrees
        // and return. Since we traverse factors starting from smaller
        // to greater, left child will always have smaller factor
        createFactorTree(&((*node_ref)->left), i);
        createFactorTree(&((*node_ref)->right), v/i);
        return;
    }
}

// Iterative method to find the height of Binary Tree
void printLevelOrder(Node *root) {
    // Base Case
    if (root == NULL)
        return;

    queue <Node*> q;
    q.push(root);

    while (q.empty() == false) {
        // Print front of queue and remove it from queue
        Node *node = q.front();
        cout << node->data << " ";
        q.pop();
        if (node->left != NULL)
            q.push(node->left);
        if (node->right != NULL)
            q.push(node->right);
    }
}

/* ---------------- MAIN DRIVER CODE ------------- */
int main() {
    int val = 48;
    struct Node *root = NULL;
    createFactorTree(&root, val);
    cout << "Level order traversal of constructed factor tree: ";
    printLevelOrder(root);
    return 0;
}
