#ifndef TEST_CIRCLE_H
#define TEST_CIRCLE_H

#endif //TEST_CIRCLE_H
#pragma once
#include <iostream>
using namespace std;
#include "point.h"

class Circle
{
private:
    Point center;
    double r;
public:
    void set_r(double in_r)
    {
        r = in_r;
    }
    void set_center(double x, double y)
    {
        center.setPoint(x, y);
    }
    void isIn(Point p)
    {
        if(p.distance(center)>r*r)
            cout << "点在圆外" << endl;
        else if(p.distance(center)==r*r)
            cout << "点在圆上" << endl;
        else
            cout << "点在圆内" << endl;
    }
};