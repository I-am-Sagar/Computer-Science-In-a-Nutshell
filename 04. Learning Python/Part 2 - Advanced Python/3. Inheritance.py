############################ TOPIC 3 - INHERITANCE #############################

# 1. SINGLE INHERITANCE:

    # The following discussion assumes that you know a little bit about 
    # Inheritance, from your experience in C++ or Java. 

    # The syntax of single inheritance is:

    class SubClass (BaseClass):
        # methods and attributes of the class

    # The SubClass will have all the methods and attributes of the BaseClass
    # and can override them if re-defined in the BaseClass. A simple example
    # of single inheritance is given below:
    
    # Create a file - 'base.py' and add the following content:

    class Base:
        def __init__(self):
            print('Base class initializer')
        
        def f(self):
            print('Base.f()')

    class Sub(Base):
        pass

    # On REPL, 

    from base import *
    b = Base()              # Output: Base class initializer
    b.f()                   # Output: Base.f()
    s = Sub()               # Output: Base class initializer
    s.f()                   # Output: Base.f()

    # Now let's override the __init__() and f() function in sub class.

    class Sub(Base):
        def __init__(self):
            print('Sub class initializer')

        def f(self):
            print('Sub.f()')

    # On REPL, 

    from base import *
    s = Sub()               # Output: Sub class initializer
    s.f()                   # Output: Sub.f()

    # One important thing to notice is that, when creating the object of the 
    # derived subclass, the initializer of base class is not executed. Other 
    # programming languages like C++ or Java, also call initializer of base
    # class automatically when creating the object of sub class. So base class
    # __init__() is not called if overridden. If you want to call base class 
    # __init__(), use super() to do so.

    class Sub(Base):
        def __init__(self):
            super().__init__()
            print('Sub class initializer')

        def f(self):
            print('Sub.f()')
    
    # On REPL, 

    from base import *
    s = Sub()               
    # Output: Base class initializer
    #         Sub class initializer

# ------------------------------------------------------------------------------

# 2. EXAMPLE - WORKING WITH LISTS

    # Create a file - 'sorted_list.py' and add the following contents:

    class SimpleList:
        def __init__(self, items):
            self._items = list(items)

        def add(self, item):
            self._items.append(item)

        def __getitem__(self, index):
            return self._items[index]

        def sort(self):
            self._items.sort()

        def __len__(self):
            return len(self._items)

        def __repr__(self):
            return "SimpleList({!r})".format(self._items)

    # We now create another list - SortedList, which keeps the items of list 
    # sorted.

    class SortedList(SimpleList):
        def __init__(self, items=()):
            super().__init__(items)
            self.sort()

        def add(self, items):
            super().add(item)
            self.sort()

        def __repr__(self):
            return "SortedList({!r})".format(list(self))

    # On REPL, test SortedList.

    from sorted_list import SortedList
    sl = SortedList([4, 3, 78, 11])
    sl                                  # SortedList([3, 4, 11, 78])
    len(sl)                             # 4
    sl.add(-42)                         # SortedList([-42, 3, 4, 11, 78])

# ------------------------------------------------------------------------------

# 3. isinstance() and issubclass() methods:

    # Along with the SortedList class we defined earlier, we want to define
    # another class IntList, which only allows integer contents. This list
    # subclass will prevent the insertion of non-integer elements. To do this,
    # we need to check type of the items that are inserted. And the tool which
    # we will use for this is - isinstance() method. 

    # isinstance() determines if an object is of a specified type. Use this 
    # function for runtime type checking. It takes first argument as object, 
    # and its type as second. It returns either true or false. isinstance() also
    # returns true if an object belongs to subclass and is checked for type of 
    # the base class. For example, on REPL,

    isinstance(3, int)                  # True
    isinstance("sagar", str)            # True
    isinstance(4.567, bytes)            # False
    isinstance(sl, SortedList)          # True
    isinstance(sl, SimpleList)          # True

    # You can also pass a tuple of types and isinstance() returns true if the 
    # type of an object matches with any of the type mentioned in the tuple.
    x = [3, 4]
    isinstance(x, (float, list, dict))  # True

    # Now add the implentation of IntList in your sorted_list.py

    class IntList(SimpleList):
        def __init__(self, items=()):
            for x in items:self._validate(x)
            super().__init__(items)
        
        @staticmethod
        def _validate(x):
            if not isinstance(x, int):
                raise TypeError('IntList only supports integer values.')

        def add(self, item):
            self._validate(item)
            super.add(item)

        def __repr__(self):
            return "IntList({!r})".format(list(self))

    # Let's test this on REPL.

    from sorted_list import IntList
    il = IntList([1, 2, 9, 4])
    il.add(19)
    il                          # Output: IntList([1, 2, 9, 4, 19])
    il.add('5')
    # TypeError: IntList only supports integer values.

    
    # Another function which does type-checking is - issubclass(). This function
    # determines if one type is a subclass of another. It takes two arguments, 
    # and both of them need to be type arguments. It returns true if a type
    # is direct or indirect subclass of another. For example, 

    from sorted_list import *
    issubclass(IntList, SimpleList)             # True
    issubclass(SortedList, SimpleList)          # True
    issubclass(IntList, SortedList)             # False

