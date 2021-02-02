# ######################### TOPIC 6 - INPUT and OUTPUT #########################

# 1. input() FUNCTION

# INTRODUCTION:

    # This function first takes the input from the user and then evaluates 
    # the expression, which means Python automatically identifies whether 
    # user entered a string or a number or list. If the input provided is 
    # not correct then either syntax error or exception is raised by python. 

    val = input("Enter your value: ") 
    print(val)

    # How input() works?
    # - When input() function executes program flow will be stopped until the 
    #   user has given an input. 
    # - The text or message display on the output screen to ask a user to enter 
    #   input value is optional i.e. the prompt, will be printed on the screen 
    #   is optional.
    # - Whatever you enter as input, input function convert it into a string. 
    #   If you enter an integer value still input() function convert it into a 
    #   string. You need to explicitly convert it into an integer in your code 
    #   using typecasting.

    num = input ("Enter number :") 
    print(num) 
    name1 = input("Enter name : ") 
    print(name1) 

    print ("type of number", type(num)) 
    print ("type of name", type(name1)) 

    # Enter number :56
    # 56
    # Enter name : Sagar
    # Sagar
    # type of number <class 'str'>
    # type of name <class 'str'>

# TYPECASTING:

# a) Typecasting the input to Integer:

    num1 = int(input()) 
    num2 = int(input()) 
    print(num1 + num2) 

# b) Typecasting the input to Float:

    num1 = float(input()) 
    num2 = float(input())  
    print(num1 + num2) 

# c) Typecasting the input to String:

    # input 
    string = str(input()) 
    print(string) 

# MULTIPLE INPUTS:

    # In Python user can take multiple values or inputs in one line by 
    # two methods.
    # - Using split() method
    # - Using List comprehension

# a) Using split() method

    # taking two inputs at a time 
    x, y = input("Enter a two value: ").split() 
    print("Number of boys: ", x) 
    print("Number of girls: ", y) 

    # taking three inputs at a time 
    x, y, z = input("Enter a three value: ").split() 
    print("Total number of students: ", x) 
    print("Number of boys is : ", y) 
    print("Number of girls is : ", z) 

# b) Using List Comprehension

    # taking two input at a time 
    x, y = [int(x) for x in input("Enter two value: ").split()] 
    print("First Number is: ", x) 
    print("Second Number is: ", y) 

    # taking three input at a time 
    x, y, z = [int(x) for x in input("Enter three value: ").split()] 
    print("First Number is: ", x) 
    print("Second Number is: ", y) 
    print("Third Number is: ", z) 

    # taking multiple inputs at a time 
    x = [int(x) for x in input("Enter multiple value: ").split()] 
    print("Number of list is: ", x) 

# ------------------------------------------------------------------------------

# 2. STRING FORMATTING:

    # There are several ways to format the output:
    # - Using formatted string literals
    # - Using str.format()
    # - Manually string formatting

# a) Using formatted string literals:

    # Formatted string literals (also called f-strings for short) let you 
    # include the value of Python expressions inside a string by prefixing the 
    # string with f or F and writing expressions as {expression}. 

    # Example 1:
    year = 2016
    event = 'Referendum'
    print(f'Results of the {year} {event}')
    
    # Example 2:

    # Passing an integer after the ':' will cause that field to be a minimum 
    # number of characters wide. This is useful for making columns line up.
    table = {'Sjoerd': 4127, 'Jack': 4098, 'Dcab': 7678}
    for name, phone in table.items():
        print(f'{name:10} ==> {phone:10d}')

    # Example 3:

    # The general syntax for a format placeholder is:
    #       %[width][.precision]type 
    print(f"Total students: %3d\n Average Marks: %2.2f" %(240, 78.658333))
    
    # Example 4:

    # When the right argument is a dictionary, then the formats in the string 
    # must include a parenthesised mapping key into that dictionary inserted 
    # immediately after the '%' character.
    print(f'%(language)s has %(number)03d quote types.'%{'language': "Python", "number": 2})

