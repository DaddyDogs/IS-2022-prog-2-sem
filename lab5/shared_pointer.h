#pragma once

template <class T>
class shared_pointer {
public:
    using pointer = T*;

    shared_pointer(size_t size) {
        count = new int(0);
        ptr = new T[size];
    }

    shared_pointer& operator=(const shared_pointer& other) {
        if (this == &other) {return *this;}
        ptr = other.ptr;
        count = other.count;
        ++(*count);
        return *this;
    }

    shared_pointer& operator+(size_t numb) {
        return static_cast<shared_pointer<T>>(this + numb);
    }

    void init (pointer p) {
        ptr = p;
        ++(*count);
    }

    void clean() {
        if (*count == 1) {
            operator delete[](static_cast<void*>(ptr));
            delete count;
        } else {
            --(*count);
        }
    }

    explicit operator pointer() const {
        return ptr;
    }

private:
    pointer ptr = nullptr;
    int* count;
};
