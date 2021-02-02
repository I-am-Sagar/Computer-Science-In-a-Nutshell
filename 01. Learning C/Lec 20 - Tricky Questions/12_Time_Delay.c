#include <stdio.h>
#include <time.h>

int main()
{
    //delay is a variable of data type clock_t.
    //this clock_t is typedef form of floating point number
    clock_t delay; 
                                    
    float seconds;
    printf ("Enter the time delay you want in seconds: ");
    scanf("%f", &seconds);
    
    //seconds converted to ticks
    delay = seconds*CLOCKS_PER_SEC; 
    
    printf ("Starting...\n");
    
    //This starts the clock
    clock_t start = clock();      
    
    // When clock starts it has some non-zero value. That value is stored in 
    // start. The value of clock() will keep on increasing and we wait in loop 
    // till difference < delay.
    while (clock() - start < delay);   
                                        
    printf ("Done.\n");
    return 0;
}
