# Chapter7 Functions: C++'s Programming Modules

## C++ palce an restriction on what types you can use for a return value: The return value cannot be an array. Everything else is possible.

## an example of fill array
```C++
int fill_array(double ar[], int limit)
{
    using namespace std;
  	double temp;
  	int i;
  	for (i = 0; i < limit; i++)
    {
        cout << "Enter value #" << (i+1) <<": ";
      	cin >> temp;
      	if (!cin)
        {
            cin.clear();
          	while (cin.get() != '\n')
              continue;
          	cout << "Bad input; input process terminated. \n";
          	break;
        }
      	else if (temp < 0)
          break;
      	ar[i] = temp;
    }
  return i;
}
```

Note that this code includes a prompt to the user. If the user enters a non-negative value, the value is assigned to the array. Otherwise, the loop terminates. If the user enters only valid values, the loop terminates after it read *limit* values.

## example

```C++
// arrfun.cpp -- array functions and const
#include <iostream>
const int Max = 5;

// function prototypes
int fill_array(double ar[], int limit);
void show_array(const double ar[], int n);
void revalue(double r, double ar[], int n);

int mian()
{
    using namespace std;
  	double properties[Max];
  
  	int size = fill_array(properties, Max);
  	show_array(properties, size);
  	if (size > 0)
    {
        cout << "Enter revaluation factor: ";
      	double factor;
      	while (!(cin >> factor))				// bad input
        {
            cin.clear();
          	while (cin.get() != '\n')
              continue;
          	cout << "Bad input; Please enter a number: ";
        }
      	revalue(factor, properties, size);
      	show_array(properties, size);
    }
  	cout << "Done. \n";
  	cin.get();
  	cin.get();
  	return 0;
}

int fill_array(double ar[], int limit)
{
    using namespace std;
  	double temp;
  	int i;
  	for (i = 0; i < limit; i++)
    {
        cout << "Enter value #" << (i+1) <<": ";
      	cin >> temp;
      	if (!cin)
        {
            cin.clear();
          	while (cin.get() != '\n')
              continue;
          	cout << "Bad input; input process terminated. \n";
          	break;
        }
      	else if (temp < 0)
          break;
      	ar[i] = temp;
    }
  return i;
}

// the following function can use, but not alter the array whose address is ar
void show_array(const double ar[], int n)
{
    using namespace std;
  	for (int i = 0; i < n; i++)
    {
        cout << "Property #" << (i + 1)<< ": $";
      	cout << ar[i] << endl;
    }
}

// mutiplies each element of ar[] by r
void revalue(double r, double ar[], int n)
{
    for (int i = 0; i < n; i++)
    	ar[i] *= r;
}
```

## Pointers and *const*

use the *const* keyword tow different ways with pointers:

- make a pointer point to a constant object, and that prevents you from using the pointer to change the pointed-to-value.

  ```C++
  int age = 39;
  const int * pt = &age;		// pt points to a const int
  ```

  This declaration for *pt* does't necessarily mean that the value it points to is really a constant; it just means the value is a constant insofar as pt is concerned. You can change the value directly bu using the *age* variable, but you can't change the value indirectly via the *pt*  pointer.

  You can assign the address of a reguar variable or a constant variable to a pointer-to-const, But you can only assign regular variable to a regular pointer.

  ```c++
  const float g_earth = 9.8;
  const float * pe = &g_earth;	// valid

  const float g_moon = 1.63;
  float * pm = &g_moon;	// invalid
  ```

  ​

- make the pointer itself constant, and prevents you from changing where the pointer points.

  ```C++
  double trouble = 2.0e40;
  double * const finger = &trouble;	// a const pointer to double
  ```

- if you want to declare a const pointer to a const object:

  ```C++
  int sloth = 2;
  const int * const ps = &sloth; 
  ```

  const pointer can only used to fundamental types, don't used to a pointer to a pointer.

## Function with Two-Dimensional arrays

- a function has a two-demensional array as an argument,

  ```C++
  int data[3][4] = {{1, 2, 3, 4}, {1, 2, 3, 4}, {2, 3, 4, 5}};
  int total = sum(data,3);

  // The appropriate prototypes would be:
  int sum(int (*ar2)[4], int size);
  int sum(int ar2[][4], int size);	// easier to read
  ```

## Function pointer basics

- Obtaining the addres of a function is simple: you just use the function name without trailing parentheses. If *think()* is a function, then *think* is the address of the function.

- Declaring a pointer to a function should provide the same information  about a function that a function prototype dose.

  ```C++
  double pam(int);		// prototype
  double (*pf)(int);		// pf points to a function that takes one int argument, 
  						// and that returntype double
  ```

  `*pf (int)` means *pf* is a function that returns a pointer, 

  `(*pf) (int)` means *pf* is a pointer to a function

- Pointer to function has to match the function both signature and return type.

- ```C++
  void estimate(int lines, double (*pf)(int));
  ```

  this declaration says the second argument is a pointer to a function that has an int argument and a double return value.

- Automatic type deduction works with a single initializer value, not an initialization list.