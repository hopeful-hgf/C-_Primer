# Chapter 3. Dealing with Data

- Names beginning with two underscore characters or with an underscore character followed by an uppercase letter are reserved for use by the implementation---that is, the compiler and the resources it uses. Names beginning with a single underscore character are reseved for use as global identifiers by the implementation.

  不要使用类似于```__varible ```和```_Ballnumber```这样的变量名。 


- *climits* header filecontains information about integer type limits. In particular, it defines symbolic names to represent different limits.

  | Symbolic Constant      | Represents                            |
  | ---------------------- | ------------------------------------- |
  | CHAR_BIT               | Nunber of bits in a char              |
  | CHAR_MAX   CHAR_MIN    | Maximum, minimum char value           |
  | SCHAR_MAX    SCHAR_MIN | Maximum, minimum signed char value    |
  | UCHAR_MAX              | Maximum unsigned char value           |
  | SHRT_MAX    SHRT_MIN   | Maximum, minimum short  value         |
  | USHRT_MAX              | Maximum unsigned short value          |
  | INT_MAX   INT_MIN      | Maximum, minimum int value            |
  | UINT_MAX               | Maximum unsigned int value            |
  | LONG_MAX   LONG_MIN    | Maximum, minimum long value           |
  | ULONG_MAX              | Maximum unsigned long value           |
  | LLONG_MAX   LLONG_MIN  | Maximum, minimum long long value      |
  | ULLONG_MAX             | Maximum unsigned long long char value |
  ​

- initialization 

  ```C++
  int year = 2017;	// we can do assignment with declaration 
  int year(2017);		// also like this way
  int year{2017};		// and this way (in C++11)
  int year={2017};	// and this way also right

  int zero{};		// set zero to 0
  int zero = {};	// also set zero to 0
  ```

- integer literals 字面量

  write integers in three defferent number bases:

  - base 10 (decimal): the first digit is in the range 1-9
  - base 8 (octal): the first digit is 0 and the second digit is in range 1-9
  - base 16(hexadecimal): the first two characters are 0x or 0X

- *iostream* manipulator to display numbers in octal or hexadecimal

  Like *iostream* header file provides the *endl* manipulator to give *cout* the message to start a new line, it provides *dec*, *hex*, and *oct* manipulator to give *cout* the message to dispaly integers in decimal, hexadecimal, and octal formats.

- Special suffix to indicate a particular type of integer 
  - *l* or *L* for long
  - *u* or *U* for unsigned
  - *ul* or any cobination of orders and uppercase and lowercase, indicates unsigned long constant
  - *ll* for long long and *ull* for unsigned long long
  - a hexadecimal literal constant like 0x4C50 will saved as an unsigned int, for hexadecimal is frequently used to express memory addreses, which intrinsically are unsigned.

- Escape sequence codes
  | Character Name  | ASCII Symbol | C++ code |
  | :-------------: | :----------: | :------: |
  |     Newline     |    NL(LF)    |    \n    |
  | Horizontal tab  |      HT      |    \t    |
  |  Vertical tab   |      VT      |    \v    |
  |    Backspace    |      BS      |    \b    |
  | Carriage return |      CR      |    \r    |
  |      Alert      |     BEL      |    \a    |
  |    Backslash    |      \       |    \\    |
  |  Question mark  |      ?       |    \?    |
  |  Single quote   |      '       |    \'    |
  |  Double quote   |      "       |    \"    |

- Universal Caracter  Name

  - *\u* followed by 8 hexadecimal digits. The digits represent the ISO 10646 code point for the character.
  - *\U* followed by 16 hexadecimal digits.

- **wchar_t** is a 16-bit type, can represent the largest extended character set used on system.

  The *cin* and *cout* family cosider input and output as consisiting of streams of *chars*, so they are not suitable for handling the *wchar_t* type. The *iostream* header provides parallel facilities in the form of *wcin* and *cout* for handling *wchar_t* streams.

  We can indicate a wide-character constant or string by receding it with an *L*.

  **New C++11 Type:** *char16* & *char32* 

- Float point type limits 

  we can look in the *cfloat*  or *float.h* header files.

- force output to stay in fixed-point notation

  ```C++
  std::cout.setf(ios_base::fixed, ios_base::floatfield);	//fixed-point
  ```

- Floalting-point constants
  By default, floating-point constants such as *8.34* and *2.4E8* are type *double*. If you want to a constant to be type *float*, you use a *f* or *F* suffix. For type *long double*, you use an *l* or *L* suffix.

- Classifying Data Types

  - integer
    - signed integer: signed char, short, int, long, long long
    - unsigned integer:
    - bool, char, wchar_t
  - floating-point
    - float, double, long double

- initializtion conversions when {} are used (C++11)

  a *list-initialization* is an initialization uses braces, this form can be used more generally to provide lists of values for more complicated data types. In particular, list-initializatin doesn't permit narrowing, which is when the type of the variable may not be able to represent the assigned value. For example, conversions of floating types to integer types are not allowed. Converting from integer types to other integer types or floating types may be allowed if the compiler can tell if the target variable can hold the value correctly.

  ```C++
  const int code = 66;
  int x = 66;
  char c1 { 23231};	// narrowing, not allowed
  char c2 = {66};		// allowed because char can hold 66
  char c3 {code};		// ditto
  char c4 = {x};		// not allowed, x is not a constant
  x = 23231;
  char c5 = x;		// allowed by this form of initialization
  ```

- Type casts

  ```C++
  (typeName) value 	// converts value to typeName type
  typeName (value)	// converts value to typeName type 
  ```

  The first form is straight C. the second is pure C++. Both form type cast donot alter the  value variable itself, it creates a new value of the indicated type.

  **static_cast<typeName>** operator can be used for converting vales form one numeric type to another.

  ```C++
  static_cast<typeName> (value);	// converts value to typeName type 
  ```

- Auto Decalarations in C++11

  C++11 introduces a facility that allows the compiler to deduce a type from type of an initializaion value.

  Automatic type deduction becomes much more useful when dealing with compliated types, such as those in STL. For example, C++98 might have this:

  ```C++
  std::vector<double> scores;
  std::vector<double>::iterator pv = scores.begin();
  ```

  C++11 allows you to write this instead:

  ```C++
  std::vector<double> scores;
  auto pv = scores.begin();
  ```

  ​

  ​