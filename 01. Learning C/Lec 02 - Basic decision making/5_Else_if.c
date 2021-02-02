//5. The else-if clause

/* The marks obtained out of 100 by a student in 6 subjects is entered. 
   If      % >= 90, he gets AA grade.
   If  90> % >= 80, he gets AB grade. 
   If  80> % >= 70, he gets BB grade.
   If  70> % >= 60, he gets BC grade.
   If  60> % >= 50, he gets CC grade.
   If  50> %      , he fails.
Write a prog to calc the grade. */

#include <stdio.h>

int main() 
{
    float m1, m2, m3, m4, m5, m6, per;
    printf("Enter marks in six subjects\n");
    scanf("%f%f%f%f%f%f",&m1, &m2, &m3, &m4, &m5, &m6);
    
    per = (m1+m2+m3+m4+m5+m6)/600*100;
    printf("Your percentage is %f\n",per);
    
    if (per>=90)
        printf("Congrats, you got AA grade\n");
    else if (per>=80)
        printf("Keep it up, you got AB grade\n");
    else if (per>=70)
        printf("Good, you got BB grade\n");
    else if (per>=60)
        printf("Work Hard, you just got BC grade\n");
    else if (per>=50)
        printf("Poor performance, you got CC grade\n");
    else if (per<50)
        printf("It's sad for you and happy for your friends, that you FAIL!!!\n");
    return 0;
}
