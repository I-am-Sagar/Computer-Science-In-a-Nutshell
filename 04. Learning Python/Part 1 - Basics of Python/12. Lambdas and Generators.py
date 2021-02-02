# 6. LAMBDA EXPRESSIONS

# LAMBDA BASICS:

    # Besides the def statement, Python also provides an expression form that 
    # generates function objects. It's called 'Lambda expression'. Like def, 
    # this expression creates a function to be called later, but it returns the
    # function instead of assigning it to a name. This is why lambdas are 
    # sometimes known as anonymous (i.e., unnamed) functions. 

    # The lambda’s general form is the keyword lambda, followed by one or more 
    # arguments (exactly like the arguments list you enclose in parentheses in 
    # a def header), followed by an expression after a colon:

    lambda argument1, argument2,... argumentN :expression using arguments

    # But there are a few differences that make lambdas useful in specialized 
    # roles:

    # a) lambda is an expression, not a statement.

    # Because of this, a lambda can appear in places a def is not allowed by 
    # Python’s syntax—inside a list literal or a function call’s arguments.

    # b) lambda’s body is a single expression, not a block of statements.

    # Because it is limited to an expression, a lambda is less general than a 
    # def — you can only squeeze so much logic into a lambda body without using 
    # statements such as if. This is by design, to limit program nesting: lambda 
    # is designed for coding simple functions and def handles larger tasks.

    # Consider the following list:
    words = ['strawberry', 'fig', 'apple', 'maple', 'banana', 'cherry']
    # Now we need to sort this list such that rhyming words are grouped 
    # together. The idea is to sort words in reverse. 
    sorted(words, key=lambda word: word[::-1])
    
# ------------------------------------------------------------------------------

# 7. GENERATOR FUNCTIONS

# Now before we look at 'Generator' functions, let's look first at - 
# Iterables and Iterators. 

# ITERABLES AND ITERATORS:

    # In the previous section, we mentioned that for loop can work on any 
    # sequence type including lists, tuples, strings, etc. Actually, the for
    # for loop turns out to be even more generic than this — it works on any
    # iterable object. 

    # One of the easiest ways to understand what this means is to look at how 
    # it works with a built-in type such as the file. File objects have a
    # method called readline, which reads one line of text from a file at a 
    # time — each time we call the readline method, we advance to the next line. 
    # At the end of the file, an empty string is returned, which we can detect 
    # to break out of the loop:

    f = open('script1.py')
    f.readline()                # 'import sys\n'
    f.readline()                # 'print(sys.path)\n'
    f.readline()                # 'x = 2\n'
    f.readline()                # 'print(2 ** 33)\n'
    f.readline()                # ''

    # However, files also have a method named __next__ that has a nearly 
    # identical effect — it returns the next line from a file each time it is 
    # called. The only noticeable difference is that __next__ raises a built-in 
    # StopIteration exception at end-of-file instead of returning an empty 
    # string:

    f = open('script1.py')
    f.__next__               # 'import sys\n'
    f.__next__               # 'print(sys.path)\n'
    f.__next__               # 'x = 2\n'
    f.__next__               # 'print(2 ** 33)\n'
    f.__next__               # StopIteration

    # Any object with a __next__ method to advance to a next result, which 
    # raises StopIteration at the end of the series of results, is considered 
    # iterable in Python.

    # The best way to read a text file line by line today is to allow the for 
    # loop to automatically call __next__ to advance to the next line on each 
    # iteration. The file object's iterator will do the work of automatically 
    # loading lines as you go.

    for line in open('script1.py'):
        print(line.upper(), end='')

    # Output: IMPORT SYS
    #         PRINT(SYS.PATH)
    #         X = 2
    #         PRINT(2 ** 33)

    # Notice that the print uses end='' here to suppress adding a \n, because 
    # line strings already have one. 

    # The iterators work quicker and consume less memory compared to 
    # non-iterator equivalent code. For eg. it's also possible to read a file 
    # line by line with a while loop:

    f = open('script1.py')
    while True:
        line = f.readline()
        if not line: break
        print(line.upper(), end='')

    # However, this may run slower than the iterator-based for loop version, 
    # because iterators run at C language speed inside Python, whereas the 
    # while loop version runs Python byte code through the Python virtual 
    # machine.

    # Iterable objects such as strings, lists, sets, etc. can be passed to the
    # built-in iter() function to get an iterator. Iterator is like the pointer
    # which points to the elements of the iterable object. Iterator object can
    # be passed to the built-in function next() to fetch the next item. 

    # Syntax: iterator = iter(iterable)
    #         item = next(iterator)

    iterable = ['Spring', 'Summer', 'Autumn', 'Winter'] 
    iterator = iter(iterable)
    next(iterator)          # Output: Spring

    # The above call is same as calling next() as below:
    iterator.__next__()     # Output: Summer

    next(iterator)          # Output: Autumn
    next(iterator)          # Output: Winter
    next(iterator)          # Output: StopIteration

    # When the for loop begins, it obtains an iterator from the iterable object 
    # by passing it to the iter built-in function; the object returned by iter()
    # has the required next method. This initial step is not required for files, 
    # because a file object is its own iterator. That is, files have their own 
    # __next__ method. 

    f = open('script1.py')
    iter(f) is f            # Output: True
    L = [1, 2, 3]
    iter(L) is L            # Output: False

# GENERATOR FUNCTIONS:

    # Before defining 'generators', let us first see some features of these
    # functions:

    # a) All generators are iterators. 
    # b) Generators are lazily evaluated. This means - the next value in the
    #    sequence is computed on demand. We will see how.
    # c) These are used when we need to model infinite sequences or data streams
    #    with no definite end. For eg. Sensor readings which keep on coming 
    #    from sensors as long as they are on, math sequences and series, large
    #    file processing, etc. 

    # Generators are defined as python function which uses 'yield' keyword
    # atleast once in it's definition. 

    # To understand generators, lets write the most basic generator function. 

    def gen123():
        yield 1
        yield 2
        yield 3

    # We call generators on iterator objects. We create iterators as follows:

    g = gen123()            # Here 'g' is generator object. 

    # Since generators are like iterators, they can be passed to next() method.

    next(g)         # returns 1
    next(g)         # returns 2
    next(g)         # returns 3
    next(g)         # Error: StopIteration

    # Instead of using next() again and again, we can use for loop. 

    for v in gen123():
        print(v)

    # Every generator object formed using same generator function has separate
    # address. This is due to the fact that each iterator can be advanced
    # indenpendently. 
    h = gen123()
    i = gen123()
    h               # returns some address of generator object
    i               # returns some address of generator object
    h is i          # False

    # Let us write a generator funciton with more statements. Following 
    # generator function produces lucas series on demand. 

    def lucas():
        yield 2
        a = 2
        b = 1
        while True:
            yield b
            a, b = b, a+b

    # But what is the benefit of using generators?

    # Let's say we want to calculate the sum of first 1 million squares. 
    # What we can do is - create a list of 1 million squares and then add 
    # them using for loop. This will take around 400 MB memory and considerable
    # time. But what we can do is this - 

    sum(x*x for x in range(1, 1000001))

    # So if we use generator function like range(), it will generate the
    # next value each time and sum will keep on adding it. Thus the memory usage
    # in this case will be insignificant. This is the benefit of lazy evaluation.

# ------------------------------------------------------------------------------