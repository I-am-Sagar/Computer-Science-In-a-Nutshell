// Video Link: https://www.youtube.com/watch?v=nll-b4GeiX4

/*  PROBLEM:
    a) If the question asks to sort the stack without any loops
       or any other data structure, and only basic stack operations,
       we will solve this using RECURSION.

    b) If we are allowed to use another temporary stack, we can
       sort the stack ITERATIVELY as well.

    Below is the implementation of both the methods.
*/

#include<bits/stdc++.h>
using namespace std;

// Auxiliary Function to print a stack
void printStack (stack<int> s) {
    if (s.empty())
        return;
    int x = s.top();
    s.pop();
    printStack(s);
    cout << x << " ";
    s.push(x);
}

// Utility function for recursive code
void sortedInsert(stack<int> &s, int x) {
    // Base case is - either the stack is empty
    // or newly added element is greater than top
    // i.e. it is more than all existing elements
    if (s.empty() || x>s.top() ){
        s.push(x);
        return;
    }
    // If top is greater, remove the top item and recurr
    int temp = s.top();
    s.pop();
    sortedInsert(s, x);

    // Put back the top item back to stack
    s.push(temp);
}

// Main Logic of Code
void sortRecursive (stack<int> &s) {
    if (!s.empty()) {
        // Remove the top element
        int x = s.top();
        s.pop();
        // Sort the remaining stack
        sortRecursive(s);
        // Push the top item back in sorted order
        sortedInsert (s, x);
    }
}

void sortIterative (stack<int> &s) {
    // Using a temporary stack
    stack <int> tempStack;
    while (!s.empty()) {
        // Pop the first element
        int temp = s.top();
        s.pop();

        // While the temporary stack is not empty
        // and top of stack is greater than temp
        while (!tempStack.empty() && tempStack.top() > temp) {
            // Pop from temporary stack and push it into stack
            s.push(tempStack.top());
            tempStack.pop();
        }
        // Push temp in tempStack back
        tempStack.push(temp);
    }

    // Now, tempStack contains all elements of s in sorted order.
    // Copy the elements from tempStack to s.
    stack<int> helper;
    while (!tempStack.empty()) {
        helper.push(tempStack.top());
        tempStack.pop();
    }
    while (!helper.empty()) {
        s.push(helper.top());
        helper.pop();
    }
}

/* ----------------- MAIN DRIVER CODE ---------------- */
int main() {
    stack <int> st;
    st.push(34);
    st.push(3);
    st.push(98);
    st.push(11);
    st.push(-2);
    st.push(23);

    cout << "Original Stack:\n";
    printStack (st);
    cout << endl;

    // Uncomment following line to test run
    // sortRecursive(st);
    sortIterative (st);

    cout << "Sorted Stack:\n";
    printStack(st);
    cout << endl;

    return 0;
}