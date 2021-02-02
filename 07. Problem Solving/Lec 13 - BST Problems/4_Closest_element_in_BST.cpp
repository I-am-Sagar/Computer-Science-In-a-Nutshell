/*  PROBLEM:
    Given a BST and a target node K. The task is to find the
    node with minimum absolute difference with given target
    value K.

    SOLUTION:
    A simple solution for this problem is to do inorder
    traversal of BST and find the node with the minimum
    absolute difference.
    Time complexity: O(n)

    An efficient solution for this problem is to take
    advantage of characteristics of BST.
    Here is the algorithm to solve this problem :

    a) If target value K is present in given BST, then it’s
       the node having minimum absolute difference.
    b) If target value K is less than the value of current
       node then move to the left child.
    c) If target value K is greater than the value of
       current node then move to the right child.

    Time Complexity: O(h)
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;
    Node(int x) {
        this->data = x;
        this->left = this->right = NULL;
    }
};

// Auxiliary Function
Node* insert(struct Node* node, int key) {
    if (node == NULL) {
        Node* temp = new Node(key);
        return temp;
    };

    if (key < node->data)
        node->left  = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);

    return node;
}

// Main Logic
Node* closestHelper (Node* root, int val, Node* closestNode) {
    if (root == NULL)   return closestNode;

    if (root->data == val)
        return root;

    if (closestNode == NULL || abs(root->data - val) < abs(closestNode->data - val))
        closestNode = root;

    if (val < root->data)
        return closestHelper(root->left, val, closestNode);
    else
        return closestHelper(root->right, val, closestNode);
}

Node* closestElement (Node* root, int val) {
    return closestHelper(root, val, NULL);
}

/* -------------------- MAIN DRIVER CODE ----------------- */
int main() {
    Node *root = NULL;
    root = insert(root, 20);
    root = insert(root, 8);
    root = insert(root, 4);
    root = insert(root, 12);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 22);

    int k = 10;
    cout <<  closestElement(root, k)->data <<endl;
    return 0;
}

/*  ADDITIONAL POINT:

    Here is the iterative solution (preferred over above solution)
    of above problem:

    Node* closestElement (Node* root, int val) {
        Node* closest = NULL;
        int minDiff = INT_MAX;
        Node* temp = root;
        while (temp != NULL) {
            int diff = abs (temp->data - val);
            if (diff < minDiff) {
                minDiff = diff;
                closest = temp;
            }

            if (diff == 0)
                break;

            if (temp->data > val)
                temp = temp->left;
            else
                temp = temp->right;
        }
        return closest;
    }
*/