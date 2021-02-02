// Video Link: https://www.youtube.com/watch?v=yOjQS7rdkQQ

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
void deleteNode(Node* node_ptr){
    Node* temp = node_ptr->next;
    node_ptr->data = temp->data;
    node_ptr->next = temp->next;
    delete temp;
}

/* --------------------------- MAIN DRIVER CODE ------------------ */
int main() {
    Node* head = NULL;
    // 1->12->1->4->1
    push(&head, 1);
    push(&head, 4);
    push(&head, 1);
    push(&head, 12);
    push(&head, 1);

    cout << "Before deleting: \n";
    printList(head);

    deleteNode(head->next->next);

    cout << "After deleting: \n";
    printList(head);
    return 0;
}