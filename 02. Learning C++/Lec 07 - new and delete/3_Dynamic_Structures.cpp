#include <iostream>
using namespace std;

struct shirt
{
    char name[20];
    char size[3];
    double price;
};

int main()
{
    // allot memory for struture
    shirt* s = new shirt;  
    cout << "Enter the name of buyer: ";
    // first method to access member
    cin.get(s -> name, 20);  
    cout << "Enter the size of shirt: ";
    // second method to access member
    cin >> (*s).size;   
    cout << "Enter price: ";
    cin >> s -> price;
    
    cout << "Name: " << (*s).name << endl
         << "Size: " << s -> size << endl
         << "Price: " << s -> price << endl;
    
    delete s;
    return 0;
}
