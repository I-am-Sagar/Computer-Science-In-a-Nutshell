/*  PROBLEM:
    Given a binary tree and a number, return true if the tree
    has a root-to-leaf path such that adding up all the values
    along the path equals the given number and return false if
    no such path is found.

    APPROACH:
    Recursively check if left or right child has path sum equal
    to (number – value at current node).
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

// Main Logic
bool hasPath (Node* root, int sum) {
    if (root == NULL)   return (sum==0);

    bool ans = false;
    int subSum = sum - root->data;

    if (subSum == 0 && root->left == NULL && root->right == NULL)
        return true;

    if (root->left)
        ans = ans || hasPath(root->left, subSum);
    if (root->right)
        ans = ans || hasPath(root->right, subSum);

    return ans;
}

/* -------------- MAIN DRIVER CODE --------------- */
int main() {
    int sum = 21;

    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(2);

    if(hasPath(root, sum))
        cout << "There is a root-to-leaf path with sum " << sum << endl;
    else
        cout << "There is no root-to-leaf path with sum " << sum << endl;

    return 0;
}