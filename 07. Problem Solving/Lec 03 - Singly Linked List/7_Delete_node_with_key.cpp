/*  Here we have to delete a node which stores the value equal to 'key'.
    Since last few codes, we have been using malloc() and free() for memory management.
    In this code, we will use C++'s 'new' and 'delete' operators.
 */

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void push (Node** head_ref, int new_data) {
    Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = (*head_ref);
    *head_ref = new_node;
}

void deleteNode (Node** head_ref, int key) {
    if (*head_ref == NULL) {
        cout << "Empty List.\n";
        return;
    }

    Node* temp1 = *head_ref;
    if (temp1->data == key) {
        *head_ref = temp1->next;
        delete temp1;
    }
    else {
        while (temp1->next != NULL && temp1->next->data != key)
            temp1 = temp1->next;

        if (temp1 == NULL) {
            cout << "Key not found.\n";
        }
        else {
            Node* temp2 = temp1->next;
            temp1->next = temp2->next;
            delete temp2;
        }
    }
}

void printList(struct Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

/* -------------- MAIN DRIVER CODE ---------------- */
int main() {
    /* Start with the empty list */
    struct Node* head = NULL;

    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);

    puts("Created Linked List: ");
    printList(head);
    deleteNode(&head, 3);
    puts("\nLinked List after Deletion of 3: ");
    printList(head);
    return 0;
}