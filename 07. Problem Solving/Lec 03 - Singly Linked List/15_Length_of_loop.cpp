/*
Write a function detectAndCountLoop() that checks whether a given Linked List
contains loop and if loop is present then returns count of nodes in loop.
For example, loop is present in below linked list and length of loop is 4.
1 -> 2 -> 3
     |    |
     5 <- 4
If loop is not present, then function should return 0.

Approach:
    We know that in Floyd's algo, slow and fast pointers meet at common node
    which is part of the loop. We store this address in third pointer 'ptr'.
    We initialize count = 1 and start from 'ptr' and keep on increasing this
    count till we reach again at 'ptr'. We then return this count.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data) {
    Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

int countNodes (Node* n) {
    int count = 1;
    Node* temp = n;
    while (temp->next != n) {
        count++;
        temp = temp->next;
    }
    return count;
}

int countNodesInLoop (Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return countNodes(slow);
    }
    return 0;
}

/* -------------- MAIN DRIVER CODE ---------------- */
int main() {
    Node* head = NULL;
    // List is 10-15-4-20-Null;
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);

    // Creating a loop. Pointer of 20 (viz. NULL) now points to 15.
    head->next->next->next->next = head->next;
    cout << "Length of Loop is: " << countNodesInLoop(head) << endl;

    return 0;
}