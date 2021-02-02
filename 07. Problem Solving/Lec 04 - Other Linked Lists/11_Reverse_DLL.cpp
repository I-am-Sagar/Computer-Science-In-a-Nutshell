/*  PROBLEM:
    Write a function to reverse a given Doubly Linked List.

    SOLUTION:
    All we need to do is swap prev and next pointers for all nodes,
    change prev of the head (or start) and change the head pointer
    in the end.
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
void reverse (Node **head_ref) {
    Node *temp = NULL;
    Node *current = *head_ref;

    // swap next and prev for all nodes of DLL
    while (current != NULL)  {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // Before changing head, check for the cases like
    // empty list and list with only one node
    if(temp != NULL )
        *head_ref = temp->prev;
}

/* ----------------- MAIN DRIVER CODE --------------- */
int main() {
    Node* head = NULL;

    // Created linked list will be 10->8->4->2
    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);

    cout << "Original Linked list:" << endl;
    printList(head);

    reverse(&head);

    cout << "Reversed Linked list:" << endl;
    printList(head);

    return 0;
}