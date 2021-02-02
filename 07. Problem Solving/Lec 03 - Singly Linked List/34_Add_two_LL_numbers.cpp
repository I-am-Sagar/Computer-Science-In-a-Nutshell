// Video Link : https://www.youtube.com/watch?v=LLPuC5kWD8U

/*
Possibility 1:
    We may represent numbers in reverse order. For example,
    5-3-6-NULL   // This represents number 635
    8-4-2-NULL   // This represents number 248
    Output: 3-8-8-NULL  // This represents sum 883

    Solving in above way is bit easier. Traverse both lists.
    One by one pick nodes of both lists and add the values. If sum is more
    than 10 then make carry as 1 and reduce sum. If one list has more elements
    than the other then consider remaining values of this list as 0

Possibility 2:
    When we are not allowed to represent numbers in reverese order. For example,
    5-6-3-NULL  // represents number 563
    8-4-2-NULL  // represents number 842
    Output: 1-4-0-5-NULL    // This represents sum 1405

    1) Calculate sizes of given two linked lists.
    2) If sizes are same, then calculate sum using recursion.
       Hold all nodes in recursion call stack till the rightmost node,
       calculate sum of rightmost nodes and forward carry to left side.
    3) If size is not same, then follow below steps:
        a) Calculate difference of sizes of two linked lists. Let the difference be diff
        b) Move diff nodes ahead in the bigger linked list.
           Now use step 2 to calculate sum of smaller list and right sub-list (of same size) of larger list.
           Also, store the carry of this sum.
        c) Calculate sum of the carry (calculated in previous step) with the remaining left sub-list of larger list.
           Nodes of this sum are added at the beginning of sum list obtained previous step.
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
};

Node* newNode (int data) {
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

void push (Node** head_ref, int data) {
    Node* new_node = newNode(data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void printList(Node *node)  {
    while(node != NULL)  {
        cout << node->data << " ";
        node = node->next;
    }
    cout<<endl;
}

// Function to add two lists covered in Possibility 1
Node* addTwoListsReversed (Node* first, Node* second) {
    Node* result = NULL;
    Node *temp, *prev = NULL;
    int carry = 0, sum;

    while (first || second) {
        sum = carry + (first? first->data : 0) + (second? second->data : 0);
        carry = (sum >= 10)? 1: 0;
        sum = sum%10;

        temp = newNode(sum);

        if (result == NULL)
            result = temp;
        else
            prev->next = temp;

        prev = temp;

        if (first) first = first->next;
        if (second) second = second->next;
    }
    if (carry > 0)
        temp->next = newNode(carry);

    return result;
}

// Logic to add two lists covered in Possibility 2
    
// Utility functions
void swapPointer(Node** a, Node** b) {
    Node* t = *a;
    *a = *b;
    *b = t;
}

int getSize(Node* node) {
    int size = 0;
    while (node != NULL) {
        node = node->next;
        size++;
    }
    return size;
}

Node* addSameSize(Node* head1, Node* head2, int* carry) {
    // Base case
    // Checking only head1 as both lists are of same size
    if (head1 == NULL)
        return NULL;

    // Recursive Definition
    Node* result = new Node;
    result->next = addSameSize(head1->next, head2->next, carry);

    // Add digits of current nodes and propagated carry
    int sum = head1->data + head2->data + *carry;
    *carry = sum/10;
    sum = sum % 10;

    result->data = sum;

    return result;
}

/* This function is called when smaller list is added to bigger list's
    sublist of same size. Once the right sublist is added, the carry
    must be added to left side of larger list to get final result. */
void addCarryToRemaining (Node* head1, Node* current, int* carry, Node** result) {
    int sum;
    // If 'diff' number of nodes are not traversed, add carry
    if (head1 != current) {
        addCarryToRemaining(head1->next, current, carry, result);
        sum = head1->data + *carry;
        *carry = sum/10;
        sum %= 10;

        // Add this node to the front of the result list
        push(result, sum);
    }
}

// Main Logic
Node* addTwoLists(Node* first, Node* second) {
    Node* result = new Node;
    Node* current = new Node;

    // If any one of the lists is empty
    if (first == NULL)
        return second;

    if (second == NULL)
        return first;

    int size1 = getSize(first);
    int size2 = getSize(second);
    int carry = 0;

    // Add lists directly if they are of same size
    if (size1 == size2)
        result = addSameSize(first, second, &carry);
    else {
        int diff = abs(size1-size2);
        // First list should be greater than second list
        // If not, then swap pointers
        if (size1 < size2)
            swapPointer (&first, &second);

        // Move 'diff' number of nodes in first list
        for (current = first; diff--; current = current->next);

        // Now add the same sized lists
        result = addSameSize (current, second, &carry);

        // Addition of remaining first list and carry
        addCarryToRemaining  (first, current, &carry, &result);
    }
    // If some carry is left, eg. 997 + 87, push 1 in front of result list
    if (carry)
        push(&result, carry);

    return result;
}

/* ----------------------- MAIN DRIVER CODE -------------------- */
int main() {
    Node *head1 = NULL, *head2 = NULL, *result = NULL;

    int arr1[] = {9, 9, 9};
    int arr2[] = {1, 8};

    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    // Create first list as 9->9->9
    int i;
    for (i = size1-1; i >= 0; --i)
        push(&head1, arr1[i]);

    // Create second list as 1->8
    for (i = size2-1; i >= 0; --i)
        push(&head2, arr2[i]);

    Node* result1 = addTwoListsReversed(head1, head2);
    Node* result2 = addTwoLists(head1, head2);

    printList(result1);
    printList(result2);

    return 0;
}