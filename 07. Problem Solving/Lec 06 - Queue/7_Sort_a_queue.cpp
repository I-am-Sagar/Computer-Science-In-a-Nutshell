/*  If we are allowed extra space, then we can simply move all
    items of queue to an array, then sort the array and finally
    move array elements back to queue.

    Following is the idea to sort a queue with constant space:
    - On every pass on the queue, we seek for the next minimum index.
        To do this we dequeue and enqueue elements until we find the next
        minimum. In this operation the queue is not changed at all.
        After we have found the minimum index, we dequeue and enqueue
        elements from the queue except for the minimum index, after we
        finish the traversal in the queue we insert the minimum to the
        rear of the queue. We keep on this until all minimums are pushed
        all way long to the front and the queue becomes sorted.

    - On every next seeking for the minimum, we exclude seeking on the
        minimums that have already sorted.

    - We repeat this method n times.

    - At first we seek for the maximum, because on every pass we need find
        the next minimum, so we need to compare it with the largest element
        in the queue.

    Time complexity: O(n^2) and Space complexity: O(1)
*/

#include <bits/stdc++.h>
using namespace std;

/* Utility function: Queue elements after sortedIndex
   are already sorted. This function returns index of
   min element from front to sortedIndex. */
int minIndex (queue<int> &q, int sortedIndex) {
    int min_index = -1;
    int min_val = INT_MAX;
    int n = q.size();
    for (int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();
        if (curr <= min_val && i <= sortedIndex) {
            min_index = i;
            min_val = curr;
        }
        q.push(curr);
    }
    return min_index;
}

/* Utility Function: This function moves the given
   minimum element to rear of queue. */
void insertMinToRear (queue<int> &q, int min_index) {
    int min_val;
    int n = q.size();
    for (int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();
        if (i != min_index)
            q.push(curr);
        else
            min_val = curr;
    }
    q.push(min_val);
}

// Main Logic of Code
void sortQueue(queue<int> &q) {
    for (int i = 1; i <= q.size(); i++) {
        int min_index = minIndex(q, q.size() - i);
        insertMinToRear(q, min_index);
    }
}

/* --------------- MAIN DRIVER CODE --------------- */
int main() {
  queue<int> q;
  q.push(30);
  q.push(11);
  q.push(15);
  q.push(4);

  sortQueue(q);
  while (q.empty() == false) {
     cout << q.front() << " ";
     q.pop();
  }
  cout << endl;
  return 0;
}