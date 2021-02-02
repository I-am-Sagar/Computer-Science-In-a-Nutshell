# ###################### TOPIC 1 - INTRODUCTION TO PYTHON ######################

# 1. FEATURES OF PYTHON

# - Scripting Language

# Python is a general-purpose programming language that is often applied in 
# scripting roles. The theoretical difference between the scripting languages 
# and compiled languages is that they do not require the compilation step and 
# are rather interpreted. Generally, compiled programs run faster than 
# interpreted programs because they are first converted to native machine code.
# Also, compilers read and analyze the code only once, and report the errors 
# collectively that the code might have, but the interpreter will read and 
# analyze the code statements each time it meets them and halts at that very 
# instance if there is some error.

# - Developer's Productivity

# Python has shined as a tool that allows programmers to get more done with 
# less effort. It is deliberately optimized for speed of development — its
# simple syntax, dynamic typing, lack of compile steps and built-in toolset 
# allow programmers to develop programs in a fraction of the time needed when 
# using some other tools. The net effect is that Python typically boosts 
# developer productivity many times beyond the levels supported by traditional 
# languages.

# - Program Portability

# Most Python programs run unchanged on all major computer platforms. Porting
# Python code between Linux and Windows, for example, is usually just a matter 
# of copying a script's code between machines. Moreover, Python offers multiple 
# options for coding portable graphical user interfaces, database access 
# programs, web-based systems and more. Even operating system interfaces, 
# including program launches and directory processing, are as portable in Python
# as they can possibly be.

# - Support Libraries

# Python comes with a large collection of prebuilt and portable functionality, 
# known as the standard library. This library supports a variety of 
# application-level programming tasks, from text pattern matching to network 
# scripting. In addition, Python can be extended with both homegrown libraries 
# and a vast collection of third-party application support software. Python's 
# third-party domain offers tools for website construction, numeric programming, 
# serial port access, game development and much more. The NumPy extension, 
# for instance, has been described as a free and more powerful equivalent to 
# the MATLAB numeric programming system.

# - Easy Integration with other Languages

# Python scripts can easily communicate with other parts of an application, 
# using a variety of integration mechanisms. Such integrations allow Python to 
# be used as a product customization and extension tool. Today, Python code can 
# invoke C and C++ libraries, can be called from C and C++ programs, can 
# integrate with Java and .NET components and much more. 

# ------------------------------------------------------------------------------

# 2. WHAT CAN BE DONE WITH PYTHON?

# Almost everything, but major things are:

# - GUIs

# Python comes with a standard object-oriented interface to the Tk GUI API 
# called tkinter that allows Python programs to implement portable GUIs with a 
# native look and feel. Python/tkinter GUIs run unchanged on Microsoft Windows, 
# Linux and the Mac OS (both Classic and OS X). High-level GUIs can be made 
# with even more sophisticated tools such as PyQt, PyGTK and PyWin32. 

# - Internet Scripting

# Python comes with standard Internet modules that allow Python programs to 
# perform a wide variety of networking tasks, in client and server modes. 
# Scripts can communicate over sockets; 
# extract form information sent to server-side CGI scripts; 
# transfer files by FTP; 
# parse, generate, and analyze XML files; 
# send, receive, compose, and parse email;
# fetch web pages by URLs; 
# parse the HTML and XML of fetched web pages; 
# communicate over XML-RPC, SOAP, and Telnet; and more.
# In addition, full-blown web development framework packages for Python, such as
# Django, TurboGears, Flask, etc. support quick construction of full-featured 
# and production-quality websites with Python.

# - Database Programming

# For traditional database demands, there are Python interfaces to all commonly 
# used relational database systems—Sybase, Oracle, Informix, ODBC, MySQL, 
# PostgreSQL, SQLite and more. The Python world has also defined a portable 
# database API for accessing SQL database systems from Python scripts, which 
# looks the same on a variety of underlying database systems. 
# 
# Python's standard 'pickle' module provides a simple object persistence system.
# It allows programs to easily save and restore entire Python objects to files 
# and file-like objects. On the Web, you'll also find a third-party open source 
# system named ZODB that provides a complete object-oriented database system 
# for Python scripts, and others (such as SQLObject and SQLAlchemy) that map 
# relational tables onto Python's class model.

# - ML, AI, Data Science, Numerics, Scientific Computing, etc.

# The NumPy numeric programming extension for Python mentioned earlier includes
# such advanced tools as an array object, interfaces to standard mathematical 
# libraries and much more. By integrating Python with numeric routines coded 
# in a compiled language for speed, NumPy turns Python into a sophisticated 
# yet easy-to-use numeric programming tool that can often replace existing code 
# written in traditional compiled languages such as FORTRAN or C++.

# - Game Development

# Game programming and multimedia in Python can be done with the pygame system.

# - Robotics

# Serial port communication on Windows, Linux, and more with the 'PySerial'
# extension and Robot control programming with the 'PyRo' toolkit are few 
# examples of commonly used libraries in Robotics. 

# ------------------------------------------------------------------------------

# 3. INTERACTIVE PROMPT

# Introducing Interactive Prompt/ REPL:

# The most platform neutral way to start an interactive interpreter session is 
# usually just to type 'python' at your operating system's prompt, without any 
# arguments.

# The interactive prompt runs code and echoes results as you go, but it doesn't 
# save your code in a file. Although this means you won't do the bulk of your 
# coding in interactive sessions, the interactive prompt turns out to be a great 
# place to both experiment with the language and test program files on the fly.

# Although the interactive prompt is simple to use, there are a few tips that 
# beginners should keep in mind:

# - Type Python commands only. 
    # First of all, remember that you can only type Python code at the Python 
    # prompt, not system commands. There are ways to run system commands from 
    # within Python code (e.g., with os.system), but they are not as direct as 
    # simply typing the commands themselves.

# - print statements are required only in files. 
    # Because the interactive interpreter automatically prints the results of 
    # expressions, you do not need to type complete print statements 
    # interactively. This is a nice feature, but it tends to confuse users when 
    # they move on to writing code in files: within a code file, you must use 
    # print statements to see your output because expression results are not 
    # automatically echoed. Remember, you must say print in files, but not 
    # interactively.

# - Watch out for prompt changes for compound statements. 
    # You should know that when typing lines 2 and beyond of a compound 
    # statement interactively, the prompt may change. In the simple shell window 
    # interface, the interactive prompt changes to ... instead of >>> for lines 
    # 2 and beyond; in the IDLE interface, lines after the first are 
    # automatically indented.

# - Terminate compound statements at the interactive prompt with a blank line. 
    # By contrast, blank lines are not required in files and are simply ignored 
    # if present. If you don't press Enter twice at the end of a compound 
    # statement when working interactively, you'll appear to be stuck in a limbo 
    # state, because the interactive interpreter will do nothing at all — it's 
    # waiting for you to press 'Enter' again!


# REPL AS CALCULATOR:

    2+2
    50-5*6
    (50-5*6)/4
    8/5 		# Division always returns floating point numbers
    17/3
    17//3 		# Floor division discards the fractional part
    17%3 
    2**7
    4*3.75-2 	# Mixed type operations are supported

# FOR EXECUTING PYTHON STATEMENTS:

    print("Hello World")

    # Print statement automatically puts a new line character in the end.
    print ('Hello')
    print ('World')
    # However if we want both to print on same line, we put one additional 
    # argument:
    print('Hello', end=' ')
    print('World')
    
    # The separator between the arguments to print() function in Python is 
    # space by default which can be modified and can be made to any character, 
    # integer or string as per our choice.
    print('09','12','2016', sep='-') 

# ------------------------------------------------------------------------------