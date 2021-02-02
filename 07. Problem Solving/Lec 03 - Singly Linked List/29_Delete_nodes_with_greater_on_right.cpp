/*  PROBLEM:
    Given a singly linked list, remove all the nodes
    which have a greater value on right side.

    Examples:
    a) The list 12->15->10->11->5->6->2->3->NULL should be changed
       to 15->11->6->3->NULL. Note that 12, 10, 5 and 2 have been
       deleted because there is a greater value on the right side.

    b) The list 10->20->30->40->50->60->NULL should be changed to 60->NULL.

    c) The list 60->50->40->30->20->10->NULL should not be changed.

    ALGORITHM:
    1. Reverse the list
    2. Traverse the reversed the list. Keep max till now.
       If next node is less than max, then delete the next node,
       else, max = next node.
    3. Reverse the list again to retain the original order.
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

// Utility Function used in Main Logic
void reverseList (Node** head_ref) {
    Node* current = *head_ref;
    Node* prev = NULL;
    Node* next;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

// Main Logic of Code
void deleteLesserNodes (Node** head_ref) {
    reverseList(head_ref);

    Node* current = *head_ref;
    Node* maxNode = current;
    Node* temp;

    while (current!=NULL && current->next != NULL){
        if (current->next->data < maxNode->data) {
            temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        else {
            current = current->next;
            maxNode = current;
        }
    }

    reverseList(head_ref);
}

/* ------------------- MAIN DRIVER CODE ----------------- */
int main() {
    Node* head = NULL;

    // 12->15->10->11->5->6->2->3
    push(&head, 3);
    push(&head, 2);
    push(&head, 6);
    push(&head, 5);
    push(&head, 11);
    push(&head, 10);
    push(&head, 15);
    push(&head, 12);

    printf("Given Linked List: \n");
    printList(head);

    deleteLesserNodes(&head);

    printf("Modified Linked List: \n");
    printList(head);

    return 0;
}