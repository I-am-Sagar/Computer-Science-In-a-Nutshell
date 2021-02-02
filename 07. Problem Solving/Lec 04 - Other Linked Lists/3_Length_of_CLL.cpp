#include <bits/stdc++.h>
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

// Main Logic of code
int countNodes(struct Node* head) {
    struct Node* temp = head;
    int result = 0;
    if (head != NULL) {
        do {
            temp = temp->next;
            result++;
        } while (temp != head);
    }

    return result;
}

/* ----------------- MAIN DRIVER CODE ---------------- */
int main() {
    Node* head = NULL;
    push(&head, 12);
    push(&head, 56);
    push(&head, 2);
    push(&head, 11);

    printList(head);
    printf("%d", countNodes(head));
    cout << endl;

    return 0;
}