/*
    The diameter of a tree is the number of nodes on the longest
    path between two end nodes.

    Basic observation:
    The diameter of a tree T is the largest of the following quantities:
    a) the diameter of T’s left subtree
    b) the diameter of T’s right subtree
    c) the longest path between leaves that goes through the root of T
       (this can be computed from the heights of the subtrees of T)

    The code of above implementation is:

        int diameter (Node* root) {
            if (tree == NULL)   return 0;

            int l_height = height(tree->left);
            int r_height = height(tree->right);

            int l_diameter = diameter(tree->left);
            int r_diameter = diameter(tree->right);

            return max(l_height+r_height+1, max(l_diameter, r_diameter));
        }

    Time Complexity: O(n^2)

    Here is another way to think about diameter of tree:
    Diameter of a tree can be calculated by only using the height function,
    because the diameter of a tree is nothing but maximum value of
    (left_height + right_height + 1) for each node. So we need to calculate
    this value (left_height + right_height + 1) for each node and
    update the result.

    Time Complexity: O(n)
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

// Function to compute height
int height (Node* root, int &ans) {
    if (root == NULL)   return 0;

    int left_height = height(root->left, ans);
    int right_height = height(root->right, ans);

    ans = max(ans, 1+left_height+right_height);

    return (1 + max(left_height, right_height));
}

// Computes the diameter of binary tree
int diameter (Node* root) {
    if (root == NULL)   return 0;
    int ans = INT_MIN;
    int height_of_tree = height(root, ans);
    return ans;
}

/* ----------------- MAIN DRIVER CODE ------------- */
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    printf("Diameter is %d\n", diameter(root));

    return 0;
}