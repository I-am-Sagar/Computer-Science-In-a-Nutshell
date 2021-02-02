//6. Tower of Hanoi

#include <stdio.h>

void towers (int , char, char, char);

int main()
{
    int n;
    printf("Give the number of discs: ");
    scanf("%d", &n);
    
    towers(n, 'A', 'B', 'C');
    
    return 0;
}

void towers(int m, char from, char to, char via)
{
    if (m == 1)
    {
        printf("\nMove from %c to %c\n", from, to);
        return;
    }
    else
    {
        towers(m-1, from, via, to);
        printf("\nMove from %c to %c\n", from, to);
        towers(m-1, via, to, from);
    }
}
