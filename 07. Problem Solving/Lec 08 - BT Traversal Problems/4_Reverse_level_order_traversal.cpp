/*  PROBLEM:
    Write a function to print reverse level order traversal of a tree.

    For example, for given tree:
                1
               / \
              2   3
            /  \ /  \
           7   6 5   4

    Output: 7 6 5 4 2 3 1

    SOLUTION:

    Approach 1 - Recursive Method
    We have a method printGivenLevel() which prints a given level number.
    The only thing we need to change is, instead of calling printGivenLevel()
    from first level to last level, we call it from last level to first level.

    Approach 2 - Iterative Method
    The idea is to use a stack to get the reverse level order. If we do normal
    level order traversal and instead of printing a node, push the node to a
    stack and then print contents of stack, we get “4 5 6 7 3 2 1” for
    above example tree, but output should be “7 6 5 4 2 3 1”. So to get the
    correct sequence (left to right at every level), we process children of
    a node in reverse order, we first push the right subtree to stack,
    then left subtree.
*/

#include <bits/stdc++.h>
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

// Auxiliary Functions
int height (Node* root) {
    if (root == NULL)   return 0;
    return (max(height(root->left), height(root->right)) + 1);
}

void printGivenLevel (Node* root, int level) {
    if (root == NULL)   return;
    if (level == 1)
        cout << root->data << " ";
    printGivenLevel(root->left, level-1);
    printGivenLevel(root->right, level-1);
}

// Recursive Function
void reverseLevelOrderRec(Node* root) {
    int h = height(root);
    //THE ONLY LINE DIFFERENT FROM NORMAL LEVEL ORDER
    for (int i=h; i>=1; i--)
        printGivenLevel(root, i);
    cout << endl;
}

// Iterative Function
void reverseLevelOrderItr(Node* root) {
    if (root == NULL)   return;

    // Following are the differences with normal level order traversal:
    // 1) Instead of printing a node, we push the node to stack
    // 2) Right subtree is visited before left subtree
    stack <Node*> s;
    queue <Node*> q;
    q.push(root);
    while (!q.empty()) {
        root = q.front();
        q.pop();
        s.push(root);

        if (root->right) q.push(root->right);
        if (root->left) q.push(root->left);
    }

    while (!s.empty()) {
        root = s.top();
        cout << root->data << " ";
        s.pop();
    }
    cout << endl;
}

/* ---------------- MAIN DRIVER CODE --------------- */
int main() {
    Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
    root->right->left  = new Node(6);
    root->right->right = new Node(7);

    cout << "Level Order traversal:\n";
    reverseLevelOrderRec(root);
    reverseLevelOrderItr(root);

    return 0;
}