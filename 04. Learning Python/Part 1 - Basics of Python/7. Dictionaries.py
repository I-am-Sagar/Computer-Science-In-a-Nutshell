# 6. DICTIONARIES

# MAPPING OPERATIONS: 

    # Dictionaries are coded in curly braces and consist of a series of 
    # “key: value” pairs.
    D = {'food': 'Spam', 'quantity': 4, 'color': 'pink'}
    D['food']	# 'Spam'
    D['quantity'] += 1	# Mutable
    D	# {'food': 'Spam', 'color': 'pink', 'quantity': 5}

    # Creates new key-value pairs using assignment
    D = {}
    D['name'] = 'Bob'
    D['job'] = 'dev'
    D['age'] = 40
    D
    # Output: {'age': 40, 'job': 'dev', 'name': 'Bob'}

    # We can also make dictionaries by passing 'name = value' syntax to 'dict()'
    # function or by zipping together two sequences of keys and values obtained 
    # at runtime. 
    bob1 = dict(name='Bob', job='dev', age='40')
    bob1 	# Output: {'age': 40, 'job': 'dev', 'name': 'Bob'}
    bob2 = dict(zip(['name', 'job', 'age'], ['Bob', 'dev', 40]))
    bob2	# Output: {'age': 40, 'job': 'dev', 'name': 'Bob'}
    # Notice how left to right order of dictionary keys is scrambled. Mappings 
    # are not positionally ordered because we dont access dictionary values 
    # by position but by keys. 

# NESTING:

    rec = {
            'name': {'first': 'Bob', 'last': 'Smith'},
            'job': ['dev', 'mgr'],
            'age': 40.5
        }

    # All appropiate operations are valid on values of dictionary. For example,
    rec['job'].append('janitor')
    rec
    # Output: {'age': 40.5, 'job': ['dev', 'mgr', 'janitor'], 
    #          'name': {'last': 'Smith', 'first': 'Bob'}}

    rec['exp']	# Output: KeyError: 'exp'

# SORTING KEYS:

    # We saw that the keys are printed in different order than that in which 
    # they were created. 
    D = {'a':1, 'b':2, 'c':3}
    D       # Output: {'a':1, 'c':3, 'b':2}

    # If we need to impose an ordering on dictionary's items, one common 
    # solution is to grab a list of keys, sort that list and then step through 
    # the dictionary using for loop.
    k = list(D.keys())          # ['a', 'b', 'c']          
    k.sort()
    for key in k:
        print(key, '=', D[key])
    # Output: a = 1
    #         b = 2
    #         c = 3

    # This was a 3-step process. This could be done in 1 step as:
    for key in sorted(D):
        print(key, '=', D[key])

    # In above example, we saw - how to make a list of 'keys' in a dictionary:
    k = list(D.keys())
    # Similarly, we can extract 'values' in a dictionary as:
    v = list(D.values())
    # We can also create a list of tuples of key-value pairs as:
    p = list(D.items())

# ADDING and DELETING items:

    # Using update():

    # It merges the keys and values of one dictionary into another, 
    # blindly overwriting values of the same key:
    D1 = {'spam': 2, 'ham': 1, 'eggs': 3}
    D2 = {'toast':4, 'muffin':5}
    D1.update(D2)
    D1      # {'toast': 4, 'muffin': 5, 'eggs': 3, 'ham': 1, 'spam': 2}

    # Using pop():

    D.pop('muffin')         # 5
    D.pop('toast')          # 4
    D       # {'eggs': 3, 'ham': 1, 'spam': 2}

# COMPREHENSIONS:

    # One nice use of dictionary comprehensions is to invert dictionaries. 
    
    country_to_capital = {
        'UK':'London',
        'Brazil':'Brazilia',
        'Morocco':'Rabat',
        'Sweden':'Stockholm'
    }

    capital_to_country = {
        capital:country for country, capital in country_to_capital.items()
    }

    # It is important to understand how this comprehension is working. 
    # 'country_to_capital.items()' returns a tuple of key-value pairs. 
    # 'country, capital' uses tuple unpacking on each tuple element and gets 
    # the corresponding values.
    # 'capital:country' generates the inverted dictionary.

    # Note: If there are duplicate keys, while handling comprehensions (or 
    # usually anytime) latter keys overwrite the former ones. Also, we shouldn't
    # use comprehensions alot and obfuscate the code. Readability of code is 
    # still the main purpose. Because code is written once, but read again and 
    # again. 
# ------------------------------------------------------------------------------