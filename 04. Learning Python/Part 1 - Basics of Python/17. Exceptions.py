# ####################### TOPIC 9 - EXCEPTION HANDLING ########################

# 1. SYNTAX ERROR

    # There are (at least) two distinguishable kinds of errors: 
    # syntax errors and exceptions.

    # Syntax errors, also known as parsing errors, are perhaps the most common 
    # kind of complaint you get while you are still learning Python:
    while True print('Hello world')
    # File "<stdin>", line 1
    #     while True print('Hello world')
    #                 ^
    # SyntaxError: invalid syntax

    # The parser repeats the offending line and displays a little 'arrow' 
    # pointing at the earliest point in the line where the error was detected.
    # In the example, the error is detected at the function print(), since a 
    # colon (':') is missing before it. File name and line number are printed 
    # so you know where to look in case the input came from a script.

# ------------------------------------------------------------------------------

# 2. EXCEPTIONS

# try...except block:

    # Even if a statement or expression is syntactically correct, it may cause 
    # an error when an attempt is made to execute it. Errors detected during 
    # execution are called exceptions and are not unconditionally fatal: 
    # you will soon learn how to handle them in Python programs.

    10 * (1/0)
    # Traceback (most recent call last):
    # File "<stdin>", line 1, in <module>
    # ZeroDivisionError: division by zero

    4 + spam*3
    # Traceback (most recent call last):
    # File "<stdin>", line 1, in <module>
    # NameError: name 'spam' is not defined

    '2' + 2
    # Traceback (most recent call last):
    # File "<stdin>", line 1, in <module>
    # TypeError: Can't convert 'int' object to str implicitly

    # It is possible to write programs that handle selected exceptions. 
    # Look at the following example, which asks the user for input until a 
    # valid integer has been entered, but allows the user to interrupt the 
    # program (using Control-C or whatever the operating system supports); 
    # note that a user-generated interruption is signalled by raising the 
    # KeyboardInterrupt exception.

    while True:
        try:
            x = int(input("Please enter a number: "))
            break
        except ValueError:
            print("Oops!  That was no valid number.  Try again...")

    # The try statement works as follows:

    # - First, the try clause (the statement(s) between the try and except 
    #   keywords) is executed.
    
    # - If no exception occurs, the except clause is skipped and execution of 
    #   the try statement is finished.
    
    # - If an exception occurs during execution of the try clause, the rest of 
    #   the clause is skipped. Then if its type matches the exception named 
    #   after the except keyword, the except clause is executed, and then 
    #   execution continues after the try statement.
    
    # - If an exception occurs which does not match the exception named in the 
    #   except clause, it is passed on to outer try statements; if no handler is 
    #   found, it is an unhandled exception and execution stops with a message 
    #   as shown above.
    
    # - A try statement may have more than one except clause, to specify 
    #   handlers for different exceptions. At most one handler will be executed.
   
    # - An except clause may name multiple exceptions as a parenthesized tuple, 
    #   for example:    
    except (RuntimeError, TypeError, NameError):
    
    # - The raise statement allows the programmer to force a specified 
    #   exception to occur. For example:
    raise NameError('HiThere')
    # Traceback (most recent call last):
    # File "<stdin>", line 1, in <module>
    # NameError: HiThere

    # - The last except clause may omit the exception name(s), to serve as a 
    #   wildcard. Use this with extreme caution, since it is easy to mask a 
    #   real programming error in this way!  
    try:
        f = open('myfile.txt')
        s = f.readline()
        i = int(s.strip())
    except OSError as err:
        print("OS error: {0}".format(err))
    except ValueError:
        print("Could not convert data to an integer.")
    except:
        print("Unexpected error:", sys.exc_info()[0])
        raise       
    # Without any argument 'raise' raises the exception, currently being
    # handled. 

