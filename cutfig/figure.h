#ifndef FIGURE_H
#define FIGURE_H

#include <cstddef>
#include <string>

class IFigure {
public:
    size_t virtual getHeight() const = 0;
    size_t virtual getWidth() const = 0;
    std::string virtual print() const = 0;
    virtual ~IFigure() = default;
};

#endif // FIGURE_H
