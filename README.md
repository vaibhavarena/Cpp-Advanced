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
* ##### info
```c++
v1.size()
v1.front()
v1.back()
```

* ##### index
```c++
v1[5]
v1.at(5)
```

* ##### insert
```c++
v1.insert(v1.begin() + 5, 42)
v1.insert(v1.begin(), {1, 2, 3, 4, 5})      Insert with initializer list
```

* ##### erase
```c++
v1.erase(v1.begin() + 5)
```

* ##### push_back
```c++
v1.push_back(3)    
```

* ##### pop_back
```c++
v1.pop_back()
```

* ##### empty
```c++
v1.empty()
```

* ##### clear
```c++
v1.clear()
```


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


___
#### list

Optimized for rapid insert and delete operation, and does not support random access.

Most functions remain same as vector(Refer 4.list_stl.cpp).


___
#### pair

Used when you want to carry multiple strongly typed values.
```c++
pair<int, string> p(23, "twenty three");

pair<int, string> p3;
p3 = make_pair(7, "seven");

cout << p3.first() << " " << p3.second() << endl;
```

___
#### tuple

Starting from C++ 11, we can use tuple as pair but can contain more than 2 values.

```c++
// Getting values
get<0>(t);
```

___
#### array

Available from C++ 11, fixed size sequence container.
```c++
array<string, 5> a1;

// data function - returns the pointer to underlying C-array
int *a = a1.data();
```

___
#### deque

Deque is optimized for push and pop, so it is default container for stacks and queues. It has random access and iterator capabilities.


___
#### queue

It is an wrapper adapter which takes another container to implement queue functionality(Optimized to be used with deque). It is not a random access container.


___
#### stack

Wrapper adapter like queue. Default underlying container is deque.


---
#### sets
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


___
#### Map
Provide sorted key-value pair. Each element in a map is a pair.

multimap allows duplicates and keys do not remain unique, indexing and at operator with multimap


## Iterator

An iterator is an STL object that can iterate through the elements of the container. It acts lot like a pointer. The iterator class is defined in the scope of the container class(vector<int>::iterator).

```c++
#include <iterator>     // For input and output iterator
#include <forward_list> // For forward iterator
#include <set>          // For bi directional iterator
#include <vector>       // For random iterator
```

#### Types of iterators:
- Input iterator
    - Capable of reading, but not writing
    - Incrementing but not decrementing
    - Once the value is read, cannot be read again

- Output iterator
    - Write a value once and increment

- Forward iterator
    - Combination of input and output iterator
    - Designed to be efficient for iterating from beginning to end, not vice versa

```A range based for loop, uses a forward iterator```

- Bi directional iterator
    - Set type uses bi directional iterator

- Random access iterator
    - Most complete of all iterators
    - Access any element in any position
    - Have all functionality of C pointer
    - Vector iterator will work here


## Transform function

Bulk transforms on elements of a container. These are found in <algorithm> header.

* Unary operator
```c++
transform(v1.begin(), v1.end(), v2.begin(), x)
```

Argument 1 and 2 are begin and end of container, 3rd is for output, 4th is object operator, its a unary function, its pointer to either function or object functor, that takes 1 argument.

* Binary operator
```c++
transform(v1.begin(), v1.end(), v2.begin(), v3.begin(), x)
```



## STL Functions

Functor is a class with an operator overload for the function called operator.

Definition : **"A function pointer allows a pointer to a function to be passed as a parameter to another function. Functors (Function Objects) in C++ allows the function call operator() to be overloaded. It allows instantiated object of a class to be called like a function."** 

```c++
#include<functionl>
```

* Arithmetic functors
```c++
plus<long> f;
minus<long> m;
multiplies<long> mul;
divides<long> div;
modulus<long> mod;
negate<long> neg;   // Unary functor
```

* Relational functors
```c++
greater<long> f;
less<long> l;
greater_equal<long> ge;
less_equal<long> le;
equal_to<long> e;
not_equal_to<long> ne;
```

* Logical functors
Give output like logical gates, you can use bool vectors of values filled with 0 or 1.

```c++
logical_or<bool> lo;    
logical_and<bool> la;
logical_not<bool> ln;   // Unary
```


## STL Algorithms

```c++
#include<algorithm>

sort(v1.begin(), v1.end());
binary_search(v1.begin(), v1.end(), n); // Returns bool
```

* Conditional algorithm

```c++
all_of(v1.begin(), v1.end(), is_prime<int>);    // is_prime is custom function
any_of(v1.begin(), v1.end(), is_prime<int>);    // (not in c++)
none_of(v1.begin(), v1.end(), is_prime<int>);
```

* Searching and counting

```c++
find(v1.begin(), v1.end(), 41);     // Returns an iterator if found, else returns end()
find_if(v1.begin(), v1.end(), is_odd<int>);         // Find first odd number
find_if_not(v1.begin(), v1.end(), is_odd<int>);     //Finds first even number
search(v1.begin(), v1.end(), v2.begin(), v2.end());  // Search for a sequence v2
count(v1.begin(), v1.end(), 7);    // Count occurences
count_if(v1.begin(), v1.end(), is_odd<int>);
```

* Replacing and Removing

```c++
replace(v1.begin(), v1.end(), 47, 99);
replace_if(v1.begin(), v1.end(), is_even<int>, 99);
remove(v1.begin(), v2.end(), 42);   // Returns iterator to last element in container that is not removed
unique(v1.begin(), v1.end());   // Removes consecutive duplicates
```

* Modifying algorithms

```c++
copy(v1.begin(), v1.end(), v2.begin());
copy_n(v1.begin(), 15, v2.begin());     // Copy n number of items - 15 here
copy_backward(v1.begin(), v1.end(), v2.end());      // Copies from back to front
reverse_copy(v1.begin(), v1.end(), v2.begin());     // Does same as copy_backward
reverse(v1.begin(), v1.end());      // Uses swap function to reverse
fill(v1.begin(), v1.end() - 10, 100);   // fill with n - 100 here
fill_n(v1.begin(), 10, 100);        // Fill n elements with num - 10 and 100 here
generate(v2.begin(), v2.end(), []()->int{ return rand() % 100; });  
random_shuffle(v1.begin(), v1.end());  // Shuffles elements in place, can provide lambda(Deprecated since C++ 17, alternative below)

// Alternative for random shuffle, requires random generator
#include <random>

random_device rd;
mt19937 g(rd());

shuffle(v1.begin(), v1.end(), g);
```

* Partitions

Take range of vector to be modified and use bool predicate function to parition

```c++
partition(v1.begin(), v1.end(), f);     // Moves no. with condition true to front
stable_partition(v1.begin, v1.end(), f); // Leaves elements in order, takes more time and memory
partition_copy(v1.begin(), v1.end(), v2.begin(), v3.begin());   // Partition in seperate containers
```


* Sort

```c++
template <typename T>
bool mycomp(const T & a, const T & b){
    return a > b;
}

sort(v1.begin(), v1.end(), mycomp);
stable_sort(v1.begin(), v1.end(), mycomp);
```