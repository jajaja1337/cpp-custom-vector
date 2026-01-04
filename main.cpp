#include <iostream>
#include "Vector.h"

int main() {
    // Construction examples
    Vector a {1.0, 2.0, 3.0};
    Vector b {4.0, 5.0, 6.0};

    std::cout << "Vector a: " << a << "\n";
    std::cout << "Vector b: " << b << "\n\n";

    // Arithmetic operations
    Vector sum  = a + b;
    Vector diff = a - b;
    Vector prod = a * b;

    std::cout << "a + b = " << sum  << "\n";
    std::cout << "a - b = " << diff << "\n";
    std::cout << "a * b = " << prod << "\n\n";

    // Dot product
    double dot = a.dot(b);
    std::cout << "Dot product (a · b) = " << dot << "\n\n";

    // Range-based loop using iterators
    std::cout << "Elements of (a + b): ";
    for (double x : sum) {
        std::cout << x << " ";
    }
    std::cout << "\n\n";

    // Copy and move semantics demonstration
    Vector copy = a;              // Copy constructor
    Vector moved = std::move(b);  // Move constructor

    std::cout << "Copy of a: " << copy << "\n";
    std::cout << "Moved-from b (contents undefined): " << moved << "\n";

    return 0;
}
