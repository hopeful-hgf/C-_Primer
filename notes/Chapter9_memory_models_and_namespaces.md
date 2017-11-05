# Memory Models and Namespace

## Separate Compilation

we can divide the original program into three parts:

- A header file that  contains the structure declarations and prototypes for functions that use those structure
- A source code file that contains the code for the structure-related functionse
- A source code file that calls the structure reated functions

One header file, contains the definition of the user-defined types, a source code file contains the functions for manipulating the user-defined types.



**common things found in header file:**

- function prototype
- symbolic constants defined using *define* or *const*
- structure declaratin
- class declarations
- template declarations
- inline functions



## Storage duration, scope, and linkage

-  to create a static duration varible with external linkage, you declare it outside any block.
-  to create a static duration varible with internal linkage, you declaration it outside any block and use the static storage class modifier.
-  to create a static duration with no linkage, you declare it inside a block, using the static modifier.



C++ offering the scope-resolution operator *::* , when it is prefixed to the name of a variable, this opeator means to use the globle version of that varible.



When  *static* causes a local variable to have static storage duration, even though the variable is known within that block, it exists even while the block is inactive. Thus a static local variable can preserve it value between function calls. Static variables initialization once at the beginning, and retains its value between funcion calls.



### Storage Class Specifiers

- auto
- register
- static
- extern
- thread_local
- mutable

*nutable* can used to indicate that a particular member of a structure or class can be altered even if a particular structure varible is a const.

```C++
struct data
{
    char name[30];
  	mutable int accesses;
  	...
};
const data veep = {"Calisi Drogeen", 0, ...};
strcpy(veep.name, "Joy Joux");      // not allowed
veep.accesses++;                   // allowed
```



### Cv-Qualifiers

- const
- volatile

the internt of keyword *yoltaile* is to improve the otimization abilities of compilers.

> suppose the compiler notices that a program uses the value of a particular variable twice within a few statements. Rather than have the program kook up the value twice, the compiler might cache the value in a register. This optimization assumes that the value of the variable doesn't change between the two uses. If you don't declare a variable as *volatile* , the compiler can feel free to make this optimization. If you do declare a variable as *volatile* , you're telling the comiler not to make that sort of optimization.



A global variable has external linkage by default, a const global variable has internal linkage by default. To make a const have external linkage, you can use the *extern* key word to override the default internal linkage:

```C++
extern const int states = 50;      // definitaion with external linkage
```

You can also use the keyword *static* to give a function internal linkage, confining its use to a single file. You would apply this keyword to the prototype and to the function definition.

```C++
static int private(double x);
...

static int private(double x)
{
    ...
}
```

### initialization with the *new* operator

- creat and initialize storage for one of the scalar built-in types, we can do so by following the desired type with an initialization value enclosed in parentheses

  ```C++
  int *pi = new int (6);
  double * pd = new double (999.009);
  ```

  The parentheses syntax also can be used with classes having suitable constructor.

- To initialize an ordinary structure of an array, can use list-initialization using braces

  ```C++
  struct where {doulbe x; double y; double z;};

  where *one = new where {2.2, 5.2, 33.2};    // C++11
  int *ar = new int [4] {2, 4, 5, 6};    // C++11
  ```

- with C++11, we can also use the brace initalization for sigle-valued variables



### Placement *new* operator

Specify the location to be used when use the *new* operator.

1. include the *new* header file, which provides a prototypes for this version of *new*
2. use *new* with an argument that provides the intended address

```C++
#include <new>
struct chaff
{
    char dross[20];
  	int salg;
};
char buffer1[50];
char buffer2[500];
int main()
{
    chaff *p1, *p2;
    int *p3, *p4;
    // first the regular forms of new
  	p1 = new chaff;
    p3 = new int[20];
  
    // now, the two form of placement new
    p2 = new (buffer1) chaff;    // place structure in buffer1
    p4 = new (buffer2) int[20];  // place int array in buffer2
}
```

Placement *new* simply uses the address that is passed to it, it doesn't keep track of whether that location has already been used, and it dosen't search the block for unused memory.

The memory specified by *buffer* is static memory, can not use *delete* to free.

## Namespace

- Namespace can be located at the global level or inside other namespaces, but they cannot be placed in a block.

- a name declared in a namespace has external linkage by default.

- The *using* declaration lets you make particular identifiers available, and the using directive makes the entire namespace accessible

  ```c++
  using Jill::fetch;        // a using declaration
  using namespace Jack;     // a using directive
  ```

  When you use a using declaration, it is  as if the name is declared at the location of the using declaration. If a particular name is alltready declared in a function, you can't import the same name with a declaration.

  When you use a using directive, nmae reolution takes place as if you declared the names in the smallest declarative rigion containing both the using declaration and the namespace itself. If you use a using directive to import a name that is already declared in a function, the local name will hide the namespace name, just as it would hide a globle variable of the same name, you can still use the scope-resolution operator.

  Although a suing directive in a function treats the namespace names as being declared outside the function, it doesn't make those names available the ohter function in the file.

  ```C++
  namespace Jill
  {
      double ducket(double n){ ... }
    	double fetch;
    	struct Hill { ... };
  }
  char fetch;				// global namespace

  int main()
  {
      using namespace Jill;		// import all namespace names
    	Hill Thrill;				// create a type Jill::Hill structure
    	double water = bucket(2);	// using JiLL::bucket()
    	double fetch;				// hides Jill::fetch
    	cin >> fetch;
    	cin >> :: fetch;
    	cin >> Jill::fetch;
    	...
  }
  int foom()
  {
      Jill top;			// Error
    	Jill::Hill crest;	// valid
  }
  ```

- You can vereate an alias for a namespace.

  ```C++
  namespace my_very_favorite_things
  {
      ...
  }
  namespace mvft = my_very_favorite_things
  ```

  ​