#include <iostream>
#include <cstddef>

template <typename T, size_t Size>
class Array {
public:
    // Constructors
    Array();
    // Destructor
    ~Array();

    // Copy constructor
    Array(const Array& other);

    // Copy assignment operator
    Array& operator=(const Array& other);

    // Access elements using array index operator
    T& operator[](size_t index);
    const T& operator[](size_t index) const;

    // Size of the array
    size_t size() const;

    // Traverse and print array elements
    void traverse() const;

private:
    T arr[Size];
};

// Default constructor
template <typename T, size_t Size>
Array<T, Size>::Array() {
    // Default constructor initializes the array elements
    // This is not necessary as each element of the array will be initialized according to its type
}

// Destructor
template <typename T, size_t Size>
Array<T, Size>::~Array() {
    // No dynamic memory allocation, so nothing specific to delete
}

// Copy constructor
template <typename T, size_t Size>
Array<T, Size>::Array(const Array& other) {
    for (size_t i = 0; i < Size; ++i) {
        arr[i] = other.arr[i];
    }
}

// Copy assignment operator
template <typename T, size_t Size>
Array<T, Size>& Array<T, Size>::operator=(const Array& other) {
    if (this != &other) {
        for (size_t i = 0; i < Size; ++i) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

// Array index operator (non-const version)
template <typename T, size_t Size>
T& Array<T, Size>::operator[](size_t index) {
    if (index >= Size) {
        std::cerr << "Array::operator[]: Index out of bounds\n";
        exit(1);
    }
    return arr[index];
}

// Array index operator (const version)
template <typename T, size_t Size>
const T& Array<T, Size>::operator[](size_t index) const {
    if (index >= Size) {
        std::cerr << "Array::operator[]: Index out of bounds\n";
        exit(1);
    }
    return arr[index];
}

// Size of the array
template <typename T, size_t Size>
size_t Array<T, Size>::size() const {
    return Size;
}

// Traverse and print array elements
template <typename T, size_t Size>
void Array<T, Size>::traverse() const {
    std::cout << "Array: ";
    for (size_t i = 0; i < Size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Example usage of the Array class
    Array<int, 5> arr;

    for (size_t i = 0; i < arr.size(); ++i) {
        arr[i] = i * 10;
    }

    arr.traverse();

    return 0;
}
