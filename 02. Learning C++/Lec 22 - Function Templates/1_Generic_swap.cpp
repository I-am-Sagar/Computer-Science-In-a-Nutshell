#include <iostream>
#include <string>
using namespace std;

//A generic function is being created which accepts parameter of type 'Type'
template <typename Type>
//Function prototype with parameter type generalized by using 'Type'
void Swap(Type &a, Type &b)			
{
    Type temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    int i = 10, j = 20;
    double x = 10.1, y = 23.3;
    char a = 'x', b = 'y';
    string p = "Hello", q = "World";
    
    cout << "Before Swapping: " << endl
         << i << " " << j << endl
         << x << " " << y << endl
         << a << " " << b << endl
         << p << " " << q << endl;
    
    Swap (i, j);
    Swap (x, y);
    Swap (a, b);
    Swap (p, q);
    
    cout << "After Swapping: " << endl
         << i << " " << j << endl
         << x << " " << y << endl
         << a << " " << b << endl
         << p << " " << q << endl;
    
    return 0;
}

/* Note that:

    a) There is already a generic swap function available in library with a 
       name 'swap' only. So for successful compilation without clashing the 
       definitions of common function, we name it something other than 'swap'. 
          
       b) Instead of keyword typename, one can use keyword 'class' also without 
       any issue. These words are interchangeable as far as Templates are 
       concerned.
          
       c) Here you see that generic function takes two arguments and both are of 
       general argument type 'Type'. It is possible to have one argument of 
       variable type and other type being fixed like int or float, etc. 
       Eg.
          template <typename Type>
          Type function_name (Type arg1, int arg2)
          {	//Function body;	}
       
   Why this works? 
   
       Firstly lets see the mechanism of working of template:
       
       When a generic function is called, say using int arguments, compiler will 
    create a 'int' version of the function and perform the operation. Next time 
    when same function is called using double arguments, compiler will create a 
    'double' version of the function and so on for char arguments as well. 
    If after this, again a 'int' version of function is called, compiler will 
    use the earlier generated function and will not create it again. So the
    redundancy in code is avoided.
       
       So for each different combination of arguments, compiler generates a new 
    function with those parameters. When the compiler creates the specific 
    version of function, it is called 'specialization'.
       
       Now for swapping, instead of built in types, support for string objects 
    should be provided to swap strings. So Type can even take the class arguments. 
    Thus Typename should be changed to Class in such case. Thus support for 
    both keywords is assumed to be true.
*/
