<p align="center">
  <img src="banner.svg" width="100%">
</p>

# Custom C++ Vector Class
A clean implementation of a dynamic Vector type in C++, showcasing memory management, operator overloading, and modern class design.

## Overview
This project implements a custom Vector class in C++ with full support for copying, moving, arithmetic operations, iteration, and stream input/output. It demonstrates essential low-level and high-level C++ concepts while maintaining a simple and readable interface.

The class provides:
- Dynamic memory management via `new[]` and `delete[]`
- Full Rule of Five implementation (copy/move constructor and assignment)
- Operator overloading for arithmetic and comparison
- Stream operators for input and output
- Iterators (`begin()`, `end()`) for range-based for loops
- Support for brace initialization using `std::initializer_list`
- A dot product implementation using `std::accumulate` and lambdas

## Implemented Features

### Memory Management
The Vector handles its own memory and performs deep copies. Move semantics ensure efficient resource transfer without unnecessary allocations.

### Rule of Five
The class defines:
- `Vector(const Vector&)` – Copy constructor  
- `Vector(Vector&&) noexcept` – Move constructor  
- `operator=` copy assignment  
- `operator=` move assignment  
- `~Vector()` destructor  

This guarantees correct management of dynamic resources.

### Arithmetic Operators
The Vector supports element-wise operations:

- `+` and `+=`
- `-` and `-=`
- `*` and `*=`
- `==` and `!=`

Each operator internally checks for size compatibility.

### Iterators
The class provides:

- `begin()`  
- `end()`  

allowing usage like:

```cpp
for (double x : v) { /* ... */ }
