#include "Figures.h"

Point::Point(double x, double y):x(x), y(y) {}

Point::Point(const Point &p) = default;

Point& Point::operator = (Point const& p){
    if (&p != this){
        x = p.x;
        y = p.y;
    }
    return *this;
}

__attribute__((unused)) void Point::shift(double a, double b){
    this->x += a;
    this->y += b;
}

double Point::get_x() const {return x;}
double Point::get_y() const {return y;}


Chain::Chain(int number, Point *p): points_number(number), points(p) {}

Chain::Chain(const Chain &c): points_number(c.points_number), points(new Point[points_number]){
    for (int i = 0; i < points_number; i++){
        points[i] = c.points[i];
    }
}

Chain &Chain::operator = (const Chain &c) {
    if (this != &c){
        delete [] this->points;
        points = new Point[c.points_number];
        points_number = c.points_number;
        for (int i = 0; i < points_number; i++){
            points[i] = c.points[i];
        }
    }
    return *this;
}

double Chain::perimeter() const {
    double result = 0;
    for (int i = 0; i < points_number - 1; i++){
        double dx = points[i].get_x() - points[i + 1].get_x();
        double dy = points[i].get_y() - points[i + 1].get_y();
        result += sqrt(dx*dx + dy*dy);
    }
    return result;
}

Chain::~Chain() {
    delete [] points;
}

ClosedChain::ClosedChain(int number, Point *p): points_number(number + 1), points(new Point[number + 1]){
    for (int i = 0; i < points_number - 1; i++){
        points[i] = p[i];
    }
    points[points_number - 1] = p[0];
}
ClosedChain::ClosedChain(const ClosedChain &c): points_number(c.points_number), points(new Point[points_number]){
    for (int i = 0; i < points_number; i++){
    points[i] = c.points[i];
    }
}
ClosedChain &ClosedChain::operator = (const ClosedChain &c) {
    if (this != &c){
        delete [] this->points;
        points = new Point[c.points_number];
        points_number = c.points_number;
        for (int i = 0; i < points_number; i++){
            points[i] = c.points[i];
        }
    }
    return *this;
}

double ClosedChain::perimeter() const {
    double result = 0;
    for (int i = 0; i < points_number - 1; i++){
        double dx = points[i].get_x() - points[i + 1].get_x();
        double dy = points[i].get_y() - points[i + 1].get_y();
        result += sqrt(dx*dx + dy*dy);
    }
    return result;
}

ClosedChain::~ClosedChain() {
    delete [] points;
}

Polygon::Polygon(int number, Point *p): points_number(number + 1), points(new Point[number + 1]){
    for (int i = 0; i < points_number - 1; i++){
        points[i] = p[i];
    }
    points[points_number - 1] = p[0];
}
Polygon::Polygon(const Polygon &p): points_number(p.points_number), points(new Point[points_number]){
    for (int i = 0; i < points_number; i++){
        points[i] = p.points[i];
    }
}
Polygon &Polygon::operator = (const Polygon &p) {
    if (this != &p){
        delete [] this->points;
        points = new Point[p.points_number];
        points_number = p.points_number;
        for (int i = 0; i < points_number; i++){
            points[i] = p.points[i];
        }
    }
    return *this;
}

double Polygon::perimeter() const {
    double result = 0;
    for (int i = 0; i < points_number - 1; i++){
        double dx = points[i].get_x() - points[i + 1].get_x();
        double dy = points[i].get_y() - points[i + 1].get_y();
        result += sqrt(dx*dx + dy*dy);
    }
    return result;
}

double Polygon::area() const {
    double res1 = 0, res2 = 0;
    for (int i = 0; i < points_number - 1; i++){
        res1 += points[i].get_x() * points[i + 1].get_y();
        res2 += points[i + 1].get_x() * points[i].get_y();
    }
    return (abs(res1 - res2)) / 2;
}

Polygon::~Polygon() {
    delete [] points;
}


Triangle::Triangle(Point *p): points(new Point[4]){
    for (int i = 0; i < 3; i++){
        points[i] = p[i];
    }
    points[3] = p[0];
}

