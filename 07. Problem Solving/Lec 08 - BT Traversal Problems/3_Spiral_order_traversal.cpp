/*  PROBLEM:
    Write a function to print spiral order traversal of a tree.

    For example, for given tree:
                1
               / \
              2   3
            /  \ /  \
           7   6 5   4

    Output: 1 2 3 4 5 6 7
    NOTE: The above spiral traversal is Counter-Clockwise Traversal.

    SOLUTION:

    Recursive Approach:
    We will use normal Level Order Traversal. An additional Boolean
    variable ltr is used to change printing order of levels.
    If ltr is 1 then printGivenLevel() prints nodes from left to right
    else from right to left. Value of ltr is flipped in each iteration
    to change the order.

    Worst case time complexity of the above method is O(n^2).
    Worst case occurs in case of skewed trees.

    Iterative Approach:
    We can print spiral order traversal in O(n) time and O(n) extra space.
    The idea is to use two stacks. We can use one stack for printing from
    left to right and other stack for printing from right to left.
    In every iteration, we have nodes of one level in one of the stacks.
    We print the nodes, and push nodes of next level in other stack.
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

// Utility Functions for Recursive Approach
int height (Node* root) {
    if (root == NULL)   return 0;
    return (max(height(root->left), height(root->right)) + 1);
}

void printGivenLevel (Node* root, int level, int ltr) {
    if (root == NULL)   return;
    if (level == 1)
        cout << root->data << " ";
    if (ltr) {
        printGivenLevel(root->left, level-1, ltr);
        printGivenLevel(root->right, level-1, ltr);
    } else {
        printGivenLevel(root->right, level-1, ltr);
        printGivenLevel(root->left, level-1, ltr);
    }
}

// Main Logic of Recursive Approach
void printSpiralRec (Node* root) {
    int h = height (root);
    bool ltr= false;
    for (int i = 1; i <= h; i++) {
        printGivenLevel(root, i, ltr);
        ltr = !ltr;
    }
    cout << endl;
}

// Main Logic of Iterative Approach
void printSpiralItr (Node* root) {
    if (root == NULL)   return;

    // Stack 1: For levels to be printed from R to L
    stack <Node*> s1;
    // Stack 2: For levels to be printed from L to R
    stack <Node*> s2;

    s1.push(root);

    while(!s1.empty() || !s2.empty()) {
        while (!s1.empty()) {
            Node* temp = s1.top();
            s1.pop();
            cout << temp->data << " ";

            // Note right node is pushed before left
            if (temp->right) s2.push(temp->right);
            if (temp->left) s2.push(temp->left);
        }
        while (!s2.empty()) {
            Node* temp = s2.top();
            s2.pop();
            cout << temp->data << " ";

            // Note left node is pushed before right
            if (temp->left) s1.push(temp->left);
            if (temp->right) s1.push(temp->right);
        }
    }
    cout << endl;
}

/* -------------------- MAIN DRIVER CODE ------------------ */
int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);
    cout << "Spiral Order traversal:\n";
    printSpiralRec(root);
    printSpiralItr(root);

    return 0;
}

/*  ADDITIONAL POINT:

    The Clockwise Spiral Traversal is also known as "ZigZag Traversal".
    For example, for given tree:
                1
               / \
              2   3
            /  \ /  \
           7   6 5   4

    Zigzag Traversal: 1 3 2 7 6 5 4

    The only thing we need to modify in above "Spiral Order Traversal"
    code is:
    a) In Recursive Function:
        "ltr" flag. We will initially consider "ltr" flag to be true
        instead of false.
    b) In Iterative Function:
        The use of stacks will change. Stack 1 will be used to print
        from L to R and Stack 2 will be used to print from R to L.
        To do so, we interchange the order of pushing left and right
        nodes onto stack. So the modified while loop becomes:

    while(!s1.empty() || !s2.empty()) {
        while (!s1.empty()) {
            Node* temp = s1.top();
            s1.pop();
            cout << temp->data << " ";

            // Note left node is pushed before right
            if (temp->left) s1.push(temp->left);
            if (temp->right) s1.push(temp->right);
        }
        while (!s2.empty()) {
            Node* temp = s2.top();
            s2.pop();
            cout << temp->data << " ";

            // Note right node is pushed before left
            if (temp->right) s2.push(temp->right);
            if (temp->left) s2.push(temp->left);
        }
    }

*/
