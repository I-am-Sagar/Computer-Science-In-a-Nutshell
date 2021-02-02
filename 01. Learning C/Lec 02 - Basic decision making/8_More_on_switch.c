//8. More on Switch Statement

/* --------------- POINT 1 - DATA TYPES OF CASE LABEL ----------------------- */

// In C++, If a variable is used as case label, i.e instead of writing case 3:, 
// we are writing case i:, then i must be a constant integer, i.e. i should be
// declared using 'const' variable.

// Following code fails in compilation: 

int main()
{
    int i = 10; int c = 10;
    switch (c)
    {
        case i: //i is not a const int
        printf("Case executed perfectly!");
        break;
    }
    return 0;
}

// But following code works perfectly fine in C++.

int main()
{
    const int i = 10;
    int c = 10;
    
    switch (c)
    {
        case i: 
            printf("Value of c is %d\n", c);
            break;
    }
    return 0;
}

// The above point is valid only for C++. In C, both programs produce error. 
// We cannot use variable name or expression with case.

/* ------------------- POINT 2 - RANGE IN SWITCH CASE ----------------------- */

// We can use range in switch cases as follows:

    case 1 ... 5:   //Correct way
    case 1...5:     //Incorrect way
    
// We have provided the next code demonstrating range in switch case.

