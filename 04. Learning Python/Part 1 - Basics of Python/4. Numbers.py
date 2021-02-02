# 3. NUMBERS: Int, Bool, Float, Complex, (Decimal)

# a) Integers:

# No limit on range of Python Integers:
    len(str(2**1000000)) 
    # Output: 301030. 2 power 1 million has 301030 digits.

# USAGE OF BUILT-IN FUNCTIONS:
    # - NUMERIC FUNCTIONS: abs(x), divmod(x, y), pow(x, y, [z]), round(x, n)
    # - CONVERSION FUNCTIONS: 

        # Conversion from various bases to decimal.
        a = 1980            # Decimal Notation
        b = 0b11110111100   # Binary Notation
        c = 0x7bc           # Hexadecimal Notation
        d = 0o3674          # Octal Notation
        print(a, b, c, d)
        # Output: 1980 1980 1980 1980

        # Conversion from decimal to various bases.
        bin(a)              # Output: 0b11110111100
        hex(a)              # Output: 0x7bc
        oct(a)              # Output: 0o3674
        print(a, bin(a), hex(a), oct(a)) 
        # Output: 1980 0b11110111100 0x7bc 0o3674

        # int() function:
        # Syntax: int(x, base)
        # - Converts object x to an integer. If the optional base argument is 
        # given it should be an integer between 2 and 36 inclusive.
        # - Raises ValueError on failure or TypeError if x's data type does not 
        # support integer conversion. 
        x = int('5')    # 5 is assigned to x as integer
        x = int('2.5')  
        # Output: ValueError: invalid literal for int() with base 10: '2.5'
        x = int([2, 3])
        # Output: TypeError: int() argument must be a string, a bytes-like 
        # object or a number, not 'list'
        x = int('3674', 8)
        print(x)    # 1980

# b) Booleans:

    # There are two built-in Boolean objects: True and False. 
    a = True
    b = False
    a and b     # False
    a or True   # True

    # Boolean types are the output of the comparison expressions. 
    # COMPARISON OPERATORS: < > == != <= >= 

    # In Python, chained comparisons are allowed. Eg. 'X < Y < Z' will result 
    # in same boolean type as 'X < Y and Y < Z'

    # In python: 0 and 0.0 both represent 'False'.
    0 == False      # Output: True
    0.0 == False    # Output: True

    # "", {}, [], () - are neither 'True' nor 'False'.
    "" == False     # Output: False
    "" == True      # Output: False

    # However, they can be typecasted to bool and then they represent 'False'.
    bool("") == False   # Output: True
    bool([]) == False   # Output: True
      
    # Rest every value of every data type represents 'True'.
    bool(0.0)
    # Output: False
    bool(-0.156)
    # Output: True

    # True and False in python are same as 1 and 0. Example:
    print(True + True + True)       # Output: 3
    print(5*True)                   # Output: 5
    print(True - True - True)       # Output: -1
    print(True + False)             # Output: 1


