/* 
   We have studied 'Sets' in Mathematics. We know, in sets - elements have to be 
   unique.
   For example, if a = {1, 2, 3, 5, 4} and b = {1, 3, 1, 2, 5}, then
   a is a set and b is not because 1 is repeated in b.

   We will see below some basic functions and implementation of set. 
*/

#include <iostream>
#include <set>
#include <iterator>
using namespace std;

int main() {
    // creating empty set of integers
    set <int> s;

    // We can insert elements using s.insert(element);
    s.insert(4);
    s.insert(3);
    s.insert(1);
    s.insert(2);
    s.insert(5);
    // We may add duplicates, but they will occur only once in set.
    // Set manages to keep only unique elements automatically.
    s.insert(2);

    /* 
    We will now print contents of set 's' and you will notice 2 things:
    a) 2 appears only once. This means, duplicates are automatically removed.
    b) All the elements are sorted in ascending order automatically. If you need, 
       elements to get ordered as per descending order, we need to define 's' as:

       set <int, greater<int>> s;   

       The second argument is the greater comparator. It sorts elements in 
       descending order.
    */
    set <int> :: iterator itr;
    for (itr = s.begin(); itr != s.end(); ++itr)
        cout << *itr << " ";
    cout << endl;

    // Creating set 't' which is copy of set 's'
    set <int> t (s.begin(), s.end());
    for (itr = t.begin(); itr != t.end(); ++itr)
        cout << *itr << " ";
    cout << endl;

    // Without actually reversing the set, we may print it's contents in 
    // reverse order
    set <int> :: reverse_iterator rti;
    for (rti = t.rbegin(); rti != t.rend(); rti++)
        cout << *rti << " ";
    cout << endl;

    // we can print size of our set
    cout << s.size() << endl;

    // Now I want to remove '1' from my set 's'
    s.erase(1);
    for (itr = s.begin(); itr != s.end(); ++itr)
        cout << *itr << " ";
    cout << endl;

    // I want to remove from '1' to '3' from set 't'
    t.erase(t.begin(), t.find(4));
    for (itr = t.begin(); itr != t.end(); ++itr)
        cout << *itr << " ";
    cout << endl;

    return 0;
}

/* 
   There is something called as 'unordered_set' in which the elements don't get 
   sorted. So whenever the order of elements is not important while solving the 
   question, we preferably use 'unordered_set' as it is little faster than 
   normal 'set'.
   
 */