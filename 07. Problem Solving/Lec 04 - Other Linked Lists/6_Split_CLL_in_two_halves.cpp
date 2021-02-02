/*  Write a function to split a CLL into two halves.
    If there are odd number of nodes, then first should contain one extra.

    ALGORITHM:
    1. Store the mid and last pointers of the CLL using tortoise
       and hare algorithm.
    2. Make the second half circular
    3. Make the first half circular
    4. Set head (or start) pointers of the two linked lists.
*/

#include <bits/stdc++.h>
using namespace std;

class Node  {
    public:
        int data;
        Node *next;
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

// Auxiliary Function
void printList(Node *start)  {
    Node *temp;

    if(start != NULL)  {
        temp = start;
        do {
        cout<<temp->data<<" ";
        temp = temp->next;
        } while(temp != start);
    }
    cout << endl;
}

void push (Node** head_ref, int data) {
    Node* ptr1 = new Node(data);
    ptr1->next = *head_ref;
    // If linked list is not NULL then set the next
    // of last node
    if (*head_ref != NULL) {
        // Find the node before head and update next of it
        Node* temp = *head_ref;
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1;

    *head_ref = ptr1;
}

// Function to split a list
void splitList (Node* head, Node** head1_ref, Node** head2_ref) {
    Node* slow_ptr = head;
    Node* fast_ptr = head;

    if (head == NULL)
        return;

    /* If there are odd nodes in the circular list
       then fast_ptr->next becomes head and for
       even nodes fast_ptr->next->next becomes head. */
    while (fast_ptr->next != head && fast_ptr->next->next != head) {
        fast_ptr = fast_ptr->next->next;
        slow_ptr = slow_ptr->next;
    }

    // If there are even number of nodes, then move fast_ptr
    if (fast_ptr->next->next == head)
        fast_ptr = fast_ptr->next;

    // Set the head pointer of first half
    *head1_ref = head;
    // Set the head pointer of second half
    if (head->next != head)
        *head2_ref = slow_ptr->next;

    // Make second half circular
    fast_ptr->next = slow_ptr->next;
    // Make first half circular
    slow_ptr->next = head;
}

/* ------------------- MAIN DRIVER CODE ---------------- */
int main() {
    struct Node *head = NULL;
    struct Node *head1 = NULL;
    struct Node *head2 = NULL;

    /* Created linked list will be 12->56->2->11 */
    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);

    printf("Original Circular Linked List: ");
    printList(head);

    splitList(head, &head1, &head2);

    printf("First Circular Linked List: ");
    printList(head1);

    printf("Second Circular Linked List: ");
    printList(head2);

    return 0;
}