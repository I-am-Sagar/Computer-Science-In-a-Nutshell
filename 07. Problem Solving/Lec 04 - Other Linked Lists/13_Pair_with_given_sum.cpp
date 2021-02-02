/*  PROBLEM:
    Given a sorted doubly linked list of positive distinct
    elements, the task is to find pairs in doubly linked list
    whose sum is equal to given value x

    Input : head : 1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9 and x = 7
    Output: (6, 1), (5,2)

    SOLUTION:

    1. Initialize two pointer variables to find the candidate elements
       in the sorted doubly linked list.Initialize first with start of
       doubly linked list i.e; first=head and initialize second with
       last node of doubly linked list i.e; second=last_node.
    2. We initialize first and second pointers as first and last nodes.
       Here we don’t have random access, so to find second pointer, we
       traverse the list to initialize second.
    3. If current sum of first and second is less than x, then we move
       first in forward direction. If current sum of first and second
       element is greater than x, then we move second in backward direction.
    4. Loop termination conditions are also different from arrays. The loop
       terminates when either of two pointers become NULL, or they cross each
       other (second->next = first), or they become same (first == second).
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->next = NULL;
    }
};

// Auxiliary Function to Traverse list
void printList(Node* node)  {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

void push (Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = *head_ref;
    new_node->prev = NULL;
    if ((*head_ref)!= NULL)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}

// Main Logic of Code
void pairSum(struct Node *head, int x) {
    // Set two pointers, first to the beginning of DLL
    // and second to the end of DLL.
    struct Node *first = head;
    struct Node *second = head;

    while (second->next != NULL)
         second = second->next;

    // To track if we find a pair or not
    bool found = false;

    // The loop terminates when either of two pointers become NULL,
    // or they cross each other (second->next == first), or
    // they become same (first == second)
    while (first != NULL && second != NULL && first != second && second->next != first) {
        // pair found
        if ((first->data + second->data) == x) {
            found = true;
            cout << "(" << first->data<< ", " << second->data << ")" << endl;
            // move first in forward direction
            first = first->next;
            // move second in backward direction
            second = second->prev;
        }
        else {
            if ((first->data + second->data) < x)
                first = first->next;
            else
                second = second->prev;
        }
    }
    // if pair is not present
    if (found == false)
        cout << "No pair found.\n";
}

/* --------------------- MAIN DRIVER CODE -------------------- */
int main() {
    struct Node *head = NULL;
    push(&head, 9);
    push(&head, 8);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 2);
    push(&head, 1);
    int x = 7;

    pairSum(head, x);

    return 0;
}