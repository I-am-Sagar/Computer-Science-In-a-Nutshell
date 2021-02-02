#include <iostream>
#include "1_time_1.h"
using namespace std;

int main()
{
    Time coding   (2, 40);
    Time studying (5, 55);
    Time enjoying (3, 30);
    Time t1, t2, t3, t4, t5, t6;
    
    cout << "Coding time: ";
    coding.Show();
    cout << endl;
    
    cout << "Studying time: ";
    studying.Show();
    cout << endl;
    
    cout << "Enjoying time: ";
    enjoying.Show();
    cout << endl;
    
    //Overloaded '+' operator
    t1 = coding + studying;     
    cout << "Total studying time: ";
    t1.Show();
    cout << endl;
    
    //Using operator function
    t2 = coding.operator+(enjoying);   
    cout << "Total enjoying time: ";
    t2.Show();
    cout << endl;
    
    //Overloaded '-' operator
    t3 = t1 - t2;      
    cout << "Extra study time compared to enjoying time: ";
    t3.Show();
    cout << endl;
    
    //Monthly study time, sundays chutti
    t4 = t1*26;            
    cout << "Monthly studying time: ";
    t4.Show();
    cout << endl;
    
    //Weekly study time
    t5 = t4/4;       
    cout << "Weekly studying time: ";
    t5.Show();
    cout << endl;
    
    //Testing modulus operator, output should be ideally zero here
    t6 = t4 % t5;
    cout << "t4 % t5: ";
    t6.Show();
    cout << endl;
    
    return 0;
}
