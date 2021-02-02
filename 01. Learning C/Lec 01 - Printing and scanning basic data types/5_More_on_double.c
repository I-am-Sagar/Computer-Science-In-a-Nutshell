// More on Double

#include <stdio.h>
#include <float.h>

int main() {
    /* ----------------- Point 1 - Different decimal formats -----------------*/
    
    double a = 3.141592;
    double b = 6.022000e+23; 
    double c = 0.00003;
    
    printf(" %f %f %f \n", a, b, c);
    printf("\n %e %e %e \n", a, b, c);
    printf("\n %g %g %g \n", a, b, c);
    
    /* ---------------- Point 2 - Float inaccuracies solved  -----------------*/
    
    double d = 331.79;
    printf("\n %f %e %g\n", d, d, d);
    
    /* ----------------- Point 3 - Size and Limits of double -----------------*/
    
    printf("\n SIZE = %d, MIN = %g, MAX = %g\n", sizeof(d), DBL_MIN, DBL_MAX);
    
    /* ------------------- Point 4 - Data modifier for double ----------------*/
    
    // Only 'long' modifier is allowed for double data types. However we won't 
    // be using long double as double often is adequate.
    long double e = 108.00e+450L;
    printf("\n Size of long double = %d", sizeof(e));
    return 0;
}

/* NOTE ON ABOVE PROGRAM:

 If any other data modifier is used with double, compiler will give an error. 
 Eg. for 'short double a;', we get error as follows:
    
    [Error]'short' invalid for 'double'.
    
*/

