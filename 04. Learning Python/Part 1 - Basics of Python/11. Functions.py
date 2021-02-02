# ############################ TOPIC 5 - FUNCTIONS #############################

# 1. WHY USE FUNCTIONS?
    # - Maximizing code reuse and minimizing redundancy
    # - Procedural decomposition

# ------------------------------------------------------------------------------

# 2. DEF statement

    # The def statement creates a function object and assigns it to a name. 
    # Its general format is as follows:
    def <name>(arg1, arg2,... argN):
        <statements>
        return <value>
    # Technically, a function without a return statement returns the None object 
    # automatically, but this return value is usually ignored.

    # Here are some basic points regarding functions:

    # a) In Python, 'def' is an executable statement. 

    # The Python 'def' is a true executable statement: when it runs, it creates 
    # a new function object and assigns it to a name. We will see exactly - 
    # what does it really mean by - 'def is an executable statement' when we 
    # will see about 'Default Arguments' later.

    # Because it's a statement, a 'def' can appear anywhere — even nested in 
    # other statements. For example: 
    if test:
        def func(): # Define func this way
        ...
    else:
        def func(): # Or else this way
        ...
    ...
    func() # Call the version built during runtime

    # Because the definition of a function is decided at runtime, there's 
    # nothing special about the function name. What's important is the object 
    # to which it refers:
    othername = func    # Assign function object
    othername()         # Equivalent of calling func again

    # b) All functions in Python are polymorphic.
    
    # Functions work on arbitrary types, as long as they support the expected 
    # object interface.
    def intersect(seq1, seq2):
        res = []                # Start empty
        for x in seq1:          # Scan seq1
            if x in seq2:       # Common item?
                res.append(x)   # Add to end
        return res

    s1 = "SPAM"
    s2 = "SCAM"
    x = intersect(s1, s2)               # ['S', 'A', 'M']
    x = intersect([1, 2, 3], (1, 4))    # [1]
    # This time, we passed in different types of objects to our function — 
    # a list and a tuple (mixed types) — and it still picked out the common 
    # items. Because you don't have to specify the types of arguments ahead of 
    # time, the intersect function happily iterates through any kind of sequence 
    # objects you send it, as long as they support the expected interfaces.

# ------------------------------------------------------------------------------

# 3. ARGUMENT PASSING

    # Consider the following situation:

    m = [9, 15, 24]

    def modify(k):
        k.append(39)
        print("k = ", k)

    modify(m)           # Output: k = [9, 15, 24, 39]
    print(m)            # Output: [9, 15, 24, 39]

    # Thus, we can see even 'm' is changed! 

    # Now consider one more situation:

    m = "Sagar"

    def modify(k):
        k = k[:2] + 'm' + k[-2:]
        print(k)
    
    modify(m)           # Output: Samar
    print(m)            # Output: Sagar

    # In this case, 'm' remains unchanged. 

    # From above two situations, we can draw two conclusions:
    # a) Immutable arguments are effectively passed 'by value'.
    # b) Mutable arguments are effectively passed 'by reference'.

    # Finally, we consider one last situation:

    def f(d):
        return d            # This function simply returns whatever it gets

    c = [9, 10]
    e = f(c)
    e is c          # Output: True

    c = "Sagar"
    e = f(c)
    e is c          # Output: True

    # In this case, same objects were returned and no new copies were created.

    # So one last conclusion which we can draw from above situation is:
    # c) 'return' works on 'return by reference' instead of 'return by value',
    #    irrespective of it is returning mutable object or immutable object.

# ------------------------------------------------------------------------------

# 4. DEFAULT, POSITIONAL and KEYWORD ARGUMENTS

# INTRODUCTION:

    # Consider the following function:

    def banner(message, border = '-'):
        line = border*len(message)
        print(line)
        print(message)
        print(line)
    
    banner("Norwegian Blue")   
    # 1 positional argument, and other argument taken by default as '-'

    banner("Sun, Moon & Stars", '*')
    # 2 positional arguments which must be provided in order

    banner("Sun, Moon & Stars", border='#')
    # 1 positional argument and 1 keyword argument. 
    # keyword arguments should be specified only after the positional arguments
    # have been specified in order.
    
    banner(border='+', message="Hello, from World!")
    # 2 keyword arguments. Now order is not important. 

