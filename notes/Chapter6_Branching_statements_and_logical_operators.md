# Chapter6 Branching statements and logical operators

## The *cctype* library of character functions

| Function name | Return value                             |
| ------------- | ---------------------------------------- |
| isalnum()     | is a letter or a digit                   |
| is alpha(0)   | is alphabetic                            |
| isblank()     | space or a horizontal tab                |
| iscntrl()     | is a contol character                    |
| isdigit()     | is a decimal digit (0-9)                 |
| isgraph()     | is any printing character other than a space |
| islower()     | is a lowercase letter                    |
| isupper(0)    | is an uppercase letter                   |
| isprint()     | is any printing character, including a spac |
| ispunct()     | is a punctuation character               |
| isspace()     | space, formfeed, newline, carriage return, horizontal tab, vertical tab |
| isxdigit()    | is a hexadecimal digit character (0-9, a-f, or A-F) |
| tolower()     |                                          |
| toupper()     |                                          |

## reset *cin* befor getting rid of the bad input

```C++
// non-numeric input skipped 
#include <iostream>
const int Max = 5;
int main()
{
	using namespace std;
  	int golf[Max];
  	cout << "Please enter your golf scores.\n";
  	cout << "You mast enter " << Max << " rounds.\n";
  	int i;
  	for (i = 0; i < Max; i++)
    {
        cout << "round #" << i+1 << ": ";
      	while (!(cin >> golf[i])){
            cin.clear();
          	while (cin.get() != '\n')
              continue;
          	cout << "Please enter a number: ";
        }
    }
	
  	double total = 0.0;
  	for (double x: golf)
      total += x;
  	cout << total / Max << " = average score "
      << Max << " roundes\n";
  	return 0;
}
```



## The *exit()* function 

is prototyped in the *cstdlib* headfile, which also defines *EXIT_FAILURS* as an argument value used to communicate with the operating system.

