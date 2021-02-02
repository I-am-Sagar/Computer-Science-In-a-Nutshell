/*  PROBLEM:
    Given a Binary Search Tree and two keys in it.
    Find the distance between two nodes with given
    two keys. It may be assumed that both keys exist
    in BST.

    SOLUTION:
    We start from the root and for every node, we do following:

    a) If both keys are greater than the current node,
       we move to the right child of the current node.
    b) If both keys are smaller than current node,
       we move to left child of current node.
    c) If one keys is smaller and other key is greater,
       current node is Lowest Common Ancestor (LCA) of two nodes.

    We find distances of current node from two keys and
    return sum of the distances.
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
Node* insert (Node* root, int key) {
    if (root == NULL) {
        Node* temp = new Node(key);
        return temp;
    }
    if (root->data < key)
        root->right = insert (root->right, key);
    else
        root->left = insert(root->left, key);

    return root;
}

// Utility function to find distance from root
int distanceFromRoot(Node* root, int x) {
    if (root->data == x)
        return 0;
    else if (root->data > x)
        return (1 + distanceFromRoot(root->left, x));
    return (1 + distanceFromRoot(root->right, x));
}

// Main Logic
int distanceBetween2(Node* root, int a, int b) {
    if (!root)  return 0;

    // Both keys lie in left
    if (root->data > a && root->data > b)
        return distanceBetween2(root->left, a, b);

    // Both keys lie in right
    if (root->data < a && root->data < b)
        return distanceBetween2(root->right, a, b);

    // Lie in opposite directions (Root is LCA of two nodes)
    if (root->data >= a && root->data <= b)
        return distanceFromRoot(root, a) + distanceFromRoot(root, b);
}

int findDist(Node *root, int a, int b) {
   if (a > b)
     swap(a, b);
   return distanceBetween2(root, a, b);
}

/* ------------------ MAIN DRIVER CODE ----------------- */
int main() {
    Node* root = NULL;
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 30);
    insert(root, 25);
    insert(root, 35);

    cout << findDist(root, 5, 35) << endl;
    return 0;
}

/*  ADDITIONAL POINT:

    Given a BST, your task is to find out maximum valued
    node between two nodes A and B. Elements of BST are
    given in an array in random order.

    SOLUTION:
    The idea is to find Lowest Common Ancestor of node
    ‘a’ and node ‘b’. Then search maximum node between
    LCA and ‘a’, also find maximum node between LCA and
    ‘b’. Answer will be maximum node of two.

    Following function returns the maximum value of the
    node between given node and its LCA.

    int maxelpath (Node *q, int x) {
        Node *p = q;
        int max = INT_MIN;

        while (p -> data != x) {
            if (p -> data > x) {
                max = max(max, p -> data);
                p = p -> left;
            }
            else {
                max = max(max, p -> data);
                p = p -> right;
            }
        }
        return max(max, x);
    }

    Following function returns maximum element in
    the path between two given Node of BST:

    int maximumElement(Node *root, int x, int y) {
        Node *p = root;
        while ((x < p -> data && y < p -> data) || (x > p -> data && y > p -> data)) {
            if (x < p -> data && y < p -> data)
                p = p -> left;
            else if (x > p -> data && y > p -> data)
                p = p -> right;
        }
        return max(maxelpath(p, x), maxelpath(p, y));
    }

*/