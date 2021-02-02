# 8. SCOPE

# LEGB RULE:

    # In Python, names are resolved using LEGB rule. Let's see the scopes first
    # and then we shall see each one of them in detail.

    # a) L - Local: These are the names assigned in any way within a function  
    #        (def or lambda) and not declared 'global' in that function. 
    # b) E - Enclosing: Names in the local scope of any and all enclosing
    #        functions, from inner to outer. (Think of this as - Nested scope)
    # c) G - Global: Names assigned at the top-level of the module file or 
    #        declared global within the file.
    # d) B - Built-in: Names preassigned in the built-in names module.

# BUILT-IN scope:

    # Built-in scope is bit simpler than what you may think. The built-in scope 
    # is implemented as a standard library module named builtins, but that name 
    # itself is not placed in the built-in scope, so you have to import it in 
    # order to inspect it. Once you do, you can run a dir call to see which 
    # names are predefined.

    import builtins
    dir(builtins)       # Output: Returns a list of built-in words. 

    # The names in this list constitute the built-in scope in Python; roughly 
    # the first half are built-in exceptions, and the second half are built-in 
    # functions. Also in this list are the special names None, True, and False, 
    # though they are treated as reserved words. Because Python automatically 
    # searches this module last in its LEGB lookup, you get all the names in 
    # this list 'for free' i.e., you can use them without importing any modules.

    # Thus, there are really two ways to refer to a built-in function — by 
    # taking advantage of the LEGB rule, or by manually importing the builtins 
    # module:
    
    zip                 # The normal way
    # Output: <class 'zip'>

    import builtins     # The hard way
    builtins.zip
    # Output: <class 'zip'>

    # The second approach is sometimes useful when local scope overrides 
    # variables of same name in both - the built-in scope and global scope. 
    
    # A function can, for instance, create a local variable called open by 
    # assigning to it:
    
    def hider():
        open = 'spam'           # Local variable, hides built-in
        ...
        f = open('data.txt')    # This won't open a file now in this scope!

    # However, this will hide the built-in function called open that lives in 
    # the built-in (outer) scope. It's also usually a bug, and a nasty one at 
    # that, because Python will not issue a warning message about it. 

# GLOBAL scope:

    # Variables which are declared with the 'global' keyword lie in the 
    # global scope. 'global' allows us to change names that live outside a 
    # def at the top level of a module file. For example:

    X = 88
    def func():
        global X
        X = 99      # This changes X globally
    func()          # Call the function
    print(X)        # Prints 99.

    # But we should try to avoid using 'global' as much as possible. Changing 
    # globals can lead to well-known software engineering problems: because the 
    # variables' values are dependent on the order of calls to arbitrarily 
    # distant functions, programs can become difficult to debug. For example:

    X = 99

    def func1():
        global X
        X = 88

    def func2():
        global X
        X = 77

    # What will the value of X be here?
    # Really, that question has no meaning unless it's qualified with a point 
    # of reference in time—the value of X is timing-dependent, as it depends on 
    # which function was called last (something we can't tell from this file 
    # alone).

    # So the basic doubt would come - then 
    # What's the need of 'global' variables? 
    # When is it actually useful? 

    # One of the possible answers could be - during multithreading, networking, 
    # etc. Multithreading runs function calls in parallel with the rest of the 
    # program. Because all threaded functions run in the same process, 
    # global scopes often serve as shared memory between them. Threading is 
    # commonly used for long-running tasks in GUIs, to implement nonblocking 
    # operations in general and to leverage CPU capacity. 

    # For now, though, especially if you are relatively new to programming, 
    # avoid the temptation to use globals whenever you can — try to communicate 
    # with passed-in arguments and return values instead.

