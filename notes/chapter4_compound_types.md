# Chapter 4 Compound Types

- If you use the *sizeof* operator returns the size of a type or data object. Note that if you use the *sizeof* operator with an array name, you get the number of bytes in the whole array. But if you use sizeof with an array element, you get the size of the element.

- If you partially initialize an array, the comiler sets the remaining elements to zero.

- Array use list-initialization in C++11

  - you can drop the *=* sign when initializing an array

    ```C++
    double earnings[4] {33.2, 45.0, 1.3e2, 3432.0};
    ```

  - you can use empty braces to set all the elements to 0:

    ```C++
    int counts[100] {};
    float balances [99] {};
    ```

  - list-initialization protects against narrowing.

- C-style string: the last character of every string is the null character.

  - initialize a character array to a string.

    ```C++
    char bird[11] = "Mr. Cheeps";			// the \0 is uderstood
    char fish[] = "Bubbles";				// let the compiler count
    ```

  - *strlen()* can used to get the length of a string. The standard *cstring* header provides declarations for this and many other string-related functions.

- Adventures in string input

  - The *cin* technique is to use whitespace----spaces, tabs, and newlines to deline                 ate a string. This means *cin* reads just one word when it gets input for a character array.

  - *cin.getline()* and *cin.get()* both read an entire input line----up until a newline character. However, *getline()* the discards the newline character, whereas *get()* leaves it in the input queue.

    - `cin.getline(name,20);`

      the first arument is the name of the target----the array destined to hole the line of input. 

      the second argument is a limit on the number of characters to be read. If this limit is 20, the function read no more than 19 characters, leaving room to automatically add the null character at the end.

      it reads input through the newline character mrking the end of the line, but it doesn't save the newline character, instead, it replaces it with a null character when storing the string.

    - `cin.get(name,20);`

      in this varant, *get()* takes the same arguments, interprets them the same way, and reads to the end of a line. But leaves that character in the input queue.

      This means, the *cin.get()* may get a nothing when the last one's newline character in the input queue.

      We can read two line like this:

      ```C++
      cin.get(name,20);			// read first line
      cin.get();					// read newline
      cin.get(dessert,20);		// read second line
      ```

      Because the *cin.get()* return a *cin* object, so we can use *cin.get()* like follow:

      ```C++
      cin.get(name,20).get();		//concatenate member functions
      cin.get(dessert,20);		
      ```

- the **string** class

  The *string* class is simpler to use than the array and also provids a trueer representation of a string as a type.

  - to use the *string* class, a programe has to include the *string* header file. The *string* class is part of the *std* namespace.

  - You cannot simply assign one array to another, But you can assign one string abject to another.

    ```C++
    char charr1 [20];				
    char charr2 [20] = "jaguar";
    string str1;
    string str2 = "panther";
    charr1 = charr2;			// invalid, no array assignment
    str1 = str2;				// Valid, object assignment ok
    ```

  - The *string* class simplifies combining strings. you can use the + operator to add two string object together and the += operator to tack on a string to the end of an existing string object.

  - `sting str1= "a string"` The length of str1 is `int len = str1.size();`

  - to get an input line to a C-style string `char charr[30]`, we use `cin.getline(charr,30);`,

    to get an input line to a string object `string str`, we use `getline(cin,str);`

  - C++ use the `L, u, U` prefixes, respactively, for string literals of *wchar_t*, *char16_t*, *char32_t*.

  - **Raw String**, characters simply stand for themselves. The raw strings use `"(` and `)"` as delimiters, and they use an `R` prefix to identify them as raw strings. And you can place additional characters between the openning `"` and `(` , and the same characters between the final `)` and `"` 

    ```C++
    R"( Jim "king" Tutt uses "\n " instead of endl.)";
    R"++"("(is this ok)", may be.)++"";
    ```

- we can use assignment operator `=` to assign one structure to another of the same type, it's called *memberwise assigment*.

- **union** used to save memory space, the size of the union is the size of its largest member.

- **enum** provides an alternative to *const* for creating symbolic constants.

  - The only valid values that you can assign to an enumeration variable without a type cast are the enumerator values used in defining the type.

  - Only the assignment operator is defined for enumerations. In particular, arithmetic operations are not fefined.

  - enumerator are of integer type and can be promoted to type int, but int types are not converted automaticall to the enumeration type.

    You can assign an int value to an enum, provided that the value is valid and that you use an explicit type cast.

  - You can set enumerator values explicitly by using the assignment operator, and you can create more than one enumerator with the same value.

  - Each enumeration has a range, and you can assign any integer value in the range, even if it's not an enumerator value, by using a type cast to an enumeration variable.

    The range of enum, the upper lmit is up to the smallest power of two greater than the largest value of the enumeration. and the lower limit : if the smallest enumerator is 0 or greater, it's 0; if the smallest enumerator is negative, use the same approach as for finding the upper limit but toss in a minus sign.

