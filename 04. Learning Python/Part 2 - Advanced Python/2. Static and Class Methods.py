#################### TOPIC 2 - STATIC AND CLASS METHODS ########################

# 1. CLASS ATTRIBUTES

    # Create a file - 'shipping.py' and add the following contents:

    class ShippingContainer:
        def __init__(self, owner_code, contents):
            self.owner_code = owner_code
            self.contents = contents

    # This class is simple enough to run from REPL.

    from shipping import *
    c1 = ShippingContainer("YML", "books")
    c1.owner_code                   # Output: YML
    c1.contents                     # Output: books

    # If we create another shipping container, it will have its own owner_code
    # and contents as you would expect.

    c2 = ShippingContainer("MAE", "clothes")
    c2.owner_code                   # Output: MAE
    c2.contents                     # Output: clothes

    # Sometimes, we would wish to have an attribute which is associated with the
    # class and not with the instance of each of the class. In other words, 
    # we would like to have an attribute whose value is shared between all 
    # instances of the class. For example, let's say we want to assign each new
    # shipping container a serial number. Let this serial number start from an
    # arbitrary value 1337. We modify our class as follows:

    class ShippingContainer:
        next_serial = 1337
        def __init__(self, owner_code, contents):
            self.owner_code = owner_code
            self.contents = contents
            self.serial = ShippingContainer.next_serial
            ShippingContainer.next_serial += 1
    
# ------------------------------------------------------------------------------

# 2. STATIC METHOD

    # Let's make a small change in our code. Let's put the logic of getting
    # next serial number into a class method, instead of putting it in 
    # initializer.

    class ShippingContainer:
        next_serial = 1337

        def _get_next_serial(self):
            result = ShippingContainer.next_serial
            ShippingContainer.next_serial += 1
            return result

        def __init__(self, owner_code, contents):
            self.owner_code = owner_code
            self.contents = contents
            self.serial = self._get_next_serial()

    # You can see that - inside _get_next_serial(), we are not using 'self'
    # at all. And moreover, in __init__() function, self._get_next_serial() 
    # creates a misconception that _get_next_serial() is bound to a instance
    # instead of a class. So we modify the code a little bit, as:

    class ShippingContainer:
        next_serial = 1337

        @staticmethod
        def _get_next_serial():
            result = ShippingContainer.next_serial
            ShippingContainer.next_serial += 1
            return result

        def __init__(self, owner_code, contents):
            self.owner_code = owner_code
            self.contents = contents
            self.serial = ShippingContainer._get_next_serial()

    # When you define a method as static, it gets associated with the class, 
    # and could be called using class name, instead of calling it on instance.
    # We can omit - 'self' in static methods.

# ------------------------------------------------------------------------------

# 3. CLASS METHOD

    # As an alternative to static method, we can use - 'class method'.
    # Class methods require first argument as - 'cls', which stands for 'class'.
    # 'class' is already a keyword used to define classes, we are provided with
    # the word - 'cls'.

    # The 'cls' argument performs the analogous role in the class methods, what
    # 'self' performs in instance methods.

    class ShippingContainer:
        next_serial = 1337

        @classmethod
        def _get_next_serial(cls):
            result = cls.next_serial
            cls.next_serial += 1
            return result

        def __init__(self, owner_code, contents):
            self.owner_code = owner_code
            self.contents = contents
            self.serial = ShippingContainer._get_next_serial()

    
    # So the question is - when to use which function?

    # a) If you want to call a method on each instance, you use normal 
    #    function with 'self' as first argument. 

    # b) If you want to call a method on class, you have two options -
    #    use @staticmethod or @classmethod. @staticmethod receives no arguments.
    #    It is like a normal function, like the ones you define outside classes,
         
        def some_function_name():
            # few statements
        
    #    But this function is now restricted in the scope of the class. Apart
    #    from the scope, it is similar to normal functions. @classmethod receives
    #    the class object. Most of the times - @classmethod and @staticmethods
    #    can be used interchangably, but it is often recommended to use 
    #    @classmethod if you are using the class attributes or methods inside it.

    #    A common use of @classmethod is to define different type of initializers.
    #    For example, in the following code - create_empty() creates an empty
    #    container and create_with_items() creates a container with items.

    class ShippingContainer:
        next_serial = 1337

        @classmethod
        def _get_next_serial(cls):
            result = cls.next_serial
            cls.next_serial += 1
            return result

        @classmethod
        def create_empty(cls, owner_code):
            return cls(owner_code, contents=None)

        @classmethod
        def create_with_items(cls, owner_code, items):
            return cls(owner_code, contents=list(items))

        def __init__(self, owner_code, contents):
            self.owner_code = owner_code
            self.contents = contents
            self.serial = ShippingContainer._get_next_serial()

    # On REPL, 

    from shipping import *
    c3 = ShippingContainer.create_empty("YML")
    c3.serial                   # Output: 1337
    c3.owner_code               # Output: YML
    c3.contents                 # No Output, meaning None.

    c4 = ShippingContainer.create_with_items("MAE", ['food', 'oil', 'minerals'])
    c4.serial                   # Output: 1338
    c4.owner_code               # Output: MAE
    c4.contents                 # Output: ['food', 'oil', 'minerals']

# ------------------------------------------------------------------------------
