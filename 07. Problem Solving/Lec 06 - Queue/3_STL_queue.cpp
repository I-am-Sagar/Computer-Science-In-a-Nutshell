#include <iostream>
#include <queue>
#include <stdlib.h>
using namespace std;

int main() {
    queue<int> s;

    int option, val, front, rear, dequeued, queue_size;

    do {
        cout << "\n1.ENQUEUE\n2.DEQUEUE\n3.FRONT\n4.REAR\n5.SIZE\n6.EXIT\n";
        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter the value to be enqueued: ";
                cin >> val;
                s.push(val);
                break;

            case 2:
                if (s.empty())
                    cout << "Underflow" << endl;
                else {
                    dequeued = s.front();
                    s.pop();
                    cout << dequeued << " dequeued from queue.\n";
                }
                break;

            case 3:
                front = s.front();
                cout << front << " is the front element." << endl;
                break;

            case 4:
                rear = s.back();
                cout << rear << " is the last element in queue" << endl;
                break;

            case 5:
                queue_size = s.size();
                cout << "Size of queue is " << queue_size << endl;
                break;

            case 6:
                exit (0);

            default:
                cout << "Invalid option.\n";

        }
    }
    while (option != 6);

    return 0;
}
