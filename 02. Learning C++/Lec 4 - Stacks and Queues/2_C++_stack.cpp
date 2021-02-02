#include <iostream>
#include <stdlib.h>
#include <malloc.h>
using namespace std;

class Stack
{
    private: 
        int top;
    public:
        int max, *array;
    
    Stack()
    {
        top = -1; 
    }
    
    void size(int x);
    bool isEmpty();
    bool isFull();
    void push (int item);
    int pop();
    int peek();
};

void Stack :: size(int x)
{ 
    max = x;
    array = (int*)malloc(x*sizeof(int));
}

bool Stack :: isEmpty()
{
    return (top == -1);
}

bool Stack :: isFull()
{
    return (top == max - 1);
}

void Stack :: push (int item)
{
    array[++this->top] = item;
}

int Stack :: pop()
{
    return array[this->top--];
}

int Stack :: peek()
{
    return array[this->top];
}

/* --------------------------- Main Code ------------------------ */

int main()
{
    Stack stack;
    
    int max, option, val;
    
    cout << "Enter the size of the stack: ";
    cin >> max;
    
    stack.size(max);
    
    do 
    {
        printf ("\n1.PUSH\n2.POP\n3.TOP\n4.EXIT\n");
        cin >> option;
        
        switch (option)
        {
            case 1:
                if (stack.isFull())
                    cout << "Overflow" << endl;
                else
                {
                    cout << "Enter the value to be pushed: ";
                    cin >> val;
                    stack.push(val);
                } 
                break;
            
            case 2:
                if (stack.isEmpty())
                    cout << "Underflow" << endl;
                else
                    cout << stack.pop() << " popped out of stack." << endl;
                break;
            
            case 3:
                cout << stack.peek() << " is top element." << endl;
                break;
                
            case 4:
                exit (0);
            
            default:
                printf ("Invalid option.\n");
                
        }
    }
    while (option != 4);
    
    return 0;
}
