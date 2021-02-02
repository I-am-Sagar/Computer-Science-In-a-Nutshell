/*  PROBLEM:
    Given a linked list, write a function to reverse every
    k nodes (where k is an input to the function).
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
Node* reverse (Node* head, int k) {
    Node* current = head;
    Node* subsequent = NULL;
    Node* previous = NULL;
    int count = 0;

    // Reverse first K nodes of the linked list
    while (current != NULL && count < k) {
        subsequent = current->next;
        current->next = previous;
        previous = current;
        current = subsequent;
        count++;
    }

    // 'subsequent' is now pointing to the (k+1)th node
    // Recursively call the function for the remaining list
    if (subsequent != NULL)
        head->next = reverse(subsequent, k);

    // Previous is the new head of the input list
    return previous;
}

/* --------------------- MAIN DRIVER CODE ------------------ */
int main() {
    Node* head = NULL;

    // Created Linked list is 1->2->3->4->5->6->7->8
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    cout << "Given linked list: \n";
    printList(head);
    head = reverse(head, 3);

    cout << "\nReversed Linked list: \n";
    printList(head);

    return(0);
}

/* ADDITIONAL POINT:

    If there is a question which says "Reverse alternate K nodes",
    then reverse first k nodes and move the current pointer k
    nodes ahead and then recursively call for the rest of the list.

    count = 0;
    while(count < k-1 && current != NULL ) {
        current = current->next;
        count++;
    }
*/