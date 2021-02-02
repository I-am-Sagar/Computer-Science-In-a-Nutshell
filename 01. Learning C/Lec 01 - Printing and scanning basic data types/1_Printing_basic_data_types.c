//1. Printing basic data types

#include <stdio.h>
#include <stdbool.h>

int main() {
    int integer = 55;
    float decimal1 = 3.14159265; //value of pi
    double decimal2 = 9.4607e+15; //value of light year in meters
    char alphabet = 'a';
    bool boolean = 0;
    
    printf("integer = %d\n", integer);
    printf("decimal1 = %f\n", decimal1);
    printf("decimal2 = %lf\n", decimal2);
    printf("alphabet = %c\n", alphabet);
    printf("boolean = %i\n", boolean);
    
    return 0;
}
