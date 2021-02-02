#include "2_student.h"
using namespace std;

/* ------------------------- Public Methods --------------------------------- */
// This method accesses the member functions like size() and sum() of private 
// members of valarray object
double Student::Average() const
{
    if (scores.size() > 0)
        return scores.sum()/scores.size();
    else
        return 0;
}

//This method just returns the name of the student. This returns object by reference. 
const string & Student::Name() const
{
    return name;
}

/* As we discussed in the previous header file, we cannot use overloaded 
   operators directly in the main function. So here we overload [] (indexing) 
   operator which will return the ith quiz score of the student. What happens 
   is, when student[i] is called, overloaded [] for student is called. Inside 
   the overloaded function, scores[i] is executed. This calls the overloaded 
   [] function by object of class valarray. This returns the value of scores 
   then. 
   
   There is similar function with word 'const' written outside (). Why need 
   two declarations? If you observe in second case we are returning scores[i] 
   by value. Now if we don't declare const we may call function only non-const 
   objects. Like following will give an error if the function is not declared 
   as const:

       int x = 3;
       const Student obj;
    //Error obj is const and overloaded function works only for non-const objects. 
       cout << obj[x]; 
   
   So this restricts the user to use only const objects. However if we declare 
   function as const, we can use overloaded function for both const and non-const 
   objects as well.
*/
   
double & Student::operator[](int i)
{
    return scores[i];   // uses valarray<double>::operator[]()
}

double Student::operator[](int i) const
{
    return scores[i];
}

/*--------------------------------- Private Methods --------------------------------------*/

/*
   There is no overloaded '<<' in the valarray class which can print scores like 
   strings, cout << strings;
   Now we want to print something like this, cout << studentObject;
   
   But this should print all the scores (i.e. whole valarray) and the name of 
   the student. Printing the name is easy but printing the array is bit difficult. 
   So first we develop a function that prints valarray.
*/

ostream & Student::arr_out(ostream & os) const
{
    int i;
    int lim = scores.size();
    if (lim > 0)
    {
        for (i = 0; i < lim; i++)
        {
            os << scores[i] << " ";
            if (i % 5 == 4)
                os << endl;
        }
        if (i % 5 != 0)
        os << endl;
    }
    else
        os << " empty array ";
    return os;
}

/* -------------------------------- Friends --------------------------------- */

// This includes the valarray output member function. The overloaded operator 
// can access private_member function. 

// use string version of operator<<()
ostream & operator<<(ostream & os, const Student & stu) 
{
    os << "Scores for " << stu.name << ":\n";
    // use private method for scores
    stu.arr_out(os);      
    return os;
}

/* These are two methods which take input. One is our normal cin >> student 
   which will take only one word as input for name. And other is getline() 
   function which takes line as input for name. */

// use string version of operator>>()
istream & operator>>(istream & is, Student & stu)  
{
    is >> stu.name;
    return is;
}

// use string friend getline(ostream &, const string &)

istream & getline(istream & is, Student & stu) {  
    getline(is, stu.name);
    return is;
}
