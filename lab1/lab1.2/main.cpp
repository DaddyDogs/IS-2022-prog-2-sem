//
// Created by Настя on 03.02.2022.
//
#include "Polynomial.h"
#include <cassert>


void PolynomialOperators(){
    const auto a =  Polynomial(0, 2, std::vector<double>{1, 2, 3});
    const auto b = Polynomial(1, 2, std::vector<double>{-3, 4});
    auto c = Polynomial(-1,  2, std::vector<double>{1, -3, 0, -1});
    const auto d = Polynomial();
    const auto e =  Polynomial(0, 2, {0, 3, -3});
    const auto f = Polynomial(-2, 2, {1, 0, 0, 0, 1});
    assert(a * b == b * a);
    assert(d * e == d);
    assert(a * b * c == a * (b * c));
    assert(a * b == Polynomial(1, 4, {-3, -2, -1, 12}));
    assert(a + b == b + a);
    assert(c != b);
    assert(d + e == e);
    assert(a + b + c == Polynomial(-1, 2, {1, -2, -1, 6}));
    assert(a + b + c == a + (b + c));
    assert(5 * a == a * 5);
    assert(10 * c == c * 10);
    assert(5 * e == Polynomial(0, 2, {0, 15, -15}));
    assert(c / 2 == Polynomial(-1, 2, {0.5, -1.5, 0, -0.5}));
    assert(a[1] == 2);
    assert(a[10] == 0);
    c[5] = 3;
    assert((-c) == (-(-(-c))));
    auto h = -c;
    assert(c[5] == 3 && h[5] == -3);
    assert((-c)[5] == -3);
    auto g = b;
    g[3] = 0;
    assert(g == b);
}
int main(){
    PolynomialOperators();
    Polynomial c;
    std::cin >> c;
    std::cout << c;
    return 0;
}


