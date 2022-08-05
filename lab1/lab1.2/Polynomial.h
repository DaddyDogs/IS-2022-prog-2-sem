//
// Created by Настя on 03.02.2022.
//

#ifndef LAB2_POLYNOMIAL_H
#define LAB2_POLYNOMIAL_H

#include <map>
#include <iostream>
#include <vector>



class Polynomial {
public:
    Polynomial();
    Polynomial(int min, int max, std::vector<double> const &coefficients);

    Polynomial(Polynomial const&a);

    Polynomial & operator = (Polynomial const& a);

    bool operator == (Polynomial const& a);
    bool operator != (Polynomial const& a);

    Polynomial & operator += (Polynomial const& a);
    friend Polynomial operator + (Polynomial a, Polynomial const& b);
    Polynomial operator - () const;
    Polynomial & operator -= (Polynomial const& a);
    friend Polynomial  operator - (Polynomial a, Polynomial const& b);

    Polynomial & operator *= (double number);
    Polynomial operator *= (Polynomial const&a);
    friend Polynomial operator * (Polynomial a, double number);
    friend Polynomial operator * (double number, Polynomial a);
    friend Polynomial operator * (Polynomial a, Polynomial const&b);
    Polynomial & operator /= (double number);
    friend Polynomial & operator / (Polynomial const& a, double number);

    friend std::ostream& operator << (std::ostream &out, const Polynomial &p);
    friend std::istream& operator >> (std::istream &in, Polynomial &p);

    double operator [] (int i) const;
    double& operator[](int index);


private:
    int min, max;
    int coefficients_number;
    std::map <int, double> polynomial;

};


#endif //LAB2_POLYNOMIAL_H

