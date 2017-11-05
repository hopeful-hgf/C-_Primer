# Chapter 11 Working with Classes

- To overload an operator, you use a special form called an operator function. An operator function has the folowing form, where *op* is the symbol for the operator being overloaded:
  ```C++
  operatorop(argument-list)
  ```
  For example, operator+() overloads the + operator, and operator*() overloads the * operator. You just append the operator symbol to the end of operator and use the result as a method name.
- Limits C++ imposes on user-defined operator overloading:
  - The overloaded operator must have at least one operand that is user-defined types. This prevents you frome overloading operators for the standard types.
  - you can't use an operator in a manner that violates the syntax rules for the original operator. Similarly, you can't alter operator precedence.
  - You can't create new operator symbols
  - You can't overload the following operators:
    - sizeof                           -- The sizeof operator
	- .                                -- The membership operator
	- .*                               -- The pointer-tomember operator
	- ::                               -- The scope-resolution operator
	- ?:                               -- The conditional operator
	- typeid                           -- An RTTI operator
	- const_cast                       -- A type cast operator
	- dynamic_cast                     -- A type cast operator
	- reinterpret_cast                 -- A type cast operator
	- static_cast                      -- A type cast operator
  - Most of the operator can be overloaded by using either member or nonmember functions.
  However, you can use **only** member functions to overload the following operators:
    - =                                 -- Assignment operator
	- ()                                -- Function call operator
	- []                                -- Subscripting operator
	- ->                                -- Class member access by pointer operator

- The first step toward creating a friend function is to place a prototype in the class declaration and prefix the declaration with the keyword *friend*:
  ```C++
  friend Time operator*(double m, const Time & t);        // goes in class declaration
  ```
  This prototype has two implications:
    - Although the operator*() function is declarad in the class declaration, it is not a member function.
    - Although the operator*() fnction is not a member function, it has the same access rights as a member function.
  The second step is  to write the function definition. Because it is not a member function, you don't use the Time:: qualifier. Also you don't use the friend keyword in the definition.

- overload << operator
  ```C++
  ostream & operator << (ostream & os, const Time & t)
  {
	  os << t.hours << " hours, " << t.minutes << " minutes";
	  return os;
  }
  ```

  You use the friend keyword only in the prototype found in the class declaration, you don't use it in the funtion definition unless the definition is also the prototype.

- A nonmember version of an overloaded operator function requires as many formal parameters as the operator has operands. A member version of the same operator requires on fewer parameter because one operator can convert the statment.

- The standard ANSI C library, which also comes with C++ includes a rand() function, that returns integer in the range from 0 to some implementation-dependent value. We can use `rand() % 360` get an angle value in the range 0 to 359.
- The *cstdlib* header file (formerly *stdlib.h*) contain the prototypes for *srand()* and *rand()*,whereas *ctime* (formerly *time.h*) contains the *time()* prototype.
  C++11 provides more extemsive random number support with fnctions supported by the *random* header fine.


- Any constructor that takes a single argument acts as a blueprint for converting a value of that argument type to the class type.
  Thus the following constructor serves as instructions for vonverting a type double value to a type stonewt value:
  ```C++
  Stonewt(double lbs);               // template for double-to Stonewt conversion
  ```
  That is, you can write code like the following:
  ```C++
  Stonewt myCat;                    // Create a Stonewt object
  myCat = 19.5;                     // Use Stonewt (double) to convert 19.5 to Stonewt
  ```
  This program use the Stonewt(double) constructor to construct a temporary Stonewt object, using 19.5 as the initializatin value. Then memberwise assignment copies the contents of the temporary object into myCat. This process is termed an *implicit conversion*, because it hanpens automatically, without the need of an explicit type cast.

- C++ added a new keyword *explicit* to turn off the automatic aspect. You can declare the constructor this way:
  ```C++
  explicit Stonewt(double lbs);               // no implicit conversins allowed
  ```
  This turn off implicit conversions, but still allows explicit conversions.

- Constructor only provide for converting another type to the class type. To do the reverse, you have to use a special form of a C++ operator function, called a **conversin function**.
  Conversion fnctions are user-defined type casts, and you can use them the way you would use a type cast.
  To convert to type typeName, you use a conversion function in this form:
  ```C++
  operator typeName();
  ```
  Notes:
  - The conversion function must be a class method.
  - The conversion function must not specify a return type.
  - The conversion function must have no argurment.

- C++ provides the following type  conversions for classes:
  - A class constructor that has but a single argument server as an instruction for vonverting a value of the argument type to the class type.
  - A special class member oerator function called a **conversion function** serves as an instruction for converting a class object to some other type.
