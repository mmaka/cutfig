#ifndef OCCUPANCY_H
#define OCCUPANCY_H

#include <vector>
#include "ioccupancy.h"

class Occupancy : public IOccupancy {
    std::vector<size_t> occupancyX;
    size_t width, height, space;
public:
    explicit Occupancy(size_t sizeX, size_t sizeY, size_t space): width {sizeX}, height{sizeY}, space{space} {
        occupancyX = std::vector<size_t> (sizeX, sizeY);
    }
    bool setPosition(Point &position, const std::unique_ptr<IFigure> &figure) override;
    virtual ~Occupancy() override;
private:
    size_t getMaxYForFigure(const Point &position, const std::unique_ptr<IFigure> &figure) const override;
    size_t getMaxXForFigure(const Point &position, const std::unique_ptr<IFigure> &figure) const override;
    bool checkPosition(const Point &p, const std::unique_ptr<IFigure> &figure) const;
    void goMaxUp(Point& position, const std::unique_ptr<IFigure> &figure);
    void goMaxRight(Point &position, const std::unique_ptr<IFigure> &figure);
};
#endif // OCCUPANCY_H
