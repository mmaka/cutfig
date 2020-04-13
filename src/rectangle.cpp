#include "rectangle.h"
#include <sstream>

size_t Rectangle::getHeight() const {return height;}
size_t Rectangle::getWidth() const {return width;}

std::string Rectangle::print() const
{
    std::stringstream ss;
    ss << "("<<width << ", " << height << ")";
    return ss.str();
}
