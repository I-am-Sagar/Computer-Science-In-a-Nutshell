/*  A linked list is called circular if it not NULL terminated and
    all nodes are connected in the form of a cycle.

    The idea is to store head of the linked list and traverse it.
    If we reach NULL, linked list is not circular.
    If reach head again, linked list is circular.
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

// Main Logic of code
bool isCircular(struct Node *head) {
    // An empty linked list is circular
    if (head == NULL)
       return true;

    // Next of head
    struct Node *node = head->next;

    // This loop would stope in both cases (1) If
    // Circular (2) Not circular
    while (node != NULL && node != head)
       node = node->next;

    // If loop stopped because of circular condition
    return (node == head);
}

/* ---------------- MAIN DRIVER CODE ---------------- */
int main() {
    struct Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    isCircular(head)? cout << "Yes\n" : cout << "No\n" ;

    // Making linked list circular
    head->next->next->next->next = head;

    isCircular(head)? cout << "Yes\n" : cout << "No\n" ;

    return 0;
}