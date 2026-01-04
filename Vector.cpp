#include "Vector.h"
#include <vector>
#include <utility>



Vector::Vector(size_t rows, double initValue)
    : rows_(rows), data(nullptr)
{
    if (rows_ > 0) {
        data = new double[rows_];
        for (size_t i = 0; i < rows_; ++i) {
            data[i] = initValue;
        }
    }
}


Vector::Vector(size_t rows)
    : Vector(rows, 0.0)
{
}


Vector::Vector(std::initializer_list<double> l)
    : rows_(l.size()), data(nullptr)
{
    if (rows_ > 0) {
        data = new double[rows_];
        size_t i = 0;
        for (double value : l) {
            data[i++] = value;
        }
    }
}

// destructor
Vector::~Vector() {
    delete[] data;
}


// Copy constructor
Vector::Vector(const Vector& other)
    : rows_(other.rows_), data(nullptr)
{
    if (rows_ > 0) {
        data = new double[rows_];
        for (size_t i = 0; i < rows_; ++i) {
            data[i] = other.data[i];
        }
    }
}


// Move constructor
Vector::Vector(Vector&& other) noexcept
    : rows_(other.rows_), data(other.data)
{
    other.rows_ = 0;
    other.data = nullptr;
}


// Copy assignment operator
Vector& Vector::operator=(const Vector& other) {
    if (this != &other) {
        delete[] data;

        rows_ = other.rows_;
        data = nullptr;

        if (rows_ > 0) {
            data = new double[rows_];
            for (size_t i = 0; i < rows_; ++i) {
                data[i] = other.data[i];
            }
        }
    }
    return *this;
}


// Move assignment operator
Vector& Vector::operator=(Vector&& other) noexcept {
    if (this != &other) {
        delete[] data;

        rows_ = other.rows_;
        data = other.data;

        other.rows_ = 0;
        other.data = nullptr;
    }
    return *this;
}


void swap(Vector& a, Vector& b) {
    using std::swap;
    swap(a.rows_, b.rows_);
    swap(a.data, b.data);
}


bool Vector::operator==(const Vector& b) const {
    if (rows_ != b.rows_) {
        return false;
    }

    for (size_t i = 0; i < rows_; ++i) {
        if (data[i] != b.data[i]) {
            return false;
        }
    }
    return true;
}


bool Vector::operator!=(const Vector& b) const {
    return !(*this == b);
}


Vector& Vector::operator+=(const Vector& b) {
    assert(rows_ == b.rows_);

    for (size_t i = 0; i < rows_; ++i) {
        data[i] += b.data[i];
    }
    return *this;
}


Vector Vector::operator+(const Vector& b) const {
    Vector result(*this);
    result += b;
    return result;
}


Vector& Vector::operator-=(const Vector& b) {
    assert(rows_ == b.rows_);

    for (size_t i = 0; i < rows_; ++i) {
        data[i] -= b.data[i];
    }
    return *this;
}


Vector Vector::operator-(const Vector& b) const {
    Vector result(*this);
    result -= b;
    return result;
}


Vector Vector::operator*(const Vector& b) const {
    Vector result(*this);
    result *= b;
    return result;
}


Vector& Vector::operator*=(const Vector& b) {
    assert(rows_ == b.rows_);

    for (size_t i = 0; i < rows_; ++i) {
        data[i] *= b.data[i];
    }
    return *this;
}


// print matrixelements to stream
std::ostream& operator<<(std::ostream& outputStream, const Vector& m) {
    for (size_t i = 0; i < m.rows_; ++i) {
        outputStream << m.data[i];
        if (i + 1 < m.rows_) {
            outputStream << " ";
        }
    }
    return outputStream;
}


// read matrixelements from stream
std::istream& operator>>(std::istream& inputStream, Vector& m) {
    std::vector<double> temp;
    double value;

    while (inputStream >> value) {
        temp.push_back(value);
        if (inputStream.peek() == '\n') {
            break;
        }
    }

    if (temp.empty()) {
        throw std::runtime_error("Failed to read Vector");
    }

    delete[] m.data;
    m.rows_ = temp.size();
    m.data = new double[m.rows_];

    for (size_t i = 0; i < m.rows_; ++i) {
        m.data[i] = temp[i];
    }

    return inputStream;
}


double* Vector::begin() {
    return data;
}

double* Vector::end() {
    return data + rows_;
}

const double* Vector::begin() const {
    return data;
}

const double* Vector::end() const {
    return data + rows_;
}


size_t Vector::size() const {
    return rows_;
}

double Vector::dot(const Vector& b) const {
    assert(rows_ == b.rows_);

    size_t i = 0;
    return std::accumulate(begin(), end(), 0.0,
        [&b, &i](double sum, double value) {
            return sum + value * b.data[i++];
        }
    );
}

