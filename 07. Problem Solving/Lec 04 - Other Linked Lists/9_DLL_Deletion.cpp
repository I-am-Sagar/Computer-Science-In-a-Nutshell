/*  Following is the algorithm to delete a node in DLL:

    Let the node to be deleted be 'P'.
    1. If node to be deleted is head node, then change
        the head pointer to next current head.
    2. Set next of previous to 'P', if previous to 'P' exists.
    3. Set prev of next to 'P', if next to 'P' exists.
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
void deleteNode (Node** head_ref, Node* P) {
    if (*head_ref == NULL || P == NULL)
        return;

    // If node to be deleted is head node
    if (*head_ref == P)
        *head_ref = P->next;

    // Change next only if node to be deleted is NOT the last node
    if (P->next != NULL)
        P->next->prev = P->prev;

    // Change prev only if node to be deleted is NOT the first node
    if (P->prev != NULL)
        P->prev->next = P->next;

    delete P;
}

/* ----------------- MAIN DRIVER CODE ------------------ */
int main() {
    Node* head = NULL;
    // Created DLL: 10<->8<->4<->2
    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);

    cout << "Original Linked list:\n";
    printList(head);

    deleteNode(&head, head);    //delete first node
    deleteNode(&head, head->next); // delete middle node
    deleteNode(&head, head->next); // delete last node

    // Modified linked list will be NULL<-8->NULL
    cout << "Modified Linked list:\n";
    printList(head);

    return 0;
}