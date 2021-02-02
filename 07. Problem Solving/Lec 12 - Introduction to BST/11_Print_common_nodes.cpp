/*  PROBLEM:
    Given two Binary Search Trees, find common nodes in them.
    In other words, find intersection of two BSTs.

    SOLUTION:

    Approach 1:
    A simple way is to one by once search every node of first
    tree in second tree. Time complexity of this solution is
    O(m * h) where m is number of nodes in first tree and
    h is height of second tree. In the worst case, second tree
    may be skewed and the time complexity will turn O(m*n).

    Approach 2:
    We can find common elements in linear time, by following way:
    1. Do inorder traversal of first tree and store the traversal
       in an auxiliary array arr1[].
    2. Do inorder traversal of second tree and store the
       traversal in an auxiliary array arr2[].
    3. Find the intersection of sorted arrays arr1[] and arr2[].
    Time and space complexity: O(m+n)

    Approach 3:
    We can find common elements in O(n) time and O(h1 + h2) extra
    space where h1 and h2 are heights of first and second BSTs
    respectively.
    The idea is to use iterative inorder traversal. We use two
    auxiliary stacks for two BSTs. Since we need to find common
    elements, whenever we get same element, we print it.
*/


#include<bits/stdc++.h>
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

// Auxiliary functions
void inorder(Node *root) {
    if (root) {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

Node* insert(struct Node* node, int key) {
    if (node == NULL) {
        Node* temp = new Node(key);
        return temp;
    };

    if (key < node->data)
        node->left  = insert(node->left, key);
    else if (key > node->data)
        node->right = insert(node->right, key);

    return node;
}

// Main Logic of Code
void printCommon (Node* root1, Node* root2) {
    stack <Node*> stack1, s1, s2;
    while (1) {
        if (root1) {
            s1.push(root1);
            root1 = root1->left;
        }
        else if (root2) {
            s2.push(root2);
            root2 = root2->left;
        }
        else if (!s1.empty() && !s2.empty()){
            root1 = s1.top();
            root2 = s2.top();
            if (root1->data == root2->data) {
                cout << root1->data << " ";
                s1.pop();
                s2.pop();
                root1 = root1->right;
                root2 = root2->right;
            }
            else if (root1->data < root2->data) {
                s1.pop();
                root1 = root1->right;
                root2 = NULL;
            }
            else if (root1->data > root2->data) {
                s2.pop();
                root2 = root2->right;
                root1 = NULL;
            }
        }
        else
            break;
    }
}

/* --------------------- MAIN DRIVER CODE ----------------- */
int main() {
    Node *root1 = NULL;
    root1 = insert(root1, 5);
    root1 = insert(root1, 1);
    root1 = insert(root1, 10);
    root1 = insert(root1,  0);
    root1 = insert(root1,  4);
    root1 = insert(root1,  7);
    root1 = insert(root1,  9);

    Node *root2 = NULL;
    root2 = insert(root2, 10);
    root2 = insert(root2, 7);
    root2 = insert(root2, 20);
    root2 = insert(root2, 4);
    root2 = insert(root2, 9);

    cout << "Tree 1 : ";
    inorder(root1);
    cout << endl;

    cout << "Tree 2 : ";
    inorder(root2);

    cout << "\nCommon Nodes: ";
    printCommon(root1, root2);
    cout << endl;

    return 0;
}