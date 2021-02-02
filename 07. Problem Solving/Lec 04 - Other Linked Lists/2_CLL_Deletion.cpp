/*
    We need to delete node from CLL.
    If the list is empty we will simply return.

    If the list is not empty, then we define two pointers 'curr' and 'prev'.
    Initialize the 'curr' pointer with the head node.
    Traverse the list using 'curr' pointer and find the node to be deleted.
    Maintain a 'prev' node, which will be previous to 'curr' pointer at any time.
    - If the node is found, check if it's the only node in the list.
      If yes, set head = NULL and delete curr.
    - If the list has more than one node, check if it is the first node of the list.
      If yes, then move the prev pointer to last node. Then,
        head = head->next   and     prev->next = head.  Delete curr.
    - If curr is not first node, we check if it is the last node in the list.
      If yes, set   prev->next = head   and     delete curr.
    - If node to be deleted is neither the first node and nor the last node,
      set   prev->next = temp->next     and     delete curr.
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node (int data) {
            this->data = data;
            this->next = NULL;
        }
};

// Auxiliary Function ot print the CLL
void printList (Node* last) {
    Node* temp;
    // If list is empty, return.
    if (last == NULL) {
        cout << "List is empty.\n";
        return;
    }

    temp = last->next;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != last->next);
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

// Main Logic of Code
void deleteNode (Node** head, int key) {
    // If linked list is empty, just return
    if (*head == NULL)  return;

    // If the list contains only a single node
    if ((*head)->data == key && (*head)->next == *head) {
        delete *head;
        *head = NULL;
    }

    Node* last = *head, *d;

    // If head is to be deleted
    if ((*head)->data == key) {
        // Find the last node of the list
        while (last->next != *head)
            last = last->next;
        // Point last node to the next of head i.e. second last node
        last->next = (*head)->next;
        delete *head;
        *head = last->next;
    }

    // Either the node to be deleted is not found
    // Or the end of the list is not reached
    while (last->next != *head && last->next->data != key) {
        last = last->next;
    }

    // If node to be deleted was found
    if (last->next->data == key) {
        d = last->next;
        last->next = d->next;
        delete d;
    }
    else
        cout << "No such key found!\n";
}

/* -------------------- MAIN DRIVER CODE ----------------- */
int main() {
    Node* head = NULL;
    push(&head, 2);
    push(&head, 5);
    push(&head, 7);
    push(&head, 8);
    push(&head, 10);

    cout << "List Before Deletion: ";
    printList(head);

    deleteNode(&head, 7);

    cout << "List After Deletion: ";
    printList(head);

    return 0;
}