Triangle::~Triangle() {
    delete [] points;
}
Triangle::Triangle(const Triangle &t): points(new Point[4]){
    for (int i = 0; i < 4; i++){
        points[i] = t.points[i];
    }
}
Triangle &Triangle::operator = (const Triangle &t) {
    if (this != &t){
        delete [] this->points;
        points = new Point[t.points_number];
        points_number = t.points_number;
        for (int i = 0; i < 4; i++){
            points[i] = t.points[i];
        }
    }
    return *this;
}
double Triangle::perimeter() const {
    double result = 0;
    for (int i = 0; i < points_number - 1; i++){
        double dx = points[i].get_x() - points[i + 1].get_x();
        double dy = points[i].get_y() - points[i + 1].get_y();
        result += sqrt(dx*dx + dy*dy);
    }
    return result;
}

double Triangle::area() const {
    auto *sides = new double[3];
    double dx = points[0].get_x() - points[1].get_x();
    double dy = points[0].get_y() - points[1].get_y();
    sides[0] = sqrt(dx*dx + dy*dy);
    double dx2 = points[1].get_x() - points[2].get_x();
    double dy2 = points[1].get_y() - points[2].get_y();
    sides[1] = sqrt(dx2*dx2 + dy2*dy2);
    double dx3 = points[0].get_x() - points[2].get_x();
    double dy3 = points[0].get_y() - points[2].get_y();
    sides[2] = sqrt(dx3*dx3 + dy3*dy3);
    double perimeter = this->perimeter() / 2;
    return sqrt(perimeter * (perimeter - sides[0]) * (perimeter - sides[1]) * (perimeter - sides[2]));
}

Trapezoid::Trapezoid(Point *p): points(new Point[5]), base_1(new Point[2]), base_2(new Point[2]){
    for (int i = 0; i < 4; i++){
        points[i] = p[i];
    }
    points[4] = p[0];
    base_1[0] = p[0];
    bool is_correct = false;
    for (int i = 1; i < 4; i++) {
        if (!is_correct) {
            if (p[i].get_x() == p[0].get_x()) {
                height = 'x';
                if (i == 1) {
                    base_1[1] = p[1];
                    if ((p[2].get_x() == p[3].get_x())) {
                        is_correct = true;
                        base_1[0] = p[2]; base_1[1] = p[3];
                    }
                    continue;
                }
                if (i == 2) {
                    base_1[1] = p[1];
                    if ((p[1].get_x() == p[3].get_x())) {
                        is_correct = true;
                        base_1[0] = p[1]; base_1[1] = p[3];
                    }
                    continue;
                }
                if (i == 3) {
                    base_1[0] = p[3];
                    if ((p[2].get_x() == p[1].get_x())) {
                        is_correct = true;
                        base_1[0] = p[2]; base_1[1] = p[1];
                    }
                    continue;
                }
            }
            if (p[i].get_y() == p[0].get_y()) {
                height = 'y';
                if (i == 1) {
                    base_1[1] = p[1];
                    if ((p[2].get_y() == p[3].get_y())) {
                        is_correct = true;
                        base_2[0] = p[2]; base_2[1] = p[3];
                    }
                    continue;
                }
                if (i == 2) {
                    base_1[1] = p[2];
                    if ((p[1].get_y() == p[3].get_y())) {
                        is_correct = true;
                        base_2[0] = p[1]; base_2[1] = p[3];
                    }
                    continue;
                }
                if (i == 3) {
                    base_1[1] = p[3];
                    if ((p[2].get_y() == p[1].get_y())) {
                        is_correct = true;
                        base_2[0] = p[1]; base_2[1] = p[2];
                    }
                    continue;
                }
            }
        }
    }
    if (!is_correct){
        std::cout << "Trapezoid in incorrect: no parallel sides";
        exit(1);
    }
}

Trapezoid::~Trapezoid() {
    delete[] points;
}

Trapezoid::Trapezoid(const Trapezoid &t): points(new Point [5]) {
    for (int i = 0; i < 5; i++){
        points[i] = t.points[i];
    }
    base_1 = t.base_1;
    base_2 = t.base_2;
    height = t.height;
}

