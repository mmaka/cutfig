#ifndef IOCCUPANCY_H
#define IOCCUPANCY_H

#include "figure.h"
#include "point.h"
#include <memory>

class IOccupancy {
public:
    size_t virtual getMaxYForFigure(const Point &p, const std::unique_ptr<IFigure> &figure) const = 0;
    size_t virtual getMaxXForFigure(const Point &p, const std::unique_ptr<IFigure> &figure) const = 0;
    bool virtual setPosition(Point &p, const std::unique_ptr<IFigure> &figure) = 0;
    virtual ~IOccupancy() = default;
};
#endif // IOCCUPANCY_H
