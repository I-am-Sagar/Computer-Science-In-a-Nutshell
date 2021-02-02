/*
Given a singly linked list and a number k, find the last node whose n%k == 0, where n is the number of nodes in the list.

Examples:

Input : list = 1->2->3->4->5->6->7
        k = 3
Output : 6

Input : list = 3->7->1->9->8
        k = 2
Output : 9

Approach:

1. Take a pointer modularNode and initialize it with NULL. Traverse the linked list.
2. For every i%k=0, update modularNode.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

/* Function to find modular node in the linked list */
Node* modularNode(Node* head, int k) {
    // Corner cases
    if (k <= 0 || head == NULL)
        return NULL;

    // Traverse the given list
    int i = 1;
    Node* modularNode = NULL;
    for (Node* temp = head; temp != NULL; temp = temp->next) {
        if (i % k == 0)
            modularNode = temp;
        i++;
    }
    return modularNode;
}

/* ----------------------- MAIN DRIVER CODE -------------------- */
int main(void) {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    int k = 2;
    Node* answer = modularNode(head, k);
    printf("\nModular node is ");
    if (answer != NULL)
        printf("%d\n", answer->data);
    else
        printf("Null\n");
    return 0;
}
