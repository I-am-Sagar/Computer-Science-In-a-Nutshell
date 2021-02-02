/* This thing is to be done in C++ or python only. In Java,
   there is automatic garbage collector. */

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

void deleteList (Node** head_ref) {
    Node* current = *head_ref;
    Node* next;

    while (current != NULL) {
        next = current->next;
        delete current;
        current = next;
    }
    *head_ref = NULL;
}

void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

/* -------------- MAIN DRIVER CODE ---------------- */
int main() {
    /* Start with the empty list */
    Node* head = NULL;

    /* Use push() to construct below list
    1->12->1->4->1 */
    push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 12);
    push(&head, 1);

    cout << "Deleting linked list\n";
    deleteList(&head);

    cout << "Linked list deleted";
    return 0;
}
