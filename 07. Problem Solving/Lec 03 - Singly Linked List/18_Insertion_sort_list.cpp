/* Algorithm:
    1) Create an empty sorted (or result) list
    2) Traverse the given list, do following for every node.
        a) Insert current node in sorted way in sorted or result list.
    3) Change head of given linked list to head of sorted (or result) list.

    Time Complexity: O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void printList(struct Node *head) {
    Node *temp = head;
    while(temp != NULL) {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
    cout << endl;
}

void push(struct Node** head_ref, int new_data) {
    struct Node* new_node = new Node;
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

// Function to insert a node in sorted linked list
void sortedInsert (Node** head_ref, Node* new_node) {
    Node* current;
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data) {
        new_node->next = *head_ref;
        *head_ref = new_node;
    }
    else {
        current = *head_ref;
        while (current->next != NULL && current->next->data < new_node->data)
            current = current->next;
        new_node->next = current->next;
        current->next = new_node;
    }
}

// Main Logic Code
void insertionSort (Node** head_ref) {
    // Initialize sorted linked list
    Node* sorted = NULL;
    // Traverse the given linked list and insert every node in sorted list
    Node* current = *head_ref;

    while (current != NULL) {
        Node* next = current->next;
        sortedInsert(&sorted, current);
        current = next;
    }
    *head_ref = sorted;
}

/* -------------- MAIN DRIVER CODE ---------------- */
int main() {
    struct Node *a = NULL;
    push(&a, 5);
    push(&a, 20);
    push(&a, 4);
    push(&a, 3);
    push(&a, 30);

    printf("Linked List before sorting \n");
    printList(a);

    insertionSort(&a);

    printf("\nLinked List after sorting \n");
    printList(a);

    return 0;
}