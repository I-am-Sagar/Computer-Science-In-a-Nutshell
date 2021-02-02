/* Given a linked list and a key, count number of occurrences of given key in linked list.
   If given linked list is 1->2->1->2->1->3->1 and given key is 1, then output should be 4.

Method 1 - Iterative solution
    1. Initialize count as zero.
    2. Loop through each element of linked list:
        a) If element data is equal to the passed number then increment the count.
    3. Return count.

Method 2 - Recursive solution
    int count(struct Node* head, int key) {
        if (head == NULL)
            return 0;
        int frequency = count(head->next, key);
        if (head->data == key)
            frequency++;
        return frequency;
    }
Above function is self-explanatory.

 */

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void push(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

int countIterative (Node* head, int key) {
    Node* current = head;
    int count = 0;
    while (current != NULL) {
        if (current->data == key)
            count++;
        current = current->next;
    }
    return count;
}

int countRecursive (struct Node* head, int key) {
    if (head == NULL)
        return 0;
    int count = countRecursive(head->next, key);
    if (head->data == key)
        count++;
    return count;
}

/* -------------- MAIN DRIVER CODE ---------------- */
int main() {
    Node* head = NULL;
    //List is 2 -> 1 -> 2 -> 1 -> 3 -> 1 -> NULL
    push(&head, 1);
    push(&head, 3);
    push(&head, 1);
    push(&head, 2);
    push(&head, 1);
    push(&head, 2);

    cout << "Count of 1 is " << countIterative(head, 1) << endl;
    cout << "Count of 2 is " << countRecursive(head, 2) << endl;
    return 0;
}
