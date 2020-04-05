#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"
#include <string>

class Rectangle : public IFigure
{
public:
    size_t width, height;
    explicit Rectangle(size_t sizeX, size_t sizeY): width{sizeX}, height{sizeY}{}
    size_t getHeight() const override;
    size_t getWidth() const override;
    std::string print() const override;
    ~Rectangle() override = default;
};

#endif // RECTANGLE_H
