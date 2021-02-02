/* Given a linked list with 'n' nodes, insert a node in the middle of the list.

Input: 1 -> 2 -> 4 -> 5 -> NULL, x = 3.
Output: 1 -> 2 -> 3 -> 4 -> 5 -> NULL.

Input: 5 -> 10 -> 4 -> 32 -> 16 -> NULL, x = 41.
Output: 5 -> 10 -> 4 -> 41 -> 32 -> 16 -> NULL.

Method 1: Using the length of the linked list.
    Find the number of nodes by traversing the entire linked list once.
    Calculate c = (len)/2; if len is even or else c = (len+1)/2;
    Traverse again the first c nodes and insert the new node after cth node.

Method 2: Use 'slow and fast' pointers.
    Maintain two pointers 'slow' & 'fast'. This is called "Hare & Tortoise Technique".
    'slow' pointer jumps in list by 1 node and 'fast' pointer jumps in list by 2 nodes.
    When fast pointer reaches end, slow pointer must have reached in the mid.
    Insert a new node after slow pointer. This method requires single traversal of list.

Method 2 is implemented in below code.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* getNode (int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtMid (Node** head_ref, int x) {
    // If list is empty, make the new node as head
    if (*head_ref == NULL)
        *head_ref = getNode(x);
    else {
        Node* newNode = getNode(x);

        Node* slow = *head_ref;
        Node* fast = (*head_ref)->next;

        while (fast && fast->next) {
            //move slow pointer to next node
            slow = slow->next;
            //move fast pointer two nodes at a time
            fast = fast->next->next;
        }
        newNode->next = slow->next;
        slow->next = newNode;
    }
}

void display(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

/* -------------- MAIN DRIVER CODE ---------------- */
int main() {
    // Creating the list 1->2->4->5
    Node* head = NULL;
    head = getNode(1);
    head->next = getNode(2);
    head->next->next = getNode(4);
    head->next->next->next = getNode(5);

    cout << "Linked list before insertion: ";
    display(head);

    int x = 3;
    insertAtMid(&head, x);

    cout << "\nLinked list after insertion: ";
    display(head);

    return 0;
}
