// Video Link: https://www.youtube.com/watch?v=ZKeKwL4Db9Q

/* ALGORITHM:
    1) Initialize current node as root
    2) Create an empty stack S.
    3) Push the current node to S and set current = current->left until current is NULL
    4) If current is NULL and stack is not empty then
        a) Pop the top item from stack.
        b) Print the popped item, set current = popped_item->right
        c) Go to step 3.
    5) If current is NULL and stack is empty then we are done.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node (int data) {
        this->data = data;
        left = right = NULL;
    }
};

// Main Logic
void inOrder (Node* root) {
    Node* current = root;
    stack <Node*> s;
    while (true) {
        if (current != NULL) {
            s.push(current);
            current = current->left;
        }
        else {
            if (s.empty())  break;
            cout << s.top()->data << " ";
            current = s.top()->right;
            s.pop();
        }
    }
}

/* ---------------- MAIN DRIVER CODE ---------------- */
int main()
{

    /* Constructed binary tree is:
              1
            /   \
          2      3
        /  \      \
      4     5      6
    */
    struct Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    inOrder(root);
    return 0;
}