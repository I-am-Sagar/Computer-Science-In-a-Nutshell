// 3. String concat

#include <stdio.h>
#include <string.h>

void xstrcat (char *t, char *s) //t is target and s is source
{
    while (*t)
        t++;
    while (*s)
          *t++ = *s++;
    *t = '\0';
}


int main()
{
    char str1[] = "Nagpur";
    //String should be big enough to keep data after concatenation
    char str2[20] = "Bombay"; 
    char str3[20] = "Bombay";
    
    strcat (str2, str1);
    printf ("%s \n", str2);
    
    xstrcat (str3, str1);
    printf ("%s \n",str3);
    
    return 0;
}

/* More compact xstrcat:

    a) t = t + strlen (t);
       strcpy (t, s);
*/
