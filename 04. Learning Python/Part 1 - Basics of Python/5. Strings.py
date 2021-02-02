# 4. STRINGS

# DECLARATION:

    # Both quotation marks are allowed - '' or "".

    # '\' can be used to escape quotes.
    'doesn\'t'
    # If you don’t want characters prefaced by '\' to be interpreted as special 
    # characters, you can use raw strings by adding an r before the first quote:
    print('C:\some\name')   # here \n means newline!
    print(r'C:\some\name')  # note the r before the quote

    # Triple quotes give multi-line strings.
    print("""\
    Usage: thingy [OPTIONS]
        -h                        Display this usage message
        -H hostname               Hostname to connect to
    """)

    # Triple quotes are usually used for declaring 'Docstrings'.  
    # Python documentation strings (or docstrings) provide a convenient way of 
    # associating documentation with Python modules, functions, classes and 
    # methods.

    # What should a docstring look like?
    # - The doc string line should begin with a capital letter and end with a 
    #   period.
    # - The first line should be a short description.
    # - If there are more lines in the documentation string, the second line 
    #   should be blank, visually separating the summary from the rest of the 
    #   description.
    # - The following lines should be one or more paragraphs describing the 
    #   object’s calling conventions, its side effects, etc.

    # The docstrings can be accessed using the __doc__ method of the object or 
    # using the help function.
    def myfunction():
        """This is a docstring and explains what my function does - Nothing!"""
        return None
    
    print(myfunction.__doc__)
    # Output: This is a docstring and explains what my function does - Nothing!
    help(myfunction)
    # Output:  Help on function myfunction in module __main__:
    #          
    #      myfunction()
    #          This is a docstring and explains what my function does - Nothing!

# STRING CONCATENATION AND REPETITION: 

    # Strings can be concatenated with the + operator and repeated with *.
    3 * 'un' + 'ium'    # Output - 'unununium'

    # Two or more string literals (i.e. the ones enclosed between quotes) 
    # next to each other are automatically concatenated.
    'Py' 'thon'
    # This feature is particularly useful when you want to break long strings:
    text = ('Put several strings within parentheses ' 
            'to have them joined together.')
    text
    # Output: 'Put several strings within parentheses to have them joined together.'

    # This only works with two literals though, not with variables or expressions.
    # If you want to concatenate variables or a variable and a literal, use +.
    prefix = 'Py'
    prefix 'thon' # can't concatenate a variable and a string literal
    # Output: SyntaxError: invalid syntax

# SEQUENCE OPERATIONS:

    S = "Spam"
    len(S)
    S[0]    # 'S'
    S[1]    # 'p'
    S[-2]   # 'a'

    S[6]    # IndexError: String Index out of range
    S[-4]   # IndexError: String Index out of range

    # S[a:b] means slice from a upto b, a is inclusive and b is not.
    S[1:3]  # 'pa' 
    S[1:]   # 'pam'
    S[:3]   # 'Spa'
    S[:-1]  # 'Spa'
    S[3:1]  # '' - Order is incorrect. Returns empty string.
    S[:]    # 'Spam'

    # S[a:b:c] means get characters from a to b at intervals of c.
    S = "malayalam" 
    S[0:6:2]        # 'mly'
    S[::-1]         # Easy way to reverse a string
    S == S[::-1]    # Check if S is a palindrome
    # Output: True

# IMMUTABILITY:

    # Strings are immutable in Python, i.e. We cannot change the contents 
    # of the string
    S[3] = 'n'      # Attempt to make S = "Span"
    # Output: TypeError: 'str' object does not support item assignment
    S.replace('m', 'n') # This replaces all occurences of 'm' with 'n' in S
    # Output: 'Span'
    # But this 'Span' is a temporary nameless object. If you print contents of 
    # S, it's still - Spam!
    S
    # Output: 'Spam'
    # So what's the way to change it to 'Span'? By creating a new string object
    # and assigining it to S.
    S = S[:3] + 'n'
    S
    # Output: 'Span'

# TYPE-SPECIFIC METHODS:

    # We saw usage of replace() method over string type. What other functions we 
    # can use on string?
    dir(S)
    # You probably won’t care about the names with underscores in this list 
    # until later in the book, when we study operator overloading in classes — 
    # they represent the implementation of the string object and are available 
    # to support customization. The names without the underscores in this list 
    # are the callable methods on string objects. The dir function simply gives 
    # the methods’ names. To ask what they do, you can pass them to the help():
    help(S.replace)

    S = "Spam"
    S.upper()           # 'SPAM'
    S.isalpha()         # True

    line = "aaa,bbb,ccc,ddd"
    line.split(',')     # Output: ['aaa', 'bbb', 'ccc', 'ddd']
    line = "aa,bb,cc,dd\n"
    line.rstrip()       # Removes whitespace from right end. 
    # Output: 'aa,bb,cc,dd'
    line.rstrip().split(',')    # Combining 2 methods
    # Output: ['aa', 'bb', 'cc', 'dd']

    # Here is the list of common built-in string functions:
    # 1. str.isdecimal() - Returns true if all characters are decimal
    # 2. str.isalnum() - Returns true if all characters are alphanumeric
    # 3. str.isalpha() - Returns true if all characters are alphabets
    # 4. str.max() and str.min() - Returns maximum and minimum alphabetical 
    #    character.
    # 5. str.lower() and str.upper() - Converts the string into respective cases.
    # 6. str.find(substr, start, end) : Default values of start = 0 and 
    #    end = length-1. The find() method returns the lowest index of the 
    #    substring if it is found in given string. If its is not found then 
    #    it returns -1.
    # 7. str.rfind(substr, start, end) 
    #    rfind() method returns the highest index of the substring if found in 
    #    given string. If not found then it returns -1.
    # 8. str.split(seperator, max_limit) and str.rsplit(sep, max_limit):
    #    - separator : The is a delimiter. The string splits at this specified 
    #                  separator. If is not provided then any white space is a 
    #                  separator.
    #    - max_limit : It is a number, which tells us to split the string into 
    #                  maximum of provided number of times. If it is not provided 
    #                  then there is no limit. 
    # 9. str.count(substr, start, end)
    #    Returns the number of (non-overlapping) occurrences of substring in string.
    # 10. str.join(list/tuple) :
    #     The join() method is a string method and returns a string in which 
    #     the elements of sequence have been joined by str separator.
    # 11. str.replace(replace_what, replace_with, max_replacements):

# Additional Note: Strings, Lists, Tuples, Dictionaries and Sets are also 
# called Iterables. We will see more on iterables and iterators later. 
    
# ------------------------------------------------------------------------------
