/* Write a function which searches an element in linked list.
   Return the node's number at which key was found. Return -1 in case if key is absent.

Iterative Solution:
    1) Initialize a node pointer, current = head and count = 1.
    2) Do following while current is not NULL
        a) if current->key is equal to the key being searched, return count.
        b) current = current->next, count++
    3) Return -1

Recursive Solution:
    int search(head, x)
    1) If head is NULL, return -1.
    2) If head's key is same as x, return index;
    2) Else index++ and return search(head->next, x) where index can be global or static variable.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
};

// Auxiliary Function
void push(Node** head_ref, int new_key) {
    Node* new_node = new Node;
    new_node->data = new_key;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Main Logic of Code
int iterativeSearch (Node* head, int x) {
    Node* current = head; int count = 1;
    while (current != NULL)
        if (current->data == x)
            return count;
        else {
            count++;
            current = current->next;
        }
    return -1;
}


int recursiveSearch (Node* head, int x) {
    if (head == NULL)
        return -1;

    if (head->data == x)
        return 1;

    int indexFromChildList = recursiveSearch(head->next, x);

    if (indexFromChildList != -1)
        indexFromChildList++;

    return indexFromChildList;
}

/* --------------- MAIN DRIVER CODE -----------------*/
int main()
{
    struct Node* head = NULL;
    int x = 21;

    // Use push() to construct below list 14->21->11->30->10
    push(&head, 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);

    cout << iterativeSearch(head, 11) << endl;
    cout << iterativeSearch(head, 10) << endl;
    cout << iterativeSearch(head, 35) << endl;
    cout << recursiveSearch(head, 21) << endl;
    cout << recursiveSearch(head, 25) << endl;

    return 0;
}
