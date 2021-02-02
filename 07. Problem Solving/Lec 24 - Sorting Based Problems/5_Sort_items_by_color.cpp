/*  PROBLEM:
    Assume that we are given n pairs of items as input, 
    where the first item is a number and the second item 
    is one of three colors (red, blue, or yellow). 
    Further assume that the items are sorted by number. 
    
    Give an O(n) algorithm to sort the items by color 
    (all reds before all blues before all yellows) 
    such that the numbers for identical colors stay sorted. 
    
    For example: (1,blue), (3,red), (4,blue), (6,yellow), (9,red) 
    should become (3,red), (9,red), (1,blue), (4,blue), (6,yellow).

    SOLUTION:
    a) Create 3 buckets, one each for red, blue and yellow.

        for each Pair P in the input
            append P.number to the bucket P.color

    b) Output the data from the red, blue and yellow buckets.
*/

#include <bits/stdc++.h>
using namespace std;

struct Item {
    int number;
    string color;
};

// Main Bucket Sort Logic for this question
void bucketSort (Item* arr, int n) {
    // 1) Create 3 empty buckets
    vector <Item> b[3];

    // 2) Put elements in corresponding buckets
    for (int i = 0; i < n; i++) {
        if (arr[i].color == "red")
            b[0].push_back(arr[i]);
        else if (arr[i].color == "blue")
            b[1].push_back(arr[i]);
        else
            b[2].push_back(arr[i]); 
    }

    // 3) Concatenate all buckets
    int index = 0; 
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < b[i].size(); j++) 
			arr[index++] = b[i][j];
}

/* ------------------ MAIN DRIVER CODE ----------------- */
int main() {
    Item arr[] = {{1, "blue"}, {3, "red"}, {4, "blue"}, {6, "yellow"}, {9, "red"}};
    int size = sizeof(arr)/sizeof(arr[0]);

    bucketSort(arr, size);

    for (int i = 0; i < size; i++) {
        cout << arr[i].number << " " << arr[i].color << endl;
    }

    return 0;
}