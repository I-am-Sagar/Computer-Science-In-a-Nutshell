// Video Link: https://www.youtube.com/watch?v=IbvsNF22Ud0

#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;
};

// Size of linked list is 0 now. Used sizes because 'size' is already defined 
// in library
int sizes = 0;

//Function to create and return a Node.
Node* getNode (int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtPos (Node** current, int pos, int data) {
    // Following condition checks if the position is valid
    if (pos < 1 || pos > (sizes + 1))
        cout << "Invalid Position\n";
    else {
        //Keep on looping till position is zero
        while (pos--) {
            if (pos == 0) {
                // Create a node with given data
                Node* temp = getNode(data);
                // Make new node to point to old node at the same position
                temp->next = *current;
                // Change the pointer of the node previous to old node to point to new Node
                *current = temp;
            }
            else
                // Just move the current's next forward
                current = &(*current)->next;
        }
        sizes++;
    }
}

void printList(struct Node* head) {
    while (head != NULL) {
        cout << " " << head->data;
        head = head->next;
    }
    cout << endl;
}

/* -------------- MAIN DRIVER CODE ---------------- */
int main() {
    // Creating the list 3->5->8->10
    Node* head = NULL;
    head = getNode(3);
    head->next = getNode(5);
    head->next->next = getNode(8);
    head->next->next->next = getNode(10);

    sizes = 4;

    cout << "Linked list before insertion: ";
    printList(head);

    int data = 12, pos = 3;
    insertAtPos(&head, pos, data);
    cout << "Linked list after insertion of 12 at position 3: ";
    printList(head);

    // front of the linked list
    data = 1, pos = 1;
    insertAtPos(&head, pos, data);
    cout << "Linked list after insertion of 1 at position 1: ";
    printList(head);

    // insetion at end of the linked list
    data = 15, pos = 7;
    insertAtPos(&head, pos, data);
    cout << "Linked list after insertion of 15 at position 7: ";
    printList(head);

    return 0;
}