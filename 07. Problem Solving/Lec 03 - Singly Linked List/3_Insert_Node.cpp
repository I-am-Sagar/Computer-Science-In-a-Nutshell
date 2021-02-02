// Video Link: https://www.youtube.com/watch?v=cAZ8CyDY56s

/* A node in Linked List can be added in 3 ways:
    a) At the front of the linked list (this new node will become head)
    b) After the given node (somewhere in between)
    c) At the end of the linked list (the pointer of this new node will point to NULL)
*/
#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

void insertBeginning (Node** head_ref, int new_data) {
    // 1. Create a new node to be added in the beginning of the list
    Node* new_node = new Node();
    new_node->data = new_data;

    // 2. Make next of this new_node as head
    new_node->next = *head_ref;

    // 3. Move the head to point to this new_node
    *head_ref = new_node;
}

void insertAfter (Node** prev_node, int new_data) {
    // 1. Check if pervious node is not Null
    if (*prev_node == NULL) {
        cout << "The given previous node cannot be Null.\n";
        return;
    }

    // 2. Create a new node to be added
    Node* new_node = new Node();
    new_node->data = new_data;

    // 3. Make next of this new node as the next of previous node
    new_node->next = (*prev_node)->next;

    // 4. Move the next of prev node to this new node
    (*prev_node)->next = new_node;
}

void insertEnd (Node** head_ref, int new_data) {
    // 1. Create new node to be added
    Node* new_node = new Node();
    new_node->data = new_data;
    Node* last = *head_ref;     // This is used in step 4

    // 2. This new node is now last node so make it's next as Null
    new_node->next = NULL;

    // 3. If the linked list is empty, make this new node as head.
    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    // 4. Else travel to the last node and change the next of the last node
    while (last->next != NULL)
        last = last->next;
    last->next = new_node;

    return;
}

// Function to print the list
void printList(Node *node) {
    while (node != NULL) {
        cout<<" "<<node->data;
        node = node->next;
    }
    cout << endl;
}

/* -------------- MAIN DRIVER CODE ---------------- */
int main() {
    // Start with empty list
    Node* head = NULL;

    // Now the list becomes 6 -> NULL
    insertEnd(&head, 6);

    // Now the list becomes 7 -> 6 -> NULL
    insertBeginning(&head, 7);

    // Now the list becomes 7 -> 6 -> 8 -> NULL
    insertAfter(&(head->next), 8);

    //Now the list becomes 7 -> 6 -> 8 -> 9 -> NULL
    insertAfter(&(head->next->next), 9);

    //Now the list becomes 7 -> 6 -> 8 -> 9 -> 5 -> NULL
    insertEnd (&head, 5);

    printList(head);
    return 0;
}