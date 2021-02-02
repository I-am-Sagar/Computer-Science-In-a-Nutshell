# ###################### TOPIC 8 - CLASSES and OBJECTS #########################

# 1. INTRODUCTION TO CLASSES

    # Classes provide a means of bundling data and functionality together. 
    # Creating a new class creates a new type of object, allowing new instances 
    # of that type to be made. Each class instance can have attributes attached 
    # to it for maintaining its state. Class instances can also have methods 
    # (defined by its class) for modifying its state.

    # Let's try to make a model for aircraft flights and learn the concepts 
    # parallely. Create a file - airtravel.py

    class Flight:
        pass

    # This is a minimal class, and does nothing. Now, go to REPL, and do this:

    from airtravel import Flight
    Flight          # Output: <class 'Flight'>
    f = Flight()    
    type(f)         # Output: <class 'Flight'>

    # Here 'f' is the object of class Flight. For every class, python provides
    # it's own constructor (i.e. We don't define constructors in class 
    # definition) to create objects. Now, let's add some few more statements in
    # our class. 

    class Flight:
        def number(self):
            return 'SN060'
    
    # The first argument of all the methods (i.e. functions of class) is self. 
    # This is because: 

    # We call this function using object as:
    f = Flight()
    f.number()          # Output: SN060         (Form 1)

    # However, Python interprets above function call as follows:

    Flight.number(f)    # Output: SN060         (Form 2)

    # The above form is also correct and is equivalent to Form 1. However,
    # we will use Form 1 only as hardly anybody uses Form 2. 

# ------------------------------------------------------------------------------

# 2. __init__ method:

    # The above class is not usefful as it only represents one particular flight.
    # We need to make flight's number method more general. To do that we need to 
    # learn the initialization method i.e. __init__().

    # If provided an initialization method, it is called uring during the process
    # of creating an object. Like all other instance methods, first argument of
    # initializer method must be self. Initializer method should not return 
    # anything. It should just modify the object using 'self'.

    # Note: __init__() is an initializer, not a constructor. Constructor is
    #       provided by the Python runtime system and the constructor is called
    #       during creation of objects. When that constructor is called, one 
    #       thing constructor function does is calling the initializer function.
    #       And 'self' is similar to 'this' in C++ or Java. 

    # During initalization we create identifiers used inside the class by 
    # assignment operation. We follow the naming convention that the identifiers
    # used inside the class start with an underscore. 

    class Flight:
        def __init__(self, number):
            self._number = number
        
        def number(self):
            return self._number

    # On REPL, execute the following:

    from airtravel import flight
    f = Flight('SN060')
    f.number()      # Output: SN060

    # Note: There are no 'public', 'private' or 'protected' keywords in Python
    #       as everything is public. There is a way of creating private 
    #       variables in Python - with a way called 'Name Mangling', but we will 
    #       see it later. But there is no strict way to define private or 
    #       protected variables. This does not affect the security as program's
    #       security is maintained by system methods and is enough to provide
    #       sufficient security, even in huge programs. 

    # To check if a flight is valid or not, we need to do some checking and 
    # should raise errors if in case of exceptions.

    class Flight:
        def __init__(self, number):
            if not number[:2].isalpha():
                raise ValueError("No airline code in {}".format(number))
            if not number[:2].isupper():
                raise ValueError("Invalid airline code {}".format(number))
            if not (number[2:].isdigit() and int(number[2:]<=9999)):
                raise ValueError("Invalid route number {}".format(number))
            self._number = number

        def number(self):
            return self._number

        def airline(self):
            return self._number[:2]

# ------------------------------------------------------------------------------

