#include "Iterator.h"

template<typename T>
Iterator<T>::Iterator(T *beg, size_t index_begin, size_t curr_pos, size_t size): begin(beg), index_begin_(index_begin),
                                                                        curr_pos_(curr_pos), size_(size){
}

template<typename T>
Iterator<T> &Iterator<T>::operator+=(typename std::iterator<std::random_access_iterator_tag, T>::difference_type shift) {
    curr_pos_ += shift;
    return *this;
}

template<typename T>
Iterator<T> &Iterator<T>::operator-=(typename std::iterator<std::random_access_iterator_tag, T>::difference_type shift) {
    curr_pos_ -= shift;
    return *this;
}

template<typename T>
Iterator<T> &Iterator<T>::operator++() {
    curr_pos_ += 1;
    return *this;
}

template<typename T>
Iterator<T> &Iterator<T>::operator--() {
    *this -= 1;
    return *this;
}

template<typename T>
Iterator<T> Iterator<T>::operator+(typename std::iterator<std::random_access_iterator_tag, T>::difference_type shift) {
    return Iterator(begin, index_begin_, curr_pos_ + shift, size_);
}

template<typename T>
Iterator<T> Iterator<T>::operator-(typename std::iterator<std::random_access_iterator_tag, T>::difference_type shift) {
    return Iterator(begin, index_begin_, curr_pos_ - shift, size_);
}

template<typename T>
bool Iterator<T>::operator==(const Iterator &other) const {
    return curr_pos_ == other.curr_pos_;
}
template<typename T>
bool Iterator<T>::operator!=(const Iterator &other) const {
    return curr_pos_ != other.curr_pos_;
}
template<typename T>
bool Iterator<T>::operator>(const Iterator &other) const {
    return curr_pos_ > other.curr_pos_;
}
template<typename T>
bool Iterator<T>::operator<(const Iterator &other) const {
    return curr_pos_ < other.curr_pos_;
}
template<typename T>
bool Iterator<T>::operator>=(const Iterator &other) const {
    return curr_pos_ >= other.curr_pos_;
}
template<typename T>
bool Iterator<T>::operator<=(const Iterator &other) const {
    return curr_pos_ <= other.curr_pos_;
}

template<typename T>
T &Iterator<T>::operator*() {
    return begin[(index_begin_ + curr_pos_) % size_];
}

template<typename T>
T *Iterator<T>::operator->() {
    return begin + ((index_begin_ + curr_pos_) % size_);
}

template<typename T>
T &Iterator<T>::operator[](typename std::iterator<std::random_access_iterator_tag, T>::difference_type index) {
    return begin[(index_begin_ + index) % size_];
}

template<class Type>
Iterator<Type> operator+(typename std::iterator<std::random_access_iterator_tag, Type>::difference_type position, const Iterator<Type> &another) {
    return Iterator<Type>(another.begin, another.index_begin_, another.curr_pos_ + position, another.size, 0);
}

template<typename T>
typename std::iterator<std::random_access_iterator_tag, T>::difference_type Iterator<T>::operator-(const Iterator<T> &another) {
    return curr_pos_ - another.curr_pos_;
}



