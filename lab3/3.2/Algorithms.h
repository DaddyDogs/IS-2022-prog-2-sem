//
// Created by Настя on 26.03.2022.
//
#include<vector>
#pragma once
class myForwardIterator : public std::vector<int>::iterator {
    using T = std::vector<int>::iterator;
public:
    myForwardIterator(__normal_iterator <pointer, std::vector<int>> iterator) : T(iterator){
    }
};

namespace Algorithms {
    template<typename Iterator, typename Predicate>
    bool all_of(Iterator begin, Iterator end, Predicate condition){
        while (begin != end){
            if (!condition(*begin)) return false;
            begin++;
        }
        return true;
    }

    template<typename Iterator, typename Predicate>
    bool any_of(Iterator begin, Iterator end, Predicate condition){
        while (begin != end){
            if (condition(*begin)) return true;
            begin++;
        }
        return false;
    }

    template<typename Iterator, typename Predicate>
    bool none_of(Iterator begin, Iterator end, Predicate condition){
        while (begin != end){
            if (condition(*begin)) return false;
            begin++;
        }
        return true;
    }

    template<typename Iterator, typename Predicate>
    bool one_of(Iterator begin, Iterator end, Predicate condition){
        int count = 0;
        while (begin != end){
            if (condition(*begin)) count++;
            if (count > 1) return false;
            begin++;
        }
        if (count == 1) return true;
        return false;
    }

    template<typename Iterator, typename Predicate>
    bool is_sorted(Iterator begin, Iterator end, Predicate condition){
        while (begin != end - 1){
            if (!condition(*begin, *(begin + 1))) return false;
            begin++;
        }
        return true;
    }

    template<typename Iterator, typename Predicate>
    bool is_partitioned(Iterator begin, Iterator end, Predicate condition){
        int count = 0;
        bool flag = condition(*begin);
        begin++;
        if (flag) {
            while (begin != end) {
                if (condition(*begin) != flag) {
                    count++;
                    if (count > 1) return false;
                    flag = false;
                }
                begin++;
            }
        }
        else return false;
        if (count)
        return true;
        else return false;
    }

    template<typename Iterator, typename Type>
    Iterator find_not(Iterator begin, Iterator end, Type value){
        while (begin != end){
            if (*begin != value) return begin;
            begin++;
        }
        return end;
    }

    template<typename Iterator, typename Type>
    Iterator find_backward(Iterator end, Iterator begin, Type value){
        while (begin != end){
            if (*begin == value) return begin;
            begin--;
        }
        return end;
    }

    template<typename Iterator, typename Predicate>
    bool is_palindrome(Iterator begin, Iterator end, Predicate condition) {
        if (begin == end) return true;
        --end;
        while (begin != end){
            if (!condition(*begin, *end)) return false;
            ++begin;
            if (begin == end){
                break;
            }
            --end;
        }
        return true;
    }
};
