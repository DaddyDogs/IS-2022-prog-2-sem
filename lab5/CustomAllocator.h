#pragma once
#include <cstdio>
#include <cassert>
#include <type_traits>
#include <utility>
#include <vector>
#include <map>
#include <iostream>
#include <memory>
#include <algorithm>


template<class T>
class CustomAllocator
{
    template<class U>
    friend class CustomAllocator;

    static_assert(!std::is_same_v<T, void>, "Void allocator's type");
public:
    using value_type = T;
    using ptr = T*;
    using const_pointer = const T*;
    using void_pointer = std::nullptr_t;
    using const_void_pointer = const std::nullptr_t;

    CustomAllocator() {
        std::cout << "Constructor call " << this << std::endl;
        start = new T[memory_size];
        std::size_t n = 2, count = 0;
        for (size_t i = 0; i < 100; ++i) {
            auto buffer = std::vector<ptr>(10);
            for (size_t j = 0; j < buffer.size(); ++j) {
                auto b = static_cast<ptr>(start + count);
                buffer[j] = static_cast<ptr>(start + count);
                count += n;
            }
            blocks.insert({buffer, n});
            n += 2;
            free_count.push_back(10);
        }
//        while (n * i <= memory_size){
//            buffer[i] = static_cast<ptr>(start + count);
//            //blocks.insert({static_cast<ptr>(start + count), n});
//            v.push_back(n);
//            if (n == 2 and i == 10){
//                n *= 2;
//                i = 1;
//                blocks.insert(buffer, n);
//                buffer.clear();
//            }
//            if (i == 11) {
//                n *= 2;
//                i = 1;
//                blocks.insert(buffer, n);
//                buffer.clear();
//            }
//            i ++;
//            count += n;
//        }
    }

    CustomAllocator(size_t size, const std::initializer_list<size_t> init_list): start(new T[size]) {
        std::cout << "Constructor call " << this << std::endl;
        std::vector<size_t> sizes_list(init_list);
        std::sort(sizes_list.begin(), sizes_list.end());
        size_t n = sizes_list[sizes_list.size() - 1];
        counter.resize(n + 1);
        for(auto& item: sizes_list){
            counter[item] += 1;
        }
        size_t count = 0;
        for (size_t i = 0; i < n + 1; ++i) {
            auto buffer = std::vector<ptr>(counter[i]);
            for (size_t j = 0; j < counter[i]; ++j) {
                buffer[j] = static_cast<ptr>(start + count);
                count += i;
            }
            blocks.insert({buffer, i});
            free_count.push_back(counter[i]);
        }
    }

    template<class U>
    explicit CustomAllocator(const CustomAllocator<U> &other)
            : my_alloc(other.my_alloc)
            , v(other.v)
            , blocks(other.blocks)
            , free_count(other.free_count){
        std::cout << "Copy template constructor call " << this << " " << &other << std::endl;
    };

    CustomAllocator(const CustomAllocator& other)
    : my_alloc(other.my_alloc)
    , v(other.v),
      blocks (other.blocks),
      free_count(other.free_count){
        std::cout << "Copy constructor call " << this << " " << &other << std::endl;
    }

    ~CustomAllocator() = default;

    ptr allocate(std::size_t objects_number)
    {
        std::cout << "Allocation call " << this << std::endl;
        if (my_allocations + objects_number * sizeof(T) > memory_size){
            throw std::bad_alloc();
        }
        my_allocations += objects_number * sizeof(T);
//        for (size_t i = 0; i < v.size(); ++i){
//            if (v[i] >= objects_number * sizeof(T)){
//                chunk_number += v[i];
//                v[i] = 0;
//                return static_cast<ptr>(operator new(sizeof(T) * objects_number));
//            }
//        }
//        return static_cast<ptr>(operator new(sizeof(T) * objects_number));
        for(auto& item : blocks)
        {
            if (item.second >= objects_number * sizeof(T) and free_count[item.second] > 0) {
                free_count[item.second] -= 1;
                auto bq = (item.first[item.first.size() - free_count[item.second]]);
                return (item.first[item.first.size() - free_count[item.second]]);
            }
        }
        throw std::bad_alloc();
    }

    void deallocate(ptr p, std::size_t numObjects)
    {
        std::cout << "Deallocate call " << this << std::endl;
        for(auto& item : blocks)
        {
            for(auto& elem : item.first){
                if (elem == p) {
                    free_count[item.second] += 1;
                }
            }
        }
//        auto diff = *reinterpret_cast<T*>(p) - *reinterpret_cast<T*>(start);
//        size_t i = 1, n = 2, count = 0, c = 1;
//        while (count != diff){
//            if (i == 11) {
//                n *= 2;
//                i = 1;
//                c += 1;
//            }
//            i ++;
//            count += n;
//        }
//        v[c * 2 + i - 1] = n * i;
//        operator delete(p);

    }

    [[nodiscard]] std::size_t get_allocations() const
    {
        return my_allocations;
    }

    template<typename U, typename... Args>
    void construct(U* ptr, Args&&... args)
    {
        new (reinterpret_cast<void*>(ptr)) U { std::forward<Args>(args)... };
    }

    template<typename U>
    void destroy(U* ptr)
    {
        ptr->~U();
    }

private:
    static std::size_t my_allocations;
    CustomAllocator* my_alloc = nullptr;
    size_t memory_size = 1000000;
    ptr start;
    std::vector<std::size_t> v;
//    size_t chunk_number = 0;
    std::map<std::vector<ptr>, size_t> blocks;
    std::vector<size_t> free_count;
    std::vector<size_t> counter;
};

template<class T>
typename std::size_t CustomAllocator<T>::my_allocations = 0;

template<class T, class U>
bool operator==(const CustomAllocator<T>& lhs, const CustomAllocator<U>& rhs){
    return lhs.my_alloc == rhs.my_alloc;
}
template<class T, class U>
bool operator!=(const CustomAllocator<T>& lhs, const CustomAllocator<U>& rhs){
    return lhs.my_alloc != rhs.my_alloc;
}


