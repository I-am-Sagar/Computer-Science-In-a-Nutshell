// 4. String upper

#include <stdio.h>
#include <string.h>

void xstrupr (char *p) 
{
    while (*p)
    {
        if (*p >= 'a' && *p <= 'z')
            *p = *p - 32;
        p++;
    }
}


int main()
{
    char str1[] = "Nagpur";
    
    //strupr (str1);  Windows-only function (Not for Linux)
    printf ("%s \n", str1);
    
    xstrupr (str1);
    printf ("%s \n",str1);
    
    return 0;
}

