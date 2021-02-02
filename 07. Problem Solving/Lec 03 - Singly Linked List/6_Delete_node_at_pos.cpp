// Video Link: https://www.youtube.com/watch?v=Y0n86K43GO4

/* Approach:
    If node to be deleted is root, simply delete it. To delete a middle node,
    we must have pointer to the node previous to the node to be deleted.
    So if positions is not zero, we run a loop position-1 times and get
    pointer to the previous node.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// This function inserts node in the beginning
void push (Node** head_ref, int new_data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = new_data;
    new_node->next = (*head_ref);
    *head_ref = new_node;
}

void deleteNode (Node** head_ref, int pos) {
    if (*head_ref == NULL) {    // If the linked list is empty
        cout << "Empty list\n";
        return;
    }

    Node* temp1 = *head_ref;
    if (pos == 1) {   // If the node to be deleted is head node

        *head_ref = temp1->next;    // Head is now pointing to second node
        free(temp1);
        // We cannot free *head_ref because it is the identity of linked list.
        // Once we free head, we have lost the way to access other elements of linked list.
    }
    else {
        // After below statement, temp1 now points to (pos-1)th node
        for (int i = 0; (temp1 != NULL) && (i < pos-2); i++)
            temp1 = temp1->next;    // temp1 will be NULL if pos is greater than size of linked list

        if (temp1 == NULL) {
            cout << "Invalid Position\n";
        }
        else {
            // temp2 points to (pos)th node
            Node* temp2 = temp1->next;

            // Now temp1's next (next of pos-1 node) should point to temp2's next node (pos+1 node)
            temp1->next = temp2->next;

            // Memory is to be freed which is occupied by temp2 (pos)th element
            free(temp2);
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
    push(&head, 8);

    puts("Created Linked List: ");
    printList(head);
    deleteNode(&head, 4);
    puts("\nLinked List after deletion at position 4: ");
    printList(head);
    return 0;
}