#pragma once

#include <iterator>
#include <initializer_list>



template<typename T>
class Iterator: public std::iterator<std::input_iterator_tag, T> {
public:
    Iterator(T *beg, size_t index_begin, size_t curr_pos, size_t size);
    Iterator<T> operator + (typename std::iterator<std::random_access_iterator_tag, T>::difference_type);
    Iterator<T> operator - (typename std::iterator<std::random_access_iterator_tag, T>::difference_type);
    Iterator<T>& operator += (typename std::iterator<std::random_access_iterator_tag, T>::difference_type);
    Iterator<T>& operator -= (typename std::iterator<std::random_access_iterator_tag, T>::difference_type);
    Iterator<T>& operator ++ ();
    Iterator<T>& operator -- ();
    typename std::iterator<std::random_access_iterator_tag, T>::difference_type operator-(const Iterator<T>&);

    bool operator==(const Iterator& other) const;
    bool operator!=(const Iterator& other) const;
    bool operator>(const Iterator& other) const;
    bool operator<(const Iterator& other) const;
    bool operator>=(const Iterator& other) const;
    bool operator<=(const Iterator& other) const;


    T& operator*();
    T* operator->();
    T& operator [] (typename std::iterator<std::random_access_iterator_tag, T>::difference_type index);

    template<class Type>
    friend Iterator<Type> operator+(typename std::iterator<std::random_access_iterator_tag, Type>::difference_type, const Iterator<Type>&another);
private:
    T *begin;
    size_t index_begin_;
    size_t curr_pos_;
    size_t size_;
};
template class Iterator<int>;
