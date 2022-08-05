#include "Polynomial.h"

Polynomial::Polynomial()
        : min(0), max(0), coefficients_number(0) {}

Polynomial::Polynomial(int min, int max, std::vector<double> const &coefficients)
        : min(min), max(max), coefficients_number(max - min + 1) {
    int i = min;
    for (const auto &elem: coefficients) {
        polynomial[i] = elem;
        ++i;
    }
}

Polynomial::Polynomial(Polynomial const &a) : max(a.max), min(a.min), coefficients_number(a.coefficients_number),
                                              polynomial(a.polynomial) {}

Polynomial &Polynomial::operator=(const Polynomial &p) {
    if (this != &p) {
        coefficients_number = p.coefficients_number;
        min = p.min;
        max = p.max;
        polynomial = p.polynomial;
    }
    return *this;
}

bool Polynomial::operator==(const Polynomial &a) {
    int curr_min = (a.min < min ? a.min : min);
    int curr_max = (a.max > max ? a.max : max);
    for (int i = curr_min; i < curr_max - curr_min + 1; i++) {
        if ((i <= max and i >= min) and (i > a.max or i < a.min)) {
            if (polynomial[i] != 0) return false;
        }
        if ((i <= a.max and i >= a.min) and (i > max or i < min)) {
            if (a.polynomial.at(i) != 0) return false;
        }
    }
    return true;
}

bool Polynomial::operator!=(const Polynomial &a) {
    return !operator==(a);
}

Polynomial &Polynomial::operator+=(Polynomial const &a) {
    min = (a.min < min ? a.min : min);
    max = (a.max > max ? a.max : max);
    coefficients_number = max - min + 1;
    for(const auto &elem: a.polynomial) {
        this->polynomial[elem.first] += elem.second;
    }
    return *this;
}

Polynomial operator+(Polynomial a, Polynomial const &b) {
    return a += b;
}

Polynomial &Polynomial::operator-=(Polynomial const &a) {
    min = (a.min < min ? a.min : min);
    max = (a.max > max ? a.max : max);
    coefficients_number = max - min + 1;
    for(const auto &elem: a.polynomial) {
        this->polynomial[elem.first] -= elem.second;
    }
    return *this;
}

Polynomial operator-(Polynomial a, Polynomial const &b) {
   return a-=b;
}

Polynomial Polynomial::operator-() const {
    return Polynomial() -= *this;
}

Polynomial &Polynomial::operator*=(double number) {
    for (int i = min; i != max + 1; i++) {
        polynomial[i] *= number;
    }
    return *this;
}

Polynomial Polynomial::operator*=(Polynomial const &a) {
    Polynomial res;
    res.max = this->max + a.max;
    res.min = this->min + a.min;

    res.coefficients_number = res.max - res.min + 1;

    for (const auto& item: this->polynomial) {
        for (const auto& item2: a.polynomial) {
            res.polynomial[item.first + item2.first] = item.second * item2.second;
        }
    }

    *this = res;
    return *this;
}

Polynomial operator*(double number, Polynomial a) {
    return a *= number;
}
Polynomial operator*(Polynomial a, double number) {
    return a *= number;
}

Polynomial operator*(Polynomial a, Polynomial const &b) {
    return a *= b;
}

Polynomial &Polynomial::operator/=(double number) {
    for (int i = 0; i < coefficients_number; i++) {
        polynomial[i] /= number;
    }
    return *this;
}

Polynomial &operator/(Polynomial const &a, double number) {
    if (number == 0) {
        std::cout << "Error: division by zero";
        exit(-0);
    }
    if (a.coefficients_number != 0) {
        Polynomial result{a};
        result /= number;
        Polynomial *res = &result;
        return *res;
    } else {
        return const_cast<Polynomial &>(a);
    }
}

double Polynomial::operator[](int i) const {
    if (i > (coefficients_number)) return 0;
    return polynomial.at(i);
}

double &Polynomial::operator[](int index) {
    if (index > coefficients_number) {
        exit (0);
    }
    return polynomial[index];
}

std::ostream &operator<<(std::ostream &out, const Polynomial &p) {
    if (p.coefficients_number == 1 and p.polynomial.at(p.min) == 0) {
        out << "0";
    } else if (p.coefficients_number == 0) {
        out << "0";
    }
    else {
        for (int i = p.max; i > p.min - 1; i--) {
            if (i != 0) {
                if (p.polynomial.at(i) == 1) {
                    out << "x";
                } else if (p.polynomial.at(i) == -1) {
                    out << "-x";
                } else if (p.polynomial.at(i) == 0) {
                } else {
                    out << p.polynomial.at(i) << "x";
                }
                if (i != 1 and p.polynomial.at(i) != 0) {
                    out << "^" << i;
                }
            } else {
                if (p.polynomial.at(i) != 0) {
                    out << p.polynomial.at(i);
                }
            }
            if (i != p.min and p.polynomial.at(i - 1) > 0) {
                out << "+";
            }
        }
    }
    return out;
}

std::istream &operator>>(std::istream &in, Polynomial &p) {
    in >> p.min;
    in >> p.max;
    p.coefficients_number = p.max - p.min + 1;
    for (int i = p.min; i <= p.max; ++i) {
        in >> p.polynomial[i];
    }
    return in;
}

