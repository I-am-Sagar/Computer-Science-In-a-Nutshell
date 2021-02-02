/*  PROBLEM:
    Write a C function to insert a new value in a sorted CLL.

    ALGORITHM:
    1) Linked List is empty:
        a)  since new_node is the only node in CLL, make a self loop.
            new_node->next = new_node;
        b) change the head pointer to point to new node.
            *head_ref = new_node;
    2) New node is to be inserted just before the head node:
        a) Find out the last node using a loop.
            while(current->next != *head_ref)
                current = current->next;
        b) Change the next of last node.
            current->next = new_node;
        c) Change next of new node to point to head.
            new_node->next = *head_ref;
        d) Change the head pointer to point to new node.
            *head_ref = new_node;
    3) New node is to be  inserted somewhere after the head:
        a) Locate the node after which new node is to be inserted.
            while ( current->next!= *head_ref && current->next->data data) {
                current = current->next;
            }
        b) Make next of new_node as next of the located pointer
            new_node->next = current->next;
        c) Change the next of the located pointer
            current->next = new_node;
*/

#include <bits/stdc++.h>
using namespace std;

class Node  {
    public:
        int data;
        Node *next;
};

// Auxiliary Function
void printList(Node *start)  {
    Node *temp;

    if(start != NULL)  {
        temp = start;
        do {
        cout<<temp->data<<" ";
        temp = temp->next;
        } while(temp != start);
    }
    cout << endl;
}

// Main Logic of Code
void sortedInsert (Node** head_ref, Node* new_node) {
    Node* current = *head_ref;

    // Case 1 of above algo
    if (current == NULL) {
        new_node->next = new_node;
        *head_ref = new_node;
    } // Case 2 of above algo
    else if (current->data >= new_node->data) {
        // If the value is smaller than head's value
        // then we need to change next of last node
        while (current->next != *head_ref)
            current = current->next;
        current->next = new_node;
        new_node->next = *head_ref;
        *head_ref = new_node;
    } // Case 3 of above algo
    else {
        // Locate the node before the point of insertion
        while (current->next != *head_ref && current->next->data < new_node->data)
            current = current->next;
        new_node->next = current->next;
        current->next = new_node;
    }
}

/* ----------------- MAIN DRIVER CODE --------------- */
int main() {
    int arr[] = {12, 56, 2, 11, 1, 90};
    Node *start = NULL;
    Node *temp;

    // Created linked list will be 1->2->11->12->56->90
    for (int i = 0; i< 6; i++)  {
        temp = new Node();
        temp->data = arr[i];
        sortedInsert(&start, temp);
    }

    printList(start);

    return 0;
}