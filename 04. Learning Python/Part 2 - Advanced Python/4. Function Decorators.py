####################### TOPIC 4 - FUCNTION DECORATORS ##########################

# 1. INTRO TO DECORATORS:

    # Decorators can be used with functions, as well as with classes. However,
    # in this topic, we will restrict our discussion to functions only. 
    # Ensure that you have read about 'Scopes' from 'Python Basics' pdf. 
    # This topic is little tricky. So bear with the information given to you, 
    # till the end - to get few 'Aha...' moments!

    # Look at the following functions given below.

    def decorator(func):
        def new_func():
            original_result = func()
            modified_result = original_result.upper()  
            return modified_result 
        return new_func

    @decorator 
    def my_function():
        greeting = "Hello World!"
        return greeting
    
    # On REPL, when we call this function, we get the output with all letters
    # turned into uppercase. 

    my_function()           # Output: 'HELLO WORLD!'

    # Let's understand the flow of what's happening here.

    # STEP 1 - Python sees the function decorator() and stores it like any other
    # normal function. 

    # STEP 2 - Python sees a new syntax - @<name of the decorator function>. 
    # This is the syntax for assigining a decorator to a function, my_function()
    # in this case. Whenever python sees a decorator like this, it first compiles
    # the base function i.e. my_function() and creates an object of that function.

    # STEP 3 - Python passes this base function's object to the decorator 
    # function, which accepts this object in it's argument 'func'. Now remember,
    # a function decorator should always accept a function object as argument
    # and must also return a function object, usually a modified one. Inside
    # this decorator function, we define another function - which modifies the 
    # result of the original function (which is now stored in 'func') and returns
    # an object of it's own.

    # STEP 4 - So when we call my_function() with a decorator, it is not executed 
    # immediately. What is actually executed is - decorator(my_function). So, 
    # an object of my_function() is created which is passed to the decorator, 
    # a new function is defined, inside which our original function is called. 
    # So 'original_result' now stores 'Hello World!' and then the result is 
    # modified.This modified result will be returned when new_func() will be 
    # called. 
     
    # STEP 5 - Now decorator(my_function) internally calls new_func() and the 
    # value returned by new_func() is returned by decorator(), i.e. the modified
    # one. 

    # I know the flow is little bit complicated, but you must understand this
    # complicacy, if you want to simplify alot of your tasks. For example, 
    # Imagine you have 10 functions in a program and you want to calculate 
    # time taken by each function to complete its task. 

    # One way to do this is - In every function, start the timer clock at the 
    # first line, then stop the timer and print the time before the 
    # return statement. Or else, you can write one simple decorator as follows:

    import time

    def time_calc(func):
        def wrapper_func(*arg, **kwargs):
            t = time.time()
            result = func(*arg, **kwargs)
            print("Time taken by {} is {} seconds".format(func.__name__, time.time()-t))
            return result
        return wrapper_func

    @time_calc
    def my_function(n):
        # do something here

    # All you now need to do is, just put @time_calc before the function 
    # definition, whose execution time you want to calculate.

    # Decorators have many use cases. Suppose 10 functions are communicating with
    # each other i.e. the return value of one function, goes as the argument of 
    # the other and so on. And you want to print the values of arguments recieved
    # and the values returned for every function in order. Either you will add
    # bunch of print statements in every function and comment them out, or you
    # will make a simple decorator from the next time!

# ------------------------------------------------------------------------------

# 2. MULTIPLE DECORATORS

    # It is possible to have multiple decorators for a function. Eg. 

    @decorator1
    @decorator2
    @decorator3
    def my_function():
        # Some steps here

    # In this case, the object of my_function() is passed to decorator3(),
    # the return function of decorator3() is passed to decorator2() and so on. 
    # This means, the decorators are evaluated in the order: 3 -> 2 -> 1.

    # So calling my_function() would be equivalent of calling:
    decorator1(decorator2(decorator3(my_function)))

    # Now again you must ask - What is the use of multiple decorators?
    # What if you want to print values of arguments for some functions, 
    # print time taken by function to execute for some other functions and
    # print both for some functions. Managing print() statements in each of the
    # functions is quite tedious.

    # If this use of multiple decorators doesn't convince you, then here is my
    # favorite use of multiple decorators:

    # In python, type-checking is not done. If you define a function, 
    
    def my_func(a, b):
        # some statements

    # 'a' and 'b' can be anything! They can be lists, integers, floats, etc. 
    # What if we want 'a' and 'b' to be integers only, or strings only. If this
    # function was defined only for strings, even if you pass lists, there is a
    # possibility that the function will execute and return you some value, 
    # without giving you an error. So at this moment, I want to do Type-checking.
    
    # Here is my 'types' decorator:

    def types(arg_name, *allowed_types):
        def make_wrapper(f):
            if hasattr(f, "wrapped_args"):
                wrapped_args = getattr(f, "wrapped_args")
            else:
                code = f.__code__
                wrapped_args = list(code.co_varnames[:code.co_argcount])

            try:
                arg_index = wrapped_args.index(arg_name)
            except ValueError:
                raise NameError(arg_name)

            def wrapper(*args, **kwargs):
                if len(args) > arg_index:
                    arg = args[arg_index]
                    if not isinstance(arg, allowed_types):
                        type_list = " or ".join(str(allowed_type) for allowed_type in allowed_types)
                        raise TypeError("Expected '%s' to be %s; was %s." % (arg_name, type_list, type(arg)))
                else:
                    if arg_name in kwargs:
                        arg = kwargs[arg_name]
                        if not isinstance(arg, allowed_types):
                            type_list = " or ".join(str(allowed_type) for allowed_type in allowed_types)
                            raise TypeError("Expected '%s' to be %s; was %s." % (arg_name, type_list, type(arg)))
                return f(*args, **kwargs)

            wrapper.wrapped_args = wrapped_args
            return wrapper

        return make_wrapper


    @types("x", int, float)
    @types("y", float)
    def foo(x, y):
        return x+y
    
    foo(1, 2.5)         # Output: 3.5
    foo(2.0, 2.5)       # Output: 4.5
    foo('asdf', 2.5)    # Raises TypeError exception
    foo(1, 2)           # Raises TypeError exception

    # Although it is not expected to check types in Python and we should try
    # to avoid such upfront type checks as much as possible. The sole purpose
    # of above code was to show you that - Type Checking is possible in Python
    # as well, using decorators!

# ------------------------------------------------------------------------------