# A Sqrt() Example:

    # Following function computes square root using 'Heron's Method'.

    def sqrt(x):
        guess = x
        i = 0
        while guess*guess != x and i < 20:
            guess = (guess + x/guess)/2.0
            i += 1
        return guess

    def main():
        print(sqrt(9))
        print(sqrt(2))
        print(sqrt(-1))
    
    if __name__ == "__main__":
        main()
    
    # Now when we execute the above script, the error which we get is:

    # ZeroDivisionError: float division by zero

    # Now we know that - User of sqrt() function won't generally expect 
    # ZeroDivisionError. Thus, we use exception handing to print errors
    # that users will anticipate. Let's modify the main() as:

    def main():
        print(sqrt(9))
        print(sqrt(2))
        try:
            print(sqrt(-1))
        except ZeroDivisionError:
            print("Cannot compute square root of negative number.")
                    
    # Instead of modifying main() method, we should have incorporated exception
    # handling in sqrt() function itself. Also if we are sure that the sqrt()
    # method will fail for -ve numbers instead of trying sqrt(-ve number), we
    # can simply put an if statement and raise the error.

    def sqrt(x):
        if x < 0:
            raise ValueError("Cannot compute square root of negative number"
                             "{}.".format(x))
        guess = x
        i = 0:
        while guess*guess != x and i < 20:
            guess = (guess + x/guess)/2.0
            i += 1
        return guess

    def main():
        print(sqrt(9))
        print(sqrt(2))
        try:
            print(sqrt(-1))
        except ZeroDivisionError:
            print("Cannot compute square root of negative number.")

    # If we run the code now, we still get the unexpected program 'Traceback' 
    # call, because we forgot to modify our exception handler to catch 
    # 'ValueError' rather than 'ZeroDivisionError'.

    import sys
    
    def sqrt(x):
        if x < 0:
            raise ValueError("Cannot compute square root of negative number"
                             "{}.".format(x))
        guess = x
        i = 0:
        while guess*guess != x and i < 20:
            guess = (guess + x/guess)/2.0
            i += 1
        return guess

    def main():
        try:
            print(sqrt(9))
            print(sqrt(2))
            print((sqrt(-1)))
            print("This statement won't get executed because the control has "
                  "shifted to except block in the previous statement.\n")
        except ValueError as e:
            print(e, file=sys.stderr) 
    
# Error Handling Philosophies: 

    # There are 2 philosophies of handling failures - 
    # a) Look Before You Leap (LBYL)
    # b) Easier to Ask Forgiveness than Permission (EAFP)

    # a) LBYL Approach:

    # Consider the following code for file processing. We are not interested in
    # what is the process() being happening. We can assume, the process() func
    # does required processing for us. 

    import os
    p = '/path/to/datafile.dat'
    if os.path.exists(p):
        # 'Location X' - read following explanation
        process_file(p)
    else:
        print('No such file as {}'.format(p))
    
    # There are several problems with this approach:

    # 1) This only checks condition for file existence. 
    #    What if the file exists, but contains garbage? 
    #    What if the path refers to a directory and not to a file?
    # According to LBYL approach, we should add further tests for handling 
    # these failures too. 

    # 2) A more subtle problem is at Location X. It is possible for file to get
    #    deleted by some other process between the existence check and 
    #    process_file(p) call. This is classic 'atomicity' issue. There is no 
    #    good way here to deal with this.

    # If we started solving these errors, the main logic of code is set behind
    # and we have got involved more in writing conditions. 

    # b) EAFP Approach:

    # This method says - Handle the exceptions not by using conditions, but by
    # exception handling. Python is in favour of this appraoch. This is because
    # Python believes that if a any error can occur, let it occur. This will 
    # safeguard the program from improper usage. 
    
    # "Errors are like bells, and if we make them silent, they are of no use."

    p = '/path/to/datafile.dat'
    try:
        process_file(p)
    except OSError as e:
        print('Could not process file because {}'.format(str(e))

# finally block:

    # finally statement always executes whether the exception has occured or not.
    # This statement is majorly used for resource clean up. For example:

    # Consider the following function which uses various facilities provided by
    # 'os' module and - changes the current working directory, make a directory
    # at new location and come back to current working directory. 

    import os

    def make_at(path, dir_name):
        original_path = os.getcwd()
        os.chdir(path)
        os.mkdir(dir_name)
        os.chdir(original_path)

    # At first sight, the function seems reasonable. But if os.mkdir() function
    # fails for some reason and is unable to make a directory at mentioned path,
    # the current working directory won't be restored to its original value. 
    # And make_at() function may lead to unintended side effects. We fix this
    # by using 'finally' block.

    import os
    def make_at(path, dir_name):
        original_path = os.getcwd()
        try:
            os.chdir(path)
            os.mkdir(dir_name)
        finally:
            os.chdir(original_path)

    # The above function could be made even better by handling OSError as - 

    import os, sys
    def make_at(path, dir_name):
        original_path = os.getcwd()
        try:
            os.chdir(path)
            os.mkdir(dir_name)
        except OSError as e:
            print(e, file = sys.stderr)
        finally:
            os.chdir(original_path)

# ------------------------------------------------------------------------------