# c) Floating Point Numbers:
 
    # Like integers, even floating point numbers can be converted to hex()
    # but not to bin() and oct(). 
    print(5.6.hex())
    # Output: 0x1.6666666666666p+2
    # The exponent is indicated using p (“power”) rather than e since e is a 
    # valid hexadecimal digit. This simply shows 5.6 is an object. We will see 
    # this point later – when we will understand that everything in Python, is 
    # an object.


    # Floating point numbers are needed while doing mathematical operations like 
    # sqrt(), sin(), cos(), asin(), sinh(), etc. Python Output 15 digits after 
    # decimal point by default.

    # Doubt: What if I want precision less than 15 digits?
    # Ans: Either use string formatting (covered in Topic 6) or use 'Decimal'
    #      type, covered later in this section.

    import math
    math.pi             # Pre-defined Mathematical Constant
    # Output: 3.141592653589793
    math.sqrt(85)       # Mathematical Function
    # Output: 9.219544457292887
    
    # We dont know what else 'math' module has to offer. So we use help.
    help(math)      # Press 'Q' to end and return to REPL

    math.factorial(6)  # 720
    # This is too verbose. If we need to evaluate - nCk ie. choose k from n,
    # Writing 'math.' again and again is tedious. Here Python allows us to 
    # import specific function into current namespace.
    from math import factorial
    n = 5
    k = 3
    factorial(n)/(factorial(k)*factorial(n-k))

    # During Math operations, two special float values can come as output: 
    # inf (infinity) and nan (not a number). These two fall under 'float' 
    # category and not 'int' as we can see below:
    float('inf')
    # Output: inf
    float('-inf')
    # Output: -inf
    float('nan')
    # Output: nan
    int('inf')
    # Output: ValueError: invalid literal for int() with base 10: 'inf'.

    # Python 3.2 and higher allows checking for finiteness.
    math.isfinite(pos_inf)
    # Output: False
    math.isfinite(0.0)
    # Output: True

    # Comparison operators work as expected for positive and negative infinity.
    import sys
    sys.float_info.max
    # Output: 1.7976931348623157e+308 (this is system dependent)
    pos_inf = float('inf')
    neg_inf = float('-inf')
    pos_inf > sys.float_info.max
    # Output: True
    neg_inf < -sys.float_info.max
    # Output: True
    pos_inf == sys.float_info.max * 1.0000001
    # Out: True
    neg_inf == -sys.float_info.max * 1.0000001
    # Out: True
    -5.0 * pos_inf == neg_inf
    # Out: True
    -5.0 * neg_inf == pos_inf
    # Out: True
    pos_inf * neg_inf == neg_inf
    # Out: True

    # In Math, we can't evaluate 0*inf, inf/inf, inf-inf, etc. 
    # Such expressions result into 'NaN'. 
    0.0 * pos_inf
    # Out: nan
    pos_inf / pos_inf
    # Out: nan

    # NaN is never equal to anything, not even to itself. 
    # We can test for it is with the isnan method.
    float('nan') == float('nan')
    # Output: False
    float('nan') != 5.2
    # Output: True
    float('nan') != float('nan')
    # Output: True
    math.isnan(float('nan'))
    # Output: True

# d) Complex Numbers:

    z = -89.5 + 2.125j
    z.real, z.imag
    # Output: (-89.5, 2.125)

    # Except for //, %, divmod(), and the three-argument pow(), 
    # all the numeric operators and functions mentioned with integers 
    # can be used with complex numbers as well. In addition to that, 
    # one more builtin method i.e. conjugate() can be used with complex types:
    z.conjugate()
    # Output: -89.5 - 2.125j
    
    # There are many functions for complex types in 'cmath' module.
    import cmath
    cmath.phase(z)
    cmath.polar(z)
    cmath.sin(z)
    cmath.sinh(z)

# e) Decimal

    # So far we have seen 4 core numeric types - int, float, bool and complex.
    # These will suffice most of the number crunching that programmers will ever 
    # need. Here is an exotic numeric type - Decimal, which merits a quick look 
    # here.

    # As you may or may not already know, floating-point math is less than 
    # exact, because of the limited space used to store values. For example, the 
    # following should yield zero, but it does not. The result is close to zero,
    # but there are not enough bits to be precise here:
    print(0.1 + 0.1 + 0.1 - 0.3)
    # Output: 5.55111512313e-17

    # However, with decimals, the result can be dead-on:
    from decimal import Decimal
    Decimal('0.1') + Decimal('0.1') + Decimal('0.1') - Decimal('0.3')
    # Output: Decimal('0.0')

    # We can set precision of the decimal result we want.
    Decimal(1)/Decimal(7)
    # Output: Decimal('0.1428571428571428571428571429')
    decimal.getcontext().prec = 4
    Decimal(1)/Decimal(7)
    # Output: Decimal('0.1429')

# ------------------------------------------------------------------------------
