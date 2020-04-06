#ifndef ISTENCIL_H
#define ISTENCIL_H

#include "ioccupancy.h"
#include "figure.h"
#include "point.h"
#include <memory>

class IStencil {
public:
    bool virtual determinePosition(Point& position, const std::unique_ptr<IFigure> &figure) = 0;
    virtual ~IStencil() = default;
};

class IStencilManager {
public:
    PointFigureStencil virtual addFigure(const std::unique_ptr<IFigure> &figure) = 0;
    int virtual rateStencils() const = 0;
    virtual ~IStencilManager() = default;
};
#endif // ISTENCIL_H
