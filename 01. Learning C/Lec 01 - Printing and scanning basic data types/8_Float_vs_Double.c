//8. Difference between float and double

/* For a quadratic equation x2 - 4.0x + 3.9999999 = 0, the exact roots 
   to 10 significant digits are:
    r1 = 2.000316228 and  r2 = 1.999683772

Now the difference between double and float can be seen from following program:
*/

#include <stdio.h>
#include <math.h>

int main() {
    float fa = 1.0f, fb = -4.0f, fc = 3.9999999f;
    double da = 1.0, db = -4.0, dc = 3.9999999;
    
    printf("For float values: \n");

    float fd = fb*fb - 4.0f*fa*fc;
    float r1f = (-fb + sqrt(fd))/(2.0f*fa);
    float r2f = (-fb - sqrt(fd))/(2.0f*fa);
    
    printf("r1 = %.5f and r2 = %.5f\n", r1f, r2f);
    
    printf("\nFor double values: \n");

    double dd = db*db - 4.0*da*dc;
    double r1d = (-db + sqrt(dd))/(2.0*da);
    double r2d = (-db - sqrt(dd))/(2.0*da);
    
    printf("r1 = %.5lf and r2 = %.5lf\n", r1d, r2d);
    
    return 0;
}

/* NOTE ON ABOVE PROBLEM:

By default, every decimal constant is taken as double. So in the above example,
constants like 2.0, 3.0, etc. are considered to be double.

In earlier example, we saw that when there is a operation between int and float, 
the int value is promoted to float and operation takes place. Finally the result 
is made compatible to the data type in which it is to be stored.

So it is a good practice to tell explicity the compiler the decimal number is a 
float by appending a 'f' with the number. Otherwise, compiler will consider
constants as double and similar type promotion will happen during operation
and finally the result of double will be stored in a float variable. This might
sometimes cause hiding of inefficiency of floating point numbers. 

For example, you can delete the appended 'f's with constants and run the code
again, to see the difference yourself!

*/