# NESTED/ENCLOSING scope:

    # Before talking about 'enclosing scope', we shall first see - how we nest 
    # functions and how nested functions are called. For the sake of explaining 
    # the flow of function calls, let us take a fairly simple example:

    def f1():
        X = 88
        def f2():           # Define f2 inside f1
            print(X)        # f2 remembers the value X = 88
        return f2           # Return f2 but don't call it
    
    action = f1()           # f1 returns f2 to action.
    action()                # This literally calls f2() and prints 88.

    # Since after f1() is called and return statement is executed, the scope of 
    # variable X ends. However, calling action() allows us to call f2() and we
    # get our required result. The overall effect of this feels as if - f2() 
    # has trapped the value of X or has remembered it. 

    # This idea of 'rememberance of the value' will get clear in the following
    # concept of 'factory functions'. 

    # 'Factory functions' refers to a function object that remembers values in 
    # enclosing scopes regardless of whether those scopes are still present in
    # the memory. Although classes are usually best at remembering state, 
    # because they make it explicit with attribute assignments, such functions 
    # provide an alternative when things to remember are very small and we dont
    # want to create classes for every trivial thing. For example:

    def power(N):
        def action(X):
            return X**N
        return action
    
    square = power(2)
    square          
    # Output: <function power.<locals>.action at 0x000001725BB94E58>

    square(3)       # Output: 9
    square(4)       # Output: 16

    # The most unusual part of this is that the nested function remembers 
    # integer 2, i.e. the value of the variable N in power, even though power 
    # has returned and exited by the time we call action. In effect, N from the 
    # enclosing local scope is retained as state information attached to action, 
    # and we get back its argument squared. 

    # To make things more clearer, let's call power function again.
    cube = power(3)
    cube(3)         # Output: 27
    # Now let's see what happened to our square function.
    square(3)       # Output: 9

    # This works because each call to a factory function like this gets its own 
    # set of state information. In our case, the function we assign to name cube 
    # remembers 3, and square remembers 2, because each has its own state 
    # information retained by the variable N in power.

    # This is an advanced technique that you're unlikely to see very often in 
    # most code, except among programmers with backgrounds in functional 
    # programming languages. On the other hand, enclosing scopes are often 
    # employed by lambda functions because they are expressions, they are 
    # almost always nested within a def. 

    # We are now ready to discuss about - the enclosing scope!

    # We explored the way that nested functions can reference variables in an 
    # enclosing function’s scope, even if that function has already returned. 
    # It turns out that, we can also change such enclosing scope variables, as 
    # long as we declare them in 'nonlocal' statements. With this statement, 
    # nested defs can have both read and write access to names in enclosing 
    # functions.

    # The 'nonlocal' statement is a close cousin to 'global', covered earlier.
    # Like 'global', 'nonlocal' declares a name that will be changed in an 
    # enclosing scope. However, this won't change the variables which are 
    # defined outside all the defs in the global scope of the module. Thus,
    # we can say that - 'nonlocal' statement has meaning only inside a function.

    # Let's try to run through some examples:

    def tester(start):
        state = start
        def nested(label):
            print(label, state)
        return nested
    
    F = tester(0)
    F('spam')       # Output: spam 0
    F('ham')        # Output: ham 0
    F('eggs')       # Output: eggs 0

    # Here we wish to get the 'state' variable in nested() auto-incremented. 
    # Changing a name in an enclosing def’s scope is not allowed by default.
    # This means - we can't do the following:

    def tester(start):
        state = start
        def nested(label):
            print(label, state)
            state += 1
        return nested

    # Doing so will result into an error:
    F = tester(0)
    F('spam')
    # UnboundLocalError: local variable 'state' referenced before assignment

    # If we declare state in the tester scope as nonlocal within nested, we
    # get to change it inside the nested function, too.

    def tester(start):
        state = start
        def nested(label):
            nonlocal state
            print(label, state)
            state += 1          # This increments state on each call
        return nested

    F = tester(0)
    F('spam')       # Output: spam 0
    F('ham')        # Output: ham 1
    F('eggs')       # Output: eggs 2

    # Some cautious cases to look out for:

    # a) Unlike the global statement, nonlocal names really must have previously 
    # been assigned in an enclosing def’s scope when a nonlocal is evaluated, 
    # or else you’ll get an error—you cannot create them dynamically by 
    # assigning them anew in the enclosing scope:

    def tester(start):
        def nested(label):
            nonlocal state
            print(label, state)
            state += 1          
        return nested

    # SyntaxError: no binding for nonlocal 'state' found

    # b) 'nonlocal' restricts the scope lookup to just enclosing defs; 
    # nonlocals are not looked up in the enclosing module’s global scope or the 
    # built-in scope outside all defs, even if they are already there:

    state = 42
    def tester(start):
        def nested(label):
            nonlocal state
            print(label, state)
            state += 1          # This increments state on each call
        return nested

    # SyntaxError: no binding for nonlocal 'spam' found

