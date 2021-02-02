/*
    We know that statements like, 

        // double will be automatically converted to long int
        long int side = 3.333;   

        // int will be automatically converted to type double with value 3.0
        double type = 3;
    
    Lets see how these automatic conversions take place in classes. 
    The following class weight contains two measures of weight, stone and pounds. 
    We know the conversion, 1 stone = 14 pounds. 
*/
#include <iostream>
using namespace std;

class Stonewt
{
    private:
        static const int Lbs_per_stn = 14;
        int stone;
        double pds_left;   //Fractional pounds
        double pounds;    //entire weight in pounds
    public:
        Stonewt();
        Stonewt (double lbs);
        Stonewt (int stone, double lbs = 0);
         ~Stonewt () {}    //destructor defined here only
         
         void show_lbs() const;
         void show_stn() const;
};

class Stonewt2      //Members in this class are declared as explicit
{ private:
        static const int Lbs_per_stn = 14;
        int stone;
        double pds_left;   //Fractional pounds
        double pounds;    //entire weight in pounds
    public:
        Stonewt2();
        explicit Stonewt2 (double lbs);
         ~Stonewt2() {}    //destructor defined here only
         
         void show_lbs() const;
         void show_stn() const;
};
    
/*------------------ Definitions of first class Stonewt ----------------------*/
 
Stonewt :: Stonewt ()      //Constructor 1
{
    stone = pounds = pds_left = 0;
}

Stonewt :: Stonewt (double lbs)    //Constructor 2
{
    stone = int(lbs)/Lbs_per_stn;   //integer division
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

Stonewt :: Stonewt (int stn, double lbs) //Constructor 3
{
    stone = stn;
    pds_left = lbs;
    pounds = stn*Lbs_per_stn + lbs;
}

void Stonewt :: show_stn () const
{
    cout << stone << " stone, " << pds_left << " pounds\n";
}

void Stonewt :: show_lbs () const
{
    cout << pounds << " pounds\n";
}

/*---------------- Definition of second class Stonewt2 -----------------------*/

Stonewt2 :: Stonewt2 ()      //Constructor 1
{
    stone = pounds = pds_left = 0;
}

Stonewt2 :: Stonewt2 (double lbs)   //Constructor 2
{
    stone = int(lbs)/Lbs_per_stn;   //integer division
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

void Stonewt2 :: show_stn () const
{
    cout << stone << " stone, " << pds_left << " pounds\n";
}

void Stonewt2 :: show_lbs () const
{
    cout << pounds << " pounds\n";
}

/*----------------------------- Main code -----------------------------------*/

int main()
{
    Stonewt s1;
    // This calls the constructor 2 and converts 'double' 16.6 to 
    // type 'Stonewt' (Automatic conversion)
    s1 = 16.6;   
    
    Stonewt s2;
    // This calls the constructor 3 and converts 'int' 10 to 
    // type 'Stonewt' automatically
    s2 = 10;   
    
    /* Note that all class contructors which have ONE ARGUMENT are causing 
       automatic conversions.
    
       But soon programmers realized this type of automatic conversions is 
       leading to unexpected conversions because the statements look like 
       normal assignment statements. And sometime we may miss and write 
       the variable = value, even when we are not sure, whether variable is 
       object or built-in data-type variable. So they designed a keyword 
       'explicit' to stop these implicit conversions. 
    */
    
    Stonewt2 s21;
    //s21 = 16.6  Not allowed because constructor is declared as explicit

    // Allowed after type casting OR  s21 = Stonewt (16.6); will also work
    s21 = (Stonewt2) 16.6; 

    s1.show_stn();
    s1.show_lbs();
    cout << endl;
    
    s2.show_stn();
    s2.show_lbs();
    cout << endl;
    
    s21.show_stn();
    s21.show_lbs();
    cout << endl;
    
    return 0;
}
