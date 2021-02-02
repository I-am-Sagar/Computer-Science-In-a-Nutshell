/*  ALGORITHM:

    MergeSort(headRef)
    1) If the head is NULL or there is only one element in the Linked List
       then return.
    2) Else divide the linked list into two halves.
        FrontBackSplit(head, &a, &b); // a and b are two halves
    3) Sort the two halves a and b.
        MergeSort(a);
        MergeSort(b);
    4) Merge the sorted a and b (using mergeSorted() discussed in previous
       code) and update the head pointer using headRef.
        *headRef = mergeSorted(a, b);
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

// Utility Functions required by our logic

/* Following function splits the given list into two halves
   and returns two lists using reference parameters.
   If the length is odd, the extra node should go in the
   front list. Uses 'fast-slow' pointer technique.
*/
void frontBackSplit(Node* source, Node** front_ref, Node** back_ref) {
    Node* slow = source;
    Node* fast = source->next;
    while (fast!=NULL){
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    // slow is before the midpoint in the list
    // so split it into two at that point
    *front_ref = source;
    *back_ref = slow->next;
    slow->next = NULL;
}

/* Following function is recursive implementation of mergeSorted() routine */
Node* mergeSorted (Node* a, Node* b) {
    Node* result = NULL;

    if (a == NULL)  return (b);
    else if (b == NULL) return (a);

    if (a->data < b->data) {
        result = a;
        result->next = mergeSorted(a->next, b);
    }
    else {
        result = b;
        result->next = mergeSorted(a, b->next);
    }
    return result;
}

// Main Logic of Code
void mergeSort(Node** headRef) {
    Node* head = *headRef;
    Node* a;
    Node* b;

    // Base case for length 0 or 1
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    // Split head into 'a' and 'b' sublists
    frontBackSplit(head, &a, &b);

    // Recursively sort the sublists
    mergeSort(&a);
    mergeSort(&b);

    // answer = merge the two sorted lists together
    *headRef = mergeSorted(a, b);
}

/* -------------------- MAIN DRIVER CODE ------------------- */
int main() {
    Node* res = NULL;
    Node* a = NULL;

    // Created list a: 2->3->20->5->10->15
    push(&a, 15);
    push(&a, 10);
    push(&a, 5);
    push(&a, 20);
    push(&a, 3);
    push(&a, 2);

    mergeSort(&a);

    cout << "Sorted Linked List is: \n";
    printList(a);

    return 0;
}