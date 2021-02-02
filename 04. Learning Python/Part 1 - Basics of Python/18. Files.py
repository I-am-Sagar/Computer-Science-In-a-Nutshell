# ############################ TOPIC 10 - FILE I/O #############################

# 1. BASIC FUNCTIONS

    # To open a file in python, we use inbuilt function - open(). This function
    # takes following arguments:
    # - path: path of the file
    # - mode: read/write/append, binary/text
    # - encoding: text encoding (by default it's 'utf-8' in most of the systems)

    f = open('filepath/filename.txt', mode='wt', encoding='utf-8')
    # In this case, 'w' means write and 't' means text.

    # Here is the list of some open() modes:
    # 'r' - open for reading file (default)
    # 'w' - open for writing in file by overwriting the already existing data
    # 'a' - open for wrtiting in file by appending the data to the end of file
    # 't' - text mode (default)
    # 'b' - binary mode
    # '+' - open a disk file for updating (reading and writing at same time)

    # Let's write some text in the opened file. This is done by using write()
    # function on the file object. write() returns the number of characters
    # written in the file.

    f.write('What are the roots that clutch, ')     # 32
    f.write('what branches grow\n')                 # 19
    f.write('Out of this stony rubbish? ')          # 27
    f.close()                                       # Closing file is important

    # Now let's read what we have written in the file.

    g = open('filepath/filename.txt', mode='rt', encoding='utf-8')

    # In text mode, read method accepts the number of characters to be read.
    g.read(32)  # Output: 'What are the roots that clutch, '

    # If no argument is given to read(), it will read out the remaining 
    # characters till the end of the file.
    g.read()    # Output: 'what branches grow\nOut of this stony rubbish? '

    # Further calls on read would return an empty string.
    g.read()    # Output: ''

    # Usually we close the file after reading it, but here we will read this
    # file again. To do so, we must set the iterator to the beginning of the
    # file. For this, we use seek() method. seek(x) sets the iterator 
    # to the x'th character. 
    g.seek(0)

    # Usually, read() is not a good method to read the file because it reads 
    # the file all at once. There is another method, which reads the file
    # line by line. 

    g.readline()
    # Output: 'What are the roots that clutch, what branches grow\n'
    g.readline()
    # Output: 'Out of this stony rubbish? '

    # When we know that the file is not big enough, and we can store every
    # line in a list, we use readlines() method.
    g.seek(0)
    g.readlines()
    # Output: ['What are the roots that clutch, what branches grow\n', 'Out of 
    #           this stony rubbish? ']
    g.close()

    # Now let's append few lines in our existing file.
    h = open('filepath/filename.txt', mode='at', encoding='utf-8')
    h.writelines(
        ['Son of man, \n',
        'You cannot say, or guess, ',
        'for you know only, \n',
        'A heap of broken images, ',
        'where the sun beats\n']
    )
    h.close()

# ------------------------------------------------------------------------------

# 2. FILES AS ITERATORS

    # Let's write a function in a python script, which does the job of printing
    # each line of the file. Since file objects are iterators as well, we can
    # use them in for loops like any other iterator. Following is the script 
    # named as - files.py

    import sys

    def main(filename):
        f = open(filename, mode='rt', encoding='utf-8')
        for line in f:
            print(line)
        f.close()
    
    if __name__ == '__main__':
        main(sys.argv[1])

    # Now we run this script by using following command:
    python3 files.py filename.txt

    # Output:
    # What are the roots that clutch, what branches grow
    #
    # Out of this stony rubbish? Son of man, 
    # 
    # You cannot say, or guess, for you know only,
    # 
    # A heap of broken images, where the sun beats
    #

    # The lines are separated by newlines because each line of the file 
    # terminates with a newline and print() function prints a newline at the 
    # end of the line by it's own. This issue could be solved by two ways:
    # Either use strip() method to remove the newline character at the end 
    # of the line and let the print add its own newline, or instead of print()
    # use sys.stdout.write() method. 

    def main(filename):
    f = open(filename, mode='rt', encoding='utf-8')
    for line in f:
        sys.stdout.write(line)
    f.close()

# ------------------------------------------------------------------------------

# 3. WITH BLOCK

    # Till now, we followed this pattern - Open a file, work with the file and
    # close the file. close() is important because if you dont close the data,
    # it is possible to lose the data and makes system less secure and reliable.
    # Due to some reasons - it is possible that close() function doesn't get
    # executed. For example, if you are opening too many files, your system may
    # run out of resources and close() for all the files is not executed. 
    # 
    # Since we always want to pair - every open() with a close(), we can either
    # use try...finally block structure or use 'with' blocks.  

    # 1) without using with statement 
    file = open('file_path', 'w') 
    try: 
        file.write('Hello world!') 
    finally: 
        file.close() 
    
    # 2) using with statement 
    with open('file_path', 'w') as file: 
        file.write('Hello world!') 

    # Notice that unlike the first implementation, there is no need to call 
    # file.close() when using with statement. The with statement itself ensures 
    # proper acquisition and release of resources. 

# ------------------------------------------------------------------------------
