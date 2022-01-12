#ifndef TEST_POINT_H
#define TEST_POINT_H

#endif //TEST_POINT_H
#pragma once
#include <iostream>
using namespace std;
class Point
{
private:
    double x, y;
public:
    void setPoint(double in_x, double in_y)
    {
        x = in_x;
        y = in_y;
    }
    double get_x(){
        return x;
    }
    double get_y(){
        return y;
    }
    double distance(Point p)
    {
        return (x-p.get_x())*(x-p.get_x())+(y-p.get_y())*(y-p.get_y());
    }
};