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

- ​