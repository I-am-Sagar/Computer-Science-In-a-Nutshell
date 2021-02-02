/*  PROBLEM:
    Your task is to exchange first and last nodes of CLL.
    You should use only one extra node and not more than that.
    Apart from that, you are not allowed to declare any type
    of temporary variables.

    SOLUTION:
    The question is simple. The idea is to first find the pointer
    to the previous of last node. Let this node be 'p'.
    Now we change next links so that the last and first nodes
    are swapped.
*/

#include <bits/stdc++.h>
using namespace std;

class Node  {
    public:
        int data;
        Node *next;
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
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

void push (Node** head_ref, int data) {
    Node* ptr1 = new Node(data);
    ptr1->next = *head_ref;
    if (*head_ref != NULL) {
        Node* temp = *head_ref;
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1;

    *head_ref = ptr1;
}

// Main Logic of Code
Node* exchangeNodes (Node* head) {
    Node* p = head;
    // Find previous of last node
    while (p->next->next != head)
        p = p->next;

    // Now exchange the nodes
    p->next->next = head->next;
    head->next = p->next;
    p->next = head;
    head = head->next;

    return head;
}

/* --------------- MAIN DRIVER FUNCTION ----------------- */
int main() {
    int i;
    struct Node *head = NULL;

    for (i = 6; i > 0; i--)
        push(&head, i);

    cout << "List Before: ";
    printList(head);

    head = exchangeNodes(head);

    cout << "List After: ";
    printList(head);

    return 0;
}