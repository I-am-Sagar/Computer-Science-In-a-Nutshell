/*  PROBLEM:

    Given two integers 'n' and 'm', find all the stepping numbers
    in range [n, m].

    A number is called stepping number if all adjacent digits have
    an absolute difference of 1. For eg. 321 is a stepping number while
    421 is not. Note: All single digit numbers are stepping numbers.

    SOLUTION:

    Approach 1: (Brute Force)
    A brute force approach is used to iterate through all the integers
    from n to m and check if it's a stepping number. Call the following
    function for each number in range.

    bool isStepNum(int n) {
        int prevDigit = -1;
        while (n) {
            int currDigit = n%10;
            if (prevDigit == -1)
                prevDigit = currDigit;
            else
                if (abs(prevDigit - currDigit) != 1)
                    return false;

            prevDigit = currDigit;
            n /= 10;
        }
        return true;
    }

    Approach 2: (Using BFS)

    At first it looks strange that this problem could be solved
    using BFS. So let us see - how to build the graph first?

    Every node in the graph represents a stepping number;
    there will be a directed edge from a node U to V if V
    can be transformed from U.

    'lastDigit' refers to the last digit of U (i.e. U % 10)
    An adjacent number V can be:
    - U*10 + lastDigit + 1 (Neighbor A)
    - U*10 + lastDigit – 1 (Neighbor B)
    Therefore, every Node will have at most 2 neighboring nodes.

    Edge Cases: When the last digit of U is 0 or 9
    Case 1: lastDigit is 0 : In this case only digit 1 can be appended.
    Case 2: lastDigit is 9 : In this case only digit 8 can be appended.

    What will be the source/starting Node?
    Every single digit number is considered as a stepping number, so bfs
    traversal for every digit will give all the stepping numbers starting
    from that digit.

    Note: For node 0, no need to explore neighbors during BFS traversal
    since it will lead to 01, 012, 010 and these will be covered by the
    BFS traversal starting from node 1.

    Below is the implementation of approach 2.
*/

#include<bits/stdc++.h>
using namespace std;

// Main Logic of Code
void bfs(int n, int m, int num) {
    // Queue will contain all the stepping numbers
    queue<int> q;
    q.push(num);
    while (!q.empty()) {
        // Get the front element and pop from the queue
        int stepNum = q.front();
        q.pop();

        // If the stepping number is in the range [n, m] then display
        if (stepNum <= m && stepNum >= n)
            cout << stepNum << " ";

        // If stepping number is 0 or greater than m, need to explore the neighbors
        if (num == 0 || stepNum > m)
            continue;

        // Get the last digit of the currently visited stepping number
        int lastDigit = stepNum % 10;

        // There can be 2 cases either digit to be appended is lastDigit+1 or lastDigit-1
        int stepNumA = stepNum * 10 + (lastDigit- 1);
        int stepNumB = stepNum * 10 + (lastDigit + 1);

        // If lastDigit is 0 then only possible digit after 0 can be 1 for a stepping number
        if (lastDigit == 0)
            q.push(stepNumB);

        //If lastDigit is 9 then only possible digit after 9 can be 8 for a stepping number
        else if (lastDigit == 9)
            q.push(stepNumA);

        else {
            q.push(stepNumA);
            q.push(stepNumB);
        }
    }
}

void displaySteppingNumbers(int n, int m) {
    for (int i = 0 ; i <= 9 ; i++)
        bfs(n, m, i);
    cout << endl;
}

/* ------------ MAIN DRIVER CODE ------------- */
int main() {
    int n, m;
    cin >> n >> m;

    displaySteppingNumbers(n,m);
    return 0;
}

/*  ADDITIONAL POINT:

    We can solve this problem by DFS also.

    void dfs(int n, int m, int stepNum) {
        // If Stepping Number is in the range [n,m] then display
        if (stepNum <= m && stepNum >= n)
            cout << stepNum << " ";

        // If Stepping Number is 0 or greater than m, then return
        if (stepNum == 0 || stepNum > m)
            return;

        // Get the last digit of the currently visited Stepping Number
        int lastDigit = stepNum % 10;

        // 2 cases either digit to be appended is lastDigit + 1 or lastDigit - 1
        int stepNumA = stepNum*10 + (lastDigit-1);
        int stepNumB = stepNum*10 + (lastDigit+1);

        // If lastDigit is 0 then only possible digit after 0 can be 1
        if (lastDigit == 0)
            dfs(n, m, stepNumB);

        // If lastDigit is 9 then only possible digit after 9 can be 8
        else if(lastDigit == 9)
            dfs(n, m, stepNumA);

        else {
            dfs(n, m, stepNumA);
            dfs(n, m, stepNumB);
        }
    }

    void displaySteppingNumbers(int n, int m) {
        for (int i = 0 ; i <= 9 ; i++)
            dfs(n, m, i);
        cout << endl;
    }
*/