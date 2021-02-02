// Video Link: https://www.youtube.com/watch?v=PpY_C_NSNwk

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node (int x) {
        data = x;
        next = NULL;
    }
};

void push(Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(struct Node *node) {
    while (node!=NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Main Logic of Code
void skipMdeleteN(Node* head, int M, int N) {
    Node* current = head;
    Node* temp;
    int count;

    while (current) {
        // skipping M nodes
        for (count = 1; count < M && current!=NULL; count++)
            current = current->next;

        // If we reached end of list, we should return
        if (current == NULL)
            return;

        // Start from next node and delete N nodes
        temp = current->next;
        for (count = 1; count <= N && temp != NULL; count++) {
            Node* t = temp;
            t = t->next;
            delete temp;
            temp = t;
        }

        current->next = temp;
        current = temp;
    }
}

/* ---------------------- MAIN DRIVER CODE ------------------- */
int main() {
    //  1->2->3->4->5->6->7->8->9->10
    Node* head = NULL;
    int M=2, N=3;
    push(&head, 11);
    push(&head, 10);
    push(&head, 9);
    push(&head, 8);
    push(&head, 7);
    push(&head, 6);
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    cout << "M = " << M<< " N = " << N << "\nGiven Linked list is:\n";
    printList(head);

    skipMdeleteN(head, M, N);

    cout<<"Linked list after deletion is :\n";
    printList(head);

    return 0;
}