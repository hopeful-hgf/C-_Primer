# Chapter 10 Objects and Classes

- Typically, C++ programmers place the interface, ti the form of a class definition, in a header file and place the implementation, in the form of code for the class methods, in a source code file.
- Member function definitions can have return types and arguments, But they also have two special characteristics:
  - When you define a member function, you use the scope-resolution operator:: to identify the class to which the function belongs.
  - Class methods can access the private components of the class.
- Any function with a definition in the class declaration automatically becomes an inlline funciton. If you like define a member fuction outside the class declaration and still make it inline, you just use the inline qualifier when you define the function in the class implementation.
- The special rules for inline functions require that they be vefined in each file in which they are used.
- C++ provides two way to initalize an object by using a constructor.
  - to call the constructor explicitly
  ```C++
  Stock food = Stock("World Cabbage", 350, 1.25);
  ```
  - to call the constructor implicitly
  ```C++
  Stock garment("Furry Mason", 59, 2.65);
  ```
- The compiler provide one default constructor only if you don't define any constructors, after you define any constructor for a class, ther responsibility for providing a default constructor for that class passes from the compiler to you.
- Destructor has a special name: it is formed formthe class name preceded by a tilde ~. A destructor can have no return value and has not declared type. Unlike a constructor, a destructor must have nor arguments.
- When you assign one object to anothe of the same class, by default C++ copies the contents of each data member of the source object to the corresponding data member of the target object.
- With C++11, you can use the list-initialization syntax, using the brace contents match the arument list of a constructor;
  ```C++
  Stock hot_tip = {"Derivative plus plus", 100, 45.0};
  Stock jeck {"Sport Age Sorage, inc"};
  Stock temp{};
  ```
- C++11 offers a class called `std::initializer_list`, that can be used as type for a fucntion or method parameter. This class can represent a list of arbitrary length, providing all hte entries are of the same type or can be converted to the same type.
- const Member function  the function promise mot to modify the invoking object, to place the const keyword after the function parentheses.
  ```C++
  void show() const;			// promises not to change invoking object
  ```
- return constant reference object
  ```C++
  const Stock & topval(const Stock & s) const;
  ```
  This function accesses one object implicitly and one boject explicitly, and it returns a reference to one of those two objects.
  The const in parentheses states that fhe function won't modify the explicitly accessed object, and the const that follows the parentheses states that the function won't modify the implicitly accessed object. **Because the function returns a reference to one of the two const objects, the return type also has to be a const reference.**
- If a method needs to refer to the invoking object as a whole, it can use the expression *this.
  Using the const qualifier after the function argument parenthese qualifies this as being a pointer to const, in that case you cannot use this to change the objecct's value.
- Class Scope cosntants
  ```C++
  class Bakery
  {
  private:
      const int Moths = 12;         // declare a constant? FAILS
	  double costs[Months];
	  ...
  }
  This won't work because declarig a class describes what an object looks like but doesn't create an object. **Hence, untilll you create an object, there's no place to store a value.** (actually, C++11 provides for member initializaion, but not in a way that would make the preceding array declaration work)
  There are a couple ways to achieve essentially the same desired effect:
  - you can declare an enumeration within a class
  ```C++
  class Bakery
  {
  private:
	  enum {Months = 12};
	  double costs[Months];
	  ...
  }
  ```
  - defining a constant within a class kusing the key word static
  ```C++
  class Bakery
  {
  private:
      static const int Months = 12;
	  double costs[Months];
	  ...
  }
  ```
- Traditional enumerations has some problems. one is that enumerators from two different enum definitions con conflict.
  ```C++
  enum egg { Small, Medium, Large, Jumbo};
  enum t_shirt {Small, Medium, Large, Xlarge};
  ```
  The egg Small and the t_shirt would both be in the same scope, and the names conflict.
  C++11 provides a new form of enumeration that avoids this problem by having class scope for its enumerators
  ```C++
  enum class egg {Small, Medium, Large, Jumbo};
  enum class t_shirt Small, Medium, Large, Xlarge};
  ```
  Alternatively, you can use the keyword struct in instead of class. In either case, you now need to use the enum name to qualify the enumerator.
- Regular enumerations get converted to integer types automatically tin some situations. such as assignment to an int variable or being used in a compariason expression, but scoped enumerations have no implicit conversions to integer types.
