#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"
#include <string>

class Rectangle : public IFigure
{
public:
    int width, height;
    explicit Rectangle(int sizeX, int sizeY): width{sizeX}, height{sizeY}{}
    int getHeight() const override;
    int getWidth() const override;
    std::string print() const override;
    ~Rectangle() override = default;
};

#endif // RECTANGLE_H
