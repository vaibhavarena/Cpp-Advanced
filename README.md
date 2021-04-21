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


## Containers

They provide the commonly used data structures.

#### vector
---

* ##### info
    v1.size()
    v1.front()
    v1.back()

* ##### index
    v1[5]
    v1.at(5)

* ##### insert
    v1.insert(v1.begin() + 5, 42)
    v1.insert(v1.begin(), {1, 2, 3, 4, 5})      Insert with initializer list

* ##### erase
    v1.erase(v1.begin() + 5)

* ##### push_back
    v1.push_back(3)    

* ##### pop_back
    v1.pop_back()

* ##### empty
    v1.empty()

* ##### clear
    v1.clear()


* ##### constructors
    * ##### from C-array
    ```c++
        constexpr size_t size = 10;
        int ia[size] = {1, 2, 3, 4, 5};
        vector<int> v2(ia, ia + size);
    ```

    * ##### filled with strings
    ```c++
        vector<string> v3(5, "string");
    ```

    * ##### copy constructor
    ```c++
        vector<string> v4(v3);
    ```

    * ##### move constructor
    ```c++
        vector<string> v5(std::move(v4));
    ```

#### list
===

Optimized for rapid insert and delete operation, and does not support random access.

Most functions remain same as vector(Refer 4.list_stl.cpp).

#### __pair__

Used when you want to carry multiple strongly typed values.
```c++
pair<int, string> p(23, "twenty three");

pair<int, string> p3;
p3 = make_pair(7, "seven");

cout << p3.first() << " " << p3.second() << endl;
```

#### __tuple__

Starting from C++ 11, we can use tuple as pair but can contain more than 2 values.

```c++
// Getting values
get<0>(t);
```

#### __array__

Available from C++ 11, fixed size sequence container.
```c++
array<string, 5> a1;

// data function - returns the pointer to underlying C-array
int *a = a1.data();
```

#### __deque__

Deque is optimized for push and pop, so it is default container for stacks and queues. It has random access and iterator capabilities.

#### __queue__

It is an wrapper adapter which takes another container to implement queue functionality(Optimized to be used with deque). It is not a random access container.

#### __stack__

Wrapper adapter like queue. Default underlying container is deque.

#### __sets__
set - does not duplicate copies
multiset - allows duplicates

Will arrange elements as in Red black trees(set and multiset). Will print elements in sorted order.

The insert method returns a pair(set and unordered_set), the first element is the iterator to new element, or the duplicate element which prevented its insert, the second element is true or false.

```c++
set<string> s1 = {"one", "two", "three", "four", "five"};

auto r = s1.insert("five");

if(!r.second)
    cout << "Insert failed";
```