# 3. WORKING WITH MULTIPLE CLASSES

    # One of the features which we will wish from our aircraft model is - 
    # that it should accept seat bookings. For that we should first build the 
    # seat layour and for that we need to know the aircraft. So lets make 
    # another class to model different kinds of aircrafts:

    class Aircraft :
        def __init__(self, registration, model, num_rows, num_seats_per_row):
            self._registration = registration
            self._model = model
            self._num_rows = num_rows
            self._num_seats_per_row = num_seats_per_row
        
        def registration(self):
            return self._registration

        def model(self):
            return self._model
    
    # Rows in aircraft are numbered from 1 and seats in each row are designated
    # with letter which omits 'I' to avoid confusion with 1. 

        def seating_plan(self):
            return (range(1, self._num_rows + 1), "ABCDEFGHJK"[:self._num_seats_per_row])
    
    # range() from the iterable sequence of row numbers from 1 upto row numbers
    # in the plane. String is sliced here to return one character per row. These 
    # two objects are bundled up into a tuple. With that in mind - lets 
    # construct a plane: (On REPL)

    from airtravel import *
    a = Aircraft('G-EUPT', 'Airbus A319', num_rows = 22, num_seats_per_row = 6)

    # Now, a user should get details of seating arrangement from flight class
    # only. It is not good implementation to expose all classes to user. 
    # Instead we pass objects of other classes to a single class and let user
    # interact with the object of that class. 

    # So we pass objects of aircraft to Flight. So now our airtravel.py looks 
    # like this:

    class Flight:
        def __init__(self, number, aircraft):
            if not number[:2].isalpha():
                raise ValueError("No airline code in {}".format(number))
            if not number[:2].isupper():
                raise ValueError("Invalid airline code {}".format(number))
            if not (number[2:].isdigit() and int(number[2:]<=9999)):
                raise ValueError("Invalid route number {}".format(number))
            self._number = number
            self._aircraft = aircraft

        def number(self):
            return self._number

        def airline(self):
            return self._number[:2]

        def aircraft_model(self)
            return self._aircraft.model()

    class Aircraft :
        def __init__(self, registration, model, num_rows, num_seats_per_row):
            self._registration = registration
            self._model = model
            self._num_rows = num_rows
            self._num_seats_per_row = num_seats_per_row
        
        def registration(self):
            return self._registration

        def model(self):
            return self._model

        def seating_plan(self):
            return (range(1, self._num_rows + 1), "ABCDEFGHJK"[:self._num_seats_per_row])

    # Now we can proceed to implement our simple booking system.

    # This is how we plan our seating arrangement:

    # There will be a list of dictionaries, where each dictionary will map
    # seat alphabet to passenger name in string format. We initialize the
    # seating plan in the 'flight' using the following fragment:

    rows, seat = self._aircraft.seating_plan()
    self._seating = [None] + [{letter:None for letter in seats} for _ in rows]

    # The second line creates a list of dictionaries for seat allocation. 
    # Rather than continuously dealing with the fact that the seating index
    # is 1 based and python lists are 0 based, we choose to waste 1 entry by
    # setting 1st entry to 'None'. The list is constructed using list
    # comprehension which iterates over the rows object which is the range of 
    # row numbers retrived from rows of the aircraft in the previous line. 
    # We are not interested in row numbers, hence we discard it by using the
    # dummy underscore variable. 
    # The main part of the list comprehension is the dictionary comprehension.
    # This iterates for each letter of the row and includes the mapping from
    # the single character string to None to indicate an empty seat. 

    # We use list comprehension rather than * operator for creating rows
    # since we need distinct rows and remember - repetition is shallow.

    # Let's test our seating arrangement now on REPL:

    from airtravel import *
    f = flight('BA758', Aircraft('G-EUPT', 'Airbus A319', num_rows=22, num_seats_per_row = 6))
    f._seating      # This gives accurate results but not particularly beautiful

    # We use pretty print for better print format.

    from pprint import pprint as pp
    pp(f._seating)      # This gives a very good format

    # Now let's add feature to allocate seats to passengers. Let's keep this 
    # simple by assuming passenger is simply a string name. Most of the code
    # is here about - seat validation. This is in flight class:

    def allocate_seat (self, seat, passenger):
        rows, seat_letters = self._aircraft.seating_plan()
        
        letter = seat[-1]
        if letter not in seat_letters:
            raise ValueError('Invalid seat letter {}'.format(letter))

        row_text = seat[:1]
        try:
            row = int(row_text)
        except ValueError:
            raise ValueError('Invalid seat row {}'.format(row_text))

        if row not in rows:
            raise ValueError('Invalid row number {}'.format(row))

        if seat._seating[row][letter] is not None:
            raise ValueError('Seaat {} is already occupied.'.format(seat))

        self._seating[row][letter] = passenger

    # We now refactor a code a little, because we are doing seat validation 
    # in allocate_seat() method. We define another function _parse_seat() which 
    # will contain parsing and validatin logic in its own. 

    def _parse_seat(self, seat):
        row_numbers, seat_letters = self._aircraft.seating_plan()
        
        letter = seat[-1]
        if letter not in seat_letters:
            raise ValueError('Invalid seat letter {}'.format(letter))

        row_text = seat[:1]
        try:
            row = int(row_text)
        except ValueError:
            raise ValueError('Invalid seat row {}'.format(row_text))

        if row not in rows:
            raise ValueError('Invalid row number {}'.format(row))

        return row, letter

    
    def allocate_seat(self, seat, passenger):
        row, letter = self._parse_seat(seat)
        if seat._seating[row][letter] is not None:
            raise ValueError('Seaat {} is already occupied.'.format(seat))

        self._seating[row][letter] = passenger

    # We now add a function to relocate the passenger's seat. 

    def relocate_passenger (self, from_seat, to_seat):
        from_row, from_letter = self._parse_seat(from_seat)
        if self._seating[from_row][from_letter] is None:
            raise ValueError("No passenger on seat {}".format(from_seat))

        to_row, to_letter = self._parse_seat(to_seat)
        if self._seating[to_row][to_letter] is not None:
            raise ValueError("Seat {} is not vacant.".format(to_seat))

        self._seating[to_row][to_letter] = self._seating[from_row][from_letter]
        self.seating[from_row][from_letter] = None

    # It's important during booking to know, how many seats are available.

    def num_available_seats(self):
        return sum(sum(1 for s in row.values() if s is None) for row in self._seating if row is not None)

    # Also we have to print 'Boarding cards' for the passengers. You can see - 
    # there is no 'self' in the argument list of following function. Because 
    # this function doesn't belong to any class. It is module level function. 

    def console_card_printer(passenger, seat, flight_number, aircraft):
        output = "| Name: {0} "\
                 " Flight: {1}"\
                 " Seat: {2}"\
                 " Aircraft: {3}"\
                 " |".format(p, flight_number, seat, aircraft)
        banner = '+' + '-'*(len(output)-2) + '+'
        border = '|' + '-'*(len(output)-2) + '|'
        lines = [banner, border, output, border, banner]
        card = '\n'.join(lines)
        print(card)
        print()

    # The following functions go into flight class:

    def make_boarding_cards (self, card_printer):
        for passenger, seat in sorted(self._passenger_seats()):
            console_card_printer(passenger, seat, self.number(), self.aircraft_model())

    def _passenger_seats(self):
        row_numbers, seat_letters = self._aircraft.seating_plan()
        for row in row_numbers:
            for letter in seat_letters:
                passenger = self._seating[row][letter]
                if passenger is not None:
                    yield(passenger, "{}{}".format(row, letter))

