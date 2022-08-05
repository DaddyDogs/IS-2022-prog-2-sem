#include <cstddef>
#include <iostream>
#include "Iterator.h"

#pragma once

template<typename Type>
class CircularBuffer {
public:
    typedef Iterator <Type> iterator;
    typedef Iterator <const Type> const_iterator;
    [[nodiscard]] Iterator<Type> begin() const;
    [[nodiscard]] Iterator<Type> end() const;

    CircularBuffer(std::initializer_list <int> values);
    explicit CircularBuffer(size_t data_size);
    CircularBuffer(CircularBuffer const &c);
    CircularBuffer & operator = (CircularBuffer const& c);

    void push_back(const Type&);
    void push_head(const Type& item);
    void pop_head();
    void pop_back();
    Type get_begin();
    Type get_end();
    ~CircularBuffer();
    Type& operator [](int);
    void resize(size_t);
    friend std::ostream& operator << (std::ostream &out, CircularBuffer &c){
        out << "[";
        for (size_t i = 0; i < c.buffer_size - 1; ++i){
            out << c.buffer[i] << ", ";
        }
        out << c.buffer[c.buffer_size - 1] << "]";
        return out;
    }
private:
    Type *buffer;
    size_t buffer_size;
    size_t begin_;
    size_t end_;
    size_t used_bytes;
};
template class CircularBuffer<int>;


