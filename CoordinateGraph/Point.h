#ifndef LAB3_POINT_H
#define LAB3_POINT_H

#include <iostream>
#include <math.h>

class Point {
public:
    double x;
    double y;
    Point() = default;
    Point(double X, double Y) {
        x = X;
        y = Y;
    };

    friend std::ostream& operator << (std::ostream &out, const Point& point) {
        out << "{ x: " << point.x << "; y: " << point.y << " }";
        return out;
    }

    bool operator == (const Point& point) const {
        return x == point.x && y == point.y;
    }

    Point& operator = (const Point& point) = default;
};


#endif
