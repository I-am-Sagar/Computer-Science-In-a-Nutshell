/*  PROBLEM:
    Given a sorted doubly linked list containing n nodes.
    The problem is to remove duplicate nodes from the given list.

    ALGORITHM:
    removeDuplicates(head_ref, x):
        if head_ref == NULL
            return
        Initialize current = head_ref
        while current->next != NULL
            if current->data == current->next->data
                deleteNode(head_ref, current->next)
            else
                current = current->next
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

// Utility function to be used in main logic of code
void deleteNode (Node** head_ref, Node* P) {
    if (*head_ref == NULL || P == NULL)
        return;

    if (*head_ref == P)
        *head_ref = P->next;

    if (P->next != NULL)
        P->next->prev = P->prev;

    if (P->prev != NULL)
        P->prev->next = P->next;

    delete P;
}

// Main Logic of Code
void removeDuplicates(Node** head_ref) {
    if ((*head_ref) == NULL)    return;

    struct Node* current = *head_ref;
    struct Node* next;

    while (current->next != NULL) {
        // Compare current node's data with next node's data
        if (current->data == current->next->data)
            // delete the node pointed to by 'current->next'
            deleteNode(head_ref, current->next);
        // else simply move to the next node
        else
            current = current->next;
    }
}

/* ---------------- MAIN DRIVER CODE ----------------- */
int main() {
    struct Node* head = NULL;

    push(&head, 12);
    push(&head, 10);
    push(&head, 8);
    push(&head, 8);
    push(&head, 6);
    push(&head, 4);
    push(&head, 4);
    push(&head, 4);
    push(&head, 4);

    cout << "Original DLL:\n";
    printList(head);

    removeDuplicates(&head);

    cout << "DLL after removing duplicates:\n";
    printList(head);

    return 0;
}

/* ADDITIONAL POINT:
    What if the given DLL is not sorted?
    -> Option 1: We can sort it first and then
       find for it's duplicates as above.
       Time Complexity: O(n*logn) and Space Complexity: O(1)

    -> Option 2: We can use Hash table.
       Time Complexity: O(n) and Space Complexity: O(n)
*/