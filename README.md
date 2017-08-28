for the book C++ Primer
=======================

##2017/08/28 sizeof gcc/clang compiler

in the `thesizes.cxx` implement, we get the sizes of datatypes of char, short, int, long, float, bouble and void*. Compiled with gcc and clang complier. 
> gcc编译的结果是
> ```char 1, short 2, int 4, long 4, float 8, double 4, void* 2130567168```
> clang编译的结果是
> ```char 1, short 2, int 4, long 4, float 8, double 8, void* 5361642412```

> 两个问题：
> 1. gcc double 比 float 所用的空间更小，精度也应该更低
> 2. 两个编译器得到的 指针类型的大小到底是几个字节

