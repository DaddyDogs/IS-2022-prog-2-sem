#include <iostream>
#include "Figures.h"

void PointCheck() {
    const Point p1;
    assert(p1.get_x() == 0 && p1.get_y() == 0);
    const Point p2(3, 4);
    assert(p2.get_x() == 3 && p2.get_y() == 4);
}

void InheritancePolygonalChainCheck(const Chain *pc, const ClosedChain *cpc) {
    assert(pc->perimeter() == 9);
    assert(cpc->perimeter() == 12);
}

void PolygonsCheck() {
    auto *a = new Point[3]{Point(0, 0), Point(3, 4), Point(3, 0)};
    auto *b = new Point[4]{Point(0, 0), Point(1, 4), Point(3, 4), Point(3, 0)};
    const Polygon p(3, a);
    const Triangle t(a);
    const Trapezoid tr(b);
    const Chain pc(3, a);
    assert(pc.perimeter() == 9);
    const ClosedChain cpc(3, a);
    assert(cpc.perimeter() == 12);
    InheritancePolygonalChainCheck(&pc, &cpc);
    assert(p.area() == 6);
    assert(tr.area() == 10);
    Trapezoid tra(b);
    tra = tr;
    assert(tra.area() == 10);
    auto* trap = new Trapezoid(b);
    Trapezoid trCopy(*trap);
    delete trap;
    assert(trCopy.area() == 10);
    RegularPolygon rp(4, new Point[4]{Point(0, 0), Point(0, 2), Point(2, 2), Point(2, 0)});
    assert(rp.perimeter() == 8);
    assert(int(rp.area()) == 4);
}

int main() {
    PointCheck();
    PolygonsCheck();
    return 0;
}
