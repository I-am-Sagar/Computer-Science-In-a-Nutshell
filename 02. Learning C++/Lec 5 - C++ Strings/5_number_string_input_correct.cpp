//5. Numeric and string input together - corrected

#include <iostream>

using namespace std;

int main()
{
    int year;
    char address[80];
    
    cout << "In what year were you born?\n";
    (cin >> year).get();
     // One can make separate calls: cin >> year; cin.get()  
    
    cout << "Where do you live?\n";
    cin.getline(address, 80);
    
    cout << "\nYear born: " << year << endl;
    cout << "Address: " << address << endl;
    
    return 0;
}
