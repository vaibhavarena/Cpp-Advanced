## Introduction

* templating works like macros and substitute the code during compile time, but also does type checking

* typename and class can be interchangeable
```c++
template <typename T>
template <class T>
```

#### template variable
    Available from C++ 14
```c++
template <typename T>
T pi = T(3.1415926535897932385L);
```

* Impact on header files
Defining class templates and template implementation in different files, the linker will try to link them in different files, but the step will fail because the linker wouldn't know how to combine them. Solution(but not best practice), implement template functions in header file only.

#### decltype
    decltype(x) y;
    Derive data type from another variable to declare a variable.

* Template argument deduction
    In cases where the template can deduce the type of arguments for a template function, you don't need to specify those types.