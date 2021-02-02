// Containment

/*
    Like everytime, we will declare data items in the private section. But this 
    has some issues. The issue is, since the object, say string, is defined 
    under private section, functions like overloaded operator '+' used for 
    concatenating string, overloaded operator '+=' used for appending string 
    to the existing string, normal member function string.size() which returns 
    size of string, etc. can be accessed by the public member functions of that 
    class and not by anyone other in main.
    
    Example, Consider Student s1; i.e. s1 is the object of class Student, and 
    lets say we use cout << s1; in main(), this won't allow us to print contents 
    of s1. So what we do is, we create overloaded '<<' operator inside which we
    will simply print the string object name and that will call the overloaded 
    '<<' operator of string object. Unfortunately '<<' is not overloaded to 
    print array of class valarray. So we will have to define our own function 
    which prints the valarray and call that function inside overloaded '<<' 
    operator made for class student i.e. for cout << s1.
    
    For now just read the function prototypes and what different functions we 
    have declared here. Also remember the comments, everything will make sense 
    once we study their definitions and program flow when we will be using them.
*/ 

#ifndef STUDENTC_H_
#define STUDENTC_H_

#include <iostream>
#include <string>
#include <valarray>
using namespace std;

class Student
{
    private:
        // For simplification of template declaration further
        typedef valarray<double> ArrayDb;
        string name;       // containing object
        ArrayDb scores;      // containing object

        // This helps to print valarray and is used in overloaded operator <<
        ostream & arr_out(ostream & os) const;

    public:
        //See the use of constructors given below in TIP 1
        Student() : name("Null Student"), scores() {}       //default constructor
        explicit Student(const string & s) : name(s), scores() {}     //Constructor 1
        explicit Student(int n) : name("Null"), scores(n) {}      //Constructor 2
        Student(const string & s, int n) : name(s), scores(n) {}     //Constructor 3 
        Student(const string & s, const ArrayDb & a) : name(s), scores(a) {}   //Constructor 4
        Student(const char * str, const double * pd, int n) : name(str), scores(pd, n) {} //Constructor 5
        ~Student() {}            //Destructor

        //Rest are well discussed in the next .cpp file
        double Average() const;           
        const string & Name() const;
        double & operator[](int i);
        double operator[](int i) const;

        // friend input
        friend istream & operator>>(istream & is, Student & stu);  // 1 word
        friend istream & getline(istream & is, Student & stu);   // 1 line
        // friend output
        friend ostream & operator<<(ostream & os, const Student & stu);
};

#endif

/*
    1. Following are the tasks performed by each constructor:
    
        Default: It creates a student object by initializing the name of student 
        to "Null student" and setting scores to zero.
        1: It receives string object which is initialized to the name of student 
           and scores are set zero.
        2: It receives an integer n and creates the array of n elements, 
           initializing the name of the student to Null.
        3: It receives string object s and integer n. The name is initialized to 
           string object and array of n elements is created.
        4: It receives string object for name initialization and valarray object 
           a which initializes the valarray scores using in-built copy constructor.
        5: It receives a C string, pointer to the first element of array and the 
           number of elements of array. ( C-style )

    2. Note the use of the keyword explicit. Recall that a constructor that can 
       be called with one argument serves as an implicit conversion function 
       from the argument type to the class type.This often is not a good idea. 
       
       For example,
       
       Suppose in a huge program, Student domnic ("domnic", 10); is created. 
       Name is domnic and array of scores of 10 quizzes is created. But due to 
       inattention of programmer, he wrote the statement, domnic = 5;
       This will cause name to get initialized to Null and the array to get 
       resized to 5. This is not a syntactical error and its not even a 
       run-time error. It will just give the wrong output. And such bugs are 
       hard to debug. So its always better to declare the constructors 
       explicit that has one parameter.
*/
