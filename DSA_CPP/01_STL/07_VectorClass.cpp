#include <iostream>
using namespace std;

template <typename T>
class Vector {
private:
    T* ptr;
    size_t size;
    size_t capacity;

public:
    Vector() : ptr(nullptr), size(0), capacity(1) {
        ptr = new T[capacity];
    }

    ~Vector() {
        delete[] ptr;
    }

    void push_back(const T& value) {
        if (size == capacity) {
            // double the capacity and copy the elements to new array. Deallocate the previous array.
            capacity = 2 * capacity;
            T* newPtr = new T[capacity];

            for (size_t i = 0; i < size; ++i) {
                newPtr[i] = ptr[i];
            }

            delete[] ptr;
            ptr = newPtr;
        }

        ptr[size++] = value;
    }

    void pop_back() {
        if (size > 0) {
            size--;
        }
    }

    void clear() {
        size = 0;
    }

    size_t getSize() {
        return size;
    }

    size_t getCapacity() {
        return capacity;
    }

    bool isEmpty() {
        return size == 0;
    }

    const T& at(size_t index) const {
        if (index >= size) {
            throw out_of_range("Index out of range");
        }
        return ptr[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size) {
            throw out_of_range("Index out of range");
        }
        return ptr[index];
    }
};

int main() {
    Vector<int> v;
    v.push_back(10);
    cout << "size : " << v.getSize() << " and capacity : " << v.getCapacity() << endl;
    v.push_back(20);
    cout << "size : " << v.getSize() << " and capacity : " << v.getCapacity() << endl;
    v.push_back(30);
    cout << "size : " << v.getSize() << " and capacity : " << v.getCapacity() << endl;
    v.push_back(40);
    cout << "size : " << v.getSize() << " and capacity : " << v.getCapacity() << endl;
    v.push_back(50);
    cout << "size : " << v.getSize() << " and capacity : " << v.getCapacity() << endl;
    v.push_back(60);
    cout << "size : " << v.getSize() << " and capacity : " << v.getCapacity() << endl;
    v.push_back(70);
    cout << "size : " << v.getSize() << " and capacity : " << v.getCapacity() << endl;
    v.push_back(80);
    cout << "size : " << v.getSize() << " and capacity : " << v.getCapacity() << endl;
    v.push_back(90);
    cout << "size : " << v.getSize() << " and capacity : " << v.getCapacity() << endl;
    return 0;
}


// size : 1 and capacity : 1
// size : 2 and capacity : 2
// size : 3 and capacity : 4
// size : 4 and capacity : 4
// size : 5 and capacity : 8
// size : 6 and capacity : 8
// size : 7 and capacity : 8
// size : 8 and capacity : 8
// size : 9 and capacity : 16