# Chapter 12 Classes and Dynamic Memory Allocation

- A program create only one copy of a static class variable, regardless of the number of objects created. That is, a static menber is shared among all object of the class.

  ```C++
  // stringbad.h      -- flawed string class definition
  #include <iostream>
  #ifndef STRINGBAD_H_
  #define STRINGBAD_H_
  class StringBad
  {
  private:
      char * str;                // pointer to a string
	  int len;                   // length of string
	  static int num_strings;    // number of objects
  public:
      StringBad(const char * s); // constructor
	  StringBad();               // default constructor
	  ~StringBad();              // destructor
  // friend function
      friend std::ostream & operator<<(std::ostream & os, const StringBad & st)
  };
  #endif
  ```
  The implement:
  ```C++
  // stringbad.cpp     -- StringBad class methods
  #include <cstring>
  #include "stringbad.h"
  using std::cout;
  
  // initializing static clas member
  int StringBad::num_strings = 0;

  // class methods

  StringBad::StringBad(const char*s)
  {
	  len = std::strlen(s);
	  str = new char(len + 1);
	  std::strcpy(str, s);
	  num_strings++;
	  cout << num_strings << ": \"" << str
	       << "\" object created \n";
  }

  StringBad::StringBad()
  {
	  len = 4;
	  str = new char[4];
	  std::strcpy(str, "C++");
	  num_strings++;
	  cout << num_strings << ": \" << str
	       << "\" default object created \n";
  }

  StringBad::~StringBad()
  {
	  cout << "\"" << str << "\" object deleted, ";
	  --num_strings;
	  cout << num_strings << " lefts\n";
	  delete [] str;
  }

  std::ostream & operator<<(std::ostream & os, const StringBad & st)
  {
	  os << st.str;
	  return os;
  }
  ````

- Not that you cannot initialize a static member variabble inside the class declaration.
  You initialize the static member independently, with a separate statement outside the class declaration. That's because the static class member is stored separately rather than as part of an object.
  **Note that the initializatin statement gives the type and uses the scope operatot, but doesn't use the static keyword.**

- A static data member is declared in the declaration and is initialized in the file containing the class methods. However, if the static member is a *const* integral type or an enumeration type, it can be initialized in the class declaration itself.
- Whenever you use new in a constructor to allocate memory, you should use *delete* in the corresponding destructor to free that memory.

- C++ automatically provides the following member functions:
  - A default constructor is you define no constructors
  - A default destructor if you don't define one
  - A copy constructor if you don't define one
  - An assignment operator if you don't define one
  - A address operator if you don't define one

- Copy constructors is used during initialization, including passing function arguments by value and not during ordinary assignment. Normally it hass this prototype:
  ```C++
  class_name(const class_name &);
  ```
  A copy constructor is invoked whenever a new object is created and initialized to an existing object of the same kind.
  - when you explicitly initialize a new object to an existing object.
  - whenever a program generates copies of an object:
    - when a function passes an object by value
	- when a function returns an object
- If a class containe members that are pointer initialized by new, you should define a copy constructor that copies the pointed-to data instead of copying the pointers themselves.
- Assignment operator is implemented similar to that of the copy constructor, but there are some difference:
  - because the target object may already refer to previously allocated data, the function should use delete [] to free former obligations.
  - The function should protect against assigning an object to itself, otherwise, the freeing of memory described previously could erase the object's contents before they are reassigned.
  - The function returns a reference to the invoking object.

- The assignment operator is one of the operators that can be overloaded only by a class member function.

- the effect of using delete [] with any pointers initialized any other way is undefied.
  ```C++
  char words[15] = "bad idea";
  char * p1 = words;
  char * p2 = new char;
  char * p3;
  delete [] p1;                      // undefined, so don't do it
  delete [] p2;                      // undefined, so don't do it
  delete [] p3;                      // undefined, so don't do it

- C++ null pointer
  in C++98, you can use 0 or NULL to identy null pointer. In C++11 a new keyword *nullptr*, denote the null pointer.

- It's okay to apply the delete operation (with or without brackets) to the null pointer.

- If a method returns a local object, it should return an object, not a reference.
  If a method or function returns an object of a class for which there is no public copy constructor, such as the *ostream* class, it must return a reference to an object.
  some methods and functions, such as the overloaded assigment operator, can return either an object or a reference to an object, the reference is preferred for reasons of efficiency.

- A const can be initialized to a value, but it can't be assigned a value. Conceptually, calling a constructor creates an object before the code within the bracket is executed.
  If you want to initialize a const data member, you have to do so when the object is create befor executin reaches the body of the constructor. C++ provides a special syntax for doing just that. It's called a member initializer list, it cansists of a comma-separated list of initializers preceded by a colon. it's placed after the closing parenthesis of the argument list and vefor theopening bracket of the function body.
  ```C++
  Queue::Queue(int qs) : qsize(qs)            // initialize qsize to qs
  {
	  ...
  }
  ```
  Only constructors can use this initializer-list syntax.
  You have to use this syntax for const class members. You also have to use it for calss members that are declared as references:
  ```C++
  class Agency
  {
	  ...
  };

  class Agent
  {
  private:
      Agency & belong;      // must use initializer list to initialize
	  ...
  };

  Agent::Agent(Agency & a) : belong(a)
  {
	  ...
  }
  ```

- Member initializer list take palce when the object is created and before any code within the brackets is executed.
  - This form can be used only with constructors
  - You must(at least, in pre-C++11) use this form to initialize a nonstatic const data member.
  - You must use this form to initialize a reference data member.

- Date members are initialized in the order in which they appear in the class declaration, not in the order in which initializers are listed.
