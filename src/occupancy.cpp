#include "occupancy.h"

size_t Occupancy::getMaxYForFigure(const Point &position, const std::unique_ptr<IFigure> &figure) const
{
    auto startX = position.x;
    auto endX = position.x + figure->getWidth();
    auto maximalY = occupancyX[startX];
    auto sizeOfOccupancyX= occupancyX.size();

    if(endX != sizeOfOccupancyX-1) endX += space;

    for(auto i = startX; i<endX; ++i)
        if(occupancyX[i] < maximalY) maximalY = occupancyX[i];

    if (maximalY != height) maximalY -= space;

    return maximalY - figure->getHeight();
}

size_t Occupancy::getMaxXForFigure(const Point &position, const std::unique_ptr<IFigure> &figure) const
{
    auto maximalY = position.y + figure->getHeight();
    size_t startX = 0;

    for(auto i = position.x; i< occupancyX.size(); ++i){
        if(occupancyX[i] < maximalY) break;
        startX = i;
    }

    if(startX != width) startX -= space;

    return startX - figure->getWidth();
}

bool Occupancy::checkPosition(const Point &position, const std::unique_ptr<IFigure> &figure) const
{
    return position.y <= getMaxYForFigure(position, figure) && position.x <= getMaxXForFigure(position, figure);
}

bool Occupancy::setPosition(Point &position, const std::unique_ptr<IFigure> &figure)
{
    if (!checkPosition(position, figure)) return false;

    goMaxUp(position, figure);
    goMaxRight(position, figure);
    goMaxUp(position, figure);

    //we can go up and right in loop -> todo
    return true;
}

void Occupancy::goMaxUp(Point &position, const std::unique_ptr<IFigure> &figure)
{
    position.y = getMaxYForFigure(position, figure);
}

void Occupancy::goMaxRight(Point &position, const std::unique_ptr<IFigure> &figure)
{
    position.x = getMaxXForFigure(position, figure);
}

Occupancy::~Occupancy(){}
