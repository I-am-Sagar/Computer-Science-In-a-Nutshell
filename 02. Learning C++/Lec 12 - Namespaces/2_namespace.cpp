// This file contains the definitions of the function prototypes declared in 
// 2_namespace.h

// Note how the definition of function prototypes are written inside the 
// namespaces only. This is allowed because, 'namespaces are open'.

#include <iostream>
#include "2_namespace.h"

namespace pers
{
    using std::cout;
    using std::cin;
    
    void getPerson (Person & rp)
    {
        cout << "Enter first name: ";
        cin >> rp.first_name;
        cout << "Enter last name: ";
        cin >> rp.last_name;
    }
    
    void showPerson(const Person & rp)
    {
        cout << rp.last_name << ", " << rp.first_name;
    }
}

namespace debts
{
    void getDebt(Debt & rd)
    { 
        getPerson(rd.name);
        std::cout << "Enter debt: ";
        std::cin >> rd.amount;
    }

    void showDebt(const Debt & rd)
    {
        showPerson(rd.name);
        std::cout <<": $" << rd.amount << std::endl;
    }

    double sumDebts(const Debt ar[], int n)
    {
        double total = 0;
        for (int i = 0; i < n; i++)
            total += ar[i].amount;
        return total;
    }
}
