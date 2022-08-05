#include "Polynomial.h"
#include <iostream>
#include <gtest/gtest.h>

int main(int argc, char *argv[]) {
    std::cout << Polynomial<5, 10, 1, 2, 3>() << std::endl;
    std::cout << Polynomial<5, 10, 1, 2, 3>::value << std::endl;
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
