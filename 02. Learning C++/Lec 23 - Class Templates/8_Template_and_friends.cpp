/*
    Type 1: Non-template friend function to Template class
    
    template <class T>
    class HasFriend
    {
            ....
        public:
            friend void counts(); // friend to all class HasFriend instantiations 
            ....
    };
    
    This declaration makes the counts() function a friend to all possible 
    instantiations of the template. For example, it would be a friend to the 
    HasFriend<int> class and the HasFriend<string> class.
    
    Type 2: Bound template Friend
    
    friend void report(HasFriend &); is not possible because there is no such 
    thing as a HasFriend object. There are only particular specializations, 
    such as HasFriend<int>, HasFriend<long>, etc. 
    
    So friend void report(HasFriend<T> &); //This is valid bound template friend
    In this case, report(HasFriend<int> &); will be friend to HasFriend<int> class. 

    Note that report itself is not a template function, but its the parameter of 
    report which is a template.
    
    This means that you have to define explicit specializations for the friends 
    you plan to use:
        void report(HasFriend<short> &) {...}; // explicit specialization for short 
        void report(HasFriend<int> &) {...}; // explicit specialization for int
*/

#include <iostream>
using namespace std;

template <typename T>
class HasFriend
{
    private:
        T item;
        static int ct;
    public:
        HasFriend(const T & i) : item(i) {ct++;}
        ~HasFriend() {ct--; }
        friend void counts();
        // template parameter
        friend void reports(HasFriend<T> &); 
};

// each specialization has its own static data member
template <typename T>
int HasFriend<T>::ct = 0;
// non-template friend to all HasFriend<T> classes

void counts()
{
    cout << "int count: " << HasFriend<int>::ct << "; ";
    cout << "double count: " << HasFriend<double>::ct << endl;
}

// non-template friend to the HasFriend<int> class
void reports(HasFriend<int> & hf)
{
    cout <<"HasFriend<int>: " << hf.item << endl;
}

// non-template friend to the HasFriend<double> class
void reports(HasFriend<double> & hf)
{
    cout <<"HasFriend<double>: " << hf.item << endl;
}

int main()
{
    cout << "No objects declared: ";
    counts();
    HasFriend<int> hfi1(10);
    cout << "After hfi1 declared: ";
    counts();
    HasFriend<int> hfi2(20);
    cout << "After hfi2 declared: ";
    counts();
    HasFriend<double> hfdb(10.5);
    cout << "After hfdb declared: ";
    counts();
    reports(hfi1);
    reports(hfi2);
    reports(hfdb);
    return 0;
}
