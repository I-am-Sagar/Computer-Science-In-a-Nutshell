# ######################## TOPIC 4 - CONTROL STATEMENTS ########################

# 1. IF statement:

    x = int(input("Please enter an integer: "))
    if x < 0:
        x = 0
        print("Negative numbers not allowed. Hence changed to 0.")
    elif x == 0:
        print("You entered zero!")
    elif x < 100:
        print("Your number is less than 100.")
    else
        print("Your number is huge!")

    # There can be zero or more elif parts, and the else part is optional. 
    # The keyword ‘elif’ is short for ‘else if’, and is useful to avoid 
    # excessive indentation. An if … elif … elif … sequence is a substitute 
    # for the switch or case statements found in other languages.

# ------------------------------------------------------------------------------

# 2. WHILE loop:

    # Let's write the code for 'Fibonaci numbers' to demonstrate few points:

    a, b = 0, 1
    while a < 10:
        print(a, end = ' ')
        a, b = b, a+b
    print()
    
    # This example introduces some new features:

    # The first line contains a multiple assignment: the variables a and b 
    # simultaneously get the new values 0 and 1. On the second last line this 
    # is used again, demonstrating that the expressions on the right-hand side 
    # are all evaluated first before any of the assignments take place. 
    # The right-hand side expressions are evaluated from the left to the right.

    # The while loop executes as long as the condition (here: a < 10) remains 
    # true. In Python, like in C, any non-zero integer value is true; zero is 
    # false. The condition may also be a string or list value, in fact any 
    # sequence; anything with a non-zero length is true, empty sequences are 
    # false.

    # print() is used to go to the newline.

# ------------------------------------------------------------------------------

# 3. FOR loop: 

    # The for statement in Python differs a bit from what you may be used to 
    # in C. Rather than always iterating over an arithmetic progression of 
    # numbers or giving the user the ability to define both the iteration step 
    # and halting condition, Python’s for statement iterates over the items of 
    # any sequence (a list or a string), in the order that they appear in the 
    # sequence. For example (no pun intended):

    # Measure some strings:
    words = ['cat', 'window', 'defenestrate']
    for w in words:
        print(w, len(w))

    # If you do need to iterate over a sequence of numbers, the built-in 
    # function range() comes in handy. To iterate over the indices of a 
    # sequence, you can combine range() and len() as follows:

    a = ['Mary', 'had', 'a', 'little', 'lamb']
    for i in range(len(a)):
        print(i, a[i])

    # In most such cases, however, it is convenient to use the enumerate() 
    # function.
    for i, v in enumerate(a):
        print(i, v)                 # Prints same results

    # A strange thing happens if you just print a range:
    print(range(10))
    # In many ways the object returned by range() behaves as if it is a list, 
    # but in fact it isn’t. It returns an object of 'range' class. Range object 
    # returns the successive items of the desired sequence when you iterate 
    # over it, but it doesn’t really make the list, thus saving space. 
    # Thus, to get the list from range(), we have an easy solution:
    list(range(4))

    # When looping through dictionaries, the key and corresponding value can be 
    # retrieved at the same time using the items() method.
    knights = {'gallahad': 'the pure', 'robin': 'the brave'}
    for k, v in knights.items():
        print(k, ': ', v)

    # To loop over two or more sequences at the same time, the entries can be 
    # paired with the zip() function.
    questions = ['name', 'quest', 'favorite color']
    answers = ['lancelot', 'the holy grail', 'blue']
    for q, a in zip(questions, answers):
        print('What is your {0}?  It is {1}.'.format(q, a))

    # To loop over a sequence in reverse, first specify the sequence in a 
    # forward direction and then call the reversed() function.
    for i in reversed(range(1, 10, 2)):
        print(i, end=' ')
    print()

    # To loop over a sequence in sorted order, use the sorted() function which 
    # returns a new sorted list while leaving the source unaltered.
    basket = ['apple', 'orange', 'apple', 'pear', 'orange', 'banana']
    for f in sorted(set(basket)):
        print(f)

# ------------------------------------------------------------------------------

# 4. BREAK and CONTINUE statements:

    # The break statement causes an immediate exit from a loop. Because the code 
    # that follows it in the loop is not executed if the break is reached, you 
    # can also sometimes avoid nesting by including a break. 

    while True:
        name = input('Enter name:')
        if name == 'stop': break
        age = input('Enter age: ')
        print('Hello', name, '=>', int(age) ** 2)
    
    # The continue statement causes an immediate jump to the top of a loop.
    # The next example uses continue to skip odd numbers. This code prints 
    # all even numbers less than 10 and greater than or equal to 0. 
    # Remember, 0 means false and % is the remainder of division operator, 
    # so this loop counts down to 0, skipping numbers that aren’t multiples 
    # of 2 (it prints 8 6 4 2 0):

    x = 10
    while x:
        x = x−1                     # Or, x -= 1
        if x % 2 != 0: continue     # Odd? -- skip print
        print(x, end=' ')

# ------------------------------------------------------------------------------

# 5. ELSE clause with loops:

    # Loop statements may have an else clause; it is executed when the 
    # loop terminates through exhaustion of the iterable (with for) or 
    # when the condition becomes false (with while), but not when the 
    # loop is terminated by a break statement.

    for n in range(2, 10):
        for x in range(2, n):
            if n % x == 0:
                print(n, 'equals', x, '*', n//x)
                break
        else:
            # loop fell through without finding a factor
            print(n, 'is a prime number')

    # Output:
    # 2 is a prime number
    # 3 is a prime number
    # 4 equals 2 * 2
    # 5 is a prime number
    # 6 equals 2 * 3
    # 7 is a prime number
    # 8 equals 2 * 4
    # 9 equals 3 * 3

# ------------------------------------------------------------------------------

# 6. PASS Statement:

    # The pass statement does nothing. It can be used when a statement 
    # is required syntactically but the program requires no action. 

    # This is commonly used for creating minimal classes:
    class MyEmptyClass:
        pass

    # Another place pass can be used is as a place-holder for a function 
    # or conditional body when you are working on new code, allowing you 
    # to keep thinking at a more abstract level.
    def initlog(*args):
        pass

# ------------------------------------------------------------------------------