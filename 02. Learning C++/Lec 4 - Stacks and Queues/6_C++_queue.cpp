#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <climits>
using namespace std;

class Queue
{
    private: 
        int Front, Rear;
    public:
        int capacity, queue_size, *array;
    
    Queue()
    {
        queue_size = 0;
        Front = 0;
        Rear = -1; 
    }
    
    void size(int x);
    bool isEmpty();
    bool isFull();
    void enqueue (int item);
    int dequeue();
    int front();
    int rear();
};

void Queue :: size(int x)
{ 
    capacity = x;
    array = (int*)malloc(x*sizeof(int));
}

bool Queue :: isEmpty()
{
    return (queue_size == 0);
}

bool Queue :: isFull()
{
    return (queue_size == capacity);
}

void Queue :: enqueue (int item)
{
    Rear++;
        array[Rear] = item;
        ++queue_size; 
}

int Queue :: dequeue()
{
    int item = array[Front]; 
    Front = (Front + 1)%capacity; 
    --queue_size; 
    return item;
}

int Queue :: front()
{
    return array[Front];
}

int Queue :: rear()
{
    return array[Rear];
}

/*--------------------Main Code -----------------------*/

int main()
{
    Queue queue;
    
    int max, option, val;
    
    cout << "Enter the size of the queue: ";
    cin >> max;
    
    queue.size(max);
    
    do 
    {
        printf ("\n1.Enqueue\n2.Dequeue\n3.Front\n4.Rear\n5.Exit\n");
        cin >> option;
        
        switch (option)
        {
            case 1:
                if (queue.isFull())
                    cout << "Overflow" << endl;
                else
                {
                    cout << "Enter the value to be enqueued: ";
                    cin >> val;
                    queue.enqueue(val);
                } 
                break;
            
            case 2:
                if (queue.isEmpty())
                    cout << "Underflow" << endl;
                else
                    cout << queue.dequeue() << " dequeued from queue." << endl;
                break;
            
            case 3:
                cout << queue.front() << " is the front element." << endl;
                break;
                
            case 4:
                cout << queue.rear() << " is the rear element." << endl;
                break;
                
            case 5:
                exit (0);
            
            default:
                printf ("Invalid option.\n");
                
        }
    }
    while (option != 5);
    
    return 0;
}
