#ifndef POINT_H
#define POINT_H

#include <memory>
#include <string>
#include <sstream>
#include "figure.h"

struct Point {
    size_t x, y; //>=0
    Point(size_t a, size_t b) : x{a}, y{b} {}
    std::string print() const {
        std::stringstream ss;
        ss << "(" << x << ", " << y << ")";
        return  ss.str();
    }
    friend bool operator==(const Point& p1, const Point& p2);
};

struct PointFigureStencil {
    Point point;
    int stencil;
    const std::unique_ptr<IFigure> &figure;
};
#endif // POINT_H
