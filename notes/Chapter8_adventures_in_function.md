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

- If a function call argument isn't an *lavlue* or does not match the type of the corresponding const reference parameter, C++ creates an anonymous variable of the correct type, assigns the value of the function call argument to the anonymous variable, and has the parameter refer to that variable.

  ​

## using references with a structure

- We should avoid returning pointers to  temporary variables.

  ```C++
  const struct_a & clone2(struct_a & sa)
  {
      struct_a newsa;		// first step to big error
    	newsa = sa;			// copy info
    	return newsa;		// return reference to copy.
  }
  ```

  The simplest way to avoid this problem is to return a reference that was passed as an argument to the function. Or to use *new* to create new storage.

## guidelines of use a reference, point, or pass by value

#### A function uses passed data without modifying it

- If the data object is small, such as built-in data type or small structure, pass it by value
- If the data object is an array, use a pointer because that's your only choice. Make the pointer a pointer to const.
- If the data object is a good-sized structure, use a const pointer or a const reference to increase program efficiency. You save the time and sace needed to copy a structure or a class design. Make the pointer or reference const.
- If the data object is a class object, use a const reference. The semannics of class design often require using a reference, which is the main reason C++ add this feature. Thus, the standart way to pass class object arguments is by reference.

#### A function modifies data in the calling function:

- If the data object is buit-in data type, use a pointer. If you spot code like `fixit(&x)` ,  where x is an int, it's pretty clear that this function intends to modify x.
- If the data object is an array, use your only choice: a pointer.
- If the data object is a structure, use a reference or a pointer.
- If the data object is a class object, use a reference.

## Function Templates

```C++
// using a function template
#include <iostream>

// function template prototype
template <typename T>		// or class T
void Swap(T &a, T &b);

int main()
{
    using namespace std;
  	int i = 10;
  	int j = 20;
  	cout << "i, j = "<< i << ", " << j << ".\n";
  	cout << "Using compiler-generated in swapper: \n";
  	Swap(i,j);	 // generates void Swap(int &, int &)
  	cout << "Now i, j = " << i << ", " << j << ". \n";
  	
  	double x = 24.5;
  	double y = 81.3;
  	cout << "x, y = " << x << ", " << y << ". \n";
  	cout << "Using compiler-generated double swapper: \n";
  	Swap(x, y);			// generates void Swap(double &, double &)
  	cout << "Now x, y = " << x << ", " << y << ". \n";
  	return 0;
}

// function template definition 
template <typename T> 		// or calss T
void Swap(T &a, T &b)
{
    T temp;
  	temp = a;
  	a = b;
  	b = temp;
}
```

Function templates automate the process of overloading functions. You define a function by using a generic type and a particular algorithm, and the compiler generates appropriate function definitions for the particular argument types you used in the program.

It's easy to write a tempate functin that cannot handle certain types.

### Explicit Specializations

If the compiler finds a specialized definition that exactly matches a function call, it uses that definition without looking for templates.

```C++
struct job
{
    char name[40];
  	double salary;
  	int floor;
}

// template prototype
template <typename T>
void Swap(T &, T &);

// explicit specialization for the job type
template <>  void Swap<job>(job &a, job &b);
// The <job> in Swap<job> is optional, the prototype can also be written as
template <> void Swap(job &, job &);
```



Now C++ allows for explicit instantiation. That means you can instruct the compiler to create aparticular instantiation, for example, Swap<int>() directly, we just using the <> notation to indicate the type and prefixing the declaration with the keword *template*;

```C++
template void Swap<int>(int, int);		// explicit instantiation
```

The explicit specialization declaration has <> after the keyword template, whereas the explicit instantiation omits the <>.



## C++11 new feature

New keyword: *decltype*. It can be used in this way:

```C+++
int x;
decltype(x) y;			// make y the same type as x
decltype(x + y) xpy;	// make xpy the same type as x + y
```



Alternative function syntax

```C++
template<class T1, class T2>
?type? gt(T1 x, T2 y)
{
    ...
    return x + y;
}
```

We don't know in advance what type results from adding x and y. It might seem that we could use decltype(x + y) for the return type. Unfortunately, at that point in the code, the parameters x and y have not yet been declared, so they are not in scope. We can use *trailing return type* `-> decltype()` with the function definition:

```C++
template<class T1, class T2>
auto gt(T1 x, T2 y) -> decltype(x+y)
{
    return x + y;
}
```



