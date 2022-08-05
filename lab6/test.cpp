#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Polynomial.h"

TEST(egalite, test_1){
    int value = Polynomial<7, 10, 20, 30>::value;
    EXPECT_EQ(value, 660);
}

TEST(inegalite, test_2){
    int value = Polynomial<8, 10, 20, 30>::value;
    EXPECT_EQ(value, 660);
}

class PolynomialTest: public testing::Test{
public:
    PolynomialTest() = default;
};

TEST(PolynomialTest, test_3){
    int value = Polynomial<1, 100, 5>::value;
    ASSERT_NE(1800, value);
}

TEST(PolynomialTest, test_4){
    int value = Polynomial<2, 5, 10>::value;
    ASSERT_FALSE(100 == value);
}

TEST(PolynomialTest, test_5){
    int value = Polynomial<2, 5, 10>::value;
    ASSERT_GT(2000, value);
}

//TEST(PolynomialTest, test_6){
//    std::stringstream ss;
//    ss << Polynomial<2, 5, 10>();
//    std::string line = ss.str();
//    ASSERT_STREQ(line, "5x + 10");
//}



