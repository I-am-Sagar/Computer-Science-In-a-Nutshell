/*  PROBLEM:
    Given a a Binary Tree, find the difference between the sum of nodes
    at odd level and the sum of nodes at even level. Consider root as
    level 1, left and right children of root as level 2 and so on.

    For example, in the following tree, sum of nodes at odd level is
    (5 + 1 + 4 + 8) which is 18. And sum of nodes at even level is
    (2 + 6 + 3 + 7 + 9) which is 27. The output for following tree
    should be 18 – 27 which is -9.

           5
         /   \
        2     6
       /  \     \
      1    4     8
     /     / \
    3     7   9

    Approach 1 - Iterative Method
    A straightforward method is to use level order traversal.
    In the traversal, check level of current node, if it is odd,
    increment odd sum by data of current node, otherwise increment
    even sum. Finally return difference between odd sum and even sum.

    Approach 2 - Recursive Method
    We can recursively calculate the required difference as,
    value of root’s data subtracted by the difference for subtree
    under left child and the difference for subtree under right child.

    Code of recursive method is this small:

        int getLevelDiff (Node* root) {
            if (root == NULL)   return 0;
            return root->data - getLevelDiff(root->left) - getLevelDiff(root->right);
        }

    Below is the implementation of iterative approach.
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

// Main Logic of Code
int evenOddLevelDifference(Node* root) {
    if (!root) return 0;

    queue<Node*> q;
    q.push(root);
    int level = 0;
    int evenSum = 0, oddSum = 0;
    while (!q.empty())  {
        int size = q.size();
        level += 1;
        while(size > 0) {
            Node* temp = q.front();
            q.pop();

            if(level % 2 == 0)
                evenSum += temp->data;
            else
                oddSum += temp->data;

            if (temp->left)  q.push(temp->left);
            if (temp->right) q.push(temp->right);
            size -= 1;
        }
    }
    return (oddSum - evenSum);
}

/* ----------------- MAIN DRIVER CODE --------------- */
int main() {
    Node* root = new Node(5);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->left->right->left = new Node(3);
    root->right->right = new Node(8);
    root->right->right->right = new Node(9);
    root->right->right->left = new Node(7);

    int result = evenOddLevelDifference(root);
    cout << "Difference between sums is " << result << endl;
    return 0;
}
