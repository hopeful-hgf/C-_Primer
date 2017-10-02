# Chapter8 Adventures in Functions

## inline function

To use this feature, you must take at least one of two acions:

- Preface the function declaration with the keyword *inline*.
- Preface the function definition with the keyword *inline*.

A common practice is to omit the prototype and to place the entire definition where the prototype would normally go.

## Reference Variables

- It is necessary to initialize the reference when you declare it; you can't declare the reference and then assign it a value later. It is you can set a reference ty a initializing declaration, not by assignment.

- If you're using a reference, you should use a constant reference.

- When function using a basic numeric type, you should use passing by value rather than the more exotic passing by reference.

- If a function call aargument isn't an *lavlue* or does not match the type of the corresponding const reference parameter, C++ creates an anonymous variable of the correct type, assigns the value of the function call argument to the anonymous variable, and has the parameter refer to that variable.

  ​