/* Given a Linked List and a number n, write a function that returns
   the value at the n’th node from end of the Linked List.

Method 1: Use length of List (Iterative)
    a) Calculate length of the list = len;
    b) Print the (len-n+1)th node from the beginning of the list.

Method 2: Recursive Solution
    void getNthFromLast(struct Node* head, int n)
    {
        static int i = 0;
        if (head == NULL)
            return;
        getNthFromLast(head->next, n);
        if (++i == n)
            printf("%d", head->data);
    }
Explantaion of Method 2:
    The getNthFromLast will keep on calling itself till head is not NULL.
    Once head is NULL, c) statement will start executing in stack order of calls.
    So now i will increment n times and function call will return in reverese order.
    In this way, it prints head->data at nth step from the end.

Method 3: Using two pointers
    Maintain two pointers – reference pointer and main pointer.
    Initialize both reference and main pointers to head.
    First move reference pointer to n nodes from head.
    Now move both pointers one by one until reference pointer reaches end.
    Now main pointer will point to nth node from the end. Return main pointer's data.

In below code, we have implemented Method 3.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void getNthFromLast (Node* head, int n) {
    Node* main_ptr = head;
    Node* ref_ptr = head;
    int count = 0;

    if (head != NULL) {
        while (count < n) {
            if (ref_ptr == NULL) {
                cout << n << " is greater than number of nodes in list.\n";
                return;
            }
            ref_ptr = ref_ptr->next;
            count++;
        }

        while (ref_ptr != NULL) {
            main_ptr = main_ptr->next;
            ref_ptr = ref_ptr->next;
        }
        cout << "Node number " << n << " from last is " << main_ptr->data << endl;
    }
}

/* -------------- MAIN DRIVER CODE ---------------- */
int main() {
    // List is 35 -> 15 -> 4 -> 20 -> NULL;
    Node* head = NULL;
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 35);

    getNthFromLast(head, 3);
    return 0;
}