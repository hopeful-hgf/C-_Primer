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

  ​

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
    - float, double, long double​