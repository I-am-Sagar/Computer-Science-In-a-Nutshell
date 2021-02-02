//9. Categorizing single char - with ASCII

/* Question: Write a C program to check alphabet, digit or special character 
   using ASCII value.*/

#include<stdio.h>

int main()
{
    char ch;
    
    printf("Enter ASCII of any character: ");
    scanf("%d", &ch);


    if((ch >= 97 && ch <= 122) || (ch >= 65 && ch <= 90))
        printf("'%c' is an alphabet.", ch);
    else if(ch >= 48 && ch <= 57)
        printf("'%c' is a digit.", ch);
    else
        printf("'%c' is a special character.", ch);
    
    return 0;
}

/*      Characters          ASCII Value   
    ------------------  -----------------
        special symbols     0 - 47
            0 - 9           48 - 57
        special symbols     58 - 64
            A - Z           65 - 90
        special symbols     91 - 96
            a - z           97 - 122
        special symbols     123 - 127
*/
