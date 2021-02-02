####################### TOPIC 5 - OBJECT INTERNALS ###########################

# 1. ATTRIBUTES and __dict__

    # Let's start with a basic class to represent a basic 2D vector.

    class Vector:
        def __init__(self, x, y):
            self.x = x
            self.y = y
        
        def __repr__(self):
            return "{}({}, {})".format(self.__class__.__name__, self.x, self.y)

    # We now test few things on the REPL.

    v = Vector(5, 3)
    v                       # Output: Vector(5, 3)
    dir(v)
    # ['__class__', '__delattr__', '__dict__', '__dir__', '__doc__', '__eq__', 
    #  '__format__', '__ge__', '__getattribute__', '__gt__', '__hash__', 
    #  '__init__', '__init_subclass__', '__le__', '__lt__', '__module__', 
    #  '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', 
    #  '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', 
    #  'x', 'y']

    # This is the list of all the attributes which could be called over v. 
    # For our further discussion, we are interested in one attribute - '__dict__'.

    v.__dict__              # Output: {'x': 5, 'y': 3}
    v.__dict__['x']         # Output: 5
    v.__dict__['x'] = 17
    v.x                     # Output: 17
    del v.__dict__['x']
    v.x 
    # AttributeError: 'Vector' object has no attribute 'x'
    'x' in v.__dict__       # Output: False
    'y' in v.__dict__       # Output: True
    v.__dict__['z'] = 3
    v.z                     # Output: 3

    # Even though such manipulations with attributes of an object are possible
    # using dictionary, you should use methods:

    getattr(v, 'y')         # Output: 3
    hasattr(v, 'x')         # Output: False
    delattr(v, 'z') 
    setattr(v, 'x', 9) 
    v.x                     # Output: 9

    # So there are two issues in above code:
    # 
    # a) The Notation: Here we use 'x' and 'y' as labels of the coordinates in 
    #    2D plane. What if the user wants to have 'u' and 'v' as the coordinate
    #    labels. This means, we want to give user the freedom to make attributes
    #    of the instance as per their desire.
    # 
    # b) Scope: If you see the output of dir(v), two new attributes have come in 
    #    the list: 'x' and 'y'. Thus, we can say - the attributes are public 
    #    and could be changed. We don't want these attributes to be visible to 
    #    the user and object should be immutable.

    # Let's solve the first issue:

    class Vector:
        def __init__(self, **coords):
            self.__dict__.update(coords)

        def __repr__(self):
            return "{}({})".format(
                self.__class__.__name__,
                ', '.join("{k}={v}".format(
                k = k,
                v = self.__dict__[k])
                for k in sorted(self.__dict__.keys())))

    # On REPL,

    v = Vector(p = 3, q = 7)
    v                           # Output: Vector(p=3, q=7)
    dir(v)
    # ['__class__', '__delattr__', '__dict__', '__dir__', '__doc__', '__eq__', 
    #  '__format__', '__ge__', '__getattribute__', '__gt__', '__hash__', 
    #  '__init__', '__init_subclass__', '__le__', '__lt__', '__module__', '__ne__', 
    #  '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', 
    #  '__sizeof__', '__str__', '__subclasshook__', '__weakref__', 'p', 'q']

    # Let's make a simple change, so that user should not be allowed to access
    # attribute names directly.

    class Vector:
        def __init__(self, **coords):
            private_coords = {'_' + k:v for k, v in coords.items()}
            self.__dict__.update(private_coords)

        def __repr__(self):
            return "{}({})".format(
                self.__class__.__name__,
                ', '.join("{k}={v}".format(
                k = k[1:],
                v = self.__dict__[k])
                for k in sorted(self.__dict__.keys())))

    v = Vector(p = 9, q = 7)
    v                           # Output: Vector(p=9, q=7)
    dir(v)
    # ['__class__', '__delattr__', '__dict__', '__dir__', '__doc__', '__eq__', 
    #  '__format__', '__ge__', '__getattribute__', '__gt__', '__hash__', 
    #  '__init__', '__init_subclass__', '__le__', '__lt__', '__module__', '__ne__', 
    #  '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', 
    #  '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_p', '_q']

    v.p
    # AttributeError: 'Vector' object has no attribute 'p'

    # What we want to do here is - We should allow the read access to the 
    # attributes, and the error should be raised only when attempt to modify it
    # is made. The read access could be made by overriding __getattr__, and 
    # avoid the write access by overriding __setattr__.

    class Vector:
        def __init__(self, **coords):
            private_coords = {'_' + k:v for k, v in coords.items()}
            self.__dict__.update(private_coords)

        def __getattr__(self, name):
            private_name = '_' + name
            try:
                return self.__dict__[private_name]
            except KeyError:
                raise AttributeError('{!r} object has no attribute {!r}'.format(
                self.__class__, name))

        def __setattr__(self, name, value):
            raise AttributeError("Can't set attribute {!r}".format(name))

        def __delattr__(self, name):
            raise AttributeError("Can't delete attribute {!r}".format(name))

        def __repr__(self):
            return "{}({})".format(
                self.__class__.__name__,
                ', '.join("{k}={v}".format(
                k = k[1:],
                v = self.__dict__[k])
                for k in sorted(self.__dict__.keys())))

