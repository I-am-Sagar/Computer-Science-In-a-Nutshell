/*  There are total 4 views of BT:
    a) Left View:
        The left view of the following tree:
                1
               / \
              2   3
            /  \ /  \
           7   6 5   4

        is: 1 2 7

        It seems like printing the leftboundary but it's different.
        For example, for the following tree:
                4
               / \
              5    2
                  / \
                 3   1
                / \
               6   7

        Left boundary is: 4 5
        But the Left View is: 4 5 3 6

    We can keep track of level of a node by passing a parameter
    to all recursive calls. The idea is to keep track of maximum
    level also. Whenever we see a node whose level is more than
    maximum level so far, we print the node because this is the
    first node in its level.

    b) Right View:
        The right view of above tree is: 4 2 1

    We can keep track of level of a node by passing a parameter
    to all recursive calls. The idea is to keep track of maximum
    level also. And traverse the tree in a manner that right subtree
    is visited before left subtree. Whenever we see a node whose
    level is more than maximum level so far, we print the node
    because this is the last node in its level. Note we traverse
    right subtree first in this case and then left subtree.

    c) Top View:
        The top view of above tree is: 5 4 2 1

    Like vertical Order Traversal, we need to put nodes of same horizontal
    distance together. We do a level order traversal so that the topmost
    node at a horizontal node is visited before any other node of same
    horizontal distance below it. Hashing is used to check if a node at
    given horizontal distance is seen or not.

    d) Bottom View:
        The bottom view of above tree is: 5 6 3 7 1

    If there are multiple bottom-most nodes for a horizontal distance from root,
    then print the later one in level traversal. For example, in the below diagram,
    3 and 4 are both the bottom-most nodes at horizontal distance 0,
    we need to print 4.

                      20
                    /    \
                  8       22
                /   \    /   \
              5      3 4     25
                    / \
                  10   14
    Output: 5 10 4 14 25

    Create a map like, map where key is the horizontal distance and value
    is a pair(a, b) where a is the value of the node and b is the height
    of the node. Perform a pre-order traversal of the tree. If the current
    node at a horizontal distance of h is the first we’ve seen, insert it
    in the map. Otherwise, compare the node with the existing one in map
    and if the height of the new node is greater, update in the Map.

    Following is the code to print different views of BT.
    We have not implemented right view function, as it is
    just the modification of left view function.
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

// LEFT VIEW
void leftViewUtil (Node* root, int level, int *max_level) {
    if (root == NULL)   return;
    // Check if the node is the first node of its level
    if (*max_level < level) {
        cout << root->data << " ";
        *max_level = level;
    }
    // Recur for left and right subtrees
    leftViewUtil(root->left, level+1, max_level);
    leftViewUtil(root->right, level+1, max_level);
    // Just swap the order of above recurring calls ie.
    // call root->right first and then root->left, and
    // the function will get converted to rightViewUtil.
}

void leftView(Node* root) {
    int max_level = 0;
    leftViewUtil(root, 1, &max_level);
    cout << endl;
}

// TOP VIEW
void topViewUtil (Node* root, int height, int hd, map<int, pair<int, int>> &m) {
    if (root == NULL)   return;
    // If the node for particular horizontal distance
    // is not present in the map, add it.
    // For top view, we consider the first element at
    // horizontal distance in level order traversal
    if (m.find(hd) == m.end()) {
        m[hd] = make_pair(root->data, height);
    }
    else {
        pair<int, int> p = (m.find(hd))->second;
        if (p.second > height) {
            m.erase(hd);
            m[hd] = make_pair(root->data, height);
        }
    }

    // Recur for left and right subtree
    topViewUtil(root->left, height + 1, hd - 1, m);
    topViewUtil(root->right, height + 1, hd + 1, m);
}

void topView (Node* root) {
    // Map to store horizontal dist, height and node's data
    map <int, pair<int, int>> m;
    topViewUtil (root, 0, 0, m);
    map<int, pair<int, int> >::iterator it;
    for (it = m.begin(); it != m.end(); it++) {
        pair<int, int> p = it->second;
        cout << p.first << " ";
    }
    cout << endl;
}

// BOTTOM VIEW
void bottomViewUtil (Node* root, int height, int hd, map<int, pair<int, int>> &m) {
    if (root == NULL)   return;

    // If node for particular horizontal distance is not present, add it.
    if (m.find(hd) == m.end())
        m[hd] = make_pair(root->data, height);
    // Compare height of already present node at similar horizontal distance
    else {
        pair <int,int> p = m[hd];
        if (p.second <= height) {
            m[hd].second = height;
            m[hd].first = root->data;
        }
    }

    // Recurr for left and right subtrees
    bottomViewUtil (root->left, height+1, hd-1, m);
    bottomViewUtil (root->right, height+1, hd+1, m);
}

void bottomView (Node* root) {
    map <int, pair<int,int>> m;
    bottomViewUtil(root, 0, 0, m);

    map <int, pair<int,int>> :: iterator it;
    for (it = m.begin(); it != m.end(); ++it) {
        pair < int, int > p = it -> second;
        cout << p.first << " ";
    }
    cout << endl;
}

/* ----------------- MAIN DRIVER CODE ------------------- */
int main() {
    Node * root = new Node(20);
    root -> left = new Node(8);
    root -> right = new Node(22);
    root -> left -> left = new Node(5);
    root -> left -> right = new Node(3);
    root -> right -> left = new Node(4);
    root -> right -> right = new Node(25);
    root -> left -> right -> left = new Node(10);
    root -> left -> right -> right = new Node(14);

    cout << "Left View:\n";
    leftView(root);
    cout << "Top View:\n";
    topView (root);
    cout << "Bottom View:\n";
    bottomView(root);
    return 0;
}