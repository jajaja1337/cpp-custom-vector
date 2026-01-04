<p align="center">
  <img src="banner.svg" width="100%">
</p>

# Custom C++ Vector Class
A clean implementation of a dynamic Vector type in C++, showcasing memory management, operator overloading, and modern class design.

## Overview
This project implements a custom Vector class in C++ with full support for copying, moving, arithmetic operations, iteration, and stream input/output.  
It demonstrates essential low-level and high-level C++ concepts while maintaining a simple and readable interface.

The class provides:
- Dynamic memory management via `new[]` and `delete[]`
- Full Rule of Five implementation (copy/move constructor and assignment)
- Operator overloading for arithmetic and comparison
- Stream operators for input (`>>`) and output (`<<`)
- Iterators (`begin()`, `end()`) for range-based for loops
- Support for brace initialization via `std::initializer_list`
- A dot product implementation using `std::accumulate` and lambdas

---

## Implemented Features

### Rule of Five
The Vector class correctly manages dynamic memory and defines all five special member functions:

- `Vector(const Vector&)` – Copy constructor  
- `Vector(Vector&&) noexcept` – Move constructor  
- `Vector& operator=(const Vector&)` – Copy assignment  
- `Vector& operator=(Vector&&) noexcept` – Move assignment  
- `~Vector()` – Destructor  

These ensure proper resource ownership, deep copying, and efficient moves.

---

### Arithmetic and Comparison Operators
The Vector supports element-wise operations and logical comparisons:

- `+` and `+=`  
- `-` and `-=`  
- `*` and `*=`  
- `==` and `!=`  

Each operator asserts that both vectors have equal size.

Example:

```cpp
Vector a {1, 2, 3};
Vector b {4, 5, 6};

Vector c = a + b; // element-wise addition
```

---

## Iterators
The class implements:

- `begin()`  
- `end()`  

allowing usage with range-based loops:

```cpp
for (double x : a) {
    std::cout << x << " ";
}
```

---

## Stream Operators
Human-readable output and safe input loading are supported through:

```cpp
std::ostream& operator<<(std::ostream&, const Vector&);
std::istream& operator>>(std::istream&, Vector&);
```

Example:

```cpp
Vector v {1, 2, 3};
std::cout << v << std::endl;
```

The input operator reads space-separated values and automatically resizes the vector.

---

## Dot Product
Implemented using `std::accumulate` with a lambda:

```cpp
double result = a.dot(b);
```

Formula:

```
sum(a[i] * b[i])
```

---

## Initializer List Constructor
The Vector supports brace initialization:

```cpp
Vector v {1.0, 2.0, 3.0, 4.0};
```

This makes the API intuitive and modern.

---

## Example Usage

```cpp
#include "Vector.h"
#include <iostream>

int main() {
    Vector a {1.0, 2.0, 3.0};
    Vector b {4.0, 5.0, 6.0};

    Vector sum = a + b;
    Vector diff = a - b;
    Vector prod = a * b;

    std::cout << "Sum: " << sum << "\n";
    std::cout << "Dot product: " << a.dot(b) << "\n";

    for (double value : sum) {
        std::cout << value << " ";
    }

    return 0;
}
```

---

## Purpose of This Project
This Vector implementation demonstrates core C++ competencies:

- Manual memory management  
- Correct use of move semantics  
- Resource ownership and the Rule of Five  
- Operator overloading and API design  
- Clean class separation via header and implementation files  
- Safe and modern C++ patterns  
- Integration with STL algorithms and range-based loops  

It is suitable for:
- University assignments  
- Portfolio showcasing  
- Teaching examples  
- A foundation for more advanced numerical libraries  

