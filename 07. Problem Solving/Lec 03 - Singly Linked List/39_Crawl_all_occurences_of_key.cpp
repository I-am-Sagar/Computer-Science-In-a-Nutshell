/* PROBLEM: Given a linked list and a key in it, the task is to move all
   occurrences of given key to end of linked list, keeping order of all other
   elements same.

   Input  : 1 -> 2 -> 2 -> 4 -> 3
            key = 2
    Output : 1 -> 4 -> 3 -> 2 -> 2

    Input  : 6 -> 6 -> 7 -> 6 -> 3 -> 10
            key = 6
    Output : 7 -> 3 -> 10 -> 6 -> 6 -> 6

SOLUTION:

    pCrawl => Pointer to traverse the whole list one by one.
    pKey => Pointer to an occurrence of key if a key is found. Else same as pCrawl.

    We start both of the above pointers from head of linked list. We move pKey
    only when pKey is not pointing to a key. We always move pCrawl. So when
    pCrawl and pKey are not same, we must have found a key which lies before
    pCrawl, so we swap data of pCrawl and pKey, and move pKey to next location.
    The loop invariant is, after swapping of data, all elements from pKey to
    pCrawl are keys.

*/

#include <bits/stdc++.h>
using namespace std;

// A Linked list Node
struct Node {
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Utility function to print the elements in Linked list
void printList(Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Moves all occurrences of given key to end of linked list.
void moveToEnd(Node* head, int key) {
    // Keeps track of locations where key is present.
    struct Node* pKey = head;

    // Traverse list
    struct Node* pCrawl = head;
    while (pCrawl != NULL) {
        // If current pointer is not same as pointer to a key location,
        // then we must have found a key in linked list. We swap data of
        // pCrawl and pKey and move pKey to next position.
        if (pCrawl != pKey && pCrawl->data != key) {
            pKey->data = pCrawl->data;
            pCrawl->data = key;
            pKey = pKey->next;
        }

        // Find next position where key is present
        if (pKey->data != key)
            pKey = pKey->next;

        // Moving to next Node
        pCrawl = pCrawl->next;
    }
}

/* ----------------------- MAIN DRIVER CODE -------------------- */
int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(10);
    head->next->next->next = new Node(30);
    head->next->next->next->next = new Node(40);
    head->next->next->next->next->next = new Node(10);
    head->next->next->next->next->next->next = new Node(60);

    printf("Before moveToEnd(), the Linked list is: \n");
    printList(head);

    int key = 10;
    moveToEnd(head, key);

    printf("\nAfter moveToEnd(), the Linked list is: \n");
    printList(head);

    return 0;
}
