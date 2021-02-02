/*  PROBLEM:
    Construct a binary tree from given inorder and preorder traversals.

    Inorder sequence: D B E A F C
    Preorder sequence: A B D E C F

    Constructed tree should be:
              A
            /   \
           B     C
         /  \    /
        D    E  F

    Approach 1 - Recursion (without Hashmap)
    In a Preorder sequence, leftmost element is the root of the tree.
    So we know ‘A’ is root for given sequences. By searching ‘A’ in
    Inorder sequence, we can find out all elements on left side of ‘A’
    are in left subtree and elements on right are in right subtree.
    So we know below structure now.

                 A
               /   \
           D B E    F C

    We recursively follow above steps and get the following tree.

    Here is the implementation of above method:

        int search(char arr[], int strt, int end, char value);
        void printInorder(node* root);

        Node* buildTree(char in[], char pre[], int inStart, int inEnd) {
            if (inStart > inEnd)  return NULL;

            static int preIndex = 0;

            // Pick current node from Preorder traversal using preIndex
            // and increment preIndex
            Node* tNode = new Node(pre[preIndex++]);

            // If this node has no children then return
            if (inStart == inEnd)   return tNode;

            // Else find the index of this node in Inorder traversal
            int inIndex = search(in, inStart, inEnd, tNode->data);

            //Using index in Inorder traversal, construct left and right subtress
            tNode->left = buildTree(in, pre, inStart, inIndex - 1);
            tNode->right = buildTree(in, pre, inIndex + 1, inEnd);

            return tNode;
        }

    Time Complexity: O(n^2)
    Worst case occurs when tree is left skewed. Example Preorder and Inorder
    traversals for worst case are {A, B, C, D} and {D, C, B, A}.

    We can optimize the above solution using hashing (unordered_map).
    We store indexes of inorder traversal in a hash table.
    So that search can be done O(1) time.

    Time Complexity : O(n)
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    char data;
    Node *left, *right;
    Node(int data) {
        this->data = data;
        this->left = this->right = NULL;
    }
};

// Auxiliary Function to print tree
void printInorder(struct Node* node) {
    if (node == NULL)
        return;
    printInorder(node->left);
    printf("%c ", node->data);
    printInorder(node->right);
}

// Main Logic
Node* buildTreeUtil(char in[], char pre[], int inStart, int inEnd, unordered_map<char, int> &map) {
    if (inStart > inEnd)    return NULL;

    static int preIndex = 0;
    // Pick current node from preorder traversal
    // using preIndex and increment preIndex
    char curr = pre[preIndex++];
    Node* tNode = new Node(curr);
    // If this node has no children, then return
    if (inStart == inEnd)   return tNode;
    // Else find the index of this node in inorder traversal
    int inIndex = map[curr];
    // Using index in inorder traversal, construct
    // left and right subtrees
    tNode->left = buildTreeUtil(in, pre, inStart, inIndex - 1, map);
    tNode->right = buildTreeUtil(in, pre, inIndex + 1, inEnd, map);

    return tNode;
}

Node* buildTree (char in[], char pre[], int len) {
    unordered_map<char, int> map;
    for (int i = 0; i < len; i++)
        map[in[i]] = i;
    return buildTreeUtil(in, pre, 0, len-1, map);
}

/* ---------------------- MAIN DRIVER CODE -----------------*/
int main() {
    char in[] = { 'D', 'B', 'E', 'A', 'F', 'C' };
    char pre[] = { 'A', 'B', 'D', 'E', 'C', 'F' };
    int len = sizeof(in) / sizeof(in[0]);

    Node* root = buildTree(in, pre, len);

    printf("Inorder traversal of the constructed tree is: \n");
    printInorder(root);
}