# ------------------------------------------------------------------------------

# 4. FINAL CODE

    # This is how - at the end 'airtravel.py' file should look like:

    """Model for Aircraft flights."""

    class Flight:
        """A flight with a particular passenger aircraft."""

        def __init__(self, number, aircraft):
            if not number[:2].isalpha():
                raise ValueError("No airline code in '{}'".format(number))

            if not number[:2].isupper():
                raise ValueError("Invalid airline code '{}'".format(number))

            if not (number[2:].isdigit() and int(number[2:]) <= 9999):
                raise ValueError("Invalid route number '{}'".format(number))

            self._number = number
            self._aircraft = aircraft

            rows, seats = self._aircraft.seating_plan()
            self._seating = [None] + [ {letter:None for letter in seats} for _ in rows ]

        
        def number(self):
            return self._number


        def airline(self):
            return self._number[:2]


        def aircraft_model(self):
            return self._aircraft.model()


        def _parse_seat(self, seat):
            """Parse a seat designator into a valid row and letter.

            Args:
                seat: A seat designator such as 12F

            Returns:
                A tuple containing an integer and a string for row and seat.
            """
            row_numbers, seat_letters = self._aircraft.seating_plan()

            letter = seat[-1]
            if letter not in seat_letters:
                raise ValueError("Invalid seat letter {}".format(letter))

            row_text = seat[:-1]
            try:
                row = int(row_text)
            except ValueError:
                raise ValueError("Invalid seat row {}".format(row_text))

            if row not in row_numbers:
                raise ValueError("Invalid row number {}".format(row))

            return row, letter


        def allocate_seat(self, seat, passenger):
            """Allocate a seat to a passenger.

            Args:
                seat: A seat designator such as '12C' or '21F'.
                passenger: The passenger name.

            Raises:
                ValueError: If the seat is unavailable.
            """
            row, letter = self._parse_seat(seat)

            if self._seating[row][letter] is not None:
                raise ValueError("Seat {} already occupied".format(seat))

            self._seating[row][letter] = passenger
            

        def relocate_passenger(self, from_seat, to_seat):
            """Relocate a passenger to a different seat.

            Args:
                from_seat: The existing seat designator for the
                        passenger to be moved.

                to_seat: The new seat designator.
            """

            from_row, from_letter = self._parse_seat(from_seat)
            if self._seating[from_row][from_letter] is None:
                raise ValueError("No passenger to relocate in seat {}".format(from_seat))

            to_row, to_letter = self._parse_seat(to_seat)
            if self._seating[to_row][to_letter] is not None:
                raise ValueError("Seat {} already occupied".format(to_seat))

            self._seating[to_row][to_letter] = self._seating[from_row][from_letter]
            self._seating[from_row][from_letter] = None


        def num_available_seats(self):
            return sum( sum(1 for s in row.values() if s is None)
                        for row in self._seating
                        if row is not None)


        def make_boarding_cards(self, card_printer):
            for passenger, seat in sorted(self._passenger_seats()):
                card_printer(passenger, seat, self.number(), self.aircraft_model())

        def _passenger_seats(self):
            """An iterable series of passenger seating allocations."""
            row_numbers, seat_letters = self._aircraft.seating_plan()
            for row in row_numbers:
                for letter in seat_letters:
                    passenger = self._seating[row][letter]
                    if passenger is not None:
                        yield (passenger, "{}{}".format(row, letter))

    class Aircraft:
        def __init__(self, registration, model, num_rows, num_seats_per_row):
            self._registration = registration
            self._model = model
            self._num_rows = num_rows
            self._num_seats_per_row = num_seats_per_row
        

        def registration(self):
            return self._registration


        def model(self):
            return self._model


        def seating_plan(self):
            return (range(1, self._num_rows + 1), "ABCDEFGHJK"[:self._num_seats_per_row])


    def make_flights():
        f = flight('BA758', Aircraft('G-EUPT', 'Airbus A319', num_rows=22, num_seats_per_row = 6))
        f.allocate_seat('12A', 'Guido van Rossum')
        f.allocate_seat('15F', 'Bjarne Stroustrup')
        f.allocate_seat('15E', 'Anders Hejlsberg')
        f.allocate_seat('1C', 'John McCarthy')
        f.allocate_seat('1D', 'Richard Hickey')
      return f, g


    def console_card_printer(passenger, seat, flight_number, aircraft):
      output = "| Name: {0}"     \
               "  Flight: {1}"   \
               "  Seat: {2}"     \
               "  Aircraft: {3}" \
               " |".format(passenger, flight_number, seat, aircraft)
      banner = '+' + '-' * (len(output) - 2) + '+'
      border = '|' + ' ' * (len(output) - 2) + '|'
      lines = [banner, border, output, border, banner]
      card = '\n'.join(lines)
      print(card)
      print()
# ------------------------------------------------------------------------------