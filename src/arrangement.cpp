#include "arrangement.h"
#include <iostream>

void Arrangement::generate(const std::vector<size_t> &indices, const std::vector<std::unique_ptr<IFigure> > &figures)
{
    for(auto index : indices)
        addFigure(figures[index]);
}

void Arrangement::printPosition() const
{
    for(auto &item : positions){
        std::cout << "StencilNo: " << item.stencil << " position: " << item.point.print() << "(figure: " << item.figure->print() << ")\n";
    }
}

void Arrangement::addFigure(const std::unique_ptr<IFigure> &figure)
{
    positions.push_back(stencilManager->addFigure(figure));
}

Point& Arrangement::getPositionAtIndex(size_t index){
  return positions[index].point;
}
