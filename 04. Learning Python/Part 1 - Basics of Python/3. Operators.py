# 2. OPERATORS:

# ARITHMETIC: + - * / % // ** 
# RELATIONAL: > < == != >= <= 
# LOGICAL: and, or, not.

    # Python provides three logical operators: and, or, and not. 
    # Both 'and' and 'or' use short-circuit logic. 
    # 'and' returns the first false value. If not found, returns last.
    # 'or' returns the first true value. If not found, returns last.
    3 and 0 and 5                   # Output: 0
    3 and 5 and 10                  # Output: 10
    'large' and '' and 'small'      # Output: ''
    'large' or '' or 'small'        # Output: 'large'

# BITWISE: | & ^ ~ << >> 
# ASSIGNMENT: = += -= *= /= %= //= **= &= |= ^= >>= <<=
# IDENTITY: is, is not.

    # 'is' and 'is not' are the identity operators both are used to check 
    # if two objects are located on the same part of the memory. 
    # Two variables that are equal does not imply that they are identical.

    a1 = 3
    b1 = 3
    a2 = 'Sagar'
    b2 = 'Sagar'
    a3 = [1,2,3] 
    b3 = [1,2,3] 
    print(a1 is not b1)     # False
    print(a2 is b2)         # True
    print(a3 is b3)         # False, since lists are mutable.

# MEMBERSHIP: in, not in. 

    # 'in' and 'not in' are used to test whether a value or variable is in a 
    # sequence.
    x = 'Sagar'
    y = [1, 3, 5, 7]
    z = {3:'blue', 1:'brown'}

    print('g' in x)         # True
    print(5 not in y)       # False
    print(3 in z)           # True
    print('brown' in z)     # False

# ------------------------------------------------------------------------------