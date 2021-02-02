/*
    This header file contains normally found items, like constants, structures 
    and function prototypes. The items are placed under two namespaces. 
    
    The first namespace, pers, contains a definition of a Person structure and 
    prototypes for the functions that fill a structure and one that displays 
    the structure's contents. The second namespace, debts, defines a structure 
    for storing name of the person and the amount owed to that person. This 
    structure uses the Person structure, so the debts namespace has a using 
    directive to make the names in the pers namespace available in the debts 
    namespace. The debts namespace also contains some prototypes.
*/

#include <string>

namespace pers
{
    struct Person
    {
        std::string first_name;
        std::string last_name;
    };
    
    void getPerson (Person &);
    void showPerson (const Person &);
}

namespace debts
{
    using namespace pers;
    struct Debt
    {
        Person name;
        double amount;
    };
    void getDebt(Debt &);
    void showDebt(const Debt &);
    double sumDebts(const Debt ar[], int n);
}