- **address operator**  *&*  、**dereferencing operator** *\**

  - You need an * for each pointer variable name

    ```C++
    int * p1, p2;
    ```

    That declaration creates one pointer p1, and ordinary int p2.

    - Pointer are based on other types, like arrays. It always point to a specific type. `double * pb` pb is type pointer-to-double, `char * pc` is type point-to-char.

    - You can use a declaration statement to initialize a pointer, in that case, the pointer, not the pointed-to value, is initialized.

      ```C++
      int higgens = 9;
      int * pt = &higgens;
      ```

      The statements set pt and not *pt the value &higens.

    - We can't simply assign an integer to a pointer. If you want to use a numeric value asan address, you should use a type cast to vonvert the number to  the appropriate address type.

      ```C++
      int * pt;
      pt = 0xB7235678;			// We cannot do this, -- type mismatch
      pt = (int *) 0xB7235678;	// we can do like this ,-- types now match
      ```

    - We should allways balance a use of *new* with a use of *delete*, We should not  attempt to free a block of memory tha we have previously freed, also  we cannot use *delete* to free memory created by declaring ordinary variables.

      ```C++
      int * pt = new int; 		// ok
      delete pt;					// ok
      delete pt;					// not ok now
      int jugs = 5;
      int * pi = &jugs;
      delete pi;					// not allowed, memory not allocated by new
      ```

    - Creating a Dynamic Array with *new*

      ```C++
      int * pia = new int [10];		// get a block of 10 ints
      delete [] pia;					// free a dynamic array
      ```

      It's your responsibility to keep tack of how many elements are in the block.

    - you can't change the value of an array name, but a pointer is a variable, hence you can change its value.

      ```C++
      #include <iostream>
      int main()
      {
        using namespace std;
        double * pd = new double [3];
        pd[0] = 0.4;
        pd[1] = 0.5;
        pd[2] = 0.6;
        
        cout << "pd[1] is "<< pd[1] <<".\n";
        pd = pd+1;
        cout<< "Now pd[1] is "<< pd[1] <<".\n";
        pd = pd -1;
        delete [] pd;
        return 0;
      }
      ```

    - In genreal, wherever you use array `arrayname[i]` becomes `* (arrayname + i)`

    - Applying the *sizeof* operator to an array name yields the size of the array, but applying *sizeof* to a pointer yields the size of the pointer, even if the pointer points to an array.

    - The name of the array is interpreted as the address of the first element of the array , whereas applying the address operator yields the address of the whole array.

      ```C++
      short tell[10];
      cout <<tell << endl;		// display &tell[0]
      cout << &tell << endl; 		// display address of whole array
      ```

      *tell* is type pointer to a *short*, or a *short \**, and *&tell* is type pointer to an array of 20 shorts, or *(\*)[20]* . *tell +1* and 2 to rhe address value, whereas *&tell +1* add 20 to the address value.

    - ```C++
      short (*pas) [20] = &tell;		// pas points to array of 20 shorts
      short * pas [20];				// pas is an array of 20 points-to-short
      ```

    - `const char * brid = "wren";` string literals are constants, which is why the code use the *const* keyword in the declaration. Using *const* in this fashion means you can use *brid* to access the string but not to change it.

    - Normally, if you give cout a pointer, itprints an address. But if the pointer is type *char \**, cout displays the pointed-to string. If you want to see the address of the string, you have to type cast the pointer to another pointer type,shach as *int \**.

    - The *vector* Template class

      ```C++
      #include <vector>
      using namespace std;
      vector<int> vi;				// Create a zero-size array of int
      int n;
      cin>>n;
      vector<double> vd(n);		// create an array of n doubles
      ```

    - The *array* Template Class

      C++11 add the array template class, which is part of the std namespace. Like the built-in type, an array object has a fixed size and uses the stack(or else static memory allocation) instead of  the free store, so it shares the efficiency of built-in array.
      ```C++
      #include <array>
      using namespace std;
      array<int,5> ai;				// Create an array of 5 ints
      array<double,4> ad = {1.2, 2.3, 3.4, 4.5};		// create an array of 4 doubles
      ```
      `array<typeName, n_elem> arr;` this declaration dreates an array object arr with n_elem elements of typeName. The n_elem can't be a variable.

    - Comparing Arrays, *vector* Object, and *array* objects

      1. whether we use a built-in array, a vector object, or an array object, we can use the standard array notation to access individual members.
      2. array objects use the same region of memory as the built-in array, whereas the vector object is stored in a different region.
      3. you can assign an array object to another array object. for built-in arrays, you have to copy the data element-by-element.