//4. More on Floats

#include <stdio.h>
#include <float.h>

int main() {
   /* ------------------- Point 1 - Different decimal formats ---------------*/
   
   float a = 3.141592;
   // Before 'e' is Mantissa and after that is Exponent
   float b = 6.022000e+23;
   float c = 0.00003;
   
   printf(" %f %f %f \n", a, b, c);
   printf("\n %e %e %e \n", a, b, c);
   printf("\n %g %g %g \n", a, b, c);
   
   /* ------------------- Point 2 - Float inaccuracies ----------------------*/
   
   float d = 331.79;
   printf("\n %f %e %g\n", d, d, d);
   
   /* ------------------ Point 3 - Size and Limits of float -----------------*/
   
   printf("\n SIZE = %d, MIN = %g, MAX = %g\n", sizeof(d), FLT_MIN, FLT_MAX);

   return 0;
}

/* NOTES ON ABOVE PROGRAM:

1. %f prints in normal decimal format. %e prints in scientific or exponential 
   format. %g prints what is shorter, scientific form or decimal form. After 
   decimal point, float can hold the precision or accuracy upto 6 digits only. 
   
2. 331.79 is printed as 331.790009. The small inaccuracy is because of the 
   ability of system to store the information. 
   
   Say we have to store 1/3. Now we know to store this we should stack infinite 
   3s which is not possible. This is because after a certain point we have to 
   cut off the remaining 3s. So we store 0.333333 and when we access the value 
   back, we get 0.333333 as answer and not 1/3. 
   
   Similarly computer store decimal numbers in binary. Conversion from decimal 
   to binary may be recurring, so since the limited space is alloted to store 
   data variables, computer has to cut off at some point. 
   
   So there is a loss of accuracy here. Next time when we access that variable 
   to print the value or use it for calculations, that inaccurate binary is 
   converted back to decimal which causes small inaccuracies. 
   
   Because of this reason when high accuracy is needed in calculations, we 
   prefer double. Double (as the name suggests) stores the significant numbers 
   twice more as compared to float i.e. upto 12 digits.

3. We can't use any modifiers with float data type. For example statement like 
   'long float' will give the following error:

   [Error]'long' invalid for 'float'
   
*/
