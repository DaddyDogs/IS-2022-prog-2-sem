#include <cmath>
#include <cassert>
#include <iostream>

#define PI 3.14159265

#ifndef LAB1_FIGURES_H
#define LAB1_FIGURES_H

class Point {
public:
    explicit Point(double x = 0, double y = 0);
    Point(Point const&p);
    Point & operator = (Point const& p);
    __attribute__((unused)) void shift(double x, double y);
    double get_x() const;
    double get_y() const;
private:
    double x;
    double y;
};

class Chain {
public:
    explicit Chain(int number = 0, Point *p = nullptr);
    Chain(Chain const&c);
    Chain & operator = (Chain const& c);
    virtual double perimeter() const;
    virtual ~Chain();
protected:
    int points_number;
    Point *points;
};

class ClosedChain : public Chain {
public:
    explicit ClosedChain(int number = 0, Point *p = nullptr);
    ClosedChain(ClosedChain const&c);
    ClosedChain & operator = (ClosedChain const& c);
    double perimeter() const override;
    ~ClosedChain() override;
private:
    int points_number;
    Point *points;
};

class Functions {
protected:
    virtual double perimeter() const = 0;
    virtual double area() const = 0;
};

class Polygon: public Functions{
public:
    explicit Polygon(int number = 0, Point *p = nullptr);
    Polygon(Polygon const&p);
    Polygon & operator = (Polygon const& p);
    double perimeter() const override;
    double area() const override;
    ~Polygon();
private:
    int points_number;
    Point *points;
};

class Triangle: public Functions{
public:
    explicit Triangle (Point *p = nullptr);
    Triangle(Triangle const& t);
    Triangle & operator = (const Triangle &t);
    double perimeter() const override;
    double area() const override;
    ~Triangle();
private:
    int points_number = 4;
    Point *points;
};

class Trapezoid: public Functions{
public:
    explicit Trapezoid (Point *p = nullptr);
    Trapezoid(Trapezoid const& t);
    Trapezoid & operator = (const Trapezoid &t);
    double perimeter() const override;
    double area() const override;
    ~Trapezoid();
private:
    int points_number = 5;
    Point *points;
    Point *base_1;
    Point *base_2;
    char height;
};

class RegularPolygon: public Functions{
public:
    explicit RegularPolygon (int number = 0, Point *p = nullptr);
    static double get_cos(const Point& p1, const Point& p2, const Point& p3);
    static double get_length(const Point& p1, const Point& p2);
    RegularPolygon(RegularPolygon const& rp);
    RegularPolygon& operator = (const RegularPolygon &rp);
    double perimeter() const override;
    double area() const override;
    ~RegularPolygon();
private:
    int points_number;
    Point *points;
    __attribute__((unused)) double cos_ = 0;

};




#endif //LAB1_FIGURES_H
