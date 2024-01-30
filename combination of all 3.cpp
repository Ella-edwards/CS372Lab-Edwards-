// Ella Edwards
// 1/17/2024
// assinment 1


#include <iostream>
#include <string>

void Function(int size) {
   
    int* Pointer = new int[size];

    for (int i = 0; i < size; ++i) {
        Pointer[i] = i;
    }

    // second pointer to the same memory
    int* second = Pointer;

    delete[] Pointer;

    std::cout << "First ten integers pointed to with second pointer: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << second[i] << " ";
    }
    std::cout << std::endl;
}

void secondFunction(int size) {
    // Use new to allocate memory for another array of integers
    int* newPointer = new int[size];

    
    int* first = newPointer;
    int* second = newPointer;

    // delete first pointer
    delete[] first;

   
    std::cout << "Address of the second pointer: " << second << std::endl;

    
    std::cout << "First ten elements of the array referenced by the second pointer: ";
    for (int i = 0; i < 10; ++i) {
        std::cout << second[i] << " ";
    }
    std::cout << std::endl;
}

std::string* createStringOnHeap() {
    
    std::string* strPointer = new std::string("abcdefghijkl");

    return strPointer;
}

void printStringFromHeap() {
    
    std::string* stringPointer = createStringOnHeap();

    std::string str = *stringPointer;

    std::cout << "String from the heap: " << str << std::endl;

   //delete the dynamically allocated string
    delete stringPointer;
}

int main() {
   // question 1
    int arraySize = 1000;
    Function(arraySize);

    //question 2
    secondFunction(arraySize);

    // question 3
    printStringFromHeap();

    return 0;
}
