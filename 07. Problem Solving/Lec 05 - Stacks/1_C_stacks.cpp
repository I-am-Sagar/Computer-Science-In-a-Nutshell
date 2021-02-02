/*
    Following are the ways of implementing stacks:
    a) Simple array based implementation - C way (using struct) and C++ way (using class)
    b) Dynamic array based implementation
    c) Linked List implementation   (left to the reader for implementation)
    d) By using C++ STL's stack

    In following code, we will implement Simple array based C way implementation.
 */

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <limits.h>

struct Stack {
    int* array;
    int top;
    unsigned capacity;
};

struct Stack* createStack (unsigned capacity) {
    struct Stack* stack = (struct Stack*) malloc(sizeof (struct Stack));
    stack -> capacity = capacity;
    stack -> top = -1;
    stack -> array = (int*) malloc((stack -> capacity)*sizeof(int));
    return stack;
}

int isFull (struct Stack* stack) {
    return (stack -> top == stack -> capacity-1);
}

int isEmpty (struct Stack* stack) {
    return (stack->top == -1);
}

void push (struct Stack* stack, int item) {
    if (isFull(stack)) {
        printf ("Overflow.\n");
        return;
    }
    else {
        stack -> array[++(stack->top)] = item;
        printf("%d pushed to stack.\n", item);
    }
}

int pop (struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Underflow.\n");
        return INT_MIN;
    }
    return (stack->array[(stack->top)--]);
}

int top (struct Stack* stack) {
    if (isEmpty(stack)) {
        return INT_MIN;
    }
    else {
        return (stack->array[stack->top]);
    }
}

/* --------------- Main Driver Code ------------------- */
int main() {
    struct Stack* stack = createStack(100);
    int option, val;

    do {
        printf ("\n1.PUSH\n2.POP\n3.TOP\n4.EXIT\n");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the number to be pushed: ");
                scanf("%d", &val);
                push(stack, val);
                break;

            case 2:
                printf("%d is popped out.\n", pop(stack));
                break;

            case 3:
                printf ("%d is the top element.\n", top(stack));
                break;

            case 4:
                exit(0);

            default:
                printf ("Invalid option.\n");
        }
    }
    while (option != 4);

    return 0;
}