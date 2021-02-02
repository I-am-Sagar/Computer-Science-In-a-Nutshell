/*
    Method 2 - Using single traversal

    Method 1 requires 3 tree traversals plus extra spaces for
    path arrays. In this method we will find LCA without
    extra space and in single traversal.

    The idea is to traverse the tree starting from root. If
    any of the given keys (n1 and n2) matches with root, then
    root is LCA. If root doesn't match with any of the nodes,
    we recurr for left and right subtree. The node which has
    one key present in its left subtree and the other key
    present in right subtree is the LCA. If both keys lie in
    left subtree, then left subtree has LCA also, otherwise
    LCA lies in right subtree.

    Time complexity of the above solution is O(n) as the method
    does a simple tree traversal in bottom up fashion.
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

// This function returns pointer to LCA of two given values
// Function assumes that n1 and n2 are present in BT
Node* findLCA (Node* root, int n1, int n2) {
    if (root == NULL)   return NULL;

    // If either n1 or n2 matches with root's data, report
    // the presence by returning root. Note that if a key
    // is ancestor of other, then the ancestor key becomes LCA
    if (root->data == n1 || root->data == n2)
        return root;

    // Look for keys in left and right subtrees
    Node* left_lca = findLCA (root->left, n1, n2);
    Node* right_lca = findLCA (root->right, n1, n2);

    // If both of the above calls return Non-NULL, then one
    // key is present in one subtree and other is present
    // in another subtree. So this node is LCA.
    if (left_lca && right_lca)  return root;

    // Otherwise check if left subtree or right subree contains LCA
    return ((left_lca != NULL) ? left_lca : right_lca);
}

/* ------------------ MAIN DRIVER CODE ------------------ */
int main() {
    Node * root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->data;
    cout << "\nLCA(4, 6) = " << findLCA(root, 4, 6)->data;
    cout << "\nLCA(3, 4) = " << findLCA(root, 3, 4)->data;
    cout << "\nLCA(2, 4) = " << findLCA(root, 2, 4)->data;
    cout << endl;
    return 0;
}

/*  ADDITIONAL POINT:

    Note that the above method assumes that keys are present
    in Binary Tree. If one key is present and other is absent,
    then it returns the present key as LCA.
    (Ideally should have returned NULL). We can extend this
    method to handle all cases by passing two boolean variables
    v1 and v2. v1 is set as true when n1 is present in tree
    and v2 is set as true if n2 is present in tree.

    Node *findLCAUtil(Node* root, int n1, int n2, bool &v1, bool &v2) {
        if (root == NULL) return NULL;

        if (root->key == n1) {
            v1 = true; return root;
        }

        if (root->key == n2) {
            v2 = true;
            return root;
        }

        Node *left_lca  = findLCAUtil(root->left, n1, n2, v1, v2);
        Node *right_lca = findLCAUtil(root->right, n1, n2, v1, v2);

        if (left_lca && right_lca)  return root;

        return (left_lca != NULL)? left_lca: right_lca;
    }

    // Returns true if key k is present in tree rooted with root
    bool find(Node *root, int k) {
        if (root == NULL)   return false;

        if (root->key == k || find(root->left, k) ||  find(root->right, k))
            return true;
        else
            return false;
    }

    // This function returns LCA of n1 and n2 only if both n1 and n2
    // are present in tree, otherwise returns NULL;
    Node *findLCA (Node *root, int n1, int n2) {
        bool v1 = false, v2 = false;
        Node *lca = findLCAUtil(root, n1, n2, v1, v2);

        // Return LCA only if both n1 and n2 are present in tree
        if (v1 && v2 || v1 && find(lca, n2) || v2 && find(lca, n1))
            return lca;
        else
            return NULL;
    }

    // Main driver code
    int main()
    {
        Node * root = new Node(1);
        root->left = new Node(2);
        root->right = new Node(3);
        root->left->left = new Node(4);
        root->left->right = new Node(5);
        root->right->left = new Node(6);
        root->right->right = new Node(7);

        Node *lca =  findLCA(root, 4, 5);
        if (lca != NULL)
            cout << "LCA(4, 5) = " << lca->key;
        else
            cout << "Keys are not present ";

        lca =  findLCA(root, 4, 10);
        if (lca != NULL)
            cout << "\nLCA(4, 10) = " << lca->key;
        else
            cout << "\nKeys are not present ";

        return 0;
    }
*/
