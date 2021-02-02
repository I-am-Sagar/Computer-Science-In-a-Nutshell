/*  PROBLEM:
    Given a BT, print the corner nodes at each level.
    The node at the leftmost and the node at the rightmost.

    For example, for given tree:
                1
               / \
              2   3
            /  \ /  \
           7   6 5   4

    Output: 1 2 3 7 4

    SOLUTION:

    Approach 1:
    A Simple Solution is to do two traversals using the approaches
    discussed in the earlier question for printing left view and
    right view.

    Approach 2:
    The idea is to use Level Order Traversal. Every time we store
    the size of the queue in a variable n, which is the number of
    nodes at that level. For every level we check three conditions,
    whether there is one node or more than one node, in case there
    is only one node we print it once and in case we have more than
    1 nodes, we print the first (i.e node at index 0) and the node
    at last index (i.e node at index n-1).
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

// Main Logic of Code
void printCorner (Node* root) {
    if (root == NULL)   return;

    queue<Node*> q;
    q.push(root);
    vector<int> result; //This will store answer
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; i++) {
            Node* temp = q.front();
            q.pop();
            // leftmost corner value
            if (i == 0)
                result.push_back(temp->data);
            // rightmost corner value
            else if (i == n-1)
                result.push_back(temp->data);

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
    for (auto i : result)
        cout << i << " ";
}

/* ---------------- MAIN DRIVER CODE ----------------- */
int main () {
    Node *root =  new Node(15);
    root->left = new Node(10);
    root->right = new Node(20);
    root->left->left = new Node(8);
    root->left->right = new Node(12);
    root->right->left = new Node(16);
    root->right->right = new Node(25);
    printCorner(root);
    return 0;
}