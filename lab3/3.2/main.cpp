#include <iostream>
#include "Algorithms.h"
#include <vector>
#include <set>
#include <cassert>
using namespace Algorithms;
void check() {
    std::vector<int> a{1, 2, 3, 4};
    std::vector<int> b{1, 2, 3, 4, 2};
    std::vector<int> c{4, 3, 2, 1, 0};
    std::vector<int> d{1, 1};
    std::vector<int> e{1, 2, 3, 4, 3, 2, 1};
    std::vector<int> f{1, 2, 3, 4, 3, 2, 3};
    std::vector<int> e1{1, 2, 3, 3, 2, 1};
    std::vector<int> f1{1, 2, 3, 4, 2, 1};
    std::vector<std::pair<int ,int>> h{{1, 2}, {2, 3}, {3, 4}};
    std::vector<int> g{1};
    std::set<int> s{1, 2, 3};

    assert(all_of(a.begin(), a.end(), [](int x){return x <= 5;}));
    assert(!all_of(a.begin(), a.end(), [](int x){return x <= 3;}));
    assert(any_of(a.begin(), a.end(), [](int x){return x == 3;}));
    assert(!any_of(a.begin(), a.end(), [](int x){return x == 5;}));
    assert(none_of(a.begin(), a.end(), [](int x){return x > 5;}));
    assert(!none_of(a.begin(), a.end(), [](int x){return x >= 3;}));
    assert(one_of(b.begin(), b.end(), [](int x){return x == 3;}));
    assert(!one_of(b.begin(), b.end(), [](int x){return x == 2;}));
    assert(is_sorted(a.begin(), a.end(), [](int x, int y){return x < y;}));
    assert(!is_sorted(b.begin(), b.end(), [](int x, int y){return x < y;}));
//    assert(is_sorted(a.begin(), a.end()));
//    assert(!is_sorted(b.begin(), b.end()));
    assert(is_sorted(c.begin(), c.end(), [](int x, int y){return x > y;}));
    assert(is_partitioned(a.begin(), a.end(), [](int x){return x <= 3;}));
    assert(!is_partitioned(a.begin(), a.end(), [](int x){return x % 2 == 0;}));
    assert(is_partitioned(a.begin(), a.end(), [](int x){return x <= 3;}));
    assert(find_not(a.begin(), a.end(), 1) == ++a.begin());
    assert(find_not(d.begin(), d.end(), 1) == d.end());
    assert(find_backward(static_cast<myForwardIterator>(b.begin()), static_cast<myForwardIterator>(b.end()), 2) == --b.end());
    //assert(find_backward(static_cast<myForwardIterator>(b.begin()), static_cast<myForwardIterator>(b.end()), 5) == b.end());
    assert(is_palindrome(e.begin(), e.end(), [](int x, int y){return x == y;}));
    assert(!is_palindrome(f.begin(), f.end(), [](int x, int y){return x == y;}));
    assert(is_palindrome(e1.begin(), e1.end(), [](int x, int y){return x == y;}));
    assert(!is_palindrome(f1.begin(), f1.end(), [](int x, int y){return x == y;}));
    assert(is_palindrome(s.begin(), s.end(), [](int x, int y){return x + y > 0;}));
    assert(is_palindrome(g.begin(), g.end(), [](int x, int y){return x == y;}));
    assert(is_sorted(h.begin(), h.end(), [](std::pair<int, int> x, std::pair<int, int> y) {return x < y;}));
    //assert(is_sorted(h.begin(), h.end()));
}
int main() {
    check();
    return 0;
}
