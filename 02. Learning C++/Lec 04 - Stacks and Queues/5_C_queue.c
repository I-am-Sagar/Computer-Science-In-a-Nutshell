/*
    OPERATIONS PERFORMED ON QUEUE: 
    a) Enqueue: Adds an item in queue and if the queue is full, it gives Overflow condition.
    b) Dequeue: Removes an item from queue and if the queue is empty, it gives Underflow condition.
    c) Rear: It gives item which is last added
    d) Front: It gives item which was first added
    
    This is almost similar to Stacks. The only difference being we remove first 
    added element instead of last as done in stacks.
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <malloc.h>

struct Queue {
    int* array;
    int front, rear, size;
    unsigned capacity; 
    };

struct Queue* createQueue(unsigned capacity) 
{ 
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue)); 
    queue->capacity = capacity; 
    queue->front = queue->size = 0;
    queue->rear = -1; 
    queue->array = (int*) malloc(queue->capacity * sizeof(int)); 
    return queue; 
} 

int isFull(struct Queue* queue) 
{   
    return queue->size == queue->capacity; 
} 

int isEmpty(struct Queue* queue) 
{
    return queue->size == 0;  
} 

void enqueue(struct Queue* queue, int item) 
{ 
    if (isFull(queue)) 
    {
        printf ("Overflow\n");
            return;
    } 
    else
    {
        queue->rear = (queue->rear + 1)%queue->capacity; 
        queue->array[queue->rear] = item;
        queue->size = queue->size+1; 
        printf("%d enqueued to queue\n", item); 
    }
} 

int dequeue(struct Queue* queue) 
{ 
    if (isEmpty(queue)) 
       {
           printf ("Underflow.\n");
           return INT_MIN;
       } 
    int item = queue->array[queue->front]; 
    queue->front = (queue->front + 1)%queue->capacity; 
    queue->size = queue->size - 1; 
    return item; 
} 

int front (struct Queue* queue)
{
    if  (isEmpty(queue))
        return INT_MIN;
    else 
        return queue-> array[queue->front];
}

int rear (struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    else 
        return queue -> array [queue -> rear];
}

int main()
{
    struct Queue* queue = createQueue (100);
    int option, val;
    
    do 
    {
        printf ("\n1.ENQUEUE\n2.DEQUEUE\n3.FRONT\n4.REAR\n5.EXIT\n");
        scanf ("%d", &option);
        
        switch (option)
        {
            case 1:
                printf ("Enter the number to be enqueued: ");
                scanf ("%d", &val);
                enqueue (queue, val);
                break;
            
            case 2:
                printf ("%d is dequeued.\n", dequeue(queue));
                break;
            
            case 3:
                printf ("%d is front element.\n", front(queue));
                break;
                
            case 4:
                printf ("%d is rear element.\n", rear(queue));
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
