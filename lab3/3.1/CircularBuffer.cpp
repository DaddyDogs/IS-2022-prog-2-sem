#include "CircularBuffer.h"

template<typename Type>
CircularBuffer<Type>::CircularBuffer(size_t data_size): buffer(new Type[data_size]), buffer_size(data_size),
                                                        begin_(0), end_(0), used_bytes(0) {
}

template<typename Type>
CircularBuffer<Type>::~CircularBuffer() {
    delete [] buffer;
    buffer = nullptr;
}
template<typename Type>
CircularBuffer<Type>::CircularBuffer(const CircularBuffer &c): buffer(new Type[c.buffer_size]), buffer_size(c.buffer_size),
                                                               begin_(c.begin_), end_(c.end_), used_bytes(c.used_bytes)
{
    for (size_t i = 0; i < buffer_size; i++){
        buffer[i] = c.buffer[i];
    }
}

template<typename Type>
CircularBuffer<Type> &CircularBuffer<Type>::operator=(const CircularBuffer<Type> &c){
    if (this != &c){
        buffer = new Type[c.buffer_size];
        buffer_size = c.buffer_size;
        begin_ = c.begin_;
        end_ = c.end_;
        used_bytes = c.used_bytes;
    }
    return *this;
}


template<typename T>
void CircularBuffer<T>::push_back(const T &item) {
    if (used_bytes == 0){
        buffer[begin_] = item;
        end_++;
    }
    else if (used_bytes % buffer_size == 0){
        buffer[begin_] = item;
        end_ = begin_ + 1;
    }
    else{
        buffer[end_] = item;
        end_++;
    }
    used_bytes += 1;
}

template<typename Type>
void CircularBuffer<Type>::push_head(const Type &item) {
    if (used_bytes == 0){
        buffer[begin_] = item;
        end_++;
    }
    else if (used_bytes % buffer_size == 0){
        buffer[begin_] = item;
        end_ = begin_ + 1;
    }
    else{
        if (begin_ == 0) {
            Type temp = buffer[0];
            for (int i = 1; i < buffer_size; ++i) {
                std::swap(buffer[i], temp);
            }
            end_++;
        }
        begin_ = 0;
        buffer[0] = item;
    }
    used_bytes += 1;
}

template<typename Type>
void CircularBuffer<Type>::pop_head() {
    if (used_bytes == 0){
        std::cout << "Invalid operation: buffer is empty";
        exit(1);
    }
    else {
        if (begin_ % buffer_size == 0 and begin_ != 0){
            begin_ = 0;
            end_ = 0;
        }
        else{
            begin_++;
        }
    }
    used_bytes -= 1;
}

template<typename Type>
void CircularBuffer<Type>::pop_back() {
    if (used_bytes == 0){
        std::cout << "Invalid operation: buffer is empty";
        exit(1);
    }
    used_bytes -= 1;
    end_--;
}

template<typename Type>
Type CircularBuffer<Type>::get_begin() {
    return buffer[begin_];
}

template<typename Type>
Type CircularBuffer<Type>::get_end() {
    return buffer[end_ - 1];
}

template<typename Type>
Type &CircularBuffer<Type>::operator[](int index) {
    if (used_bytes == 0){
        std::cout << "Invalid operation: buffer is empty";
        exit(1);
    }
    else if(index + begin_ >= end_ or index < 0){
        std::cout << "Invalid operation: your index is out of range";
        exit(1);
    }
    else {
        return buffer[index + begin_];
    }
}

template<typename Type>
void CircularBuffer<Type>::resize(size_t capacity) {
    if (capacity < buffer_size){
        std::cout << "Invalid operation: cannot reduce capacity";
    }
    else {
        Type *new_buffer = new Type[capacity];
        for (size_t i = begin_; i < end_; ++i){
            new_buffer[i] = buffer[i];
        }
        delete [] buffer;
        buffer = new_buffer;
        buffer_size = capacity;
    }
}

template<> CircularBuffer<int>::CircularBuffer(std::initializer_list<int> values):buffer(new int[values.size()]), buffer_size(values.size()),
                                                                                  begin_(0), end_(0), used_bytes(0){
    std::copy(values.begin(), values.end(), buffer);
}

template<typename Type>
Iterator<Type> CircularBuffer<Type>::begin() const {
    return Iterator<Type>(buffer, begin_, 0, buffer_size);
}

template<typename Type>
Iterator<Type> CircularBuffer<Type>::end() const {
    return Iterator<Type>(buffer, end_, used_bytes, buffer_size);
}



