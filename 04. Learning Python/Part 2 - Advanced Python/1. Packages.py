############################ TOPIC 1 - PACKAGES ###############################

# 1. WHAT ARE PACKAGES?

    # In the Python Basics, we saw about modules. We create a script called -  
    # 'my_module.py' and we imported it in some other python script. On REPL,

    import my_module
    type(my_module)         # Output: <class 'module'>

    # So on a very high level, we can say - if modules are files, then packages
    # are directories/folders. So a package can contain various modules and thus
    # importing a package is equivalent of importing all the modules in it.
    
    # For example, 'urllib' is a ready-made package available in python. And
    # 'request.py' is a module in the directory named - urllib.

    import urllib                   # Importing a package
    import urllib.request           # Importing a module

    # However if you will check their types, both of them are objects of class
    # 'module'. This is because - anything which you import in python, is an
    # object of 'module' class. So packages and modules are no different when
    # it comes to importing them and using them in your script.

    type(urllib)            # Output: <class 'module'>
    type(urllib.request)    # Output: <class 'module'>

    # The difference between a package and a module comes based on the 
    # '__path__' attribute. Eg.

    urllib.__path__         # Returns the path where this directory is located
    # ['C:\\Users\\sagar\\AppData\\Local\\Programs\\Python\\Python37\\lib\\urllib']

    urllib.request.__path__ # Modules do not have a path attribute
    # AttributeError: module 'urllib.request' has no attribute '__path__'

    # Also note that - a folder can contain subfolders as well, which in turn
    # will contain several python scripts. So a main package can contain several
    # subpackages, along with modules. It is possible, but not at all promoted,
    # to have more folders inside the subfolders. Too much of nesting of folders,
    # spoils the package structure. 

    # How to make and implement a package? To answer this question, we first 
    # need to understand - How does python locate and import modules?
    
# ------------------------------------------------------------------------------

# 2. IMPORTING MODULES

    # - Understanding SYS.PATH :

    # 'sys.path' is the list of directories in which python searches for modules.
    # All these paths are stored in the 'path' attribute of the standard 'sys'
    # module. (Since packages and modules are both the objects of class 'module',
    # we won't treat them as different. We will highlight the packages and modules
    # differently, only when we will have to show the difference between them.)

    import sys
    sys.path        # This will output a long list of directories. 

    # So whenever we ask python for particular module, python checks into the 
    # 1st directory at sys.path and checks for the appropiate file. If no match 
    # is found in 1st directory, python checks the next directory. This goes on 
    # until the match is found or python runs out of directories in sys.path - 
    # in which case, an ImportError is raised. 

    # Let's create a simple directory with the name - 'test' and inside that
    # create a script named 'path_test.py'. So the folder structure should look
    # like:

        # test
        # --> path_test.py

    # Add the following contents in your path_test.py:

    def found():
        print('Python found me!')

    # Now come on REPL:

    import path_test
    # ImportError: No module named 'path_test'

    # This is because the path of folder 'test' is not available in sys.path.
    # To make path_test importable, we need to add the path of 'test' in 
    # sys.path. Since sys.path returns a list of directories, all operations 
    # valid on list are valid here as well. 

    import sys
    sys.path.append('test')
    import path_test
    path_test.found()       # Output: Python found me!

    # - Understanding PYTHONPATH :

    # If we close and run the REPL again, the sys.path list will revert back 
    # to normal and path of 'test' folder will be removed automatically. 
    # So whenever we want to import our 'path_test' module, we have to manually
    # append the path of 'test' to sys.path. However if we wish that path of 
    # 'test' should remain in sys.path, we need to add the path to 'PYTHONPATH'.

    # PYTHONPATH - is an environment variable listing paths added to sys.path
    # when python starts. To add the path in PYTHONPATH, use following commands
    # in CMD/Terminal (not on REPL):

    set PYTHONPATH = test       # For Windows
    export PYTHONPATH = test    # For MAC/Ubuntu/Bash shell

    # Now if you start the REPL, you can find that 'test' indeed is in sys.path.

    import sys
    [p for p in sys.path if 'test' in p]    # Outputs the path of 'test'

    # Now we can directly import path_test without manually editing sys.path.

# ------------------------------------------------------------------------------

