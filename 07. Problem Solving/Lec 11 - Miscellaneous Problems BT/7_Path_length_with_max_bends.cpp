/*
Given a binary tree, find the path length having maximum number of bends.
Note : Here, bend indicates switching from left to right or vice versa while
traversing in the tree. For example, consider below paths:
    LLRRRR – 1 Bend
    RLLLRR – 2 Bends
    LRLRLR – 5 Bends

Input :
            4
          /   \
        2      6
      /  \    / \
    1     3  5   7
                /
               9
              / \
             12 10
                  \
                  11
                  / \
                45  13
                      \
                      14

Output : 6
In the above example, the path 4-> 6-> 7-> 9-> 10-> 11-> 45
is having the maximum number of bends, i.e., 3.
The length of this path is 6.

APPROACH:
The idea is to traverse the tree for left and right subtrees of the root.
While traversing, keep track of the direction of motion (left or right).
Whenever, direction of motion changes from left to right or vice versa increment
the number of bends in the current path by 1. On reaching the leaf node,
compare the number of bends in the current path with the maximum number of bends
(i.e., maxBends) seen so far in a root-to-leaf path. If the number of bends in
the current path is greater than the maxBends, then update the maxBends equal
to the number of bends in the current path and update the maximum path length
(i.e., len) also to the length of the current path.

*/

#include <bits/stdc++.h>
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

// Recursive function to calculate the path length having maximum number of bends.
// soFar => length of the current path so far traversed
// len => length of the path having maximum number of bends
void findMaxBendsUtil(struct Node* node, char direction, int bends, int* maxBends, int soFar, int* len) {
    if (node == NULL) return;

    if (node->left == NULL && node->right == NULL) {
        if (bends > *maxBends) {
            *maxBends = bends;
            *len = soFar;
        }
    }
    else {
        if (direction == 'l') {
            findMaxBendsUtil(node->left, direction, bends, maxBends, soFar + 1, len);
            findMaxBendsUtil(node->right, 'r', bends + 1, maxBends, soFar + 1, len);
        }
        else {
            findMaxBendsUtil(node->right, direction, bends, maxBends, soFar + 1, len);
            findMaxBendsUtil(node->left, 'l', bends + 1, maxBends, soFar + 1, len);
        }
    }
}

// Helper function to call findMaxBendsUtil()
int findMaxBends(struct Node* node) {
    if (node == NULL)
        return 0;

    int len = 0, bends = 0, maxBends = -1;

    // Call for left subtree of the root
    if (node->left)
        findMaxBendsUtil(node->left, 'l', bends, &maxBends, 1, &len);

    // Call for right subtree of the root
    if (node->right)
        findMaxBendsUtil(node->right, 'r', bends, &maxBends, 1, &len);

    // Include the root node as well in the path length
    len++;

    return len;
}

/* ---------------- MAIN DRIVER CODE --------------- */
int main() {
    struct Node* root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(2);
    root->right->left->right = new Node(1);
    root->right->left->right->left = new Node(9);

    cout << findMaxBends(root) - 1;

    return 0;
}
