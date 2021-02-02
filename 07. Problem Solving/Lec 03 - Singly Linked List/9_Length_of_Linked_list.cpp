/* We can find length of Linked list in Iterative as well as Recursive way.

Iterative Solution:
    1) Initialize count as 0
    2) Initialize a node pointer, current = head.
    3) Do following while current is not NULL
        a) current = current -> next
        b) count++;
    4) Return count

Recursive Solution:
    int getCount(head)
    1) If head is NULL, return 0.
    2) Else return 1 + getCount(head->next)
*/

#include  <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

// Here Node* as arg and not Node** because we dont
// want to change anything in original list.
// We just want to traverse the list once.
int iterativeCount (Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int recursiveCount (Node* head) {
    if (head == NULL)
        return 0;
    else
        return 1 + recursiveCount(head->next);
}

/* -------------- MAIN DRIVER CODE ---------------- */
int main()
{
    struct Node* head = NULL;

    // Use push() to construct below list 1->2->1->3->1
    push(&head, 1);
    push(&head, 3);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);

    cout << "Length of Linked List is " << iterativeCount(head) << endl;
    cout << "Length of linked list is " << recursiveCount(head) << endl;
    return 0;
}