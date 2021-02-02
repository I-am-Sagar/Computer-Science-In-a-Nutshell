#include <iostream>
#include <string>
using namespace std;

template <class T1, class T2>
class Pair
{
    private:
        T1 a;
        T2 b;
    public:
        T1 & first();
        T2 & second();
        
        T1 first() const { return a; }
        T2 second() const { return b; }
    
        Pair(const T1 & avalue, const T2 & bvalue) : a(avalue), b(bvalue) { }
        Pair() {}
};

template<class T1, class T2>
T1 & Pair<T1,T2>::first()
{ return a; }

template<class T1, class T2>
T2 & Pair<T1,T2>::second()
{ return b; }

int main()
{
    Pair<string, int> ratings[4] =
    {
        Pair<string, int>("The Purple Duck", 5),
        Pair<string, int>("The Golden Fish", 4),
        Pair<string, int>("The Black Dog", 5),
        Pair<string, int>("The White Bear", 3)
    };
    
    int joints = sizeof(ratings) / sizeof (Pair<string, int>);
    
    cout << "Number:\t Animal\n";
    
    for (int i = 0; i < joints; i++)
        cout << ratings[i].second() << ":\t "
             << ratings[i].first() << endl;
    
    return 0;
}
