/*
Given a Linked List, write a function that accepts the head node of the linked
list as a parameter and returns the value of node present at (floor(sqrt(n)))th
position in the Linked List, where n is the length of the linked list or the
total number of nodes in the list.

Examples:

Input: 1->2->3->4->5->NULL
Output: 2

Input : 10->20->30->40->NULL
Output : 20

Input : 10->20->30->40->50->60->70->80->90->NULL
Output : 30

1. Simple method:
The simple method is to first find the total number of nodes present in the
linked list, then find the value of floor(squareroot(n)) where n is the total
number of nodes. Then traverse from the first node in the list to this position
and return the node at this position.
This method traverses the linked list 2 times.

2. Optimized approach: In this method, we can get the required node by
   traversing the linked list once only.

   - Initialize two counters i and j both to 1 and a pointer sqrtn to NULL to
     traverse til the required position is reached.
   - Start traversing the list using head node until the last node is reached.
   - While traversing check if the value of j is equal to sqrt(i). If the value
     is equal increment both i and j and sqrtn to point sqrtn->next otherwise
    increment only i.
   - Now, when we will reach the last node of list i will contain value of n,
     j will contain value of sqrt(i) and sqrtn will point to node at jth
     position.
*/

#include <bits/stdc++.h>
using namespace std;

// Linked list node
class Node {
    public:
        int data;
        Node* next;
        Node(int data) {
            this->data = data;
            this->next = NULL;
        }
};

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Function to get the sqrt(n)th node of a linked list
int printsqrtn(Node* head) {
    Node* sqrtn = NULL;
    int i = 1, j = 1;
    // Traverse the list
    while (head!=NULL) {
        // check if j = sqrt(i)
        if (i == j*j) {
            // for first node
            if (sqrtn == NULL)
                sqrtn = head;
            else
                sqrtn = sqrtn->next;
            // increment j if j = sqrt(i)
            j++;
        }
        i++;
        head=head->next;
    }
    // return node's data
    return sqrtn->data;
}

/* ----------------------- MAIN DRIVER CODE -------------------- */
int main() {
    /* Start with the empty list */
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    
    cout << "Given linked list is: ";
    printList(head);
    cout << "sqrt(n)th node is: " << printsqrtn(head) << endl;

    return 0;
}
