/*  PROBLEM:
    Given a binary tree and two values say n1 and n2,
    write a program to find the least common ancestor.

    The lowest common ancestor between two nodes n1 and n2
    is defined as the lowest node in T that has both n1 and n2
    as descendants (where we allow a node to be a descendant
    of itself).

    Method 1 - By storing root to n1 and root to n2 paths

    1. Find path from root to n1 and store it in a array
    2. Find path from root to n2 and store it in another array
    3. Traverse both the paths till the values in array are same
       Return the common element just before the mismatch

    Time Complexity: O(n)
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

// Utility function which finds the path from root to given
// node and stores the path in vector path[] if it exists
bool findPath (Node* root, vector <int> &path, int k) {
    if (root == NULL)   return false;

    // Store this node in path. It will be removed
    // if it doesn't lie on the path from root to k
    path.push_back(root->data);

    // Now check if root's data is equal to key
    if (root->data == k)
        return true;

    // Check if k is found in left and right subtrees
    if ((root->left && findPath(root->left, path, k)) || (root->right && findPath(root->right, path, k)))
        return true;

    // If not present in subtree rooted with root, remove
    // root from path[] and return false
    path.pop_back();
    return false;
}

// Main Logic
int findLCA (Node* root, int n1, int n2) {
    vector <int> path1, path2;
    if (!findPath(root, path1, n1) || !findPath(root, path2, n2))
        return -1;
    // Compare the paths to get first different value
    int i;
    for (i = 0; i < path1.size() && i < path2.size(); i++)
        if (path1[i] != path2[i])
            break;
    return path1[i-1];
}

/* ------------------- MAIN DRIVER CODE ----------------- */
int main() {
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5);
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6);
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4);
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4);
    cout << endl;
    return 0;
}