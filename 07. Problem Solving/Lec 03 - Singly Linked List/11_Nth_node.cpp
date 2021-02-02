/*  Write a GetNth() function that takes a linked list and an integer index
    and returns the data value stored in the node at that index position.

Iterative approach:
    1. Initialize count = 0
    2. Loop through the link list
        a. if count is equal to the passed index then return current node
        b. Increment count
        c. change current to point to next of the current.

Recursive approach:
    getnth(node,n)
    1. Initialize count = 1
    2. if count==n
        return node->data
    3. else
        return getnth(node->next,n-1)
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

// Auxiliary Function
void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Main Logic of Code
int getNthIterative (Node* head, int index) {
    Node* current = head;
    int count = 1;
    while (current != NULL) {
        if (count == index)
            return (current->data);
        count++;
        current = current->next;
    }
    // If we get to this line, this means index was invalid
    cout << "Invalid Index\n";
    assert(0);  // 0 as argument for assert means failure in execution of code
}

int getNthRecursive (Node* head, int index) {
    int count = 1;
    if (count == index)
        return head->data;
    return getNthRecursive(head->next, index-1);
}

/* ------------------ MAIN DRIVER CODE -----------------------*/
int main() {
    struct Node* head = NULL;

    // Use push() to construct below list 15->12->5->4->1
    push(&head, 1);
    push(&head, 4);
    push(&head, 5);
    push(&head, 12);
    push(&head, 15);

    cout << getNthIterative(head, 1) << endl;
    cout << getNthIterative(head, 3) << endl;
    cout << getNthIterative(head, 4) << endl;
    cout << getNthRecursive(head, 5) << endl;

    return 0;
}


