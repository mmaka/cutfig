#include "occupancy.h"
#include <iostream>
#include<algorithm>

int Occupancy::getMaxYForFigure(const Point &position, const std::unique_ptr<IFigure> &figure) const
{
    int startX = position.x;
    int endX = position.x + figure->getWidth();
    int maximalY = occupancyX[static_cast<size_t>(startX)];
    int sizeOfOccupancyX= static_cast<int>(occupancyX.size());

    if(endX != sizeOfOccupancyX-1) endX += space;

    for(size_t i = static_cast<size_t>(startX), end = static_cast<size_t>(endX); i<end; ++i)
        if(occupancyX[i] < maximalY) maximalY = occupancyX[i];

    if (maximalY != height) maximalY -= space;

    return maximalY - (figure->getHeight()-1);
}

int Occupancy::getMaxXForFigure(const Point &position, const std::unique_ptr<IFigure> &figure) const
{
    int maximalY = position.y + figure->getHeight() - 1;

    int startX = 0;

    for(size_t i = static_cast<size_t>(position.x), size = occupancyX.size(); i< size; ++i){
        if(occupancyX[i] < maximalY)
          break;
        startX = static_cast<int>(i);
    }
    if(startX != width) startX -= space;

    return startX - (figure->getWidth() - 1);
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
    updateOccupancyInfo(position, figure);
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

void Occupancy::updateOccupancyInfo(const Point &position, const std::unique_ptr<IFigure> &figure){
   auto start = occupancyX.begin() + position.x;
   auto stop = occupancyX.begin() + position.x + figure->getWidth();
   std::fill(start, stop, position.y);
}
Occupancy::~Occupancy(){}
