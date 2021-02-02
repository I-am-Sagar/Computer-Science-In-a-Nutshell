/*  Merge sort for DLL is same as SLL.
    The important change here is to modify the
    previous pointers also while merging two lists.
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->next = NULL;
    }
};

// Auxiliary Function to Traverse list
void printList(Node* node)  {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

void push (Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = *head_ref;
    new_node->prev = NULL;
    if ((*head_ref)!= NULL)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}

// Utility Functions
/* Following function merges two sorted DLLs */
Node* merge(Node *first, Node *second) {
    // If first linked list is empty
    if (!first)  return second;

    // If second linked list is empty
    if (!second)  return first;

    // Pick the smaller value
    if (first->data < second->data)  {
        first->next = merge(first->next,second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
    }
    else {
        second->next = merge(first,second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }
}

/* Following function splits a DLL into 2 DLLs of half sizes */
Node *split(Node *head)  {
    Node *fast = head,*slow = head;
    while (fast->next && fast->next->next)  {
        fast = fast->next->next;
        slow = slow->next;
    }
    Node *temp = slow->next;
    slow->next = NULL;
    return temp;
}

// Main Logic of Code
Node *mergeSort(Node *head)  {
    if (!head || !head->next)
        return head;
    Node *second = split(head);

    // Recur for left and right halves
    head = mergeSort(head);
    second = mergeSort(second);

    // Merge the two sorted halves
    return merge(head,second);
}

/* ------------------ MAIN DRIVER CODE ---------------- */
int main(void) {
    Node *head = NULL;
    push(&head, 5);
    push(&head, 20);
    push(&head, 4);
    push(&head, 3);
    push(&head, 30);
    push(&head, 10);
    head = mergeSort(head);
    cout << "Linked List after sorting:\n";
    printList(head);
    return 0;
}