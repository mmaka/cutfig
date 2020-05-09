#ifndef OCCUPANCY_H
#define OCCUPANCY_H

#include <vector>
#include "ioccupancy.h"

class Occupancy : public IOccupancy {
    std::vector<int> occupancyX;
    int width, height, space;
public:
    explicit Occupancy(int sizeX, int sizeY, int p_space): width {sizeX}, height{sizeY}, space{p_space} {
        occupancyX = std::vector<int> (static_cast<size_t>(sizeX), sizeY-1);
    }
    bool setPosition(Point &position, const std::unique_ptr<IFigure> &figure) override;
    virtual ~Occupancy() override;
private:
    int getMaxYForFigure(const Point &position, const std::unique_ptr<IFigure> &figure) const override;
    int getMaxXForFigure(const Point &position, const std::unique_ptr<IFigure> &figure) const override;
    bool checkPosition(const Point &p, const std::unique_ptr<IFigure> &figure) const;
    void goMaxUp(Point& position, const std::unique_ptr<IFigure> &figure);
    void goMaxRight(Point &position, const std::unique_ptr<IFigure> &figure);
    void updateOccupancyInfo(const Point &position, const std::unique_ptr<IFigure> &figure);
};
#endif // OCCUPANCY_H
