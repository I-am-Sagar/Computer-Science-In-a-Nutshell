/*  PROBLEM:
    Given a Binary Tree, find the vertical sum of the nodes that
    are in the same vertical line. Print all sums through different
    vertical lines. Consider the following tree:

              1
            /   \
           2     3
          / \    / \
         4   5  6   7

    The tree has 5 vertical lines:

    Vertical-Line-1 has only one node 4 => vertical sum is 4
    Vertical-Line-2: has only one node 2=> vertical sum is 2
    Vertical-Line-3: has three nodes: 1,5,6 => vertical sum is 1+5+6 = 12
    Vertical-Line-4: has only one node 3 => vertical sum is 3
    Vertical-Line-5: has only one node 7 => vertical sum is 7

    Output: 4 2 12 3 7
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

// Traverses the tree in in-order form and fills
// a hashMap that contains the vertical sum
void verticalSumUtil(Node *node, int hd, map<int, int> &Map) {
    if (node == NULL) return;

    // Recur for left subtree
    verticalSumUtil(node->left, hd-1, Map);
    // Add val of current node to map entry of corresponding HD
    Map[hd] += node->data;
    // Recur for right subtree
    verticalSumUtil(node->right, hd+1, Map);
}

// Main Logic
void verticalSum(Node *root) {
    // a map to store sum of nodes for each horizontal distance
    map <int, int> Map;
    map <int, int> :: iterator it;

    verticalSumUtil(root, 0, Map);

    for (it = Map.begin(); it != Map.end(); ++it)
        cout << it->second << " ";
    cout << endl;
}

/* -------------- MAIN DRIVER CODE ---------------- */
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);

    verticalSum(root);

    return 0;
}