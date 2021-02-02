//10. Swapping data of two variables

#include<stdio.h>
// #include<conio.h>   
// This header was made for and used in MS-DOS Systems and can't be used in Linux
 
int main() {
   int x, y, temp;
 
   printf("Enter the value of x and y\n");
   scanf("%d%d", &x, &y);
 
   printf("Before Swapping\nx = %d\ny = %d\n",x,y);
 
   temp = x;
   x    = y;
   y    = temp;
 
   printf("After Swapping\nx = %d\ny = %d\n",x,y);
// getch();      Won't work in Linux and actually no need on terminal
   return 0;
}
