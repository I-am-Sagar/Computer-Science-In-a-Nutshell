/*  PROBLEM:
    Given two BSTs containing n1 and n2 distinct nodes respectively
    and a value x. The problem is to count all pairs from both
    the BSTs whose sum is equal to x.

    Input :
        BST 1:    5
                /   \
               3     7
              / \   / \
             2  4  6   8

        BST 2:    10
                /   \
               6     15
              / \   /  \
             3  8  11  18

        x = 16

    Output : 3

    Explanation: The pairs are: (5, 11), (6, 10) and (8, 8)

    SOLUTION:

    Method 1:
    For each node value a in BST 1, search the value (x – a) in BST 2.
    If value found then increment the count.
    Time complexity: O(n1*h2), here n1 is number of nodes in first BST
    and h2 is height of second BST. In worst case of skewed trees, h2 = n2.

    Method 2:
    1. Traverse BST 1 from smallest value to node to largest. This can
       be achieved with the help of iterative inorder traversal.
    2. Traverse BST 2 from largest value node to smallest. This can be
       achieved with the help of reverse inorder traversal.
    3. Perform these two traversals simultaneously. Sum up the
       corresponding node’s value from both the BSTs at a particular
       instance of traversals.
    4. If sum == x, then increment count.
    5. If x > sum, then move to the inorder successor of the current
       node of BST 1, else move to the inorder predecessor of the
       current node of BST 2.
    6. Perform these operations until either of the two traversals
       gets completed.

    Time and Space Complexity: O(n1 + n2)
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

// Main Logic
int countPairs (Node* root1, Node* root2, int x) {
    if (root1 == NULL || root2 == NULL)
        return 0;

    // stack1 is for inorder traversal of BST1
    // stack2 is for reverse inorder traversal of BST2
    stack <Node*> s1, s2;
    Node *top1, *top2;
    int count = 0;
    while (1) {
        // Find next node in inorder traversal of BST1
        while (root1 != NULL) {
            s1.push(root1);
            root1 = root1->left;
        }
        // Find next node in reverse inorder of BST2
        while (root2!= NULL) {
            s2.push(root2);
            root2 = root2->right;
        }
        // If either gets empty, traversal is complete
        if (s1.empty() || s2.empty())
            break;

        top1 = s1.top();
        top2 = s2.top();

        // if the sum of top nodes is equal to x, increment count
        if ((top1->data + top2->data) == x) {
            count++;

            s1.pop(); s2.pop();
            root1 = top1->right;
            root2 = top2->left;
        }
        // else if move to next possible node in BST1
        else if ((top1->data + top2->data) < x) {
            s1.pop();
            root1 = top1->right;
        }
        // else move to next possible node in reverse inorder
        // traversal of BST2
        else {
            s2.pop();
            root2 = top2->left;
        }
    }
    return count;
}

/* --------------- MAIN DRIVER CODE --------------- */
int main() {
    Node* root1 = new Node(5);
    root1->left = new Node(3);
    root1->right = new Node(7);
    root1->left->left = new Node(2);
    root1->left->right = new Node(4);
    root1->right->left = new Node(6);
    root1->right->right = new Node(8);

    Node* root2 = new Node(10);
    root2->left = new Node(6);
    root2->right = new Node(15);
    root2->left->left = new Node(3);
    root2->left->right = new Node(8);
    root2->right->left = new Node(11);
    root2->right->right = new Node(18);

    int x = 16;

    cout << "Pairs = " << countPairs(root1, root2, x) << endl;

    return 0;
}