# ------------------------------------------------------------------------------

# 2. INSTANCE CREATION

    # __new__ is one of the most easily abused features in Python. 
    # It’s obscure, riddled with pitfalls, and almost every use case I’ve 
    # found for it has been better served by another of Python’s many tools. 
    # However, when you do need __new__, it’s incredibly powerful and invaluable 
    # to understand.

    # The predominant use case for __new__ is in metaclasses. Metaclasses are 
    # complex enough to merit their own article, so I don’t touch on them here. 
    # If you already understand metaclasses, great. If not, don’t worry; 
    # understanding how Python creates objects is valuable regardless.

    # - Constructors
    
    # With the proliferation of class-based languages, constructors are likely 
    # the most popular method for instantiating objects.

    # a) JAVA
    class StandardClass {
        private int x;
        public StandardClass() {
            this.x = 5;
        }

        public int getX() {
            return this.x;
        }
    }

    # b) PYTHON
    class StandardClass(object):
        def __init__(self, x):
            self.x = x

    # c) JAVASCRIPT
    function StandardClass(x) {
        this.x = x;
    }
    var standard = new StandardClass(5);

    # In Python, as well as many other languages, there are two steps to object 
    # instantiation:

    # STEP 1 - The New Step
    # Before you can access an object, it must first be created. This is not 
    # the constructor. In the above examples, we use this or self to reference 
    # an object in the constructor; the object had already been created by then. 
    # The New Step creates the object before it is passed to the constructor. 
    # This generally involves allocating space in memory and/or whatever 
    # language specific actions newing-up an object requires.

    # STEP 2 - The Constructor Step
    # Here, the newed-up object is passed to the constructor. In Python, this is 
    # when __init__ is called.

    # This is the normal way to instantiate a StandardClass object:
    standard = StandardClass(5)

    # StandardClass(5) is the normal instance creation syntax for Python. It 
    # performs the New Step followed by the Constructor Step for us. Python also 
    # allows us to deconstruct this process:

    # New Step
    newed_up_standard = object.__new__(StandardClass)
    type(newed_up_standard) is StandardClass
    hasattr(newed_up_standard,'x') is False

    # Constructor Step
    StandardClass.__init__(newed_up_standard, 5)
    newed_up_standard.x == 5

    # object.__new__ is the default New Step for object instantiation. It’s what 
    # creates an instance from a class. This happens implicitly as the first 
    # part of StandardClass(5).

    # Notice, x is not set until after newed_up_standard is run through __init__.
    # This is because object.__new__ doesn’t call __init__. They are disparate 
    # functions. If we wanted to perform checks on newed_up_standard or 
    # manipulate it before the constructor is run, we could. However, explicitly 
    # calling the New Step followed by Constructor Step is neither clean nor 
    # scalable. Fortunately, there is an easy way.

    # Python allows us to override the New Step of any object via the __new__ 
    # magic method.

    class NewedBaseCheck(object):
        def __new__(cls):
            obj = super(NewedBaseCheck,cls).__new__(cls)
            obj._from_base_class = type(obj) == NewedBaseCheck
            return obj
        def __init__(self):
            self.x = 5

    newed = NewedBaseCheck()
    newed.x == 5
    newed._from_base_class is True

    # __new__ takes a class instead of an instance as the first argument. Since 
    # it creates an instance, that makes sense. 
    # super(NewedClass, cls).__new__(cls) is very important. We don’t want to 
    # call object.__new__ directly; again, you’ll see why later.

    # Why is from_base_class defined in __new__ instead of __init__? 
    # It’s metadata about object creation, which makes more semantic sense in 
    # __new__. However, if you really wanted to, you could place define 
    # _from_base_class:

    class StandardBaseCheck(object):
        def __init__(self):
            self.x = 5
            self._from_base_class == type(self) == StandardBaseCheck

    standard_base_check = StandardBaseCheck()
    standard_base_check.x == 5
    standard_base_check._from_base_class is True

    # There is a major behavioral difference between NewBaseCheck and 
    # StandardBaseCheck in how they handle inheritance:

    class SubNewedBaseCheck(NewedBaseCheck):
        def __init__(self):
            self.x = 9

    subnewed = SubNewedBaseCheck()
    subnewed.x == 9
    subnewed._from_base_class is False

    class SubStandardBaseCheck(StandardBaseCheck):
        def __init__(self):
            self.x = 9

    substandard_base_check = SubStandardBaseCheck()
    substandard_base_check.x == 9
    hasattr(substandard_base_check,"_from_base_class") is False

    # Because we failed to call super(...).__init__ in the constructors, 
    # _from_base_class is never set.

    # Up until now, classes defining both __init__ and __new__ had no-argument 
    # constructors. Adding arguments has a few pitfalls to watch out for. 
    # We’ll modify NewBaseCheck:

    class NewedBaseCheck(object):
        def __new__(cls):
            obj = super(NewedBaseCheck,cls).__new__(cls)
            obj._from_base_class = type(obj) == NewedBaseCheck
            return obj

        def __init__(self, x):
            self.x = x

    try:
        NewedBaseCheck(5)
    except TypeError:
        print True

    # Instantiating a new NewedBaseCheck throws a TypeError. NewedBaseCheck(5) 
    # first calls NewBaseCheck.__new__(NewBaseCheck, 5). Since __new__ takes 
    # only one argument, Python complains. Let’s fix this:

    class NewedBaseCheck(object):
        def __new__(cls, x):
            obj = super(NewedBaseCheck,cls).__new__(cls)
            obj._from_base_class = type(obj) == NewedBaseCheck
            return obj

        def __init__(self, x):
            self.x = x

    newed = NewedBaseCheck(5)
    newed.x == 5

    # There are still problems with subclassing:

    class SubNewedBaseCheck(NewedBaseCheck):
        def __init__(self, x, y):
            self.x = x
            self.y = y

    try:
        SubNewedBaseCheck(5,6)
    except TypeError:
        print True

    # We get the same TypeError as above; __new__ takes cls and x, and we’re 
    # trying to pass in cls, x, and y. The generic fix is fairly simple:

    class NewedBaseCheck(object):
        def __new__(cls, *args, **kwargs):
            obj = super(NewedBaseCheck,cls).__new__(cls)
            obj._from_base_class = type(obj) == NewedBaseCheck
            return obj

        def __init__(self, x):
            self.x = x

    newed = NewedBaseCheck(5)
    newed.x == 5

    subnewed = SubNewedBaseCheck(5,6)
    subnewed.x == 5
    subnewed.y == 6

    # Unless you have a good reason otherwise, always define __new__ with 
    # *args and **kwargs.

    
    # __new__ is incredibly powerful (and dangerous) because you manually 
    # return an object. There are no limitations to the type of object you 
    # return.

    class GimmeFive(object):
        def __new__(cls, *args, **kwargs)):
            return 5

    GimmeFive() == 5

    # If __new__ doesn’t return an instance of the class it’s bound to 
    # (e.g. GimmeFive), it skips the Constructor Step entirely:

    class GimmeFive(object):
        def __new__(cls, *args, **kwargs):
            return 5

        def __init__(self,x):
            self.x = x

    five = GimmeFive()
    five == 5
    isinstance(five, int) is True
    hasattr(five, "x") is False

    # That makes sense: __init__ will throw an error if passed anything but an 
    # instance of GimmeFive, or a subclass, for self. Knowing all this, we can 
    # easily define Python’s object creation process:

    def instantiate(cls, *args, **kwargs):
        obj = cls.__new__(cls, *args, **kwargs)
        if isinstance(obj,cls):
            cls.__init__(obj, *args, **kwargs)
        return obj
    
    instantiate(GimmeFive) == 5
    newed = instantiate(NewedBaseCheck, 5)
    type(newed) == NewedBaseCheck
    newed.x == 5

    # Note: DON'T DO THIS EVER:

    # While experimenting for this post I created a monster that, like 
    # Dr. Frankenstein, I will share with the world. It is a great example of 
    # how horrifically __new__ can be abused. (Seriously, don’t ever do this.)

    class A(object):
        def __new__(cls):
            return super(A,cls).__new__(B)
        def __init__(self):
            self.name = "A"

    class B(object):
        def __new__(cls):
            return super(B,cls).__new__(A)
        def __init__(self):
            self.name = "B"

    a = A()
    b = B()
    type(a) == B
    type(b) == A
    hasattr(a,"name") == False
    hasattr(b,"name") == False

    # The point of the above code snippet: please use __new__ responsibly; 
    # everyone you code with will thank you.

    # __new__ and the new step, in the right hands and for the right task, are 
    # powerful tools. Conceptually, they neatly tie together object creation. 
    # Practically, they are a blessing when you need them. They also have a 
    # dark side. Use them wisely.

# ------------------------------------------------------------------------------