# ------------------------------------------------------------------------------

# 4. MULTIPLE INHERITANCE:

    # Multiple inheritance means defining a class with more than one base class.
    # This feature is not universal in OOP Languages. For example, C++ supports
    # multiple inheritance while Java does not. Multiple Inheritance can lead
    # to certain complex situations. For eg. deciding what to do when more than
    # one base class defines a particular method. But Python has a simple and 
    # understandable system for handling such cases in multiple inheritance.

    # The syntax for defining multiple inheritance is:

    class SubClass(Base1, Base2, ...):
        # methods and attributes of subclass

    # Subclasses inherit methods of all bases. If there are no name conflicts, 
    # names resolve in obvious way. But if there are any name conflicts, MRO
    # (Multiple Resolution Order) is used to lookup for names. We will look into
    # MRO shortly. 
    
    # Let's define SortedIntList class.

    class SortedIntList(IntList, SortedList):
        def __repr__(self):
            return 'SortedIntList({!r})'.format(list(self))

    # Here we have just overridden __repr__ method, and on REPL, we can check
    # that the class works as expected.

    from sorted_list import SortedIntList
    sil = SortedIntList([42, 23, 2])
    sil                         # Output: SortedIntList([2, 23, 42])
    SortedIntList([3, 2, '1'])
    # TypeError: IntList only supports integer values.
    sil.add(-123)
    sil                         # Output: SortedIntList([-123, 2, 23, 42])
    sil.add("Smallest Number")
    # TypeError: IntList only supports integer values.

    # It may not be apparent as of now, how all of this works together. 
    # We yet don't know - How does Python know which 'add' to call? 
    # Or more importantly, How does Python maintain both constraints?

    # Before answering these questions, there are few more details related to
    # multiple inheritance which we need to cover. 

    # Point 1: __bases__ attribute
    # This attribute returns a tuple of types of base classes.

    SortedIntList.__bases__
    # Output: (<class 'sorted_list.IntList'>, <class 'sorted_list.SortedList'>)
    IntList.__bases__
    # Output: (<class 'sorted_list.SimpleList'>, )

    # Point 2: Initializer of Base Class
    # If a class has multiple base classes and defines no initializer of its 
    # own, then only the initializer of the first base class is automatically
    # called. For example:

    class Base1:
        def __init__(self):
            print('Base1.__init__')

    class Base2:
        def __init__(self):
            print('Base2.__init__')
    
    class Sub(Base1, Base2):
        pass

    s = Sub()               # Output: Base1.__init__

# ------------------------------------------------------------------------------

# 5. METHOD RESOLUTION ORDER (MRO)

    # MRO is the order that determines the method name lookup. 

    # First lets look where MRO of a class is stored. To get MRO of a class, 
    # we use an attribute __mro__.

    from sorted_list import SortedIntList
    SortedIntList.__mro__
    # Output: (<class 'sorted_list.SortedIntList'>, <class 'sorted_list.IntList'>, 
    # <class 'sorted_list.SortedList'>, <class 'sorted_list.SimpleList'>, 
    # <class 'object'>)

    # We can also call mro as a function to get the output in a list, than a tuple.
    SortedIntList.mro()
    # Output: [<class 'sorted_list.SortedIntList'>, <class 'sorted_list.IntList'>, 
    # <class 'sorted_list.SortedList'>, <class 'sorted_list.SimpleList'>, 
    # <class 'object'>]

    # When an object calls a function, python looks at the MRO of that class
    # and then starting from the first entry, python starts searching for that
    # function. If any class has the requested method, it uses that method and 
    # the search stops. 

    # The question is - If you look at the MRO of the SortedIntList, IntList
    # comes before SortedList and thus when we call for add() function with 
    # proper integer value, add() of SortedList was called and not of IntList. 
    # In this way, SortedIntList maintained both the constraints. So how is
    # IntList.add() deferring to SortedList.add() ?

    # The answer to this mystery contains in the way, how super() actually works.

