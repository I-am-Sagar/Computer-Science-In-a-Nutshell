/*  PROBLEM:
    Given a singly linked list, rotate the linked list
    counter-clockwise by k nodes.

    ALGORITHM:
    1. To rotate the linked list, we need to
       - change next of kth node to NULL
       - change next of the last node to the previous head node
       - change head to (k+1)th node.
       So we need to get hold of three nodes: kth node, (k+1)th node and last node.

    2. Traverse the list from the beginning and stop at kth node.
       Store pointer to kth node. We can get (k+1)th node using kthNode->next.
       Keep traversing till the end and store pointer to last node also.
       Finally, change pointers as stated above.
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

// Auxiliary Functions
void push (Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Main Logic of Code

/* The following function assumes that 'k' is smaller
   than the size of linked list and does nothing if
   k is equal or more than the size of the list.*/
void rotate (Node** head_ref, int k) {
    if (k==0)   return;
    Node* current = *head_ref;

    // Advance current by 'k' nodes
    int count = 1;
    while (count < k && current != NULL) {
        current = current->next;
        count++;
    }
    // If current is NULL that means 'k' is
    // greater than the size of the list
    if (current == NULL)    return;

    // Current points to kth node now. Store it.
    Node* kthNode = current;

    // Make current point to the last node now
    while (current->next!=NULL)
        current = current->next;

    // Change next of the last node to the head
    current->next = *head_ref;

    // Change head of (k+1)th node
    *head_ref = kthNode->next;

    // Change next of kth node to NULL
    kthNode->next = NULL;
}

/* --------------------- MAIN DRIVER CODE ------------------ */
int main(void) {
    Node* head = NULL;

    // create a list 10->20->30->40->50->60->70
    for (int i = 70; i > 0; i -= 10)
        push(&head, i);

    cout << "Given linked list: \n";
    printList(head);
    rotate(&head, 4);

    cout << "\nRotated Linked list: \n";
    printList(head);

    return (0);
}