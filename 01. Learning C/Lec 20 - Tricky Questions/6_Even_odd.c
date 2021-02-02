// Print number is even or odd without using conditional statements

#include<stdio.h> 
  
int main() 
{ 
  char arr[2][5] = {"Even", "Odd"}; 
  int no1 = 69;
  int no2 = 98; 
   
  printf("69 is %s and 98 is %s.\n", arr[no1%2], arr[no2%2]); 
 
  return 0; 
} 

