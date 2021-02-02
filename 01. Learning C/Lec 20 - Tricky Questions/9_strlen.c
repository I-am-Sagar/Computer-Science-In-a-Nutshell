//Find the length of the string without using string.h and loop.

#include <stdio.h> 
  
void LengthofString(int n, char *string) 
{  
    if(string[n] == '\0')  
    { 
        printf("%i",n);  
        return; 
    } 
      
    LengthofString(n+1, string); 
    //printf("%c",string[n]); 
} 
  
int main() 
{  
    char string[100]; 
    printf("Give a string : \n");  
    scanf("%s",string); 
    printf("Entered string is:%s\n", string); 
    LengthofString(0,string);
    printf("\n"); 
      
    return 0; 
} 

