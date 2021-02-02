/*
The Stable Marriage Problem states that given N men and N women, where each
person has ranked all members of the opposite sex in order of preference,
marry the men and women together such that there are no two people of opposite
sex who would both rather have each other than their current partners.
If there are no such people, all the marriages are 'stable'.

Consider the following example.

Let there be two men m1 and m2 and two women w1 and w2.
Let m1's list of preferences be {w1, w2}
Let m2's list of preferences be {w1, w2}
Let w1's list of preferences be {m1, m2}
Let w2's list of preferences be {m1, m2}

The matching { {m1, w2}, {w1, m2} } is not stable because m1 and w1 would prefer
each other over their assigned partners. The matching {m1, w1} and {m2, w2} is
stable because there are no two people of opposite sex that would prefer each
other over their assigned partners.

It was shown by Gale and Shapley that - It is always possible to form stable
marriages from lists of preferences. Refer to this article for more reading:
http://www.ams.org/publicoutreach/feature-column/fc-2015-03

Following is Gale–Shapley algorithm to find a stable matching:

The idea is to iterate through all free men while there is any free man
available. Every free man goes to all women in his preference list according to
the order. For every woman he goes to, he checks if the woman is free, if yes,
they both become engaged. If the woman is not free, then the woman chooses
either says no to him or dumps her current engagement according to her
preference list. So an engagement done once can be broken if a woman gets
better option. Time Complexity of Gale-Shapley Algorithm is O(n^2).

Initialize all men and women to free
while there exist a free man m who still has a woman w to propose to {
    w = m's highest ranked such woman to whom he has not yet proposed
    if w is free
       (m, w) become engaged
    else some pair (m', w) already exists
       if w prefers m to m'
          (m, w) become engaged
           m' becomes free
       else
          (m', w) remain engaged
}

Input & Output: Input is a 2D matrix of size (2*N)*N where N is number of
women or men. Rows from 0 to N-1 represent preference lists of men and rows
from N to 2*N – 1 represent preference lists of women. So men are numbered from
0 to N-1 and women are numbered from N to 2*N – 1.

The output is list of married pairs.
*/

#include<bits/stdc++.h>
using namespace std;

// Number of Men or Women
#define N 4

// This function returns true if woman 'w' prefers man 'm1' over man 'm'
bool wPrefersM1OverM(int prefer[2*N][N], int w, int m, int m1) {
    // Check if w prefers m over her current engagment m1
    for (int i = 0; i < N; i++) {
        // If m1 comes before m in the list of w, then w prefers
        // her current engagement. Don't do anything
        if (prefer[w][i] == m1)
            return true;

        // If m comes before m1 in w's list, then free her current
        // engagement and engage her with m
        if (prefer[w][i] == m)
            return false;
    }
}

// Prints stable matching for N boys and N girls. Boys are numbered as 0 to
// N-1. Girls are numbereed as N to 2N-1.
void stableMarriage(int prefer[2*N][N]) {
    // Stores partner of women. This is our output array that
    // stores paing information. The value of wPartner[i]
    // indicates the partner assigned to woman N+i. Note that
    // the woman numbers between N and 2*N-1. The value -1
    // indicates that (N+i)'th woman is free
    int wPartner[N];

    // An array to store availability of men. If mFree[i] is
    // false, then man 'i' is free, otherwise engaged.
    bool mFree[N];

    // Initialize all men and women as free
    memset(wPartner, -1, sizeof(wPartner));
    memset(mFree, false, sizeof(mFree));
    int freeCount = N;

    // While there are free men
    while (freeCount > 0) {
        // Pick the first free man (we could pick any)
        int m;
        for (m = 0; m < N; m++)
            if (mFree[m] == false)
                break;

        // One by one go to all women according to m's preferences.
        // Here m is the picked free man
        for (int i = 0; i < N && mFree[m] == false; i++) {
            int w = prefer[m][i];

            // The woman of preference is free, w and m become
            // partners (Note that the partnership maybe changed
            // later). So we can say they are engaged not married
            if (wPartner[w-N] == -1) {
                wPartner[w-N] = m;
                mFree[m] = true;
                freeCount--;
            }
            // If w is not frees
            else {
                // Find current engagement of w
                int m1 = wPartner[w-N];

                // If w prefers m over her current engagement m1, then
                // break the engagement between w and m1 and engage m with w.
                if (wPrefersM1OverM(prefer, w, m, m1) == false) {
                    wPartner[w-N] = m;
                    mFree[m] = true;
                    mFree[m1] = false;
                }
            } // End of Else
        } // End of the for loop that goes to all women in m's list
    } // End of main while loop


    // Print the solution
    cout << "Woman  Man" << endl;
    for (int i = 0; i < N; i++)
    cout << " " << i+N << "\t" << wPartner[i] << endl;
}

/* ------------------ MAIN DRIVER CODE ------------------- */
int main() {
    int prefer[2*N][N] = {
        {7, 5, 6, 4},
        {5, 4, 6, 7},
        {4, 5, 6, 7},
        {4, 5, 6, 7},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
        {0, 1, 2, 3},
    };

    stableMarriage(prefer);

    return 0;
}
