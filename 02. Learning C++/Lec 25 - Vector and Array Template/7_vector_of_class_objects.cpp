#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class sample
{
    int temp;
   public:
       sample() {temp = 0;}
       sample (int x) {temp = x;}
       sample & operator = (int x)	{temp = x; return *this;}
       int get_temp() {return temp;}
};

bool operator < (sample a, sample b)
{	return a.get_temp() < b.get_temp();	}

bool operator == (sample a, sample b)
{	return a.get_temp() == b.get_temp(); }


int main()
{
    vector <sample> v;
    unsigned int i;
    
    for (i = 0; i < 7; i++)
        v.push_back ( sample(60 + rand()%30) );
    
    cout << "Fahrenheit temperatures: \n";
    for (i = 0; i < v.size(); i++)
        cout << v[i].get_temp() << " ";
    cout << endl;
    
    //Converting Fahrenheit to Centigrade
    for (i = 0; i < v.size(); i++)
        v[i] = (v[i].get_temp() - 32)*5/9;
        
    cout << "Centigrade temperatures: \n";
    for (i = 0; i < v.size(); i++)
        cout << v[i].get_temp() << " ";
    cout << endl;
    
    return 0;
}
