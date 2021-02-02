/* Given a singly linked list and a number k, write a function to find the
   (n/k)-th element, where n is the number of elements in the list. We need
   to consider ceil value in case of decimals.

Examples:

Input : list = 1->2->3->4->5->6
        k = 2
Output : 3
Since n = 6 and k = 2, we print (6/2)-th node
which is 3.

Input : list = 2->7->9->3->5
        k = 3
Output : 7
Since n is 5 and k is 3, we print ceil(5/3)-th
node which is 2nd node, i.e., 7.

Approach:

1. Take two pointers temp and fractionalNode and initialize them with null
   and head respectively.
2. For every k jumps of the temp pointer, make one jump of the fractionalNode
   pointer.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
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

// Main Logic of the code
Node* fractionalNodes(Node* head, int k) {
    // Corner cases
    if (k <= 0 || head == NULL)
        return NULL;

    Node* fractionalNode = NULL;
    // Traverse the given list
    int i = 0;
    for (Node* temp = head; temp != NULL; temp = temp->next) {
        // For every k nodes, we move fractionalNode one step ahead.
        if (i % k == 0) {
            // First time we see a multiple of k
            if (fractionalNode == NULL)
                fractionalNode = head;
            else
                fractionalNode = fractionalNode->next;
        }
        i++;
    }
    return fractionalNode;
}

/* ----------------------- MAIN DRIVER CODE -------------------- */
int main(void) {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    int k = 2;

    printList(head);

    Node* answer = fractionalNodes(head, k);
    printf("Fractional node is: ");
    printf("%d\n", answer->data);

    return 0;
}