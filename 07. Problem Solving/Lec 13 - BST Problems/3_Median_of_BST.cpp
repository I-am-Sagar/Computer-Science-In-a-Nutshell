/*  PROBLEM:
    Find the median of the elements in BST
    in O(n) time and O(1) space complexity.
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *left, *right;
    Node(int x) {
        this->data = x;
        this->left = this->right = NULL;
    }
};

// Auxiliary Function
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

// Since we need O(1) space solution, we can't use previous recursive num() 
// to count nodes. Below function "Morris Inorder Traversal" and counts the 
// number of nodes
int num (Node* root) {
    if (root == NULL)   return 0;

    int count = 0;
    Node *curr, *prev;
    curr = root;
    while (curr != NULL) {
        if (curr->left == NULL) {
            // Count node if its left is NULL
            count++;
            // Move to its right
            curr = curr->right;
        }
        else {
            // Find inorder predecessor of current
            prev = curr->left;
            while (prev->right != NULL && prev->right != curr)
                prev = prev->right;
            // Make current as right child of its inorder predecessor
            if (prev->right == NULL) {
                prev->right = curr;
                curr = curr->left;
            }
            // Revert the changes made in if part to restore the original tree 
            // i.e., fix the right child of predecssor
            else {
                prev->right = NULL;
                // Increment count if the current node is to be visited
                count++;
                curr = curr->right;
            }   // End of if condition: prev->right == NULL
        }   // End of if condition: curr->left == NULL
    }   // End of while
    return count;
}

// Function to find median again with O(1) space using 'Morris Inorder Traversal'
double findMedian (Node* root) {
    if (root == NULL)   return 0.0;

    int count = num(root);
    int current_count = 0;
    Node* current = root, *pre, *prev;

    while (current != NULL){
        if (current->left == NULL) {
            current_count++;
            // Check if current node is median
            // Odd case:
            if (count%2 != 0 && current_count == (count+1)/2)
                return (double)prev->data;
            // Even case:
            else if (count%2 == 0 && current_count == (count/2)+1)
                return ((prev->data + current->data)/2.0);
            // Update prev for even number of nodes
            prev = current;
            current = current->right;
        }
        else {
            // Finding the inorder predecessor of current
            pre = current->left;
            while (pre->right != NULL && pre->right != current)
                pre = pre->right;
            // Make current as right child of its inorder predecessor
            if (pre->right == NULL) {
                pre->right = current;
                current = current->left;
            }
            // Revert the changes made in if part to restore the original tree 
            // i.e., fix the right child of predecssor
            else {
                pre->right = NULL;
                prev = pre;
                current_count++;
                // Check if the current node is median
                if (count%2 != 0 && current_count == (count+1)/2)
                    return (double)prev->data;
                else if (count%2 == 0 && current_count == (count/2)+1)
                    return ((prev->data + current->data)/2.0);

                // Update prev node for the case of even number of nodes
                prev = current;
                current = current->right;
            }
        }
    }
}

/* ------------------ MAIN DRIVER CODE ---------------- */
int main() {
    Node *root = NULL;
    root = insert(root, 5);
    insert(root, 3);
    insert(root, 2);
    insert(root, 5);
    insert(root, 7);
    insert(root, 6);
    insert(root, 8);

    cout << "\nMedian of BST is " << findMedian(root) << endl;
    return 0;
}