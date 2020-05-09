#include "rectangle.h"
#include <sstream>

int Rectangle::getHeight() const {return height;}
int Rectangle::getWidth() const {return width;}

std::string Rectangle::print() const
{
    std::stringstream ss;
    ss << "("<<width << ", " << height << ")";
    return ss.str();
}