# ------------------------------------------------------------------------------

# 6. super() [Advanced Topic*]

    # So far we have been using super() to actually invoke the functions in the
    # base class. Recall, in SortedList class, we called super().add() in add()
    # function, to call the SimpleList's add() method. 

    def add(self, item):
        super().add(item)
        self.sort()

    # From this example, you might conclude, super() somehow returns base-class
    # of the method's class and you can than invoke the method in the base-class.
    # But this is only partly true. It's hard to sum up what super() does in a 
    # single sentence, but here is an attempt:

    # "Given a method resolution order and a class C, super() gives you an 
    # object which resolves methods using only the part of the MRO which comes
    # after C."

    # Don't worry, if this statement doesn't make any sense to you right now. 
    # We will understand this statement bit by bit. And the moment we understood
    # this statement - we are done understanding the mysteries of Multiple 
    # Inheritance in Python.

    # super can be called in two ways: 
    # a) super(base-class, derived-class)
    # b) super(class, instance-of-class)

    # By now, you must have concluded that super returns some temporary object
    # of the base class, on which we can call methods of the base class. We call
    # this temporary return object as 'proxy'.

    # These proxies can bound to - classes or instances. If a proxy is bound to
    # a class, it can only call 'staticmethods' and 'classmethods' i.e. methods 
    # which are bound to classes. If a proxy is bound to an instance, it can 
    # call the methods associated with the instance i.e. all methods containing 
    # 'self'.

    # So when we call super() in first way i.e. super(base-class, derived-class),
    # we get a proxy which is bound to class (class-bound proxies). Now we must
    # find - in case of multiple inheritance, proxy belongs to which of the base
    # class. For that, following steps are followed:

    # - Python finds MRO of the derived class
    # - It then finds base-class in that MRO
    # - It takes everything after base-class in that MRO, and finds the first
    #   class in that sequence with a matching method name

    # Let's see in action, whatever we discussed above:

    from sorted_list import *
    SortedIntList.mro()
    # [<class 'sorted_list.SortedIntList'>, 
    #  <class 'sorted_list.IntList'>, 
    #  <class 'sorted_list.SortedList'>, 
    #  <class 'sorted_list.SimpleList'>, 
    #  <class 'object'>]

    super(SortedList, SortedIntList)
    # <super: <class 'SortedList'>, <SortedIntList object>>

    # Let's use the 3 steps mentioned above to validate the output we got by
    # executing above python statement.

    super(SortedList, SortedIntList)
    # 1. Find the MRO of the derived class. We have already found that above.
    # 2. Find 'SortedList' in that MRO. It's the third entry in the list.
    # 3. It takes everything after 'SortedList' 
    #    i.e. [<class 'sorted_list.SimpleList>, 
    #          <class 'object'>]
    #    and returns this MRO containing only 2 entries. 

    # So if we call add over this super(), add must belong to SimpleList. 
    # Let's see if we are right.

    super(SortedList, SortedIntList).add
    # Output: <function SimpleList.add at 0x10436a050>

    # However we can't call this add() method because add() is bound to object 
    # and not to class. 
    super(SortedList, SortedIntList).add(4)
    # TypeError: add() missing 1 required positional argument: 'item'

    # We can only call 'staticmethod' and 'classmethod'. We can see this as:
    super(SortedIntList, SortedIntList)._validate(5)    
    # No output. Statement executed successfully.
    super(SortedIntList, SortedIntList)._validate("hello")
    # TypeError: IntList only supports integer values.


    # Now lets call super() in second way. To find the instance to which proxy
    # is bound to (instance-bound proxies), we must follow the following steps:

    # - Find the MRO for the type of the second argument
    # - Find the location of the first argument in the MRO
    # - Uses everything after the first argument's location for resolving
    #   methods.

    # Let's see in action, whatever we discussed above:

    from sorted_list import *
    SortedIntList.mro()
    # [<class 'sorted_list.SortedIntList'>, 
    #  <class 'sorted_list.IntList'>, 
    #  <class 'sorted_list.SortedList'>, 
    #  <class 'sorted_list.SimpleList'>, 
    #  <class 'object'>]

    sil = SortedIntList([5, 15, 10])
    sil             # Output: SortedIntList([5, 10, 15])
    
    super(SortedList, sil)
    # Output: <super: <class 'SortedList'>, <SortedIntList object>>

    # Like discussed in case 1, the above super() method now works on the 
    # remaining MRO with 2 entries only: 
    #   [<class 'sorted_list.SimpleList>, 
    #    <class 'object'>]

    # So the above super proxy will directly use the SimpleList's methods, 
    # by-passing our constraint checks.

    super(SortedList, sil).add(6)
    sil                 # Output: SortedIntList([5, 10, 15, 6])
    super(SortedList, sil).add("I m not a Int")
    sil                 # Output: SortedIntList([5, 10, 15, 6, "I m not a Int"])

    # So our SortedIntList isn't even sorted and also contains elements apart 
    # from ints. This means - we need to use super() with care. It does give you
    # some super-powers XD.

    # Examples we used above, had arguments in super(), while the examples we 
    # used in our sorted_list.py did not have any arguments. If no arguments are
    # passed in super(), python will sort out the arguments for us.

    # For class-bound proxies, super() is equivalent to:
    #   super(class-of-method, class)

    # For instance-bound proxies, super() is equivalent to:
    #   super(class-of-method, class)


    # Now that you have absorbed so much of information, you know that how
    # super() uses everything after a specific class in an MRO to resolve 
    # method calls. 

    # Coming back to our mystery - How does SortedIntList work?

    # The key is - Both classes (SortedList and IntList) use super() instead of 
    # direct base classes references. But as we now know, super() doesn't just
    # let us access the base classes, but rather let's access the complete 
    # MRO of the class. Let's look at the entire code again:

    class SimpleList:
        def __init__(self, items):
            self._items = list(items)

        def add(self, item):
            self._items.append(item)

        def __getitem__(self, index):
            return self._items[index]

        def sort(self):
            self._items.sort()

        def __len__(self):
            return len(self._items)

        def __repr__(self):
            return "SimpleList({!r})".format(self._items)

    
    class SortedList(SimpleList):
        def __init__(self, items=()):
            super().__init__(items)
            self.sort()

        def add(self, items):
            super().add(item)
            self.sort()

        def __repr__(self):
            return "SortedList({!r})".format(list(self))

    
    class IntList(SimpleList):
        def __init__(self, items=()):
            for x in items:self._validate(x)
            super().__init__(items)
        
        @staticmethod
        def _validate(x):
            if not isinstance(x, int):
                raise TypeError('IntList only supports integer values.')

        def add(self, item):
            self._validate(item)
            super.add(item)

        def __repr__(self):
            return "IntList({!r})".format(list(self))

    
    class SortedIntList(IntList, SortedList):
        def __repr__(self):
            return 'SortedIntList({!r})'.format(list(self))

    
    # Look again at the MRO of the SortedIntList:

    # [<class 'sorted_list.SortedIntList'>, 
    #  <class 'sorted_list.IntList'>, 
    #  <class 'sorted_list.SortedList'>, 
    #  <class 'sorted_list.SimpleList'>, 
    #  <class 'object'>]

    sil = SortedIntList()
    sil.add(6)

    # A call to add() on SortedIntList, resolves to the add() of the IntList.
    # The add() of the IntList calls super().add(). This super() uses the MRO
    # after IntList class, to resolve for add() and thus refers to the add()
    # of the SortedList, instead of SimpleList (what we thought earlier).
    # This is how add() on SortedIntList maintains two constraints, without
    # manually combining them. The super().add() in SortedList resolves to add()
    # of the SimpleList. 

    # This is a fairly deep result and if you understand how SortedIntList works,
    # then you have a good grasp on super(). 
    
# ------------------------------------------------------------------------------

