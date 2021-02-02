// Video Link: https://www.youtube.com/watch?v=ZcqJ6cSKho0

/* EXPLANATION:

    To convert an inherently recursive procedures to iterative, we need an explicit stack.
    Following is a simple stack based iterative process to print Preorder traversal.
    1) Create an empty stack s and push root node to stack.
    2) Do following while s is not empty.
        a) Pop an item from stack and print it.
        b) Push right child of popped item to stack
        c) Push left child of popped item to stack

    Right child is pushed before left child to make sure that left subtree is processed
    first.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node (int data) {
        this->data = data;
        left = right = NULL;
    }
};

// Main Logic
void preOrder (Node* root) {
    if (root == NULL)   return;

    stack <Node*> s;
    s.push(root);

    while (!s.empty()) {
        Node* current = s.top();
        cout << current->data << " ";
        s.pop();

        if (current->right)
            s.push(current->right);
        if (current->left)
            s.push(current->left);
    }
}

/* ---------------- MAIN DRIVER CODE ---------------- */
int main()
{
    /* Binary Tree constructed is:
            10
          /   \
        8      2
      /  \    /
    3     5  2
  */
  Node *root = new Node(10);
  root->left        = new Node(8);
  root->right       = new Node(2);
  root->left->left  = new Node(3);
  root->left->right = new Node(5);
  root->right->left = new Node(2);
  preOrder(root);
  return 0;
}