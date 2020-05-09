#include "stencil.h"
#include "istencil.h"
#include<iostream>

PointFigureStencil StencilManager::addFigure(const std::unique_ptr<IFigure> &figure)
{
    Point position {0, 0};
    size_t stencilNo = 0;

    while (!stenciles[stencilNo]->determinePosition(position, figure)){
       if(stencilNo == stenciles.size()-1)
           stenciles.push_back(std::make_unique<Stencil>(width, height, space));
       stencilNo++;
    }

    return {std::move(position), static_cast<int>(stencilNo), figure};
}

int StencilManager::rateStencils() const
{
    return 0;
}
bool Stencil::determinePosition(Point &position, const std::unique_ptr<IFigure> &figure)
{
    return occupancy->setPosition(position, figure);
}

Stencil::~Stencil(){}

StencilManager::~StencilManager(){}
