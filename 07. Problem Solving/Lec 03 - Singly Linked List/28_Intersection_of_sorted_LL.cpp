/*  PROBLEM:
    Given two lists sorted in increasing order, create and
    return a new list representing the intersection of the two lists.
    For example, let the first linked list be 1->2->3->4->6 and
    second linked list be 2->4->6->8, then your function should create
    and return a third list as 2->4->6.

    Note: Here intersection means common elements (as in Set Theory).
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
Node* sortedIntersect (Node* a, Node* b) {
    Node* result = NULL;
    Node** last_ptr_ref = &result;

    // Compare the first nodes of both lists and advance
    // When one or the other list exhausts, we are done.
    while (a!=NULL && b!=NULL) {
        if (a->data == b->data) {
            push (last_ptr_ref, a->data);
            last_ptr_ref = &((*last_ptr_ref)->next);
            a = a->next;
            b = b->next;
        }
        else if (a->data < b->data)
        // advance smaller list
            a = a->next;
        else
            b = b->next;
    }
    return result;
}

/* ------------------ MAIN DRIVER CODE ------------------ */
int main() {
    struct Node* a = NULL;
    struct Node* b = NULL;
    struct Node *intersect = NULL;

    // First List: 1->2->3->4->5->6
    push(&a, 6);
    push(&a, 5);
    push(&a, 4);
    push(&a, 3);
    push(&a, 2);
    push(&a, 1);

    // Second List: 2->4->6->8
    push(&b, 8);
    push(&b, 6);
    push(&b, 4);
    push(&b, 2);

    intersect = sortedIntersect(a, b);

    cout << "Intersection List:\n";
    printList(intersect);

    return 0;
}