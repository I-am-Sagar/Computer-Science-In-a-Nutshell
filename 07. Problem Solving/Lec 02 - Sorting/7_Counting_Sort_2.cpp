/*
    The problem with the previous counting sort was that
    we could not sort the elements if we have negative
    numbers in it. Because there are no negative array indices.
    So what we do is, we find the minimum element and
    we will store count of that minimum element at zero index.
*/

#include<bits/stdc++.h>
using namespace std;

// Auxiliary Function
void printArray(vector <int> & arr) {
    for (int i=0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// Counting sort with negative numbers allowed
void countSort(vector <int>& arr) {
    int max = *max_element(arr.begin(), arr.end());
    int min = *min_element(arr.begin(), arr.end());
    int range = max - min + 1;

    vector<int> count(range), output(arr.size());
    for(int i = 0; i < arr.size(); i++)
        count[arr[i]-min]++;

    for(int i = 1; i < count.size(); i++)
           count[i] += count[i-1];

    for(int i = arr.size()-1; i >= 0; i--) {
        output[ count[arr[i]-min] -1 ] = arr[i];
        count[arr[i]-min]--;
    }

    for(int i=0; i < arr.size(); i++)
        arr[i] = output[i];
}

/* ------------------- MAIN DRIVER CODE ---------------- */
int main() {
    int number, temp;

    cout << "Size = ";
    cin >> number;

    vector<int> arr;

    for (int i = 0; i < number; i++) {
        cout << "a[" << i << "] = ";
        cin >> temp;
        arr.push_back (temp);
    }

    countSort (arr);
    printArray (arr);

    return 0;
}
