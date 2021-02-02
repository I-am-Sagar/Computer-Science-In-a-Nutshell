/*  PROBLEM:
    Given preorder of a full binary tree, calculate its depth
    [starting from depth 0]. The preorder is given as a string
    with two possible characters:
    'l' denotes the leaf
    'n' denotes internal node

    Input  : nlnnlll
    Output : 3

    Tree:
                n
               / \
              l   n
                 / \
                n   l
               / \
              l   l
*/

#include<bits/stdc++.h>
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
int findDepthUtil (string preorder, int &index) {
    if (index >= preorder.length() || preorder[index] == 'l')
        return 0;
    // Calc height of left subtree
    // In preorder left subtree is processed before right
    index++;
    int left = findDepthUtil(preorder, index);
    // Calc height of right subtree
    index++;
    int right = findDepthUtil(preorder, index);

    return (max(left, right) + 1);
}

int findDepth (string preorder) {
    int index = 0;
    return findDepthUtil(preorder, index);
}

/* ---------------- MAIN DRIVER CODE ------------- */
int main() {
    string tree = "nlnnlll";
    cout << findDepth(tree) << endl;

    return 0;
}