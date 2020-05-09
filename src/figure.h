#ifndef FIGURE_H
#define FIGURE_H

#include <string>

class IFigure {
public:
    int virtual getHeight() const = 0;
    int virtual getWidth() const = 0;
    std::string virtual print() const = 0;
    virtual ~IFigure() = default;
};

#endif // FIGURE_H
