/*  PROBLEM:
    Given a sorted dictionary (array of words) of an alien 
    language, find order of characters in the language.

    For eg.
    Input:  words[] = {"baa", "abcd", "abca", "cab", "cad"}
    Output: Order of characters is 'b', 'd', 'a', 'c'

    SOLUTION:
    The idea is to create a graph of characters and then 
    find topological sorting of the created graph. 

    1) Create a graph g with number of vertices equal to the 
       size of alphabet in the given alien language. For example, 
       if the alphabet size is 5, then there can be 5 characters 
       in words. Initially there are no edges in graph.

    2) Do following for every pair of adjacent words in given 
       sorted array.
        a) Let the current pair of words be word1 and word2. 
           One by one compare characters of both words and 
           find the first mismatching characters.
        b) Create an edge in g from mismatching character of 
           word1 to that of word2.

    3) Print topological sorting of the above created graph.
*/

#include<bits/stdc++.h>
using namespace std;

// Helper function to print topological sort order
void topologicalSortUtil (vector<int>* adj, int n, int v, bool visited[], stack<int> &s) {
    visited[v] = true;
    for (auto i = adj[v].begin(); i != adj[v].end(); i++)
        if (!visited[*i])
            topologicalSortUtil(adj, n, *i, visited, s);
    s.push(v);
}

void topologicalSort (vector<int>* adj, int n) {
    stack<int> s;
    bool visited[n] = {false};

    for (int i = 0; i < n; i++)
        if (!visited[i])
            topologicalSortUtil(adj, n, i, visited, s);

    // Printing the stack
    while (!s.empty()) {
        cout << (char)('a' + s.top()) << " ";
        s.pop();
    }
    cout << endl;
}

// Main logic of code
void printOrder (vector<string> words, int n, int alpha) {
    vector<int>* graph = new vector<int>[alpha];
    for (int i = 0; i < n-1; i++) {
        string word1 = words[i], word2 = words[i+1];
        for (int j = 0; j < min(word1.length(), word2.length()); j++) {
            if (word1[j] != word2[j]) {
                graph[word1[j]-'a'].push_back(word2[j]-'a');
                break;
            }
        }
    }
    topologicalSort (graph, alpha);
}


/* ---------------- MAIN DRIVER CODE ------------------- */
int main() {
    int num_of_words, num_of_alphabets;
    cin >> num_of_words >> num_of_alphabets;
    vector<string> words;
    string temp;
    for (int i = 0; i < num_of_words; i++) {
        cin >> temp;
        words.push_back(temp);
    }

    printOrder (words, num_of_words, num_of_alphabets);
    return 0;
}