# 'DEF' is an EXECUTABLE STATEMENT:

    # Let's see what we meant earlier by - 'def' is an executable statement. 

    # Consider the following function which shows current time. 

    import time
    def show_time(arg = time.ctime()):
        print(arg)

    show_time()         # Output: Sun Dec 29 01:58:32 2019
    
    # Try executing same function, few seconds or minutes later.
    show_time()         # Output: Sun Dec 29 01:58:32 2019
    show_time()         # Output: Sun Dec 29 01:58:32 2019

    # We may see that show_time() is suggesting that - 'time has stopped 
    # progressing' - which we know is definitely not the case. So how can
    # we explain the output of these calls? By giving following explanation:

    # The 'def' statement is executed. And when 'def' was being executed, 
    # default argument took the value of the current time and was never
    # evaluated again. So we can say - 'def' is executable statement, and is
    # not like a blue-print which classes provide for objects, and default 
    # arguments are evualuated only once. 

# DEFAULT ARGS SHOULD BE IMMUTABLE:

    def add_spam (menu = []):
        menu.append('spam')
        return menu

    breakfast = ['bacon', 'eggs']
    add_spam(breakfast)
    breakfast           # Output: ['bacon', 'eggs', 'spam']

    lunch = ['baked beans']
    add_spam(lunch)
    lunch               # Output: ['baked beans', 'spam']

    # By this moment, our function works as expected. But look what happens
    # when we rely just on default arguments. 

    add_spam()          # returns ['spam']
    add_spam()          # returns ['spam', 'spam']
    add_spam()          # returns ['spam', 'spam', 'spam']

    # This is completely opposite to the intention of programmer of keeping 
    # default argument as empty list. Programmer wanted that everytime, 
    # add_spam() is called with no arguments, it should return just ['spam']. 

    # The solution to this problem is simple, but not very obvious:
    # 'Always use immutable objects as default arguments.'
    # So we modify the above function as:

    def add_spam (menu = None):
        if menu is None:
            menu = []
        menu.append('spam')
        return menu

    add_spam()          # returns ['spam']
    add_spam()          # returns ['spam']

    # Now everything looks fine. 
# ------------------------------------------------------------------------------

# 5. VARARGS

    # Functions can use special arguments preceded with one or two * characters 
    # to collect an arbitrary number of extra arguments. (a feature called as 
    # 'variadic arguments' or 'varargs')

    # Callers can also use the * syntax to unpack argument collections into 
    # discrete, separate arguments.

    # Before we explain the above two points, first look at the syntax:

    # a) As a caller: 
    # func(*sequence)   Pass all objects in sequence as individual positional 
    #                   arguments
    # func(**dict)      Pass all key-value pairs in dict as individual keyword 
    #                   arguments

    # b) At function definition:
    # def func(*name)   Matches and collects remaining positional arguments in 
    #                   a tuple
    # def func(**name)  Matches and collects remaining keyword arguments in 
    #                   a dictionary

    # Now let's look at what they mean: 

    # A function can be called with an arbitrary number of arguments. 
    # These arguments will be wrapped up in a tuple. Before the variable number 
    # of arguments, zero or more normal arguments may occur. Any formal 
    # parameters which occur after the *args parameter are 'keyword-only' 
    # arguments, meaning that they can only be used as keywords rather than 
    # positional arguments. For example:

    def concat(*args, sep = '/'):
        return sep.join(args)
    
    concat("earth", "mars", "venus")
    # returns 'earth/mars/venus'
    concat("earth", "mars", "venus", sep=".")
    # returns 'earth.mars.venus'

    # The reverse situation occurs when the arguments are already in a list or 
    # tuple but need to be unpacked for a function call requiring separate 
    # positional arguments. For instance, the built-in range() function expects 
    # separate start and stop arguments. If they are not available separately, 
    # write the function call with the * operator to unpack the arguments out 
    # of a list or tuple:

    list(range(3, 6))            # normal call with separate arguments
    # returns [3, 4, 5]

    args = [3, 6]
    list(range(*args))           # call with arguments unpacked from a list
    # returns [3, 4, 5]

    # In the same fashion, dictionaries can deliver keyword arguments with the 
    # ** operator:

    def parrot(voltage, state='a stiff', action='voom'):
        print("-- This parrot wouldn't", action, end=' ')
        print("if you put", voltage, "volts through it.", end=' ')
        print("E's", state, "!")

    d = {"voltage": "four million", "state": "bleedin' demised", "action": "VOOM"}
    parrot(**d)

    # Output: '-- This parrot wouldn't VOOM if you put four million volts' 
    #         'through it. E's bleedin' demised !'

# ------------------------------------------------------------------------------
