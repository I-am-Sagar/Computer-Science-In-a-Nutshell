# 7. TUPLES

# INTRODUCTION:
    
    # The tuple object is roughly like a list that cannot be changed.

    T = (1, 2, 3, 4)
    len(T)          # Output: 4
    T + (5, 6)      # Output: (1, 2, 3, 4, 5, 6)
    T               # Output: (1, 2, 3, 4).  Because tuples are immutable.

    T[0]            # 1
    T.index(4)      # 3. Meaning: Element '4' is at what index?
    T.count(4)      # 1. Meaning: How many times does 4 appear?

    # Like Lists and Dictionaries, Tuples also support mixed types and nesting.
    # They cant be grown or shrunk as they are immutable. 
    T.append(5)
    # Output: AttributeError: 'tuple' object has no attribute 'append'

    # Tuples can be formed from lists using tuple() method:
    T = tuple([1, 2, 3, 4])
    T   # (1, 2, 3, 4)

    # Some of the functions which can be used on tuples:
    # - len()
    # - max() and min()
    # - sum()
    # - sorted()

# SOME FACTS ABOUT TUPLES:

    # a) Tuples can't contain a single element. 

    h = (391)
    h               # Output: 391
    type(h)         # Output: <class 'int'>

    # Here, the parentheses are considered as the precedence order operator. 
    # Thus, 391 evaluates to an integer. 

    # If we attempted to make tuple using tuple() function, we get TypeError. 
    t = tuple((132))    # Or you can also try: t = tuple(132)
    # TypeError: 'int' object is not iterable

    # However there is a trick with which you can create a single element tuple,
    # i.e. by including a trailing comma. 
    t = (391,)
    t           # Output: (391,)
    type(t)     # Output: <class 'tuple'>

    # b) Parentheses can be omitted while defining tuples

    p = 1, 1, 1, 4, 9
    p           # Output: (1, 1, 1, 4, 9)

    # This feature is often useful when returning multiple values from the
    # function. Following is an example function which does nothing by itself 
    # and is made just to demonstrate how to return multiple values from func.

    def minmax(items):
        return min(items), max(items)

    minmax([83, 33, 84, 32, 85, 31, 86])
    # Output: (31, 86)

    # We can also collect the multiple return values because of tuple unpacking:
    lower, upper = minmax([83, 33, 84, 32, 31, 86]) 
    lower       # Output: 31
    upper       # Output: 86

    # This tuple unpacking leads to Python's famous 1 line swap statement:
    x, y = y, x

# WHY TUPLES?:

    # If we provide collection of objects to any program or method, there is a
    # possibility that it might get changed. But passing a tuple won't let that 
    # happen. It is like passing 'const array' or 'const string' in C/C++ rather
    # than just array or string. In short, tuples provide a sort of integrity 
    # constraint that is conveninent in programs larger than we usually write. 

# ------------------------------------------------------------------------------

# 8. SETS

# INTRODUCTION:

    # An unordered collection of unique and immutable objects that supports 
    # operations corresponding to mathematical set theory. Sets are iterable, 
    # can grow and shrink on demand, and may contain a variety of object types.
    x = set('spammer')
    x                       # Output: {'m', 's', 'r', 'a', 'p', 'e'}
    y = {'h', 'a', 'm'}     # Creating a set with literals. 

    x & y                   # Intersection 
    # Output: {'m', 'a'}
    x | y                   # Union
    # Output: {'m', 's', 'h', 'r', 'a', 'p', 'e'}
    x - y                   # Set Difference
    # Output: {'s', 'e', 'p', 'r'}
    x ^ y                   # Symmetric Difference
    # Output: {'s', 'h', 'r', 'p', 'e'}
    x > y                   # Is X superset of Y?
    # Output: False
    x < y                   # Is X subset of Y?
    # Output: False

# SET FUNCTIONS:

# a) Adding elements to a set

    # Using add():

    # Only one element at a time can be added to the set by using add() method, 
    # loops are used to add multiple elements at a time with the use of add() 
    # method.

    # Note: Lists cannot be added into sets, whereas tuples can be added.
    # Reason (advanced): Because lists are mutable, hence not hashable; 
    #                    whereas tuples are immutable, and hence hashable.
    s = set()           # s = {} doesn't work as this will create 's' as empty dictionary.
    s.add(8)
    s.add(9)
    s.add((5, 6))
    s   # {8, 9, (5, 6)}

    # Using update():

    # For addition of two or more elements update() method is used. 
    # The update() method accepts lists, strings, tuples as well as other sets 
    # as its arguments. In all of these cases, duplicate elements are avoided.
    set1 = set([ 4, 5, (6, 7)]) 
    set1.update([10, 11]) 
    set1    # {10, 11, 4, 5, (6, 7)}

# b) Accessing a set

    # Set items cannot be accessed by referring to an index, since sets are 
    # unordered the items has no index. But you can loop through the set items 
    # using a for loop, or ask if a specified value is present in a set, by 
    # using the 'in' keyword.
    for i in set1: 
        print(i, end=" ")       # Output: 4 5 (6, 7) 10 11

    print(11 in set1)      # Output: True

# c) Removing elements from set

    # Using remove() or discard():
    
    # Elements can be removed from the Set by using built-in remove() function 
    # but a KeyError arises if element doesn’t exist in the set. 
    # To remove elements from a set without KeyError, use discard(), if the 
    # element doesn’t exist in the set, it remains unchanged.
    set1 = set([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12])
    set1.remove(5) 
    set1.remove(6) 
    set1.discard(8)
    set1.discard(9)
    set1        # {1, 2, 3, 4, 7, 10, 11, 12}

    # Using pop():

    # For an unodered set, there’s no such way to determine which element is 
    # popped by using the pop() function. 
    set1.pop()  # 1
    set1        # {2, 3, 4, 7, 10, 11, 12}
    
    # Note (advanced): Internally, set uses BSTs. So pop() removes the elements
    # in order from leaf node to root. Hence pop removes minimum element in this
    # case. However, pop() will remove minimum element in a set - should not be 
    # generalized.

    # Using clear():
    # Used to clear entire set and convert it into a null set.

# USAGE:
    
    # Sets are useful for tasks such as - filtering out duplicates, 
    # order-neutrality, equality tests without sorting, etc. 
    list(set([1, 2, 1, 3, 1, 2]))       # Filtering out duplicates
    # Output: [1, 2, 3]
    set('spam') == set('maps')          # Order-neutrality Equality Test
    # Output: True

# ------------------------------------------------------------------------------

# 9. NONE

    # This is a special constant used to denote a null value or a void. 
    # Note: 0 or any empty container (e.g empty list) do not compute to None.
    0 == None       # Output: False
    [] == None      # Output: False
    
    # It is an object of its own datatype – NoneType.
    a = None
    a == None       # Output: True

# ------------------------------------------------------------------------------