# b) Using str.format():

    # The brackets and characters within them (called format fields) are 
    # replaced with the objects passed into the str.format() method.
    print('We are the {} who say "{}!"'.format('knights', 'Ni'))

    # A number in the brackets can be used to refer to the position of the 
    # object passed into the str.format() method.
    print('{0} and {1}'.format('spam', 'eggs'))
    print('{1} and {0}'.format('spam', 'eggs'))

    # If keyword arguments are used in the str.format() method, their values 
    # are referred to by using the name of the argument.
    print('This {food} is {adjective}.'.format(food='spam', adjective='absolutely horrible'))

    # Positional and keyword arguments can be arbitrarily combined.
    print('The story of {0}, {1}, and {other}.'.format('Bill', 'Manfred', other='Georg'))

    # If you have a really long format string that you don’t want to split up, 
    # it would be nice if you could reference the variables to be formatted by 
    # name instead of by position. This can be done by simply passing the dict 
    # and using square brackets '[]' to access the keys. 
    table = {'Sjoerd': 4127, 'Jack': 4098, 'Dcab': 8637678}
    print('Jack: {0[Jack]:d}; Sjoerd: {0[Sjoerd]:d}; Dcab: {0[Dcab]:d}'.format(table))

    # This could also be done by passing the table as keyword arguments with 
    # the ‘**’ notation.
    table = {'Sjoerd': 4127, 'Jack': 4098, 'Dcab': 8637678}
    print('Jack: {Jack:d}; Sjoerd: {Sjoerd:d}; Dcab: {Dcab:d}'.format(**table))

    # Example 1:

    # Formatting of Integers 
    String1 = "{0:b}".format(16) 
    print("\nBinary representation of 16 is ") 
    print(String1) 

    # Formatting of Floats 
    String1 = "{0:e}".format(165.6458) 
    print("\nExponent representation of 165.6458 is ") 
    print(String1) 

    String1 = "{0:.2f}".format(1/6) 
    print("\none-sixth is : ") 
    print(String1) 

    # Example 2:

    # A string can be left() or center(^) justified with the use of format 
    # specifiers, separated by colon(:).

    String1 = "|{:<10}|{:^10}|{:>10}|".format('Left','Center','Right') 
    print("\nLeft, center and right alignment with Formatting: ") 
    print(String1) 

    # Example 3:
    for x in range(1, 11):
        print('{0:2d} {1:3d} {2:4d}'.format(x, x*x, x*x*x))

# c) Manual string formatting:

    # In this, formatting is done by using string functions. For example, 
    # The str.rjust() method of string objects right-justifies a string 
    # in a field of a given width by padding it with spaces on the left. 
    # There are similar methods str.ljust() and str.center(). 

    for x in range(1, 11):
        print(repr(x).rjust(2), repr(x*x).rjust(3), end=' ')
        print(repr(x*x*x).rjust(4))
    
    # There is another method, str.zfill(), which pads a numeric string
    # on the left with zeros.

    '12'.zfill(5)               # '00012'
    '-3.14'.zfill(7)            # '-003.14'
    '3.14159265359'.zfill(5)    # '3.14159265359'

# ------------------------------------------------------------------------------

# 3. TIPS FOR COMPETITIVE PROGRAMMERS (Advanced Topic)

# a) Normal Method:

    # The usual input() and print() functions are very slow. 

    # Consider a question of finding the sum of N numbers given by the user.
    # INPUT FORM:
    # Input a number N.
    # Input N numbers separated by a single space in a line.

    # Basic Code will look like this
    n = int(input()) 
    arr = [int(x) for x in input().split()] 
    summation = sum(arr)
    print(summation) 

# b) Using stdin and stdout:

    # A bit faster method using inbuilt stdin and stdout. 
    # - sys.stdin is a File object. This file will be standard input buffer.
    # - stdout.write('D\n') is faster than print('D').

    # import inbuilt standard input output 
    from sys import stdin, stdout 

    # input via readline method 
    n = stdin.readline() 
    # array input similar method 
    arr = [int(x) for x in stdin.readline().split()] 
    summation = sum(arr)
    # could use inbuilt summation = sum(arr) 

    # print answer via write(). 
    # Write() writes only strings. So we need to convert 
    # any data other data into string first.
    stdout.write(str(summation)) 

# c) Adding a buffered pipe IO: 

    # Simply, adding the buffered IO code before your submission code to 
    # make the output faster. 
    # - io.BytesIO object performs file input-output
    # in form of bytes. BytesIO objects have an internal pointer and for 
    # every call to read(n) the pointer advances. 
    # - The atexit module provides a simple interface to register functions 
    # to be called when a program closes down normally. 
    # - The sys module also provides a hook, sys.exitfunc, but only one 
    # function can be registered there.

    # ----------------------- template begins ----------------------------
    # import libraries for input/ output handling on generic level 
    import atexit, io, sys 

    # A stream implementation using an in-memory bytes buffer. It inherits 
    # BufferedIOBase. 
    buffer = io.BytesIO() 
    sys.stdout = buffer

    # print via here 
    @atexit.register 
    def write(): 
        sys.__stdout__.write(buffer.getvalue())  
    # ----------------------- template ends ------------------------------

    n = int(input()) 
    arr = [int(x) for x in input().split()] 
    summation = sum(arr)
    print(summation) 
