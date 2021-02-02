/*  PROBLEM:
    Check if the leaves of given BT are at same level.

    SOLUTION:
    The idea is to first find level of the leftmost leaf
    and store it in a variable leafLevel. Then compare
    level of all other leaves with leafLevel.
    If same, return true, else return false.
    We traverse the given Binary Tree in Preorder fashion.
    An argument leaflevel is passed to all calls.
    The value of leafLevel is initialized as 0 to indicate
    that the first leaf is not yet seen yet. The value is
    updated when we find first leaf. Level of subsequent
    leaves (in preorder) is compared with leafLevel.
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

bool checkUtil (Node* root, int level, int* leafLevel) {
    if (root == NULL)   return true;

    if (root->left == NULL && root->right == NULL) {
        // Set first found leaf's level
        if (*leafLevel == 0) {
            *leafLevel = level;
            return true;
        }

        // If this is not first leaf node, compare
        // its level with first leaf's level
        return (level == *leafLevel);
    }
    return (checkUtil(root->left, level+1, leafLevel) && checkUtil(root->right, level+1, leafLevel));
}

bool checkLeafLevels(Node* root) {
    int level = 0, leafLevel = 0;
    return checkUtil(root, level, &leafLevel);
}

/* ------------ MAIN DRIVER CODE -------------- */
int main() {
    Node *root = new Node(12);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(9);
    root->left->left->left = new Node(1);
    root->left->right->left = new Node(1);
    if (checkLeafLevels(root))
        cout << "Leaves are at same level\n";
    else
        cout << "Leaves are not at same level\n";

    return 0;
}

/*  ADDITIONAL POINT:
    Q. 1 Given a binary tree containing n nodes. The problem is
    to get the sum of all the leaf nodes which are at minimum
    level in the binary tree.

    Input :
              1
            /   \
           2     3
         /  \   /  \
        4   5   6   7
           /     \
          8       9

    Output : 11
    Leaf nodes 4 and 7 are at minimum level.
    Their sum = (4 + 7) = 11.

    APPROACH:
    Perform iterative level order traversal using queue and
    find the first level containing a leaf node. Sum up all
    the leaf nodes at this level and then stop performing
    the traversal further.

    int sumOfLeafNodesAtMinLevel(Node* root) {
        if (!root)  return 0;

        if (!root->left && !root->right)
            return root->data;

        queue<Node*> q;
        int sum = 0;
        bool f = 0;
        q.push(root);

        while (f == 0) {
            int n = q.size();

            // traverse the current level nodes
            while (n--) {
                Node* top = q.front();
                q.pop();

                if (!top->left && !top->right) {
                    sum += top->data;
                    f = 1;
                }
                else {
                    if (top->left) q.push(top->left);
                    if (top->right) q.push(top->right);
                }
            }
        }
        return sum;
    }
*/