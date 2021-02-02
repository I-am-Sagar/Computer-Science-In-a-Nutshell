// Video Link: https://www.youtube.com/watch?v=ER4ivZosqCg

/*  Problem: Suppose an array A consists of n elements, 
    each of which is red, white, or blue. We seek to sort 
    the elements so that all the reds come before all the whites, 
    which come before all the blues.
    
    The only operation permitted on the keys are
    1. Examine(A,i) -- report the color of the ith element of A.
    2. Swap(A,i,j) -- swap the ith element of A with the jth element.

    Find a correct and efficient algorithm for red-white-blue sorting. 
    There is a linear-time solution.

    SOLUTION:
    This problem is called - "Dutch National Flag Problem".
    The simplest linear time solution performs two passes of the partition 
    operation from Quicksort. The first pass treats the red and white elements 
    as indistinguishable, and separates them from the blue. The second pass is 
    just separates the elements within the red/white sub-array.
*/

#include <bits/stdc++.h>
using namespace std;
enum Colors {RED, WHITE, BLUE};

// Auxiliary function to print array
void print(const Colors* balls, int size) {
    const char* labels[] = {"RED", "WHITE", "BLUE"};
    for (int i = 0; i < size; i++)
        cout << labels[balls[i]] << " ";
    cout << endl;
}

void swap(Colors* a, Colors* b) { 
    Colors temp = *a; 
    *a = *b; 
    *b = temp; 
}

// DNF Partition logic - also called "Three way partition"
void dnf_partition (Colors* balls, int size) {
    int i = 0, j = 0, n = size-1;
    while (j <= n) {
        if (balls[j] < WHITE)
            swap(&balls[i++], &balls[j++]);
        else if (balls[j] > WHITE)
            swap(&balls[j], &balls[n--]);
        else
            j++;
    }
}

int main() {
    Colors balls[] = {RED, WHITE, BLUE, RED, WHITE, RED, BLUE, BLUE, RED};

    random_shuffle(balls, balls+9);
    print(balls, 9);

    dnf_partition(balls, 9);
    print(balls, 9);
}