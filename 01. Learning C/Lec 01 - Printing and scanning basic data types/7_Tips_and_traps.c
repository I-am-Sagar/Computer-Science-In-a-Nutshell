//7. Basic tips and traps on data types

#include <stdio.h>

int main() {
    /* --------------------- Integer truncation ------------------- */
    int a = 25, b = 2;
    int c = a/b*b;
    
    printf("25/2*2 = %d\n", c);
    
    /* ----------------------- Type promotion --------------------- */
    
    float f1 = 9/2;
    float f2 = 9.0/2;
    float f3 = 9/2.0;
    float f4 = 9.0/2.0;
    printf("\n%f %f %f %f\n", f1, f2, f3, f4);
    
    float f5 = 2/9;
    float f6 = 2/9.0;
    float f7 = 2.0/9;
    float f8 = 2.0/9.0;
    printf("\n%f %f %f %f\n", f5, f6, f7, f8);
    
    //Take it as exercise: Predict the outputs from printf if f1 to f8 were int 
    //type variables and %f is replaced by %d.
    
    double c1, c2, c3, f = 212.0;
    
    c1 = 5/9*(f-32);
    c2 = 5/9.0*(f-32);
    c3 = (f-32)*5/9;
    
    printf("\n%f %f %f\n", c1, c2, c3);
    
    return 0;
}