# 3. IMPLEMENTING A PACKAGE:

    # To create a module, you create a python file and make sure that it's 
    # folder's location is available in sys.path. The process of creating a 
    # package is not much differnt. To create a package, we create a root
    # directory, whose path must be in sys.path. And inside this root directory,
    # we have a directory for our package. In this package directory, there is 
    # a special file '__init__.py' which makes packages importable as modules.

        #  root_folder/         
        #  --> my_package/
        #      --> __init__.py

    # In the following discussion, we assume that you are working inside the 
    # root_folder and the path of the root_folder is available in sys.path.

    # Create a package folder - 'reader' and inside that create a file 
    # '__init__.py'. The code inside this file gets executed when the package
    # is imported. Congrats! You have just made a package! (Though it does
    # nothing.) On REPL,

    import reader
    type(reader)            # Output: <class 'module'>

    # We will create a simple 'reader' script, which can read text from a file.

        # reader/
        # --> __init__.py
        # --> reader.py

    # Contents of reader.py:

    class Reader:
        def __init__(self, filename):
            self.filename = filename
            self.f = open(self.filename, mode='rt', encoding='utf-8')
        
        def close(self):
            self.f.close()
        
        def read(self):
            return self.f.read()

    # On REPL, let's import our reader.py module:

    import reader.reader                          # Imports reader.py module
    r = reader.reader.Reader('reader/reader.py')  # Let's read the reader.py file
    r.read()                                      # Outputs the file contents
    r.close()

    # What we don't like in above implementation is - we have to type 
    # 'reader.reader' to access the class of our module. Instead we wish our 
    # 'Reader' class to be at the top level of reader package. To do so,
    # in __init__.py file, add the following line:

    from reader.reader import Reader

    # Restart the REPL, and check that the Reader class is at the top level
    # reader namespace. 

    import reader
    r = reader.Reader('reader/__init__.py')
    r.read()
    r.close()

# ------------------------------------------------------------------------------

# 4. ABSOLUTE and RELATIVE IMPORTS

    # In the __init__.py file of our reader package, we wrote an import
    # statement: 

    from reader.reader import Reader        # Absoulte Import

    # This is an 'absolute import'. Such import statements use a full path to
    # a module. There is nothing wrong with this type of import statement and 
    # is recommended to use absolute imports, but sometimes writing such long 
    # import statements become tedious. So we can use - 'relative imports' 
    # instead. Such imports use a relative path to modules in the same package.
    # For eg. we could have written following import statement in our __init__.py
    # file as well:

    from .reader import Reader              # Relative Import

    # Consider a hypothetical package shown below:

        # my_package/
        # --> __init__.py
        # --> a.py
        # --> nested/
        #     --> __init__.py
        #     --> b.py
        #     --> c.py
    
    # Now let's say we have following statements in the __init__.py file of 
    # 'nested' folder:

    from ..a import A           # A can be class/function inside a.py
    from .b import B            # B can be class/function inside b.py

    # 2 dots preceding a module means the search is to be performed in parent
    # directory; and 1 dot preceding a module means the search in same directory.

# ------------------------------------------------------------------------------

# 5. EXECUTABLE DIRECTORIES

    # When you import a package on REPL or any python script, the code inside
    # __init__.py gets executed. But on command line, when we use - 

    python3 <package_name>

    # a special file inside that directory - __main__.py gets executed. 
    # For example, consider the following folder structure:

        # reader/                       (notice that this is root folder)
        # --> __main__.py
        # --> reader/                   (and this is package folder)
        #     --> __init__.py
        #     --> reader.py

    # Contents of __main__.py:

    print('Executing __main__.py with name {}'.format(__name__))

    # Now on CMD/Terminal:

    python3 reader
    # Output: Executing __main__.py with name __main__

    # We now say that - 'reader' has become an 'executable directory'.
    # But what is the use of having 'executable directories'?

    # When you make directories executable, we no more look the directories as
    # 'packages'. We now look at them as 'projects'. Usually we intend to have a
    # '__main__.py' file which can act as starting point of execution of our 
    # project. Inside this project folder, we can have many other files. Here 
    # is the 'recommended project structure':

        # project_name/                     (root folder)
        # --> __main__.py
        # --> project_name/
        #     --> __init__.py
        #     --> more_source_files.py
        #     --> subpackage/
        #         --> __init__.py
        #     --> test
        #         --> __init__.py
        #         --> testing_code.py
        # --> setup.py

    # We will be more familiar with such a project structure when we will be
    # creating some python projects. This is recommended structure, as it keeps
    # every file in its appropriate location.

# ------------------------------------------------------------------------------