Trapezoid &Trapezoid::operator = (const Trapezoid &t) {
    if (this != &t){
        delete [] this->points;
        points = new Point[t.points_number];
        points_number = t.points_number;
        for (int i = 0; i < 5; i++){
            points[i] = t.points[i];
        }
        base_1 = t.base_1;
        base_2 = t.base_2;
        height = t.height;
    }
    return *this;
}

double Trapezoid::perimeter() const {
    double result = 0;
    for (int i = 0; i < points_number - 1; i++){
        double dx = points[i].get_x() - points[i + 1].get_x();
        double dy = points[i].get_y() - points[i + 1].get_y();
        result += sqrt(dx*dx + dy*dy);
    }
    return result;
}

double Trapezoid::area() const {
    double length_base_1 = sqrt((base_1[0].get_x() - base_1[1].get_x()) * (base_1[0].get_x() - base_1[1].get_x()) +
                                (base_1[0].get_y() - base_1[1].get_y()) * (base_1[0].get_y() - base_1[1].get_y()));
    double length_base_2 = sqrt((base_2[0].get_x() - base_2[1].get_x()) * (base_2[0].get_x() - base_2[1].get_x()) +
                                (base_2[0].get_y() - base_2[1].get_y()) * (base_2[0].get_y() - base_2[1].get_y()));
    double h = std::abs(height == 'x' ? base_1[0].get_x() - base_2[0].get_x() : base_1[0].get_y() - base_2[0].get_y());
    return (length_base_2 + length_base_1) * h / 2;
}

RegularPolygon::RegularPolygon(int number, Point *p): points_number(number + 1), points(new Point[number + 1]){
    for (int i = 0; i < points_number - 1; i++){
        points[i] = p[i];
    }
    points[points_number - 1] = p[0];
    double expected_cos = get_cos(p[0], p[1], p[2]);
    double expected_length = get_length(points[0], points[1]);
    for (int i = 0; i < points_number - 1; i++){
        if(get_length(p[i], p[i + 1]) != expected_length) {
            std::cout << "Polygon is not regular";
            exit(2);
        }
        if (i == points_number - 2){
            if(abs(get_cos(p[i], p[0], p[1])) != expected_cos){
                std::cout << "Polygon is not regular";
                exit(2);
            }
        }
        else if (i == points_number - 3){
            if(abs(get_cos(p[i], p[i + 1], p[0])) != expected_cos){
                std::cout << "Polygon is not regular";
                exit(2);
            }
        }
        else if(get_cos(p[i], p[i+1], p[i+2]) != expected_cos){
            std::cout << "Polygon is not regular";
            exit(2);
        }
    }
}

RegularPolygon::~RegularPolygon() {
    delete [] points;
}


double RegularPolygon::get_length(const Point &p1, const Point &p2) {
    double dx = p2.get_x() - p1.get_x();
    double dy = p2.get_y() - p1.get_y();
    return sqrt(dx * dx + dy * dy);
}

double RegularPolygon::get_cos(const Point& p1, const Point& p2, const Point& p3) {
    double dx1 = p2.get_x() - p1.get_x();
    double dy1 = p2.get_y() - p1.get_y();
    double dx2 = p2.get_x() - p3.get_x();
    double dy2 = p2.get_y() - p3.get_y();
    double length_1 = get_length(p1, p2);
    double length_2 = get_length(p2, p3);
    return (dx1 * dx2 + dy1 * dy2) / (length_1 * length_2);
}

double RegularPolygon::perimeter() const {
    double result = 0;
    for (int i = 0; i < points_number - 1; i++) {
        result += get_length(points[i], points[i + 1]);
    }
    return result;
}


double RegularPolygon::area() const {
    double length = get_length(points[0], points[1]);
    return length * length * (points_number - 1) / (4 * tan(PI/(points_number - 1)));
}

RegularPolygon::RegularPolygon(const RegularPolygon &rp) : points_number(rp.points_number), points(new Point[points_number]){
        for (int i = 0; i < points_number; i++){
            points[i] = rp.points[i];
        }
}

RegularPolygon &RegularPolygon::operator = (const RegularPolygon &rp) {
    if (this != &rp){
        delete [] this->points;
        points = new Point[rp.points_number];
        points_number = rp.points_number;
        for (int i = 0; i < points_number; i++){
            points[i] = rp.points[i];
        }
    }
    return *this;
}


