/* PROBLEM:
    Given two linked lists, insert nodes of second list
    into first list at alternate positions of first list.
    The nodes of second list should only be inserted when
    there are positions available.

    For example, if first list is 5->7->17->13->11 and
    second is 12->10->2->4->6, then first list should be -
     5->12->7->10->17->2->13->4->11->6 and second be empty.

    Also if the first list is 1->2->3 and second list is
    4->5->6->7->8, then first list should become
    1->4->2->5->3->6 and second list to 7->8.
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

// Main Logic of the code
/* Since head of the first list will never change and
   the head of the second list may change, we need
   single pointer for first list and double pointer
   for second.
*/
void mergeAlternate (Node* p, Node** q) {
    Node *p_curr = p, *q_curr = *q;
    Node *p_next, *q_next;

    //While there are available positions in p
    while (p_curr != NULL && q_curr != NULL) {
        // Save next pointers
        p_next = p_curr->next;
        q_next = q_curr->next;

        // Make q_curr as next of p_curr
        q_curr->next = p_next; // Change next pointer of q_curr
        p_curr->next = q_curr; // Change next pointer of p_curr

        // Update current pointers for next iteration
        p_curr = p_next;
        q_curr = q_next;
    }
    *q = q_curr; // Update head pointer of second list
}

/* ----------------- MAIN DRIVER CODE ------------------ */
int main()  {
    Node *p = NULL, *q = NULL;
    push(&p, 3);
    push(&p, 2);
    push(&p, 1);
    cout<<"First Linked List:\n";
    printList(p);

    push(&q, 8);
    push(&q, 7);
    push(&q, 6);
    push(&q, 5);
    push(&q, 4);
    cout<<"Second Linked List:\n";
    printList(q);

    mergeAlternate(p, &q);

    cout<<"Modified First Linked List:\n";
    printList(p);

    cout<<"Modified Second Linked List:\n";
    printList(q);

    return 0;
}