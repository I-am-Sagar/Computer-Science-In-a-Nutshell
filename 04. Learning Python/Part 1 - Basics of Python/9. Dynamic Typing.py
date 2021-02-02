# ######################### TOPIC 3 - DYNAMIC TYPING ###########################

# 1. MISSING DECLARATIONS:

    # When we type a = 3 in an interactive session or program file, 
    # for instance, how does Python know that 'a' should stand for 
    # an integer? For that matter, how does Python know what 'a' is at all?

    # Once you start asking such questions, you’ve crossed over into 
    # the domain of Python’s dynamic typing model. In Python, types are 
    # determined automatically at runtime, not in response to declarations 
    # in your code. This means that you never declare variables ahead of time.

    # When we say, a = 3, Python will perform three distinct steps to carry out 
    # the request.
    # 1. Create an object to represent the value 3.
    # 2. Create the variable a, if it does not yet exist.
    # 3. Link the variable a to the new object 3.

    # These links from variables to objects are called references in Python — 
    # that is, a reference is a kind of association, implemented as a pointer 
    # in memory. Readers with a background in C may find Python references 
    # similar to C pointers (memory addresses). In fact, references are 
    # implemented as pointers, and they often serve the same roles, especially 
    # with objects that can be changed in-place (more on this later). However, 
    # because references are always automatically dereferenced when used, you 
    # can never actually do anything useful with a reference itself; this is a 
    # feature that eliminates a vast category of C bugs. You can think of Python 
    # references as C 'void*' pointers, which are automatically followed 
    # whenever used.

    a = 3               # a is an int
    a = "sagar"         # a is a string now
    a = 3.142           # a is a float now

    # The above series of statements are possible because -  data type lives 
    # with objects and not with references. Variable names have no type - they 
    # can be referenced to any object type. Objects, on the other hand, know 
    # what type they are — each object contains a header field that tags the 
    # object with its type. The integer object 3, for example, will contain the 
    # value 3, plus a designator that tells Python that the object is an integer. 

    # This leads to another question - when we reassign a variable, what happens
    # to the value it was previously referencing? For example, after the 
    # following statements, what happens to the object 3?

    a = 3
    a = "Spam"

    # The answer is that in Python, whenever a name is assigned to a new object,
    # the space held by the prior object is reclaimed. This automatic 
    # reclamation of objects' space is known as garbage collection. 

    # Internally, Python accomplishes this feat by keeping a counter in every 
    # object that keeps track of the number of references currently pointing to
    # that object. As soon as (and exactly when) this counter drops to zero, 
    # the object’s memory space is automatically reclaimed. In the preceding 
    # listing, we’re assuming that each time 'a' is assigned to a new object, 
    # the prior object’s reference counter drops to zero, causing it to be 
    # reclaimed.

    # The most immediately tangible benefit of garbage collection is that it 
    # means you can use objects liberally without ever needing to free up space 
    # in your script. Python will clean up unused space for you as your program 
    # runs. In practice, this eliminates a substantial amount of bookkeeping 
    # code required in lower-level languages such as C and C++.

# ------------------------------------------------------------------------------

# 2. SHARED REFERENCES:

    a = 3
    b = a
    a = 4

    # In first step, integer object '3' is created and a is reference of 
    # that object. In next step, another reference b is linked with the same 
    # object '3'. So in memory there is still only one object with value 3 and 
    # 'a' and 'b' are shared references. In last step, new object '4' is created
    # and a refer to this object. So b still refers to object '3'. 

    # This is the normal behaviour of variables in most programming languages. 
    # And as long as we are dealing with 'immutable' data types, we need not 
    # worry about shared references and we may consider references as normal 
    # variables. However, there are objects and operations that perform in-place 
    # object changes. For instance, an assignment to an offset in a list 
    # actually changes the list object itself in-place, rather than generating 
    # a brand new list object. For objects that support such in-place changes, 
    # you need to be more aware of shared references, since a change from one 
    # name may impact others.

    L1 = [2, 3, 4]      # A mutable object
    L2 = L1             # Making a new reference to same object
    L1[0] = 1           # Changing L1 in-place

    L1                  # [1, 3, 4] - L1 has changed.
    L2                  # [1, 3, 4] - L2 has also changed!

    # If we don't want such behaviour, we must create a copy of the object 
    # instead of creating references. 

    L1 = [2, 3, 4]      
    L2 = L1[:]          # Making a copy of L1
    L1[0] = 1           

    L1                  # [1, 3, 4] - L1 has changed.
    L2                  # [2, 3, 4] - L2 remains unchanged.

    # We can check if two references refer to same memory location or not using
    # 'is' and 'is not' operators. 

    a = 'Spam'  
    b = a
    a == b      # True i.e. contents of objects are same whom a and b are referring to.
    a is b      # True i.e. They refer to same memory

    a = [1, 2]
    b = a
    a == b      # True i.e. contents of objects are same whom a and b are referring to.
    a is b      # True i.e. They refer to same memory.

    # Note one more difference in 'mutable' and 'immutable' objects, 
    # in following example.

    a = 'Spam'
    b = 'Spam'
    a == b      # True
    a is b      # True

    a = [1, 2]
    b = [1, 2]
    a == b      # True
    a is b      # False

# ------------------------------------------------------------------------------

# 3. COPIES ARE SHALLOW

# We first create a nested list for our demonstration.
a = [[1, 2], [3, 4]]

# We create a copy and assign it to b.
b = a[:]

# We can confirm 'a' and 'b' are distinct objects as:
a is b              # Output: False
a == b              # Output: True

# Now replace a[0] by new list.
a[0] = [8, 9]
a               # Output: [[8, 9], [3, 4]]
b               # Output: [[1, 2], [3, 4]]

# Till now you must be convinced that a and b are distinct objects and 
# everything just works fine. But this is what happens when you do this:
a[1].append(5)
a               # Output: [[8, 9], [3, 4, 5]]
b               # Output: [[1, 2], [3, 4, 5]]

# Even b[1] is also changed. The reason is, b = a[:] creates the copy of 
# the top-most reference list. What I mean by this is - Imagine a nested list
# as, the list of references where each reference points to the corresponding 
# element. So even though 'a' and 'b' are distinct lists of referenecs, those
# references lead you to the same list elements. You can confirm this as:

a[0] is b[0]    # Output: False
# This is because we have created a new list [8, 9] and a[0] now stores the
# reference of this newly created list. Whereas, 
a[1] is b[1]    # Output: True 

# Solution (advanced): If you don't want this issue, use deepcopy() method
# available in 'copy' module. 

# ------------------------------------------------------------------------------

# 4. REPETITIONS ARE SHALLOW

# Repetition repeats the reference without copying the value. 

s = [[-1, +1]]*4
s       # Output: [[-1, 1], [-1, 1], [-1, 1], [-1, 1]]

# Let's say we do append() on third element.
s[2].append(0)
s       # Output: [[-1, 1, 0], [-1, 1, 0], [-1, 1, 0], [-1, 1, 0]]

# All of the sublists are altered. This might seem little annoying at first, 
# but the python implementation was designed in this way (i.e. by working with
# references) to optimize it's execution to the best possible level. 

# Solution: Don't use repetition. Use for loop and run it 4 times appending 
# [-1, 1] each time in the list. 

# ------------------------------------------------------------------------------