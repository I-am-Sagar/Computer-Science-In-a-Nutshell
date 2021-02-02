// 1. String length

#include <stdio.h>
#include <string.h>

int xstrlen (char *p)
{
    int count = 0;
    while (*p != '\0')
    {
        count++;
        p++;
    }
    return count;
}

int main()
{
    char str1[] = "Nagpur";
    char str2[] = "Ahmedabad";
    
    int l1, l2, x1, x2;
    
    l1 = strlen (str1);
    l2 = strlen (str2);
    
    printf ("%d %d \n", l1, l2);
    
    x1 = xstrlen (str1);
    x2 = xstrlen (str2);
    
    printf ("%d %d \n", x1, x2);
    
    return 0;
}
