#include "stencil.h"
#include "istencil.h"

PointFigureStencil StencilManager::addFigure(const std::unique_ptr<IFigure> &figure)
{
    Point position {0, 0};
    int stencilNo = 0;

    for (auto& stencil : stenciles){
        if(!stencil->determinePosition(position, figure)){
            if(stencilNo == static_cast<int>(stenciles.size()-1))
                stenciles.push_back(std::make_unique<Stencil>(width, height, space));
            ++stencilNo;
        } else
            break;
    }
    return {std::move(position), stencilNo, figure};
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
