// Following code calculates the average weight of given fishes

#include <iostream>
using namespace std;
const int Max = 6;

int main()
{
    double fish[Max];
    
    cout << "Please enter the weights of your fish.\n";
    cout << "You may enter up to " << Max
         << " fish <q to terminate>.\n";
    int i;
    
    for (i = 0; i < Max; i++)
    {
        cout << "fish #" << i+1 << ": ";
        while (!(cin>>fish[i]))
        {
            //resets input
            cin.clear();
            while (cin.get() != '\n')
                // get rid of bad input
                continue;
                
            // Prompting user for correct input
            cout << "Please enter a number: "; 
        }
    }
    
    double total = 0.0;
    
    for (int j = 0; j < i; j++)
        total += fish[j];
    
    if ( i==0)
        cout << "No fish\n";
    else
        cout << total/i << " = average weight of " << i << " fish.\n";
    
    return 0;
}
