// 9. Range in Switch statement

#include <stdio.h>

int main()
{
    int arr[] = {1, 5, 15, 20};
    
    for (int i = 0; i < 4; i++)
        switch (arr[i])
        {
            case 1 ... 6:
                printf("%d in range 1 to 6\n", arr[i]);
                break;
            
            case 19 ... 20:
                printf("%d in range 16 to 20\n", arr[i]);
                break;
                
            default:
                printf("%d not in range\n", arr[i]);
        }
    return 0;
}

/* 
    ERROR CONDITIONS:
    
    a) low > high: Compiler gives an error for 13 ... 10
    
    b) Overlaping case values: If the value of a case label is within a case 
       range that has already been used, the compiler gives an error.
*/