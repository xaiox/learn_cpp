#include <iostream>
#include <string>
using namespace std;
#include "point.h"
#include "circle.h"


int main() {
    Point p1, p2, p3;
    Circle c;
    p1.setPoint(10, 10);
    p2.setPoint(5, 0);
    p3.setPoint(-1, 0);
    c.set_r(10);
    c.set_center(10, 0);
    c.isIn(p1);
    c.isIn(p2);
    c.isIn(p3);

}
