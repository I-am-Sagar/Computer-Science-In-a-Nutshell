/*
    We have discussed a BFS based solution for this problem
    in our previous code. If you observe that solution carefully,
    you will see that the basic approach was to first find the
    node and then backtrack to the kth parent. The same thing
    can be done using recursive DFS without using an extra array.

    The idea of using DFS is to first find the given node in the
    tree, and then backtrack k times to reach to kth ancestor,
    once we have reached to the kth parent, we will simply print
    the node and return NULL.
*/

#include <bits/stdc++.h>
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

// Main Logic
Node* kthAncestorDFS(Node *root, int node , int &k) {
    if (!root)  return NULL;

    static Node* temp = NULL;
    if (root->data == node|| (temp =  kthAncestorDFS(root->left,node,k)) || (temp =  kthAncestorDFS(root->right,node,k))) {
        if (k > 0)
            k--;
        else if (k == 0) {
            // print the kth ancestor
            cout << "Kth ancestor is: " << root->data << endl;
            // return NULL to stop further backtracking
            return NULL;
        }
        // return current node to previous call
        return root;
    }
}

/* --------------- MAIN DRIVER CODE -------------- */
int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    int k = 2;
    int node = 5;

    Node* parent = kthAncestorDFS(root,node,k);

    if (parent)
        cout << "-1";

    return 0;
}

/*  ADDITIONAL APPROACH (simple one):

    First we find the path of given key data from the root
    and we will store it into a vector then we simply
    return the kth index of the vector from the last.

    bool RootToNode(node* root, int key, vector<int>& v) {
        if (root == NULL)   return false;

        // Add current node to the path
        v.push_back(root->data);

        // If current node is the target node
        if (root->data == key)  return true;

        // If the target node exists in the left or the right sub-tree
        if (RootToNode(root->left, key, v) || RootToNode(root->right, key, v))
            return true;

        // Remove the last inserted node as it is not a part of
        // the path from root to target
        v.pop_back();
        return false;
    }

*/

