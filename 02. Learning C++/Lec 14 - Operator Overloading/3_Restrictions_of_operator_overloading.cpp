RESTRICTIONS OF OPERATOR OVERLOADING:

1. No new operator like **, <<<, @, &&||, etc. can be defined. 
   Only the existing operators could be overloaded.

2. Intrinsic properties of operators cannot be changed. Like after 
   overloading also, operator preserves its arity, precedence and associativity.
  
3. The overloading of &&, || and comma (,) is not suggested as they then 
   lose their special properties.

4. These operators can not be overloaded:
    a) Scope resolution (::)
    b) Member access (.)
    c) Member access through pointer to member (*.)
    d) sizeof
    e) Ternary conditional ( ?: )
    
/*------------------------------------------------------------------------------------------------------------------------*/

EXPLANATION POINT 3: 

---------------------------------------------------------------------------------------------------------------------------
    OPERATOR    |      REASON                                                                                             |
---------------------------------------------------------------------------------------------------------------------------
    && and ||   | Consider exp1 && exp2. If exp1 is false, compiler knows the result will be false. Hence exp2 is not     |
                | executed. Similarly, in exp1 || exp2, if exp1 is true, exp2 wont be executed. This short-circuit        |
                | evaluation property of these operators will be lost if they are overloaded.                             |
---------------------------------------------------------------------------------------------------------------------------
    Comma (,)   | This operator guarantees that the first operand is evaluated before the second operand. However, if the |
                | comma operator is overloaded, its operand evaluation depends on C++'s function parameter mechanism,     |
                | which doesn't guarantee the order of evaluation.                                                        |
---------------------------------------------------------------------------------------------------------------------------

/*-------------------------------------------------------------------------------------------------------------------------*/

EXPLANATION POINT 4: 

---------------------------------------------------------------------------------------------------------------------
    OPERATOR            |                   REASON                                                                  |
---------------------------------------------------------------------------------------------------------------------
    dot (.)             | It will raise question whether it is object referencing or operator overloading           |
---------------------------------------------------------------------------------------------------------------------
Scope resolution (::)   | This operator does compile time scope resolution and not expression evaluation            |
---------------------------------------------------------------------------------------------------------------------
    Ternary ( ?: )      | exp1 ? exp2 : exp3 executes the way like, if exp1 is true exp2 will be executed.          |
                        | Or else exp3 will be executed. So here one of exp2 and exp3 executes always.              |
                        | So overloading operators doesn't guarantee this single execution and will execute both.   |
---------------------------------------------------------------------------------------------------------------------
    sizeof              | sizeof cannot be overloaded because many built-in operations such as memory allocation    |
                        | using malloc, calloc, etc. depend on it. Incorrect overloading of sizeof may cause issues.|
---------------------------------------------------------------------------------------------------------------------

/*-------------------------------------------------------------------------------------------------------------------*/
