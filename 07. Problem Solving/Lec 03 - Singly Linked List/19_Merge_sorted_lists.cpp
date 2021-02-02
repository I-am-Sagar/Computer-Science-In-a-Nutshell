/* Given two sorted linked lists, we need to merge them as a sorted list.

Method 1: Iterative method
    a) create two pointers, result_ptr which will act as head of result list
       and last_ptr which will be always pointing to the end of result list.
    b) if first element of list1 is smaller than first element of list2,
       move this first element from list1 to result list and similar for reverse case.
    c) if any list turns NULL, append the remaining list to result list.

Method 2: Recursive method
    The logic remains same as Iterative method. Implementation is given below.
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

Node* A = NULL;
Node* B = NULL;

void push(Node** head_ref, int new_data)  {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(Node *node)  {
    while (node!=NULL)  {
        cout<<node->data<<" ";
        node = node->next;
    }
    cout << endl;
}

// Following function is a helper function which takes the node
// from the front of the source and move it to the front of dest.
// Before calling moveNode(), source = 1-2-3, dest = 1-2-3
// After calling moveNode(), source = 2-3, dest = 1-1-2-3
void moveNode (Node** source_ref, Node** dest_ref) {
    // New Node is Front node of source list
    Node* new_node = *source_ref;
    assert(new_node != NULL);   // Error if the source list is empty

    // Advance the source pointer
    *source_ref = new_node->next;

    // Linking the first node of source to first node of destination
    new_node->next = *dest_ref;

    // Making *dest_ref point to new node
    *dest_ref = new_node;
}

// Main Logic Code
Node* mergeSorted (Node* a, Node* b) {
    Node* result = NULL;
    // Reference to pointer pointing to last element of the result list.
    Node** last_ref = &result;

    while (1) {
        if (a == NULL) {
            *last_ref = b;
            break;
        }
        else if (b == NULL) {
            *last_ref = a;
            break;
        }
        else if (a->data <= b->data)
            moveNode (&a, last_ref);
        else
            moveNode (&b, last_ref);

        // Tricky way to advance a pointer to the next field
        last_ref = &((*last_ref)->next);
        printList(A);
        printList(B);
        printList(result);
        cout << endl;
    }
    return result;
}

Node* mergeRecursive (Node* a, Node* b) {
    Node* result = NULL;

    if (a == NULL)  return (b);
    else if (b == NULL) return (a);

    if (a->data < b->data) {
        result = a;
        result->next = mergeRecursive(a->next, b);
    }
    else {
        result = b;
        result->next = mergeRecursive(a, b->next);
    }
    return result;
}

/* -------------- MAIN DRIVER CODE ---------------- */
int main() {
    Node* res1 = NULL;
    Node* res2 = NULL;

    // Created lists, a: 5->10->15, b: 2->3->20
    push(&A, 15);
    push(&A, 10);
    push(&A, 5);

    push(&B, 20);
    push(&B, 3);
    push(&B, 2);

    printList(A);
    printList(B);
    res1 = mergeSorted(A, B);
    printList(res1);

    //res2 = mergeRecursive(a, b);
    //printList(res2);

    return 0;
}