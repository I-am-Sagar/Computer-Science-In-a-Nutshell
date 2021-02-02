// 5. string compare

#include <stdio.h>
#include <string.h>

int xstrcmp (char *t, char *s) 
{
    while (*t == *s)
    {
        if (*t)
            break;
        t++;
        s++;
    }
    return (*t-*s);
}

int main()
{
    char str1[] = "Bombay";
    char str2[] = "Noida"; 
    char str3[] = "Ahmedabad";
    char str4[] = "Bombay";
    
    int i, j, k;
    int x, y, z;
    
    i = strcmp (str1, str2);
    j = strcmp (str1, str3);
    k = strcmp (str1, str4);
    
    printf ("%d %d %d\n", i, j, k);
    
    x = xstrcmp (str1, str2);
    y = xstrcmp (str1, str3);
    z = xstrcmp (str1, str4);
    
    printf ("%d %d %d\n", x, y, z);
    
    return 0;
}
