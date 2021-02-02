// Video Link 1: https://www.youtube.com/watch?v=_Hehd1KSq7Y
// Video Link 2: https://www.youtube.com/watch?v=IPak9nF_64k
// Video Link 3: https://www.youtube.com/watch?v=08KwCr2UZBQ

/* Here is a code of finding the type of Binary tree. */

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

/* ----------------- FULL/STRICT BINARY TREE --------------- */

bool isFullRec (Node* root) {
    // If tree is empty
    if (root == NULL)   return true;
    // If we are at leaf node
    if (root->left == NULL && root->right == NULL)  return true;
    // If both - left and right subtrees exist
    if (root->left && root->right)
        return (isFullRec(root->left) && isFullRec(root->right));

    return false;
}

bool isFullItr (Node* root) {
    // If tree is empty
    if (root == NULL)   return true;

    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        // If we are at leaf node
        if (node->left == NULL && node->right == NULL)
            continue;

        // If either of the child is not null, tree is not full
        if (node->left == NULL || node->right == NULL)
            return false;

        q.push(node->left);
        q.push(node->right);
    }
    return true;
}

/* ------------------- COMPLETE BINARY TREE ------------------ */
// totalNodes() will be used in Recursive solution
int totalNodes(Node* root) {
    if (root == NULL)
        return 0;
    return (1 + totalNodes(root->left) + totalNodes(root->right));
}

// Since we cannot change the parameters of isCompleteRec,
// We create a helper function to perform the task recursively
bool isCompleteHelper(Node* root, int index, int nodes_count) {
    if (root == NULL)   return true;
    if (index >= nodes_count)   return false;
    return isCompleteHelper(root->left, 2*index+1, nodes_count) && \
           isCompleteHelper(root->right, 2*index+2, nodes_count);
}

bool isCompleteRec(Node* root) {
    return isCompleteHelper (root, 0, totalNodes(root));
}

bool isCompleteItr(Node* root) {
    if (root == NULL)   return true;

    // flag will be set to true when non-full node is seen
    bool flag = false;

    queue <Node*> q;
    q.push(root);
    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        // Check if left child is present
        if (temp->left) {
            if (flag)
                return false;
            q.push(temp->left);
        }
        else
            flag = true;

        if (temp->right) {
            if (flag)
                return false;
            q.push(temp->right);
        }
        else
            flag = true;
    }
    return true;
}

/* ------------------------ PERFECT BINARY TREE -------------------- */
// Returns depth of leftmost leaf
int height(Node *root) {
    int d = 0;
    while(root != NULL) {
        d++;
        root = root->left;
    }
    return d;
}

// Helper function
bool isPerfectHelper(Node* root, int depth, int level) {
    if (root == NULL)   return true;

    // If we are at leaf node, it's depth must be same as
    // depth of all other leaves
    if (root->left == NULL && root->right == NULL)
        return (depth == level + 1);

    // If internal node and one child is empty
    if (root->left == NULL || root->right == NULL)
        return false;

    return isPerfectHelper(root->left, depth, level+1) && \
           isPerfectHelper(root->right, depth, level+1);
}

bool isPerfectRec (Node* root) {
    int d = height(root);
    return isPerfectHelper(root, d, 0);
}

bool isPerfectItr (Node* root) {
    if (root == NULL)   return true;

    // Once leaf node is found, flag will become true
    bool flag = false;

    queue <Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        // If current node has both children
        if (temp->left && temp->right) {
            // If leaf is already found, return false
            if (flag)
                return false;
            else {
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        // If we are at leaf node, set flag to true
        if (!temp->left && !temp->right)
            flag = true;

        // If the current node has only one child, return false
        if (!temp->left || !temp->right)
            return false;
    }
    return true;
}

/* --------------------- SKEWED BINARY TREE ------------------- */
bool isSkewedRec (Node* root) {
    // Check if node is NULL or leaf node
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return true;

    // Check if the node has two children
    if (root->left && root->right)
        return false;

    if (root->left)
        return isSkewedRec(root->left);

    return isSkewedRec(root->right);
}

/* ---------------- MAIN DRIVER CODE ---------------- */
int main()
{

    struct Node* root = NULL;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    if (isFullRec(root) && isFullItr(root))
        printf("The Binary Tree is full\n");

    if (isCompleteRec(root) && isCompleteItr(root))
        printf("The Binary Tree is complete\n");

    if (isPerfectRec(root) && isPerfectItr(root))
        printf("The Binary Tree is perfect\n");

    if (isSkewedRec(root))
        printf("The Binary Tree is skewed\n");

    return (0);
}