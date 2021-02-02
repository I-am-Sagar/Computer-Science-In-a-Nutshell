/*  A Doubly Linked List (DLL) contains an extra pointer,
    typically called previous pointer, together with next pointer
    and data which are there in singly linked list.

    Advantages over singly linked list
    1) A DLL can be traversed in both forward and backward direction.
    2) The delete operation in DLL is more efficient if pointer to
       the node to be deleted is given.
    3) We can quickly insert a new node before a given node.

    In singly linked list, to delete a node, pointer to the previous
    node is needed. To get this previous node, sometimes the list is
    traversed. In DLL, we can get the previous node using previous pointer.

    Disadvantages over singly linked list
    1) Every node of DLL Require extra space for an previous pointer.
       However it is possible to implement with single pointer only.
       (This is discussed in 15_Memory_efficient_DLL.cpp)
    2) All operations require an extra pointer previous to be maintained.
       Due to this, task of fixing links becomes little cumbersome.


    A node can be added in a DLL in three ways:
    1) At the front of the DLL
    2) After a given node
    3) At the end of the DLL

    We have mentioned steps in the comments of code.
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
void printList (Node* node) {
    Node* last;
    cout << "Traversal in Forward Direction:\n";
    while (node != NULL) {
        cout << " " << node->data << " ";
        last = node;
        node = node->next;
    }
    cout << endl;

    cout << "Traversal in Reverse Direction:\n";
    while (last != NULL) {
        cout << " " << last->data << " ";
        last = last->prev;
    }
    cout << endl;
}

// Main Logic of Insertion Code

/* The following function inserts the node in front of DLL */
void push (Node** head_ref, int new_data) {
    // 1. Allocate new node
    Node* new_node = new Node(new_data);
    // 2. Make next of new_node as head and previous as NULL
    new_node->next = *head_ref;
    new_node->prev = NULL;
    // 3. Change prev of head_node to new_node
    if ((*head_ref)!= NULL)
        (*head_ref)->prev = new_node;
    // 4. Move the head to print to the new_node
    (*head_ref) = new_node;
}

/* The following function inserts the node after the given node */
void insertAfter (Node* prev_node, int new_data) {
    // 1. Check if the previous node given is NULL
    if (prev_node == NULL) {
        cout << "The given previous node cannot be NULL.\n";
        return;
    }

    // 2. Allocate a new node
    Node* new_node = new Node(new_data);

    // 3. Make next of new_node as next of previous node
    new_node->next = prev_node->next;

    // 4. Make the next of prev_node as new node
    prev_node->next = new_node;

    // 5. Make prev_node as previous of new node
    new_node->prev = prev_node;

    // 6. Change previous of new_node's next node
    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

/* Following function adds node in the last of list */
void append (Node** head_ref, int new_data) {
    // 1. Allocate Node
    Node* new_node = new Node(new_data);
    Node* last = *head_ref; // Will be used in step 4
    // 2. This new node will be last. So make next of it as NULL.
    new_node->next = NULL;
    // 3. If the linked list is empty, make new node as head.
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
    // 4. Else traverse till last node
    while (last->next != NULL)
        last = last->next;
    // 5. Change the next of last node
    last->next = new_node;
    // 6. Make last node as previous of new node
    new_node->prev = last;
}

/* ------------------- MAIN DRIVER CODE --------------------- */
int main() {
    Node* head = NULL;
    // Try to predict the DLL formed below
    append(&head, 6);
    push(&head, 7);
    push(&head, 1);
    append(&head, 4);
    insertAfter(head->next, 8);

    printList(head);

    return 0;
}