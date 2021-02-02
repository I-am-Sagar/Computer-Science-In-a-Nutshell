/*
Given a binary tree, find all duplicate subtrees. For each duplicate subtrees,
we only need to return the root node of any one of them. Two trees are duplicate
if they have the same structure with same node values.

Input :
       1
      / \
     2   3
    /   / \
   4   2   4
      /
     4

Output :

   2
  /    and    4
 4

APPROACH:

The idea is to use hashing. We store inorder traversals of subtrees in a hash.
Since simple inorder traversal cannot uniquely identify a tree, we use symbols
like '(' and ')' to represent NULL nodes. We pass a Unordered Map in C++ as an
argument to the helper function which recursively calculates inorder string and
increases its count in map. If any string gets repeated, then it will imply
duplication of the subtree rooted at that node so push that node in Final result
and return the vector of these nodes.
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

string inorder(Node* node, unordered_map<string, int>& m) {
    if (!node)
        return "";

    string str = "(";
    str += inorder(node->left, m);
    str += to_string(node->data);
    str += inorder(node->right, m);
    str += ")";

    // Subtree already present (Note that we use unordered_map instead
    // of unordered_set because we want to print multiple duplicates only
    // once.
    if (m[str] == 1)
        cout << node->data << " ";
    m[str]++;
    return str;
}

// Wrapper over inorder()
void printAllDups(Node* root) {
    unordered_map<string, int> m;
    inorder(root, m);
}

/* ---------------- MAIN DRIVER CODE --------------- */
int main() {
    Node* root = NULL;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(2);
    root->right->left->left = new Node(4);
    root->right->right = new Node(4);

    printAllDups(root);
    return 0;
}
