//2. Scanning Basic Data Types

#include <stdio.h>
#include <stdbool.h>

int main() {
    int integer;
    float decimal1;
    double decimal2;
    char alphabet;
    
    scanf("%d", &integer);
    scanf("%f", &decimal1);
    scanf("%lf", &decimal2);
    //If you run this code, you won't be able to give alphabet input. 
    scanf("%c", &alphabet);

    printf("integer = %d\n", integer);
    printf("decimal1 = %f\n", decimal1);
    printf("decimal2 = %lf\n", decimal2);
    printf("alphabet = %c\n", alphabet);
    
    return 0;
}

/* 

------------------------ PROBLEM AND SOLUTION FOR SCANF: -----------------------

Consider you are eating a chocolate from a bowl. Now you wish that your bowl 
shouldn't get empty, so that you can eat chocolate continously. For this to 
happen, if the chocolate gets finished, someone should put some chocolate in the 
bowl. Now you will again finish that bowl and the bowl will get filled again 
for the next time.

In this example, the chocolate is the input, the bowl is the buffer and you are 
the CPU. You can relate this to watching videos online, say on YouTube. 
When you click on to a video, the company has two methods to provide you videos: 

1)  If the video is of 50 MB, it will use up your 50 MB data and then you can 
    see the video once it is fully loaded. But this is not data efficient, as 
    you might feel that the video isn't worth after watching just 1 minute and 
    you switch to the next video. So this method is wasting data. One might argue 
    that he has unlimited data but one has to wait alot till the whole video 
    memory gets loaded. 
   
2)  So the websites adpot this method. There is 50 MB stored in their local 
    storage (on server side). There is a buffer on our side (client side) which 
    loads chunks of 5 MB say. While watching the video, when you are on the 
    verge of completing once chunk, the next chunk is loaded in buffer. So in 
    this way you use data only for what you see and not for the entire video. 
    And this is the reason when internet connection is low and the next data is 
    not loaded, we face buffering which means the attempt of loading data into 
    buffer is being made.

Once we know what the buffer is, we can discuss the buffer issues on scanf. When 
we type data, say 15 and press enter, the integer data and the newline character 
(Enter Key) are stored in buffer and then from there it is taken to the memory. 
scanf() sees in buffer and by %d, it is commanded to scan an integer, so it 
scans 15. If there is immediate next scanf, it checks the buffer. By %f it is 
commanded to scan a float, but there is a newline character waiting in the queue. 
Now it is known that new line input is not float, so the buffer is cleared and 
program waits for the next input. We press 3.14 float say and press enter. 
Again the similar process will go on.

The problem comes when we want to scan a character. In C, newline is a valid 
character input. So the program take input of this character as the enter key 
input of the earlier input of data and skips that scan statement. The solution 
is to use " %c" instead of "%c", that single space before %c makes scanf wait 
and clear the whitespaces before getting the value. 

SOLUTION: scanf(" %c", &alphabet);

Another question could be, Why are we not scanning and printing Boolean values? 
The reason to this is - When we scan and print boolean values, the other data 
types behave weirdly. The reason to this might be - printf and scanf were 
defined for the built in data types which were previously available. The 
weirdness is described below: 

Let a, b, c be int, float and char respectively. 

Now scanf("%d %f %c", &a, &b, &c);
    printf("%d %f %c", a, b, c);
    
When run above code lines, with input  1  3.14    s 
we get output        1   3.140000    s

Now add 'd' as bool. 
    scanf("%d %f %c %d", &a, &b, &c, &d);
    printf("%d %f %c %d", a, b, c, d);

When run above code lines, with input  1  3.14  s  0
we get the output      1  3.125000   0

We see two problems here: The float value is not accurate and character 
is not printed.

------------------ PROBLEM WITH FLOAT: --------------------------
    
When used   scanf(" %f", &b);
            printf("%f", b);

we input 12.0 and the output comes 12.000000

But when we use  scanf("%f %d", &b, &d);  // single scanf statement 
OR     scanf(" %f", &b);
       scanf(" %d", &d);   // Two separate calls

And then    printf("%f %d", b, d);

For input       12.0     1  
we get output   8.000000 1

----------------------------- PROBLEM WITH CHAR: -------------------------------

Based on previous knowledge that there are troubles with character our first 
thought goes to buffer issues, i.e. is the user able to respond to the input 
statement of character? 

To prove that, the input is taken we incorporate the scanf statements inside 
printf statements. 

    scanf(" %d", &integer, printf("Integer is scanning: "));
    scanf(" %f", &decimal1, printf("Float is scanning: "));
    scanf(" %lf", &decimal2, printf("Double is scanning: "));
    scanf(" %c", &alphabet, printf("Alphabet is scanning: ")); 
    scanf(" %d", &boolean, printf("Boolean is scanning: "));

When the above statements will execute the input will go like this:
    
    Integer is scanning: 1
    Float is scanning: 12.0
    Double is scanning: 3.14
    Alphabet is scanning: s
    Boolean is scanning: 0

But when printed in order, the output comes as:  
1  8.000000 3.125000  0

------------------------------ FINAL STATEMENT: --------------------------------

C handles every problem very well without using bool data type. The use of 
'bool' is important in C++, where bool is in-built data type like int and float, 
but not in C. So from here on we won't be scanning or printing bool.

*/
