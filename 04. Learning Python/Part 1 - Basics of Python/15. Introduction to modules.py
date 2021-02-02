# ########################### TOPIC 7 - MODULES ################################

# 1. INTRODUCTION TO MODULES

# DIFFERENCE BETWEEN MODULES AND SCRIPTS:

    # Suppose we create a file - myfile.py; we can use this file in two ways:

    # a) as a module - that can be imported in python scripts or REPL
    # b) python script - which runs on OS's shell to do some task

    # Suppose the structure of myfile.py is - 

    from math import factorial

    def combination(n, k):
        if n > k:
            return int(factorial(n)/(factorial(k)*factorial(n-k)))
        else:
            print("n can't be smaller than k.\n")

    def permutation(n, k):
        if n > k:
            return int(factorial(n)/factorial(n-k))
        else:
            print("n can't be smaller than k.\n")

    # a) On REPL, we can use this file as module by making an import statement.

    import myfile               # Notice how we omit .py extension during import
    # We can now execute our functions using - 
    myfile.combination(5, 3)
    # We can import specific parts from the module as - 
    from myfile import permutation
    permutation(8, 5)

    # b) But on OS's shell i.e. cmd or terminal, when we run this file - 
    #    this script does nothing. 
    python myfile.py

    # This is usual because we know - all we have done is defined the function
    # but never called them. So let's call them in script! 

    # Add following two lines at the end of myfile.py
    print(combination(5, 3), end=" ")
    print(permutation(8, 5))
    
    # Run this script from OS's shell, as:
    python myfile.py
    # Output: 10 6720

    # But the issue is - when we import this file as module on REPL, 
    # We get an output '10 6720', even if we have not called any function 
    # on REPL. On REPL, 
    import myfile
    # Output: 10 6720 

    # If we import the file again, nothing happens.
    import myfile           # No output like - '10 6720'

    # It seems, as if print() statements were not executed. Thus, we can say
    # that - in python, a file is imported only once.

    # Our aim is now to make a module from which we can usefully import 
    # functions without running the function calls, as well as a file which 
    # can be run as the script. 

# '__name__' AND '__main__':

    # Python runtime environment defines special attribute names, which are 
    # delimited by double underscores. One such attribute is: __name__

    # This __name__ evaluates to __main__ or the actual module name depending
    # on how the enclosing module is being used. To see how, add the following
    # statement as last line of your module:
    print(__name__)

    # On REPL, when we do - import myfile, we get additional line as output, 
    # which is - 'myfile'. If we run this module as script - python myfile.py,
    # we get additional line as output - which is '__main__'.

    # Hence, we modify our module as: 

    from math import factorial

    def combination(n, k):
        if n > k:
            return int(factorial(n)/(factorial(k)*factorial(n-k)))
        else:
            print("n can't be smaller than k.\n")

    def permutation(n, k):
        if n > k:
            return int(factorial(n)/factorial(n-k))
        else:
            print("n can't be smaller than k.\n")

    if __name__ == "__main__":
        print(combination(5, 3), end=" ")
        print(permutation(8, 5))

    # Now we can safely import our module without unduly executing our 
    # function calls and execute the calls only when run as a script. 

# ------------------------------------------------------------------------------