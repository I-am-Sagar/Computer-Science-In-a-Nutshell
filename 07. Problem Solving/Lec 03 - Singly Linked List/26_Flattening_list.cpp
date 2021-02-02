/*  PROBLEM:
    Given a linked list where every node represents a linked
    list and contains two pointers of its type:
    1. Pointer to next node in the main list
       (we call it ‘right’ pointer in below code)
    2. Pointer to a linked list where this node
       is head (we call it ‘down’ pointer in below code).

       5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45

    Write a function flatten() to flatten the lists into a single
    linked list. The flattened linked list should also be sorted.

    For example, for the above input list, output list should be
    5->7->8->10->19->20->22->28->30->35->40->45->50.

    SOLUTION:
    The idea is to use Merge() process of merge sort for linked lists.
    We use merge() to merge lists one by one. We recursively merge()
    the current list with already flattened list.
    The down pointer is used to link nodes of the flattened list.
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* right;
        Node* down;
        Node(int data) {
            this->data = data;
            this->right = NULL;
            this->down = NULL;
        }
};

// Auxiliary Functions
void push (Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->down = *head_ref;
    *head_ref = new_node;
}

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->down;
    }
    cout << endl;
}

// Utility merge function
Node* merge( Node* a, Node* b ) {
    // If first list is empty, the second list is result
    if (a == NULL)  return b;
    // If second list is empty, the second list is result
    if (b == NULL)  return a;

    // Compare the data members of head nodes of both lists
    // and put the smaller one in result
    Node* result;
    if (a->data < b->data) {
        result = a;
        result->down = merge( a->down, b );
    }
    else{
        result = b;
        result->down = merge( a, b->down );
    }

    return result;
}

// Main Logic
Node* flatten (Node* root) {
    // Base cases
    if (root == NULL || root->right == NULL)
        return root;

    // Merge this list with the list on right side
    return merge( root, flatten(root->right) );
}

/* --------------------- MAIN DRIVER CODE ------------- */
int main() {
    Node* root = NULL;

    push( &root, 30 );
    push( &root, 8 );
    push( &root, 7 );
    push( &root, 5 );

    push( &( root->right ), 20 );
    push( &( root->right ), 10 );

    push( &( root->right->right ), 50 );
    push( &( root->right->right ), 22 );
    push( &( root->right->right ), 19 );

    push( &( root->right->right->right ), 45 );
    push( &( root->right->right->right ), 40 );
    push( &( root->right->right->right ), 35 );
    push( &( root->right->right->right ), 20 );

    root = flatten(root);
    printList(root);

    return 0;
}