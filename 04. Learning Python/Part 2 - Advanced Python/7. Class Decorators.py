####################### TOPIC 7 - CLASS DECORATORS ##########################

# There are two different ways to use decorators on classes. The first is 
# by decorating the methods of a class or decorating the whole class.

# 1. BUILT-IN CLASS DECORATORS

    # Some commonly used decorators that are built into Python are @classmethod, 
    # @staticmethod, and @property. The @classmethod and @staticmethod 
    # decorators are used to define methods inside a class namespace that’s not 
    # connected to a particular instance of that class. The @property decorator 
    # is used to customize getters and setters for class attributes.

    class Circle:
        def __init__(self, radius):
            self._radius = radius

        @property
        def radius(self):
            """Get value of radius"""
            return self._radius

        @radius.setter
        def radius(self, value):
            """Set radius, raise error if negative"""
            if value >= 0:
                self._radius = value
            else:
                raise ValueError("Radius must be positive")

        @property
        def area(self):
            """Calculate area inside circle"""
            return self.pi() * self.radius**2

        def cylinder_volume(self, height):
            """Calculate volume of cylinder with circle as base"""
            return self.area * height

        @classmethod
        def unit_circle(cls):
            """Factory method creating a circle with radius 1"""
            return cls(1)

        @staticmethod
        def pi():
            """Value of π, could use math.pi instead though"""
            return 3.1415926535

    # In this class:
    
    # - .cylinder_volume() is a regular method.

    # - .radius is a mutable property: it can be set to a different value. 
    #    However, by defining a setter method, we can do some error testing to 
    #    make sure it’s not set to a nonsensical negative number. Properties 
    #    are accessed as attributes without parentheses.

    # - .area is an immutable property: properties without .setter() methods 
    #    can’t be changed. Even though it is defined as a method, it can be 
    #    retrieved as an attribute without parentheses.
    
    # - .unit_circle() is a class method. It’s not bound to a particular 
    #    instance of Circle. Class methods are often used as factory methods 
    #    that can create specific instances of the class.
    
    # - .pi() is a static method. It’s not really dependent on the Circle class, 
    #    except that it’s part of its namespace. Static methods can be called on 
    #    either an instance or the class.

    c = Circle(5)
    c.radius                        # Output: 5
    c.area                          # Output: 78.5398163375
    c.area = 100
    # AttributeError: can't set attribute
    c.cylinder_volume(height=4)     # Output: 50.265482456
    c.radius = -1                   
    # ValueError: Radius must be positive
    c = Circle.unit_circle() 
    c.pi()                          # Output: 3.1415926535
    Circle.pi()                     # Output: 3.1415926535

# ------------------------------------------------------------------------------

# 2. DECORATING A CLASS METHOD

    # Recall our decorator function which can be used to calculate the time
    # taken by a function to execute. Here is another function, which does the
    # similar task.

    def timer(func):
        def wrapper(*args, **kwargs):
            start_time = time.perf_counter()
            value = func(*args, **kwargs)
            end_time = time.perf_counter()
            run_time = end_time - start_time
            print("Finished {} in {} secs".format(repr(func.__name__), round(run_time, 3)))
            return value
        return wrapper


    class Calculator:
        def __init__(self, num):
            self.num = num

        @timer
        def doubled_and_add(self):
            res = sum([i * 2 for i in range(self.num)])
            print("Result : {}".format(res))

    # Let's test this on REPL.

    c = Calculator(10000)
    c.doubled_and_add()
    # Output: Result : 99990000
    #         Finished 'doubled_and_add' in 0.001 secs

# ------------------------------------------------------------------------------

# 3. DECORATE ENTIRE CLASS

    # Decorating a class does not decorate its methods. Here, @timer only 
    # measures the time it takes to instantiate the class.

    @timer
    class Calculator:
        def __init__(self, num):
            self.num = num
            import time
            time.sleep(2)

        def doubled_and_add(self):
            res = sum([i * 2 for i in range(self.num)])
            print("Result : {}".format(res))

    c = Calculator(10000)
    # Output: Finished 'Calculator' in 2.001 secs

# ------------------------------------------------------------------------------

# 4. CLASSES AS DECORATORS

    # The best way to maintain state is by using classes. If we want to use 
    # class as a decorator it needs to take func as an argument in its 
    # .__init__() method. Furthermore, the class needs to be callable so that 
    # it can stand in for the decorated function. For a class to be callable, 
    # you implement the special .__call__() method.

    class CountCalls:
        def __init__(self, func):
            functools.update_wrapper(self, func)
            self.func = func
            self.num_calls = 0

        def __call__(self, *args, **kwargs):
            self.num_calls += 1
            print(f"Call {self.num_calls} of {self.func.__name__!r}")
            return self.func(*args, **kwargs)


    @CountCalls
    def say():
        print("Hello!")

    say()
    say()
    say()
    say()
    print(say.num_calls)


    # Output: 
    #   Call 1 of 'say'
    #   Hello!
    #   Call 2 of 'say'
    #   Hello!
    #   Call 3 of 'say'
    #   Hello!
    #   Call 4 of 'say'
    #   Hello!
    #   4

# ------------------------------------------------------------------------------