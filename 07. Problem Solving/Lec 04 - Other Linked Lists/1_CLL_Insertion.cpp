/*  In a circular linked list, a node can be added in four ways:
    a) Insertion in empty list
    b) Insertion at the beginning of the list
    c) Insertion at the end of the list
    d) Insertion in between the nodes

    In circular linked lists, we don't use 'head' pointer to insert nodes.
    We use 'last' pointer.

    For case a) -  Initially the 'last' pointer will be NULL.
    After insertion, 'last' pointer points to added node. Since
    added node is first and last node, it points to itself.

    For case b) - To insert a node at the beginning of list, do:
    1. Create a node, say T.
    2. Make T->next = last->next.
    3. last->next = T.

    For case c) - To insert a node at the end of list, do:
    1. Create a node, say T.
    2. Make T->next = last->next.
    3. last->next = T.
    4. last = T.

    For case d) - To insert a node in between the nodes, do:
    1. Create a node, say T.
    2. Search the node after which T is to be inserted, say that node be P.
    3. Make T->next = P->next.
    4. P->next = T.
*/

#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node (int data) {
            this->data = data;
            this->next = NULL;
        }
};

// Auxiliary Function ot print the CLL
void printList (Node* last) {
    Node* temp;
    // If list is empty, return.
    if (last == NULL) {
        cout << "List is empty.\n";
        return;
    }

    temp = last->next;

    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != last->next);
    cout << endl;
}

// Main Logic of Code
Node* addToEmpty (Node* last, int data) {
    // This function is only for empty list
    if (last != NULL)   return last;

    // Create a node dynamically
    Node* temp = new Node(data);

    // Fixing links
    last = temp;
    last->next = last;

    return last;
}

Node* addBegin (Node* last, int data) {
    if (last == NULL)
        return addToEmpty(last, data);

    Node* temp = new Node(data);
    temp->next = last->next;
    last->next = temp;

    return last;
}

Node* addEnd (Node* last, int data) {
    if (last == NULL)
        return addToEmpty(last, data);

    Node* temp = new Node(data);
    temp->next = last->next;
    last->next = temp;
    last = temp;

    return last;
}

Node* addAfter (Node* last, int data, int item) {
    if (last == NULL)
        return NULL;

    Node *temp, *p;
    p = last->next;
    do {
        if (p->data == item) {
            temp = new Node(data);
            temp->next = p->next;
            p->next = temp;

            if (p == last)
                last = temp;
            return last;
        }
        p = p->next;
    } while (p != last->next);

    cout << item << " not present in the list.\n";
    return last;
}

/* ------------------- MAIN DRIVER CODE ------------------ */
int main() {
    struct Node *last = NULL;

    last = addToEmpty(last, 6);
    last = addBegin(last, 4);
    last = addBegin(last, 2);
    last = addEnd(last, 8);
    last = addEnd(last, 12);
    last = addAfter(last, 10, 8);

    printList(last);

    return 0;
}