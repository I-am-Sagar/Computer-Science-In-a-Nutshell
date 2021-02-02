/*
    In the previous code we saw how we can convert int or double to object 
    using constructors. 
    
    But can we do reverse? 
        class_name object = value; // Using constructor
        double variable = object; // ? ? ?
    
    The answer is yes we can do that but by using conversion functions. 
    To convert to type typeName, you use a conversion function in this form: 
    operator typeName();
    Eg. operator double(); converts the class object to type double
    
    Note the following points: 
    a) The conversion function must be a class member (it cannot be friend)
    b) The conversion function must not specify any return type
    c) The conversion function must not have any arguments
*/

#include <iostream>
using namespace std;

/* ------------------------  Class Declaration ------------------------------ */

class Stonewt 
{
    private:
        enum {Lbs_per_stn = 14};  // pounds per stone
        int stone;      // whole stones
        double pds_left;    // fractional pounds
        double pounds;     // entire weight in pounds
    public:
        Stonewt();      // default constructor
        Stonewt(double lbs);   // construct from double pounds
        Stonewt(int stn, double lbs);  // construct from stone, lbs
        ~Stonewt() {}

        void show_lbs() const;    // show weight in pounds format
        void show_stn() const;    // show weight in stone format

        // conversion functions
        operator int() const;
        operator double() const;
};

/* --------------------------- Member Definitions --------------------------- */

Stonewt::Stonewt() 
{
    stone = pounds = pds_left = 0;
}

Stonewt::Stonewt(double lbs)
{
    stone = int (lbs) / Lbs_per_stn; // integer division
    pds_left = int (lbs) % Lbs_per_stn + lbs - int(lbs);
    pounds = lbs;
}

Stonewt::Stonewt(int stn, double lbs)
{
    stone = stn;
    pds_left = lbs;
    pounds = stn * Lbs_per_stn +lbs;
}

void Stonewt::show_stn() const
{
    cout << stone << " stone, " << pds_left << " pounds\n";
}

void Stonewt::show_lbs() const
{
    cout << pounds << " pounds\n";
}

Stonewt::operator int() const
{
    return int (pounds + 0.5);
}

Stonewt::operator double()const
{
    return pounds;
}

/* ---------------------------- Main Function ------------------------------- */

int main()
{
    Stonewt poppins(9,2.8);
    cout << "Initial weight: " << endl;
    poppins.show_stn();
    poppins.show_lbs();
    
    double p_wt = poppins;   // implicit conversion
    cout << "Convert to double => ";
    cout << "Poppins: " << p_wt << " pounds.\n";
    
    cout << "Convert to int => ";
    cout << "Poppins: " << int (poppins) << " pounds.\n";
    return 0;
} 
