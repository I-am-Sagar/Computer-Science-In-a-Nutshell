/*  PROBLEM:
    Given a binary tree, write a function to get the maximum width
    of the given tree.

    Let us consider the below example tree.

         1
        /  \
       2    3
     /  \     \
    4    5     8
              /  \
             6    7

    So the maximum width of the tree is 3.
    And note it is not the bottom-most level of tree.

    SOLUTION:

    In this method we store all the child nodes at the current level
    in the queue and then count the total number of nodes after the
    level order traversal for a particular level is completed.
    Since the queue now contains all the nodes of the next level,
    we can easily find out the total number of nodes in the next level
    by finding the size of queue.

    We then follow the same procedure for the successive levels.
    We store and update the maximum number of nodes found at each level.

    Time Complexity: O(n)
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

// Main Logic of code
int maxWidth (Node* root) {
    if (root == NULL)   return 0;

    int result = 0;
    queue <Node*> q;
    q.push(root);
    while (!q.empty()) {
        // Get the size of queue when the level order
        // traversal of one level finishes
        int count = q.size();
        result = max (count, result);
        // Iterate for all the nodes in queue currently
        while (count--) {
            Node* temp = q.front();
            q.pop();
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
    return result;
}

/* ----------------- MAIN DRIVER CODE ---------------- */
int main() {
    Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(8);
    root->right->right->left  = new Node(6);
    root->right->right->right  = new Node(7);

    cout << "Maximum width is " << maxWidth(root) << endl;
    return 0;
}

/*  ADDITIONAL POINT:

    If we are asked to find the level with maximum sum,
    how will we do that?

    The idea is to do level order traversal of tree.
    While doing traversal, process nodes of different level separately.
    For every level being processed, compute sum of nodes in the level
    and keep track of maximum sum.

    int maxLevelSum(struct Node * root) {
        if (root == NULL)   return 0;

        int result = root->data;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int count = q.size() ;
            int sum = 0;
            while (count--) {
                Node *temp = q.front();
                q.pop();
                sum = sum + temp->data;

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            result = max(sum, result);
        }
        return result;
    }
*/