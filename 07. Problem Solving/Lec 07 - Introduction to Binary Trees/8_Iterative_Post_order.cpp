// Video Link 1: https://www.youtube.com/watch?v=c_vyOxS7fL4
// Video Link 2: https://www.youtube.com/watch?v=kcTcfOWFizA

/* ALGORITHM:

    a) Method 1 - Using Two Stacks

        1. Push root to auxiliary stack.
        2. Loop while auxiliary stack is not empty
            a) Pop a node from auxiliary stack and push it to result stack
            b) Push left and right children of the popped node to auxiliary stack
        3. Print contents of result stack

    b) Method 2 - Using One Stack

        1. Create an empty stack
        2. Do following while root is not NULL
            a) Push root's right child and then root to stack.
            b) Set root as root's left child.
        3. Pop an item from stack and set it as root.
            a) If the popped item has a right child and the right child
                is at top of stack, then remove the right child from stack,
                push the root back and set root as root's right child.
            b) Else print root's data and set root as NULL.
        4. Repeat steps 2 and 3 while stack is not empty.

    Note:
        One stack solution is no better than 2 stacks solution in terms of space complexity.
        If you look at 2 stack solution, every time you pop from one stack you push onto another
        stack, so essentially you are not maintaining more than one copy of the same element
        across the stacks. It is just a different way to think the solution.
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
void postOrderTwo(Node* root) {
    if (root == NULL)   return;
    stack <Node*> st, result;
    st.push(root);

    while (!st.empty()) {
        Node* current = st.top();
        st.pop();
        result.push(current);

        if (current->left != NULL)
            st.push(current->left);
        if (current->right != NULL)
            st.push(current->right);
    }

    while (!result.empty()) {
        cout << result.top()->data << " ";
        result.pop();
    }
}

void postOrderOne (Node* root) {
    Node *current = root;
    stack <Node*> st;

    while (true) {
        if (current != NULL) {
            st.push(current);
            current=current->left;
        }
        else {
            if (st.empty()) break;
            current = st.top()->right;
            if (current == NULL) {
                Node* last = NULL;
                while (!st.empty() && st.top()->right == last) {
                    last = st.top();
                    st.pop();
                    cout << last->data << " ";
                }
            }
        }
    }
}

/* ---------------- MAIN DRIVER CODE ---------------- */
int main() {

    /* Constructed binary tree is:
              1
            /   \
          2      3
        /  \      \
      4     5       6
    */
    struct Node *root = new Node(1);
    root->left        = new Node(2);
    root->right       = new Node(3);
    root->left->left  = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    postOrderTwo(root);
    cout << endl;
    postOrderOne(root);

    return 0;
}