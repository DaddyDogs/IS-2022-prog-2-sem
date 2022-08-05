#include <iostream>
#include <memory>
#include <vector>
#include <queue>
#include "CustomAllocator.h"
#include <ctime>

int main()
{
    unsigned int start_time =  clock();
    std::vector<int, CustomAllocator<int>> q(4);
    std::vector<char, CustomAllocator<char>> s(5);
    q[0] = 55;
    std::cout << q[0] << "\n";
    std::vector<char, CustomAllocator<char>> s1(5);
    s1.resize(10);
    unsigned int end_time = clock();
    unsigned int search_time = end_time - start_time;
    std::cout << "My allocator time = " << search_time << "\n";
    std::cout << s1.size() << "\n";
//    std::initializer_list<size_t> i1 {1, 2, 5};
//    CustomAllocator<int>  give_me_a_name(33, i1);
//    give_me_a_name.allocate(1);
    std::vector<int> q1(4);
    std::vector<char> ss1(5);
    q[0] = 55;
    std::cout << q[0] << "\n";
    std::vector<char, CustomAllocator<char>> sss1(5);
    end_time = clock();
    search_time = end_time - start_time;
    std::cout << "Std::allocator time = " << search_time << "\n";
    //std::cout << s.get_allocator().get_allocations() << std::endl;
    return 0;
}