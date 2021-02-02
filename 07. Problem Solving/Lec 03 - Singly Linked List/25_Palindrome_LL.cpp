/*  PROBLEM:
    Given a singly linked list of characters, write a function
    that returns true if the given list is a palindrome, else false.

    Approach 1 - (Use a stack)
    1. Push every node from head to tail into stack.
    2. Traverse the list again and compare it with every popped element.
    3. If all matched, return true, else return false.
    Time Complexity: O(n)   Space Complexity: O(n)

    Approach 2 - (Reversing the list)
    1. Reverse the second half of the list by getting at the middle.
    2. Check if first and second half of the lists are identical.
    3. Construct the original linked list by reversing the second
       half again and attach it back to the first half.
    Time Complexity: O(n)   Space Complexity: O(1)

    Approach 3 - (Using Recursion)
    1. Use two pointers - left and right. Left is at start in the
       beginning and right is at the end.
    2. Increment left and decrement right pointers, and call the
       function recursively on the sublist.
    Time Complexity: O(n)   Space Complexity: O(n)

    Below we have implemented approach 2 and 3.
*/

#include <bits/stdc++.h>
using namespace std;

class Node {
    public:
        char data;
        Node* next;
        Node(char data) {
            this->data = data;
            this->next = NULL;
        }
};

// Auxiliary Functions
void push (Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

// Utility Functions for Iterative method
void reverse (Node** head_ref) {
    Node* previous = NULL;
    Node* current = *head_ref;
    Node* subsequent = NULL;
    while (current != NULL) {
        subsequent = current->next;
        current->next = previous;
        previous = current;
        current = subsequent;
    }
    *head_ref = previous;
}

bool compareLists (Node* head1, Node* head2) {
    Node* temp1 = head1;
    Node* temp2 = head2;

    while (temp1 && temp2) {
        if (temp1->data == temp2->data) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
            return false;
    }

    // If both temp1 and temp2 point to NULL now,
    // it means the lists are equal.
    if (temp1 == NULL && temp2 == NULL)
        return true;

    // If reached here, means one list is NULL while
    // other is not.
    return false;
}

// Main Logic of Iterative Approach
bool isPalindrome1 (struct Node* head) {
    Node* slow_ptr = head, *fast_ptr = head;
    Node* prev_of_slow_ptr = head;
    Node* second_half = NULL;
    Node* middle_node = NULL;   //Will be used to handle odd sized lists
    bool result = true;

    if (head != NULL && head->next != NULL) {
        // Get the middle of node by slow and fast ptr method
        while (fast_ptr != NULL && fast_ptr->next != NULL) {
            fast_ptr = fast_ptr->next->next;
            // We need previous of the slow_ptr for the
            // linked lists with odd elements
            prev_of_slow_ptr = slow_ptr;
            slow_ptr = slow_ptr->next;
        }

        // fast pointer will become Null if there are even
        // elements in the list. If not Null, we need to
        // skip the middle node and store it somewhere so
        // that we can restore the original list
        if (fast_ptr != NULL) {
            middle_node = slow_ptr;
            slow_ptr = slow_ptr->next;
        }

        // Now reverse the second half of the list
        second_half = slow_ptr;
        prev_of_slow_ptr->next = NULL;
        reverse(&second_half);
        result = compareLists(head, second_half);

        // Now reverse the second half again
        reverse(&second_half);

        // Connect the second half back to first half
        // If there was a middle node (odd sized)
        if (middle_node!=NULL) {
            prev_of_slow_ptr->next = middle_node;
            middle_node->next = second_half;
        }
        else
            prev_of_slow_ptr->next = second_half;
    }
    return result;
}

// Main Logic of Recursive approach
bool isPalindromeUtil (Node** left, Node* right) {
    // Base Case
    if (right == NULL)
        return true;

    // Check if sublist is palindrome or not
    bool temp = isPalindromeUtil(left, right->next);
    if (temp == false)
        return false;

    // Check values at current left and right
    bool result = (right->data == (*left)->data);

    // Move left to next node
    *left = (*left)->next;

    return result;
}

bool isPalindrome2(Node* head) {
    return isPalindromeUtil(&head, head);
}

/* ----------------- MAIN DRIVER CODE -------------- */
int main() {
    struct Node* head = NULL;
    char str[] = "abacaba";

    for (int i = 0; str[i] != '\0'; i++)
        push(&head, str[i]);

    printList(head);
    isPalindrome1(head) ? printf("Is Palindrome.\n") : printf("Not Palindrome.\n");
    isPalindrome2(head) ? printf("Is Palindrome.\n") : printf("Not Palindrome.\n");

    return 0;
}

/* ADDITIONAL POINT:

    If suppose we are asked to find palindromic nature of
    a list that contains loop, then we do following:
    a) Check if there is a loop using Flyod's algo
    b) Then find the starting point of the loop
    c) Then check the palindrome using above logic
*/