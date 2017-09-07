# Chapter 2: Setting Out to C++

## Creating a C++ program

```C++
// myfirst.cpp == displays a message

#include <iostream>
int main()						// function header
{
	using namespace std;
	cout<< "Come up and C++ me some time.";
	cout<< endl;
	cout<< "You won't regret it!"<<endl;
	return 0;
}							// function definition
```

## The general forat for a C++ program

- Comments, indecated by the // prefix
- Apreprocessor *#include* directive
- A function header: *int main()*
- A *using namespace * directive
- A function body, delimited by *{* and *}*
- Statements
- A return statement to terminate the *main()* function 


## The *#include* directive

- Header file naming conventions:

  | Kind of header |         Convention          |  Example   |                 comments                 |
  | :------------: | :-------------------------: | :--------: | :--------------------------------------: |
  |  C old style   |             *.h             |   math.h   |       usable by C and C++ programs       |
  | C++ old style  |             *.h             | iostream.h |          usable by C++ programs          |
  | C++ new style  |        No extension         |  iostream  | usable by C++ programs, use namespace std |
  |  Converted C   | c prefix, no extension (c*) |   cmath    | usable by C++ programs, might use non-C features, |

- place functions prototype ahead of where you first use the function, so we could take *include* before *main()*

- ```C++
  using namespace std;	// above the function definitions
  ```

  ```c++
  using namespace std; 	// in a specific function definition
  ```

  ```C++
  using std::cout;	//in a specific fuction definition make a paricular element available to the function
  ```

  ```C++
  std::cout<< "example " 	//use the std:: prefix whenever you use elements from the std namespace
  ```

  ​


## The *main()* function

when you run a C++ program, execution always begins at the beginning of *main()*

## Using the *cout* objext for output

## Placing comments in a C++ program

## How and when to use *endl*

```C++
cout << "\n";
cout << endl;
```

- **\n**  is a newline character, means start a new line.  used as an embedded character.(嵌入式)
- **endl**  is a manipulator, to start a new line in the iostream.
- One difference is that *endl* guarantees the output will be flushed before the program moves on, but the "\n" dosen't.



## Declaring and using variables

## Using the *cin* object for input

## Defining and using simple functions
