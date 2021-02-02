// Video Link 1: https://www.youtube.com/watch?v=sYcOK51hl-A
// Video Link 2: https://www.youtube.com/watch?v=MRe3UsRadKw

/* PROBLEM:
    Given pointer to the head node of a linked list,
    the task is to reverse the linked list. For example,
    Input : 1->2->3->4->NULL
    Output : 4->3->2->1->NULL

   SOLUTION:

    Approach - 1 (Iterative Method - 1)
    1. Initialize three pointers, prev as NULL, curr as head
       and next as NULL.
    2. Traverse the linked list and do the following:
        // Before changing next of current, store next node
        a) next = curr->next
        // Now change next of current to previous node.
        // This is the step where reversing happens.
        b) curr->next = prev
        // Move prev and curr one step forward
        c) prev = curr
           curr = next

    Approach - 2 (Recursive Method)
    1. Divide the list in two parts - first node and
       rest of the linked list.
    2. Call reverse for the rest of the linked list.
    3. Link rest to first.
    4. Fix head pointer

    Approach - 3 (Iterative Method - 2)
    In iterative method we had used 3 pointers prev, cur and next.
    There is code below which uses just two pointers.
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

// Method 1
void reverse1 (Node** head_ref) {
    Node* current = *head_ref;
    Node* prev = NULL, *next = NULL;
    while (current != NULL) {
        // store next
        next = current->next;
        // reverse current node's pointer
        current->next = prev;
        // Move pointers one position ahead
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

// Method 2
void reverse2 (Node** head_ref) {
    if (*head_ref == NULL) return;

    Node* first;
    Node* rest;

    first = *head_ref;
    rest  = first->next;

    // If list has only one node
    if (rest == NULL) return;

    // Recurse on the rest of the string
    reverse2(&rest);

    // Link rest to first
    first->next->next  = first;
    first->next  = NULL;

    // fix the head pointer
    *head_ref = rest;
}

// Method 3
void reverse3 (Node** head_ref) {
    Node* current = *head_ref;
    Node* subsequent;
    while(current->next != NULL) {
        subsequent = current->next;
        current->next = subsequent->next;
        subsequent->next = *head_ref;
        *head_ref = subsequent;
    }
}

/* ------------------ MAIN DRIVER CODE ------------- */
int main() {
    Node* head = NULL;

    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 85);

    printf("Given linked list:\n");
    printList(head);

    reverse1(&head);
    printf("\nReversed Linked list:\n");
    printList(head);

    reverse2(&head);
    printf("\nReversed Linked list:\n");
    printList(head);

    reverse3(&head);
    printf("\nReversed Linked list:\n");
    printList(head);

    return 0;
}

/* ADDITIONAL POINT:

    If you just want to print the list in reverse order,
    without actually reversing the linked list, here is
    the recursive code for that:

    void printReverse (Node* head) {
        // Base case
        if (head == NULL)   return;
        // Recurse for the remaining list
        printReverse (head->next);
        // Print data from last node
        cout << head->data << " ";
    }

*/