# LOCAL SCOPE:

    # This is a scope inside a function. Once function execution completes, when
    # called, the variables in this scope aren't accessible. For example:

    def square(x)
        index = 2
        return x**index
    
    # Here 'x' and 'index' both are local to function square.

# ------------------------------------------------------------------------------

# 9. MORE FUNCTION TOOLS

# MAP

    # One of the more common things programs do with lists and other sequences 
    # is apply an operation to each item and collect the results. For example:

    counters = [1, 2, 3, 4]
    updated = []
    for x in counters:
        updated.append(x+10)
    updated     # [11, 12, 13, 14]

    # But because this is such a common operation, Python actually provides a 
    # built-in that does most of the work for you. The map function applies a 
    # passed-in function to each item in an iterable object and returns a list 
    # containing all the function call results. For example:
    def inc(x): return x + 10
    list(map(inc, counters))    # returns [11, 12, 13, 14]

    # Because map expects a function to be passed in, it also happens to be one 
    # of the places where lambda commonly appears:
    list(map((lambda x: x+3), counters))    # returns [4, 5, 6, 7]

    # Moreover, map can be used in more advanced ways than shown here. For 
    # instance, given multiple sequence arguments, it sends items taken from
    # sequences in parallel as distinct arguments to the function:
    list(map(pow, [1, 2, 3], [2, 3, 4]))    # # 1**2, 2**3, 3**4
    # returns [1, 8, 81]

    # The map call is similar to the list comprehension expressions. But map 
    # applies a function call to each item instead of an arbitrary expression. 
    # Because of this limitation, it is a somewhat less general tool. However, 
    # in some cases map may be faster to run than a list comprehension (e.g., 
    # when mapping a built-in function), and it may also require less coding.

    # Python’s built-in ord() function returns the ASCII integer code of a 
    # single character (the chr() built-in is the converse — it returns the 
    # character for an ASCII integer code).

    res = list(map(ord, 'spam'))
    res         # Output: [115, 112, 97, 109]

    # Here is our version of map, which is almost similar to internal
    # implementation. However, internal implemented map() is faster compared
    # to our for loop version. The purpose is to understand what map() does.

    def mymap(func, seq):
        res = []
        for x in seq:
            res.append(func(x))
        return res
    
# FILTER 

    # filter() function is used to filter out items based on test function.
    # For example, following expression filters out positive numbers:

    list (filter((lambda x: x > 0), [-2, 3, -5, 5, 1, 4, -3]))
    # [3, 5, 1, 4]

    # Here is our for loop implementation of filter() function to understand 
    # what it does internally. 

    def myfilter(func, seq):
        res = []
        for x in seq:
            if func(x): res.append(func(x))
        return res    

# REDUCE

    # reduce() in Python 3.x lives in functools module. It accepts an iterator 
    # to process, but it’s not an iterator itself — it returns a single result. 
    # Here are two reduce calls that compute the sum and product of the items 
    # in a list:

    from functools import reduce
    reduce((lambda x, y: x + y), [1, 2, 3, 4])      # returns 10
    reduce((lambda x, y: x*y), [1, 2, 3, 4])    # returns 24

    # The following function emulates most of the built-in's behavior and helps 
    # demystify its operation in general:

    def myreduce(func, seq):
        tally = seq[0]
        for next in seq[1:]:
            tally = func(tally, seq)
        return tally    

# ------------------------------------------------------------------------------
