#include "CircularBuffer.h"
#include <cassert>
#include<sstream>
#include <algorithm>
#include <vector>
#include <list>

int main() {
//    CircularBuffer<int> c(2);
//    c.push_head(1);
//    assert(c.get_begin() == 1);
//    assert(c.get_end() == 1);
//    c.push_back(2);
//    assert(c.get_begin() == 1);
//    assert(c.get_end() == 2);
//    assert(c[0] == 1);
//    assert(c[1] == 2);
//    c.pop_head();
//    assert(c[0] == 2);
//    assert(c.get_end() == 2);
//    assert(c.get_begin() == 2);
//    c.push_head(10);
//    std::stringstream ss;
//    ss << c;
//    assert(ss.str() == "[10, 2]");
//    c.resize(3);
//    c.push_head(8);
//    std::stringstream s2;
//    s2 << c;
//    assert(s2.str() == "[8, 10, 2]");
//    c.pop_back();
//    assert(c.get_end() == 10);
//    CircularBuffer<int> c1(3);
//    c1.push_head(3); c1.push_head(4); c1.push_head(5);
//    std::cout << c1 << std::endl;
//    std::sort(c1.begin(), c1.end());
//    std::cout << c1;
//
//static_assert( std::is_arithmetic<std::vector<int *>>::value ||
//               (std::is_pointer<std::vector<int *>>::value &&
//                std::is_class<typename std::remove_pointer<std::vector<int *>>::type>::value));
std::list<int> l = {1,2,3};
l.insert(l.begin(), 4);
l.insert(l.end(), 5);

auto it = l.begin();
++it;
++it;

l.insert(it, 6);

auto rit1 = l.rbegin();
++rit1;
++rit1;
l.insert(rit1.base(), 7);

//auto rit2 = l.rbegin();
//++rit2;
//++rit2;
//l.insert(rit2.base(), 8);
for (auto i: l){ std::cout << i;};
    return 0;
}
