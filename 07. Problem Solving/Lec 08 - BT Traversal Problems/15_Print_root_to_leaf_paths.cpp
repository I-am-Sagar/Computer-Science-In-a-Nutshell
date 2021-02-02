/*  PROBLEM:
    Given a binary tree, print all its root to leaf paths.

              6
            /   \
           3     5
         /   \     \
        2     5     4
             /  \
            7    4

    There are 4 leaves, hence 4 root to leaf paths -
    6->3->2
    6->3->5->7
    6->3->5->4
    6->5>4

    APPROACH:
    Use a path array path[] to store current root to leaf path.
    Traverse from root to all leaves in top-down fashion.
    While traversing, store data of all nodes in current path
    in array path[]. When we reach a leaf node, print the path array.
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

// Utility Functions
void printArray(int arr[], int len) {
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
}

// Main Logic
void printPathsUtil (Node* node, int path[], int pathLen) {
    if (node == NULL)   return;

    path[pathLen] = node->data;
    pathLen++;

    // If it's a leaf, then print the path
    if (node->left == NULL && node->right == NULL) {
        printArray(path, pathLen);
    } else {
        printPathsUtil(node->left, path, pathLen);
        printPathsUtil(node->right, path, pathLen);
    }
}

void printPaths(Node* node)  {
    int path[1000];
    printPathsUtil(node, path, 0);
}

/* ------------------- MAIN DRIVER CODE ------------------ */
int main()
{
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(2);
    root->right->left->right = new Node(1);

    printPaths(root);
    return 0;
}

/*  ADDITIONAL POINT:
    Q. Given a Binary Tree, find the maximum sum path
       from a leaf to root.

    Approach:
    We divide this task into 2 parts:
    a) We will first find that "leaf node" which exists
       on the path using getTargetLeaf() function.
    b) Print the path from root node to target leaf.

    So our wrapper function which calls these two utility
    functions, looks like this:

    int maxSumPath (Node* root) {
        if (root == NULL)   return 0;
        Node* target_leaf;
        int max_sum = INT_MIN;
        getTargetLeaf (root, &max_sum, 0, &target_leaf);
        printPath (root, target_leaf);
        return max_sum;
    }

    Following function finds the target leaf and returns
    max sum using its reference.

    void getTargetLeaf (Node* root, int* max_sum_ref, int curr_sum, Node** target_leaf_ref) {
        if (root == NULL)   return;
        curr_sum += root->data;
        // If this is a leaf node and path to this node has
        // maximum sum so far, then make this node target_leaf
        if (Node->left == NULL && Node->right == NULL) {
            if (curr_sum > *max_sum_ref) {
                *max_sum_ref = curr_sum;
                *target_leaf_ref = Node;
            }
        }
        // If this is not a leaf node, then recur down
        // to find the target_leaf
        getTargetLeaf(Node->left, max_sum_ref, curr_sum, target_leaf_ref);
        getTargetLeaf(Node->right, max_sum_ref, curr_sum, target_leaf_ref);
    }

    Following function prints a path from root to target leaf node:

    bool printPath(Node* root, Node* target_leaf) {
        if (root == NULL)   return false;
        if (root == target_leaf || printPath(root->left, target_leaf) || printPath(root->right, target_leaf)) {
            cout << root->data << " ";
            return true;
        }
        return false;
    }

*/