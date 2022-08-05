#pragma once
#include <iostream>
#include <cmath>


constexpr int pow(int value, int degree) {
    if (degree == 0) return 1;
    return value * pow(value, degree - 1);
}

template<int Point, int Coefficient, int ...Coefficients>
class Polynomial {
public:
    enum {coefficients_number = sizeof...(Coefficients)};
    enum {value = pow(Point, coefficients_number) * Coefficient + Polynomial<Point, Coefficients...>::value};
    friend std::ostream& operator << (std::ostream& out, const Polynomial& P){
        if (Coefficient == 1) {out << "x";}
        else out << Coefficient << "x";
        if (coefficients_number == 1) {out << " + " << Polynomial<Point, Coefficients...>();}
        else {out << "^" << coefficients_number << " + " << Polynomial<Point, Coefficients...>();}
        return out;
    }
};

template<int Point, int Coefficient>
class Polynomial<Point, Coefficient>{
public:
    enum {value = Coefficient};
    friend std::ostream& operator << (std::ostream& out, const Polynomial& P){
        out << Coefficient;
        return out;
    }
};




