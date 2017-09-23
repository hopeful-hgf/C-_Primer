# Chapter 5 Loops and Relational Expressions

- commo C++ style is to place a space between for and following parenthesis and to omit space between a function name and the following parenthesis

  ```C++
  for (int i = 7; i < 10; i++)
    smart_function(i);
  ```

- Normally, *cout* converts *bool* valuse to *int* befor dispalying them, but the *cout.setf(ios::boolalpha)* function call sets a flag that instructs *cout* to display the words *true* and *false* instead of *1* and *0*.

- For class, the prefix version of increment ++ is a bit more efficient than the postfix version.

- The prefix increament, prefix decrement, and dereferencing operators all have the same precedence and associate from right to left. 

  The postfix increment and decrement operators both have the same precedence, which is higher thean the prefix precedence. These two operators associate from left to right.

  The right-to-left association rule for prefix operators implies that `*++pt` means first apply `++` to `pt`, because the `++` is to the right of the `*`, and then apply `*` to the new value of `pt`.

  ```C++
  double x = * ++pt;		// increment pointer, take the value;
  ```

  On the other hand, `++*pt` means obtain the value that pt points to and then increment that value.

  ```C++
  x = *pt++;		// dereference original loacation, then increment pointer
  ```

  The higher precedence of the postfix `++` operator means the `++` operator operates on `pt`, not on `*pt`, so the pointer is incremented. But the fact that the postfix operator is used means that the address that gets dereferenced is the original address, not the new address.

- The comma operator `,` provide with two additional properties.

  - First, it guarantees that the first expression is evaluated before the second expression
  - Second, C++ states that the value of a comma expression is the value of the second part of the experession.
  - The comma opreator has the lowest precedence of any operator. For example, the statement:`cata = 17, 240;`  gets read as this: `(cata = 17), 240`

- Function `clock()`

  it returns the system time elapsed since a program started execution.

  - it doesn't necessarily return the time in seconds.
  - The function's return type might be long on some systems, unsigned long on others, and perhaps some other type on others.
  - The `ctime` header file provides solutions to these problems. First, it defines a symbolic constant, `CLOCKS_PER_SEC`, that equals the number of system time units per second. Second, `ctime` establishes `clock_t` as an alias for the `clock()` return type.

  ```C++
  // using clock() in a time-delay loop
  #include <iostream>
  #include <ctime>

  int main()
  {
      using namespace std;
    	cout << "Enter the delay time, in seconds: ";
    	float secs;
    	cin >> secs;
    	clock_t delay = secs * CLOCK_PER_SEC;	// convert to clock ticks
    	cout << "starting\a\n";
    	clock_t start = clock();
    	while(clock() - start < delay)
        ;
    	cout << "done \a\n";
    	return 0;
  }
  ```

- The Range-based for loop (C++11)

  it simplifies one common loop task---that of doing someting with each element of an array, or nore generally, of one of the container classes, such as vector or array.

  ```C++
  double prices[5] = {4.99, 10.99, 5.63, 7.99, 8.49};
  for (double x : prices)
    std::cout << x << std::endl;
  ```

  To modify array values, you need a diffrent syntax for the loop variable:

  ```C++
  for (double &x : prices)
    x = x * 0.8;
  ```

- Three distinct modes of single-character input

  - Unadorned *cin* for input 朴素的cin

    ```C++
    char cha;
    cin >> cha;
    ```

    *cin* skips over spaces and newline characters.

  - *cin.get(char)*

    reads the next character, even if it is a space.

    ```C++
    char name[40];
    cin.get(name,40);
    ```

  - The *cin.get()* member function with no arguments returns the next character form the input. (*cin.get(char)* returns an object, not the character read).

    if the *cin.get()* with no argument read a *EOF*, it returns EOF, value of *-1*, you must assign the return value to type int instead of to type char.

- The call *cin.eof()* returns the bool value *true* if the *EOF* has been detected. The *fail()* member function returns *true* if either the eofbit or the failbit has been set to 1.

- ```C++
  int mat[4][5];		// mat is an array with four elements
  					// each of the elements is an array of five integers
  ```

  ​
