#ifndef POINT_H
#define POINT_H

#include <memory>
#include <string>
#include <sstream>
#include "figure.h"

struct Point {
    size_t x, y; //>=0
    std::string print() const {
        std::stringstream ss;
        ss << "(" << x << ", " << y << ")";
        return  ss.str();
    }
};

struct PointFigureStencil {
    Point p;
    int stencil;
    const std::unique_ptr<IFigure> &figure;
};
#endif // POINT_H
