//9. Categorizing single char - without ASCII

/* Question: Write a C program to check alphabet, digit or special character. */

#include<stdio.h>

int main()
{
    char ch;

    printf("Enter any character: ");
    scanf("%c", &ch);

    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
        printf("'%c' is alphabet.", ch);
    else if(ch >= '0' && ch <= '9')
        printf("'%c' is digit.", ch);
    else 
        printf("'%c' is special character.", ch);
    
    return 0;
}
