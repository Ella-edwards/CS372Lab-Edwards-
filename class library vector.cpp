

#include <iostream>

template <typename T>
class Vector {
public:
    Vector();
    ~Vector();

    void put(T data, int pos);
    void push_back(T data);
    T at(int index);
    int size();
    int capacity();
    void traverse();

private:
    T *arr;
    int vCapacity;
    int length;

    void expand(int newCapacity);
};

// Constructor
template <typename T>
Vector<T>::Vector() {
    arr = new T[1];
    vCapacity = 1;
    length = 0;
}

// Destructor
template <typename T>
Vector<T>::~Vector() {
    delete[] arr;
}

// push_back method
template <typename T>
void Vector<T>::push_back(T data) {
    if (length == vCapacity) {
        expand(2 * vCapacity);
    }
    arr[length] = data;
    length++;
}

// expand method
template <typename T>
void Vector<T>::expand(int newCapacity) {
    if (newCapacity > vCapacity) {
        T *temp = new T[newCapacity];
        for (int i = 0; i < length; i++) {
            temp[i] = arr[i];
        }
        delete[] arr;
        vCapacity = newCapacity;
        arr = temp;
    } else {
        std::cerr << "Vector::expand: new capacity is less than or equal to current\n";
    }
}

// put method
template <typename T>
void Vector<T>::put(T data, int pos) {
    if (pos == vCapacity) {
        push_back(data);
    } else if (pos >= 0 && pos < length) {
        arr[pos] = data;
    } else {
        std::cerr << "Vector::put: index out of bounds\n";
    }
}

// traverse method
template <typename T>
void Vector<T>::traverse() {
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// at method
template <typename T>
T Vector<T>::at(int index) {
    if (index >= 0 && index < length) {
        return arr[index];
    } else {
        std::cerr << "Vector::at: index out of bounds\n";
        exit(1);
    }
}

// size method
template <typename T>
int Vector<T>::size() {
    return length;
}

// capacity method
template <typename T>
int Vector<T>::capacity() {
    return vCapacity;
}

int main() {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);

    std::cout << "Vector size: " << v.size() << std::endl;
    std::cout << "Vector capacity: " << v.capacity() << std::endl;
    v.traverse();

    v.put(30, 0);
    std::cout << "Element at index 0: " << v.at(0) << std::endl;

    return 0;
}
