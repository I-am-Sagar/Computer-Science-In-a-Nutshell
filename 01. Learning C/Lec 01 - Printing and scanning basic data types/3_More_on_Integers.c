//3. More on integers

#include <stdio.h>
#include <limits.h>

int main() {
    /*---------------- Point 1 - Different bases of integers ----------------*/
    int x1 = 40;
    int x2 = 050;
    int x3 = 0x28;

    //Printing all in integer form which is by default in base 10 
    printf ("%i %i %i\n", x1, x2, x3);
    //Printing all in decimal form   
    printf ("%d %d %d\n", x1, x2, x3);
    //Printing all in octal form   
    printf ("%o %o %o\n", x1, x2, x3);
    //Printing all in hexadecimal form
    printf ("%x %x %x\n", x1, x2, x3);
    
    //Prints leading zero also in octal numbers
    printf ("%#o \n", x2);
    //Prints leading 0x in hexadecimal numbers
    printf ("%#x %#X \n", x3, x3);
    
    /* -------------- Point 2 - Inter-conversion of bases using printf --------*/

    //printf automatically converts base based on format specifier
    printf ("%d %o %x %X \n", 10, 10, 10, 10); 

    //Error. Here a and A are undeclared variables
 // printf ("%d %d %d %d \n", 10, 12, a, A);

    //Now a and A are constants
    printf ("%d %d %d %d \n", 10, 012, 0xa, 0XA); 

    // Error. printf can convert from decimal to octal or hexadecimal if number 
    // is an integer.
 // printf ("%x %o", 10.55, 3.14); 
    
    //Error. There is no '8' in octal system. So 088 is not octal number.
 // printf ("%x %d", 088, 088);
 
    int x, y;
    scanf ("%o %x", &x, &y);
/* Question: What values should we supply? 50  28  or  050  0x28
    The answer is both are correct. scanf() understands by format specifiers.*/
    printf("%#o %#x \n", x, y);

    /*---------------------- Point 3 - Integer Limits ---------------------- */
    
    int a;     long int b;      long long int c;   
    unsigned int e;   unsigned long int f;  unsigned long long int g; 
    signed int i;   signed long int j;  signed long long int k; 
    short int d;   unsigned short int h;  signed short int l;
    
    printf("\nint: SIZE = %d, MIN = %d, MAX = %d\n", sizeof(a), INT_MIN, INT_MAX);
    printf("\nlong int: SIZE = %d, MIN = %ld, MAX = %ld\n", sizeof(b), LONG_MIN, LONG_MAX);
    printf("\nlong long int: SIZE = %d, MIN = %lld, MAX = %lld\n", sizeof(c), LLONG_MIN, LLONG_MAX);
    printf("\nshort int: SIZE = %d, MIN = %hd, MAX = %hd\n", sizeof(d), SHRT_MIN, SHRT_MAX);
    printf("\nunsigned int: SIZE = %d, MIN = 0, MAX = %u\n", sizeof(e), UINT_MAX);
    printf("\nunsigned long int: SIZE = %d, MIN = 0, MAX = %lu\n", sizeof(f), ULONG_MAX);
    printf("\nunsigned long long int: SIZE = %d, MIN = 0, MAX = %llu\n", sizeof(g), ULLONG_MAX);
    printf("\nunsigned short int: SIZE = %d, MIN = 0, MAX = %hu\n", sizeof(h), USHRT_MAX);
    printf("\nsigned int: SIZE = %d, MIN and MAX same as int.\n", sizeof(i));
    printf("\nsigned long int: SIZE = %d, MIN and MAX same as long int.\n", sizeof(j));
    printf("\nsigned long long int: SIZE = %d, MIN and MAX same as long long int.\n", sizeof(k));
    printf("\nsigned short int: SIZE = %d, MIN and MAX same as short int.\n", sizeof(l));
    
    /*-------------------- Point 4 - Only Data modifiers ---------------------*/
    
    // if no data type is given and only data modifier is used, compiler assumes 
    // data type to be int.
    signed A, B;
    printf("\n%d %d\n", sizeof A, sizeof B); 
    
    return 0;
}
