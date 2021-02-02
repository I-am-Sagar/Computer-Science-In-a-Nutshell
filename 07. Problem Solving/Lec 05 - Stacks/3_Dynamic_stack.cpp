/*
    Limitation of array based implementation:
        The maximum size of the stack must be defined first and it cannot be changed.

    Try this:
        If the stack is full and push is called, we may create a new stack with
        size one more and then copy all elements of previous stack into this new
        stack and finally push the element.

        But this way of incrementing array size is too expensive. For eg, at n = 1,
        to push an element, we create a new array of size 2 and copy previous elements
        and add the new element. Then at n = 2, we create a new array of size 3 and copy
        previous elements and add the new element. Going in same fashion, at n = n-1,
        we create an array of size n and copy all old elements and add new element in end.

        Thus time taken for n push operations is proportional to,
        T(n) = 1 + 2 + ... + n-1  ~ O(n^2)

    Proper approach:
        The technique used is called "Array Doubling Technique."
        If the array gets full, create a new array of twice the size and copy the items.

        Let us assume we started at n = 1 and moved till n = 32. This means we performed
        doubling at 1, 2, 4, 8, 16.

        At n = 1, we do 1 copy operation.
        At n = 2, we do 2 copy operations.
        At n = 4, we do 4 copy operations.

        Hence, total copy operations = 1 + 2 + 4 + 8 + 16
                                     = 31 ~ 2n i.e. 32 (where n = 16)

        Thus, total time T(n) of n push operation is proportional to,

        T(n) = 1 + 2 + 4 + 8 + .... + n/4 + n/2 + n
             = n(1 + 1/2 + 1/4 + ... + 8/n + 4/n + 2/n + 1/n)
             ~ n(2)
             ~ 2n
        T(n) = O(n)

        Hence amortized time complexity for single push operation is O(1).
 */

#include <bits/stdc++.h>
using namespace std;

class dynamicStack {
    private:
        int top;
        void doubleStack();
    public:
        int capacity, *array;

    dynamicStack() {
        top = -1;
        capacity = 1;
        array = new int[capacity];
    }

    bool isFull();
    bool isEmpty();
    void push(int item);
    int pop();
    int peek();
};

void dynamicStack :: doubleStack() {
    // Doubling the capacity
    capacity *= 2;

    // Copying available data into temporary array
    // and then deleting the original array
    int* temp = new int[capacity];
    for (int i = 0; i < capacity/2; i++)
        temp[i] = array[i];
    delete array;

    // Allocating new memory to original again
    // which is double the size as of previous one
    // and deleting the temporary array after copying
    // the elements into newly allocated array
    array = new int[capacity];
    for (int i = 0; i < capacity/2; i++)
        array[i] = temp[i];
    delete temp;
}

bool dynamicStack :: isFull() {
    return (top == capacity-1);
}

bool dynamicStack :: isEmpty() {
    return (top == -1);
}

void dynamicStack :: push(int item) {
    if (this->isFull())
        this->doubleStack();

    array[++(this->top)] = item;
}

int dynamicStack :: pop() {
    return array[(this->top)--];
}

int dynamicStack :: peek () {
    return array[this->top];
}

/* ---------------------- MAIN DRIVER CODE ---------------------- */
int main() {
    dynamicStack stack;
    int option, val;

    do {
        cout << "\n1.PUSH\n2.POP\n3.TOP\n4.EXIT\n";
        cin >> option;

        switch(option) {
            case 1:
                cout << "Enter the value to be pushed: ";
                cin >> val;
                stack.push(val);
                break;

            case 2:
                if (stack.isEmpty())
                    cout << "Underflow\n";
                else
                    cout << stack.pop() << " popped out of stack.\n";
                break;

            case 3:
                cout << stack.peek() << " is top element.\n";
                break;

            case 4:
                exit (0);

            default:
                cout << "Invalid Option.\n";
        }
    }
    while (option != 4);

    return 0;
}
