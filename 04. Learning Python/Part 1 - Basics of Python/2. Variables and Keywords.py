# ######################### TOPIC 2 - BASIC DATA TYPES #########################

# 1. VARIABLES and KEYWORDS: 

    # When we create a data item, we can either assign it to a variable or 
    # insert it into a collection. The name of the variable should start with 
    # any character from Unicode set except the digits (0-9), operators 
    # (+, -, *, /, etc) and period '.'. Digits can occur in between. 
    width = 20
    height = 5*9 
    width*height 

    # No identifier (i.e. variable name) should be same as Python's Keywords.
    # There are 33 Keywords in Python. They are: 
    # - and 	continue except 	global 	lambda 		pass 	while
    # - as 		def 	 False 		if		None 		raise 	with
    # - assert 	del 	 finally 	import 	nonlocal 	return 	yield
    # - break 	elif 	 for 		in		not 		True
    # - class 	else 	 from 		is		or 			try
    # You can print all the 33 keywords and check if a string is a keyword or 
    # not by using 'keyword' module.
    import keyword
    print(keyword.kwlist)               # Output: Returns a list of keywords
    print(keyword.iskeyword('elif'))    # Output: True

    # Apart from these 33 Keywords, one should also take this precaution: 
    # Don't use the names of any of Python's predefined identifiers for 
    # your own identifiers. For eg. 'int', 'float', 'Ellipsis', etc. 
    # To list all the python's built-in identifiers, type the following in REPL:
    dir(__builtins__)
    # There are about 130 names in the list. Those that begin with a capital 
    # letter are the names of Python's built-in exceptions; the rest are 
    # function and data type names.

    # In interactive mode, the last printed expression is assigned to the 
    # variable '_'.
    tax = 12.5 / 100
    price = 100.50
    price * tax
    price + _

# ------------------------------------------------------------------------------