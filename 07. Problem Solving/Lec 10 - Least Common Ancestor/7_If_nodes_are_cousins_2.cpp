/*
    Previous solution that finds whether given nodes are cousins
    or not performs three traversals of binary tree. The problem
    can be solved by performing single level order traversal.

    The idea is to use a queue to perform level order traversal,
    in which each queue element is a pair of node and parent of
    that node. For each node visited in level order traversal,
    check if that node is either first given node or second given
    node. If any node is found store parent of that node. While
    performing level order traversal, one level is traversed at
    a time. If both nodes are found in given level, then their
    parent values are compared to check if they are siblings or
    not. If one node is found in given level and another is not
    found, then given nodes are not cousins.
*/

#include <bits/stdc++.h>
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

// Main Logic
bool isCousin (Node* root, Node* a, Node* b) {
    if (root == NULL)   return false;
    // To store parent of node a.
    Node* parent_A = NULL;
    // To store parent of node b.
    Node* parent_B = NULL;
    // Each element of queue is a pair of node and its parent.
    queue<pair<Node*, Node*> > q;
    // Dummy node to act like parent of root node.
    Node* temp = new Node(-1);
    // To store front element of queue.
    pair<Node*, Node*> ele;

    q.push(make_pair(root, temp));
    int levelSize;
    while (!q.empty()) {
        // find number of elements in current level.
        levelSize = q.size();
        while (levelSize) {
            ele = q.front();
            q.pop();
            // check if current node is node a or node b or not.
            if (ele.first->data == a->data)
                parent_A = ele.second;

            if (ele.first->data == b->data)
                parent_B = ele.second;

            // push children of current node to queue.
            if (ele.first->left)
                q.push(make_pair(ele.first->left, ele.first));
            if (ele.first->right)
                q.push(make_pair(ele.first->right, ele.first));

            levelSize--;

            // If both nodes are found in current level then no need
            // to traverse current level further.
            if (parent_A && parent_B)
                break;
        }
        // Check if both nodes are siblings or not.
        if (parent_A && parent_B)
            return parent_A != parent_B;

        // If one node is found in current level and another is not found,
        // then both nodes are not cousins.
        if ((parent_A && !parent_B) || (parent_B && !parent_A))
            return false;
    }
    return false;
}

/* ---------------- MAIN DRIVER CODE ------------- */
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->right = new Node(15);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);

    Node *Node1, *Node2;
    Node1 = root->left->left;
    Node2 = root->right->right;

    isCousin(root, Node1, Node2) ? printf("Yes\n") : printf("No\n");

    return 0;
}
