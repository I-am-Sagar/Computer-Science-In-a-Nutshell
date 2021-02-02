// 2. string copy

#include <stdio.h>
#include <string.h>

void xstrcpy (char *t, char *s)  //t is target and s is source
{
    while (*s)
    {
        *t = *s;
        t++;
        s++;
    }
    *t = '\0';
}


int main()
{
    char str1[] = "Nagpur";
    char str2[10];
    char str3[10];
    
    strcpy (str2, str1);
    printf ("%s \n", str2);
    
    xstrcpy (str3, str1);
    printf ("%s \n",str3);
    
    return 0;
}

/* More compact xstrcpy:

    a) while (*s)
        *t++ = *s++;
       *t = '\0';
     
    b) while (*t++ = *s++)  //Assignment and not checking statement
        ;      // No need of *t = null;
*/
