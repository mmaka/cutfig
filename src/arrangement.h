#ifndef ARRANGEMENT_H
#define ARRANGEMENT_H

#include "figure.h"
#include "istencil.h"
#include "stencil.h"
#include "point.h"
#include <vector>
#include <algorithm>
#include <random>
#include <memory>
#include "rectangle.h"

class Arrangement {
public:
    std::unique_ptr<IStencilManager> stencilManager;
    Arrangement(int space){
        stencilManager = std::make_unique<StencilManager>(100, 200, space);
    }
    void generate(const std::vector<size_t> &indices, const std::vector<std::unique_ptr<IFigure>> &figures);
    void printPosition() const;
    Point& getPositionAtIndex(size_t index);
private:
    std::vector<PointFigureStencil> positions;
    void addFigure(const std::unique_ptr<IFigure> &figure);
};

#endif // ARRANGEMENT_H
