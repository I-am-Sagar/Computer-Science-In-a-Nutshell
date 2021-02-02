/*
ORDINARY REPRESENTATION:
    Node A:
    prev = NULL, next = add(B) // previous is NULL and next is address of B
    Node B:
    prev = add(A), next = add(C) // previous is address of A and next is address of C
    Node C:
    prev = add(B), next = add(D) // previous is address of B and next is address of D
    Node D:
    prev = add(C), next = NULL // previous is address of C and next is NULL

XOR REPRESENTATION:
    Let us call the address variable in XOR representation npx (XOR of next and previous)

    Node A:
    npx = 0 XOR add(B) // bitwise XOR of zero and address of B
    Node B:
    npx = add(A) XOR add(C) // bitwise XOR of address of A and address of C
    Node C:
    npx = add(B) XOR add(D) // bitwise XOR of address of B and address of D
    Node D:
    npx = add(C) XOR 0 // bitwise XOR of address of C and 0

TRAVERSAL of XOR Linked List:
    We can traverse the XOR list in both forward and reverse direction.
    While traversing the list we need to remember the address of the
    previously accessed node in order to calculate the next node’s address.

    For example when we are at node C, we must have address of B.
    XOR of add(B) and npx of C gives us the add(D).
    The reason is simple: npx(C) is “add(B) XOR add(D)”.
    If we do xor of npx(C) with add(B), we get the result as
    “add(B) XOR add(D) XOR add(B)” which is “add(D) XOR 0” which is “add(D)”.
    So we have the address of next node.

    Similarly we can traverse the list in backward direction.
*/

#include <bits/stdc++.h>
#include <inttypes.h>
using namespace std;

class Node {
    public:
        int data;
        Node* npx; // XOR of next and previous node
        Node(int data) {
            this->data = data;
            this->npx = NULL;
        }
};

// Utility function which returns XOR of 2 node pointers
Node* XOR (Node *a, Node *b) {
    return (Node*) ((uintptr_t) (a) ^ (uintptr_t) (b));
}

// Insert a node at the beginning of the XORed linked list
// and makes the newly inserted node as head
void insert(Node **head_ref, int data) {

    Node *new_node = new Node(data);

    /* Since new node is being inserted at the beginning,
       npx of new node will always be XOR of current head
       and NULL */
    new_node->npx = XOR(*head_ref, NULL);

    /* If linked list is not empty, then npx of current head
       node will be XOR of new node and node next to current head
    */
    if (*head_ref != NULL) {
        // *(head_ref)->npx is XOR of NULL and next.
        // So if we do XOR of it with NULL, we get next
        Node* next = XOR((*head_ref)->npx, NULL);
        (*head_ref)->npx = XOR(new_node, next);
    }

    // Change head
    *head_ref = new_node;
}

// Function to traverse XOR implemented DLL
void printList (Node *head) {
    Node *curr = head;
    Node *prev = NULL;
    Node *next;

    cout << "Created DLL: \n";

    while (curr != NULL) {
        // print current node
        cout<<curr->data<<" ";

        // get address of next node: curr->npx is next^prev,
        // so curr->npx^prev will be next^prev^prev which is next
        next = XOR (prev, curr->npx);

        // update prev and curr for next iteration
        prev = curr;
        curr = next;
    }
    cout << endl;
}

/* ------------------- MAIN DRIVER CODE ------------------ */
int main () {
    Node *head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);

    printList (head);

    return (0);
}