#include <iostream>
#include "5_array_template.h"
using namespace std;

int main ()
{
    Array<int, 10> sum;
    Array<double, 10> average;
    //The following is equivalent to twoD[10][5], 10 elements each of which is array of 5 ints
    Array< Array<int, 5>, 10> twoD;
    
    int i, j;
    
    for (i = 0; i < 10; i++)
    {
        sum[i] = 0;
        for (j = 0; j < 5; j++)
        {
            twoD [i][j] = (i+1)*(j+1);
            sum[i] += twoD[i][j];
        }
        average[i] = (double)sum[i]/10;
    }
    
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 5; j++)
        {
            cout.width(2);
            cout << twoD [i][j] << " ";
        }
        cout << " : sum = ";
        cout.width(3);
        cout << sum[i] << " , average = " << average [i] << endl;
    }
    return 0;
}
