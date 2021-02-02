/* You are given an array of integers that contain numbers in random order.
   Write a program to find the longest possible subsequence of consecutive 
   numbers from the given array. 
   
   You need to return the output array which contains consecutive elements.
   If two arrays are of equal length, return the array whose index of smallest
   element comes first.

   Example 1:
    Input: 
        13
        2 12 9 16 10 5 3 20 25 11 1 8 6
    Output:
        8 9 10 11 12
    
    Example 2:
     Input:
        7
        15 13 23 21 19 11 16
     Output:
        15 16

    For more clearer explanation of this problem, watch this:
        https://www.youtube.com/watch?v=4fQJGoeW5VE
    
    We are using unordered_set to simplify the solution. We will solve it
    using DP later in DSA (Data Structures and Algorithms) part.
    */

#include<bits/stdc++.h>
using namespace std;

vector<int> longestSubsequence (int *arr, int n) 
{	
    unordered_set<int> s;
    int ans = 0, start;
  
    for (int i = 0; i < n; i++) 
        s.insert(arr[i]); 
  
    for (int i = 0; i < n; i++) 
        if (s.find(arr[i]-1) == s.end()) {
            int j = arr[i]; 
            while (s.find(j) != s.end()) {
                j++;
                if (ans < j- arr[i])
                    start = arr[i];
                ans = max (ans, j-arr[i]);
            } 
        }
    
    vector <int> result;
    
    for (int i = 0; i < ans; i++)
        result.push_back(start+i);
    
    return result;
}

int main() {
    int n;
    cin >> n;
    int *input = new int[n];
    for(int i = 0; i < n; i++){
        cin >> input[i];
    }

    vector<int> output = longestSubsequence(input, n);

    for(int i = 0; i < output.size(); i++)
        cout << output[i] << " ";
    cout << endl;

    return 0;
}
