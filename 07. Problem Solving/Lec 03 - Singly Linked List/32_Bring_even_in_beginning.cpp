/* PROBLEM: Given a Linked List of integers, write a function to modify the LL
    such that all even numbers appear before all the odd numbers in the modified
    LL. Also, keep the order of even and odd numbers same.

    Solution:
    The idea is to split the linked list into two: one containing all even nodes
    and other containing all odd nodes. And finally attach the odd node linked list
    after the even node linked list.

    To split the Linked List, traverse the original Linked List and move all odd nodes
    to a separate Linked List of all odd nodes. At the end of loop, the original list
    will have all the even nodes and the odd node list will have all the odd nodes.

    To keep the ordering of all nodes same, we must insert all the odd nodes at the
    end of the odd node list. And to do that in constant time, we must keep track of
    last pointer in the odd node list.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node (int x) {
        data = x;
        next = NULL;
    }
};

void push(Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node *node) {
    while (node!=NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Main logic of code
void segregateEvenOdd(Node** head_ref) {
    Node* evenStart = NULL;
    Node* evenEnd = NULL;
    Node* oddStart = NULL;
    Node* oddEnd = NULL;
    Node* current = *head_ref;

    while (current!=NULL) {
        int value = current->data;
        // If value is even, add node to even list
        // or else, add node to odd list
        if (value%2 == 0)
            if (evenStart == NULL) {
                evenStart = current;
                evenEnd = evenStart;
            }
            else {
                evenEnd->next = current;
                evenEnd = evenEnd->next;
            }
        else
            if (oddStart == NULL) {
                oddStart = current;
                oddEnd = oddStart;
            }
            else {
                oddEnd->next = current;
                oddEnd = oddEnd->next;
            }

        // Move head pointer one step forward
        current = current->next;
    }

    // If either list is empty, no change is required
    // as all elements are either even or odd
    if (oddStart == NULL || evenStart == NULL)
        return;

    // Add odd list after even list
    evenEnd->next = oddStart;
    oddEnd->next = NULL;

    *head_ref = evenStart;
}

/* ------------------------ MAIN DRIVER CODE --------------------- */
int main() {
    struct Node* head = NULL;

    // 0->1->4->6->9->10->11
    push(&head, 11);
    push(&head, 10);
    push(&head, 9);
    push(&head, 6);
    push(&head, 4);
    push(&head, 1);
    push(&head, 0);

    printf("Original Linked list:\n");
    printList(head);

    segregateEvenOdd(&head);

    printf("Modified Linked list:\n");
    printList(head);

    return 0;
}