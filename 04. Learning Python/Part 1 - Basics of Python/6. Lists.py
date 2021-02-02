# 5. LISTS

# INTRODUCTION: 

    squares = [1, 4, 9, 16, 25]
    squares     # Output: [1, 4, 9, 16, 25]
    
    # Lists also support operations like concatenation
    squares + [36, 49, 64, 81, 100]
    # Output - [1, 4, 9, 16, 25, 36, 49, 64, 81, 100]

    # The built-in function len() also applies to lists
    letters = ['a', 'b', 'c', 'd']
    len(letters)    # Output: 4

    L = [123, 'spam', 1.23]     # No type constraints

    # We can convert - string into a list of characters using list()
    S = 'shrubbery'
    L = list(S)
    L   # Output: ['s', 'h', 'r', 'u', 'b', 'b', 'e', 'r', 'y']
    # To get the string back from list, we can use join() method.
    A = ''.join(L)
    A   # Output: 'shrubbery'

# SEQUENCE OPERATIONS: 

    # Like strings (and all other built-in sequence types), lists can be indexed
    # and sliced.
    squares[0]      # '1'
    squares[-1]     # '25'
    squares[-3:]    # [9, 16, 25]
    squares[99]     # IndexError: list index out of range

# MUTABILITY:

    # Unlike strings, which are immutable, lists are a mutable type, 
    # i.e. it is possible to change their content.
    cubes = [1, 8, 27, 65, 125]
    cubes[3] = 64  # replace the wrong value
    cubes
    # Output - [1, 8, 27, 64, 125]

# NESTING:
    a = ['a', 'b', 'c']
    n = [1, 2, 3]
    x = [a, n]      # No type constraints.
    x               # [['a', 'b', 'c'], [1, 2, 3]]
    x[0]            # ['a', 'b', 'c']
    x[0][1]         # 'b'

# TYPE-SPECIFIC METHODS:

# a) Adding elements to the list:

    # Using append():

    # Add an item to the end of the list. Equivalent to a[len(a):] = [x].
    L = []
    L.append(1)
    L.append(2)
    L.append(4)
    L   # [1, 2, 4]

    # Using extend():

    # Extend the list by appending all the items from the iterable. 
    # Equivalent to a[len(a):] = iterable.
    L.extend([5, 6, 7])
    L   # [1, 2, 4, 5, 6, 7]
    # Note: append() and extend() can only add elements in the end.

    # Using insert():

    # Insert an item at a given position. The first argument is the index of the
    # element before which to insert, so a.insert(0, x) inserts at the front of 
    # the list, and a.insert(len(a), x) is equivalent to a.append(x).
    L.insert(2, 3)
    L   # [1, 2, 3, 4, 5, 6, 7]

# b) Removing elements from the list:

    # Using pop():
    
    # Remove the item at the given position in the list, and return it. If no 
    # index is specified, a.pop() removes and returns the last item in the list.
    L.pop()
    L   # [1, 2, 3, 4, 5, 6]
    L.pop(5)
    L   # [1, 2, 3, 4, 5]

    # Using remove():

    # Remove the first item from the list whose value is equal to x. 
    # It raises a ValueError if there is no such item.
    L.remove(3)
    L   # [1, 2, 4, 5]

    # Using clear():

    # Remove all items from the list and makes it a null list. 
    L.clear()
    L   # []

    # Using del:
    
    L = [1, 2, 3, 4]
    # We can delete elements or entire list by using 'del' keyword as well.
    # Syntax: del sequence[index]  or del sequence
    del L[2]  
    
    # Deleting the list even deletes the reference.
    del L
    L
    # Output: NameError: name 'L' is not defined

# c) Other utility functions:

    # 1. list.index(x, [start], [end])
    # Return zero-based index in the list of the first item whose value is 
    # equal to x. Raises a ValueError if there is no such item.

    # 2. list.count(x)
    # Return the number of times x appears in the list.

    # 3. list.reverse()
    # Reverse the elements of the list in place.

    # 4. list.sort()
    # Sort the items of the list in place.

    # 5. list.min() and list.max()
    # Returns minimum and maximum valued elements in the list respectively.

# range() FUNCTION:

    range(0, 5)         # Returns range object and not the list
    # The result remains the same even if we use range() inside print() as:
    print(range(0, 5))
    # To get the list, we need to typecast it, i.e.
    list(range(0, 5))
    # We shall revisit this point of range() again at two places: firstly when 
    # we shall be looking at the 'for loop' and secondly during 'generators'. 

    list(range(4))		# List of 0 to n-1 for range(n)
    # Output: [0, 1, 2, 3]
    list(range(-6, 7, 2))	# -6 to 7 by shift of 2
    # Output: [-6, -4, -2, 0, 2, 4, 6]
    [[x, x**2, x/2] for x in range(-6, 7, 2) if x > 0]
    # Output: [[2, 4, 1], [4, 16, 2], [6, 36, 3]]

# COMPREHENSIONS:

# a) Introduction: 

    # List comprehensions provide a concise way to create lists. Common 
    # applications are to make new lists where each element is the result 
    # of some operations applied to each member of another sequence or 
    # iterable, or to create a subsequence of those elements that satisfy 
    # a certain condition. 
    
    # For example, assume we want to create a list of squares, like:
    squares = []
    for x in range(10):
        squares.append(x**2)

    squares     # [0, 1, 4, 9, 16, 25, 36, 49, 64, 81]

    # We can create a similar list in more consice manner:
    squares = [x**2 for x in range(10)]

    # A list comprehension consists of brackets containing an expression 
    # followed by a for clause, then zero or more for or if clauses. 
    # The result will be a new list resulting from evaluating the expression 
    # in the context of the for and if clauses which follow it.

    # For example, this listcomb combines the elements of two lists if they 
    # are not equal:
    listcomb = [(x, y) for x in [1,2,3] for y in [3,1,4] if x != y]

    listcomb    # [(1, 3), (1, 4), (2, 3), (2, 1), (2, 4), (3, 1), (3, 4)]

    # The above listcomb comprehension is equivalent to: 
    combs = []
    for x in [1,2,3]:
        for y in [3,1,4]:
            if x != y:
                combs.append((x, y))
    combs   # [(1, 3), (1, 4), (2, 3), (2, 1), (2, 4), (3, 1), (3, 4)]
    # Note how the order of the for and if statements is the same in both 
    # these snippets.

    # Here are few examples of list comprehensions:

    vec = [-4, -2, 0, 2, 4]
    [x*2 for x in vec]          # create a new list with the values doubled
    [x for x in vec if x >= 0]  # filter the list to exclude negative numbers
    [abs(x) for x in vec]       # apply a function to all the elements

    vec = [[1,2,3], [4,5,6], [7,8,9]]
    [num for elem in vec for num in elem]   # flatten a list using two 'for'
    # Output: [1, 2, 3, 4, 5, 6, 7, 8, 9]

    from math import pi
    [str(round(pi, i)) for i in range(1, 6)]
    # Output: ['3.1', '3.14', '3.142', '3.1416', '3.14159']

    # List comprehensions become handy while working with matrices. 

    M = [[1, 2, 3],     # A 3 × 3 matrix, as nested lists
        [4, 5, 6],      # Code can span lines if bracketed
        [7, 8, 9]]

    col2 = [row[1] for row in M]
    col2    # [2, 5, 8]
    [row[1] + 1 for row in M]                   #  Add 1 to each item in col 2
    # Output: [3, 6, 9]
    [row[1] for row in M if row[1] % 2 == 0]    # Filter out odd items
    # Output: [2, 8]
    diag = [M[i][i] for i in [0, 1, 2]]         # Collect a diagonal from matrix
    diag        # [1, 5, 9]


# b) Nested List Comprehensions:

    # Consider the following example of a 3x4 matrix:
    matrix = [
        [1, 2, 3, 4],
        [5, 6, 7, 8],
        [9, 10, 11, 12],
    ]

    # The following list comprehension will transpose rows and columns:
    [[row[i] for row in matrix] for i in range(4)]
    # Output: [[1, 5, 9], [2, 6, 10], [3, 7, 11], [4, 8, 12]]

    # As we saw in the previous section, the nested listcomp is evaluated in the 
    # context of the for that follows it, so this example is equivalent to:
    transposed = []
    for i in range(4):
        transposed.append([row[i] for row in matrix])

    # which, in turn, is the same as:
    transposed = []
    for i in range(4):
        transposed_row = []
        for row in matrix:
            transposed_row.append(row[i])
        transposed.append(transposed_row)

    # Similar type of comprehensions are supported with dictionaries, sets and
    # tuples as well. 

# SEQUENCE UNPACKING:

# Sequence assignments normally require exactly as many names in the target on 
# the left as there are items in the subject on the right. We get an error if 
# the lengths disagree. 

seq = [1, 2, 3, 4]
a, b, c, d = seq
print(a, b, c, d)   # Output: 1 2 3 4 

a, b = seq
# Output: ValueError: too many values to unpack

# However, we can use a single starred name in the target to match more
# generally. 

a, *b = seq         # a = 1 and b = [2, 3, 4]
a*, b = seq         # a = [1, 2, 3] and b = 4
a, *b, c = seq      # a = 1, b = [2, 3] and c = 4
a, b, *c = seq      # a = 1, b = 2, c = [3, 4]

# This Sequence unpacking works for any type of sequence, not just lists.
a, *b, c = "spam"   # a = 's', b = ['p', 'a'] and c = 'm'

# Although extended sequence unpacking is flexible, some boundary cases are 
# worth noting. 

# First, the starred name may match just a single item, but is always 
# assigned a list:
a, b, c, *d = seq
print(a, b, c, d)       # Output: 1 2 3 [4]

# Second, if there is nothing left to match the starred name, it is assigned an 
# empty list, regardless of where it appears. In the following, a, b, c, and d 
# have matched every item in the sequence, but Python assigns e an empty list 
# instead of treating this as an error case:

a, b, c, d, *e = seq
print(a, b, c, d, e)    # Output: 1 2 3 4 []

a, b, *e, c, d = seq
print(a, b, c, d, e)    # Output: 1 2 3 4 []

# Finally, errors can still be triggered if there is more than one starred name, 
# if there are too few values.

a, *b, c, *d = seq
# Output: SyntaxError: two starred expressions in assignment

# random MODULE:

    import random
    random.random()                 # Outputs random float point number
    random.randint(1, 10)           # Outputs a random integer in given range
    random.choice([1, 2, 3, 4])     # Selects an element randomly from the list
    random.choice(['Life of Brian', 'Holy Grail', 'Meaning of Life'])
    suits = ['clubs', 'diamonds', 'spades', 'hearts']
    random.shuffle(suits)

# ------------------------------------------------------------------------------
