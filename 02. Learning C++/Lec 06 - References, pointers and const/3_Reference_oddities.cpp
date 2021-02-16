//3. Reference oddities

#include<iostream>

using namespace std;

double cube (double);
double refcube (double&);

int main()
{
    double x = 3.0;
 
    cout << cube(x) ;
    cout << " is the cube of " << x << ".\n";
    cout << refcube(x);
    cout << " is the cube of " << x << ".\n";

    return 0;
}

double cube (double a)
{
    a *= a*a;
    return a;
}

double refcube (double& refa)
{
    refa *= refa*refa;
    return refa;
}

/* NOTE ON ABOVE EXAMPLE: 

   In this problem, we can learn few a things:
   
   1) From output, we see refcube() modifies the value of x in the main() as 
      well. If we don't want to alter the original values, we should either pass 
      the arguments by value and not by reference or we should declare the 
      reference as const. 
 
     But if we declare the parameter as const, we get the following error message,
  
        [Error]assignment of read-only reference 'refa'
   
    In this case, we should modify the body of the refcube function as,
        
        double refcube (const double& refa)
        {
            return (refa*refa*refa);
        }
    
    
   2) Using reference variable arguments is quite restrictive. 
         This is because following function calls have invalid arguments,
    
        a) double z = refcube (3.0);
        b) double z = refcube (x + 2.0);
          c) int k = 10; double z = refcube(k);
        
    a) is incorrect because we know that reference variables cannot be initialized 
        with a constant. Compiler gives the following error,
      
            [Error] invalid initialization of non-const reference of type 'double&' 
                from an rvalue of type 'double'
           
      This error is solved by declaring the argument as const.
        
    b)  is incorrect because we know that reference variables cannot be initialized 
        with an expression. Compiler gives the following error,
        
            [Error] invalid initialization of non-const reference of type 'double&' 
                from an rvalue of type 'double'
            
      This error is solved by declaring the argument as const.
        
    c)  is incorrect because there is a type mis-match. The compiler gives the 
        following error,
        
            [Error] invalid initialization of reference of type 'double&' from 
                expression of type 'int'
            
       This error is solved by declaring the argument as const.

            But the question is, what happens after declaring the reference variable
        to be const that all above problems are solved. What happens is  when 
        we call the function with argument like x + 2.0, the program creates a 
        temporary, nameless variable, initializing it to the value of the 
        expression x + 2.0. Then refa becomes the reference to that temporary 
        variable. 
        
         Provided that the reference parameter is a const, the compiler generates 
        a temporary variable in two kinds of situations:
        
            * When the actual argument is the correct type but isn't an lvalue [case a), b)].
            * When the actual argument is of wrong type, but it's of a type that can be converted 
            to the correct type [case c)].
        
        Note: double y[3] = {1.0, 2.0, 3.0};  double z = refcube ( y[2] );  
        is a perfectly valid call. 
 
        So there are 3 strong reasons why to declare the reference arguments as const:
        
        1. Using const protects you against programming errors that inadvertently change the data.
        2. Using const allows functions to process both const and non-const actual arguments.
        3. Using const allows functions to generate and use a temporary variable appropiately.
        
        
   3) You might wonder why we have used 4 cout statements if we can write using only one like, 
          
        cout << cube(x)  << " is the cube of "  << x  << ".\n"
             << refcube(x)  << " is the cube of " << x  << ".\n";
      
      But doing so gives an output, 
      
        19683 is the cube of 27.
        27 is the cube of 3.
      
      One may deduce from the output that cout has printed backwards, but thats 
      not the case, because if cout were to print backwards, it would have first 
      printed a dot and a newline character and then would have gone for the rest. 
      You can confirm this by following,
      
        cout << cube(x)  << " is the CUBE of "  << x  << ".\n"
             << refcube(x)  << " is the cube of "  << x  << ".\n";
 
       Output:
       
        19683 is the CUBE of 27.
        27 is the cube of 3.
    
      What's actually happening is this: 
      
      Before printing, cout executes all the functions first. Whenever there is 
      more than 1 function, the order in which they should be evaluated is 
      undefined (until C++17). So the statement like,
      
        cout << g() << h() << i(); 
    
      doesn't gaurantee that evaluation order will be g(), h(), i(). It could be 
      evaluated in order i(), g() and h() or any other random order.
      
      So here the last x is first alloted the value 3, then the refcube(x) is 
      called, returning the value 27. This also alters the x in main() changing 
      its value to 27. This 27 gets printed in place of x on the first line and 
      then cube(x) is called which uses x as 27 and returns a value of 19683. 
      Once these values are determined in this random (here backwards) fashion, 
      the cout goes like usual left-to-right order.
      
      So a call like   cout << g() << h() << i(); must be changed to 
      
      cout << g();
      cout << h();
      cout << i();
      
      to ensure the correct order of evaluation.
*/
