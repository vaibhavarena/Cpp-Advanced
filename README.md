## Introduction

- templating works like macros and substitute the code during compile time, but also does type checking

- typename and class can be interchangeable
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