#ifndef STENCIL_H
#define STENCIL_H
#include <memory>
#include "occupancy.h"
#include "istencil.h"

class Stencil : public IStencil {
private:
    std::unique_ptr<IOccupancy> occupancy;
    //int width, height, space;
public:
    explicit Stencil(int sizeX, int sizeY, int space){//: width{sizeX}, height{sizeY}, space{space}{
        occupancy = std::make_unique<Occupancy>(sizeX, sizeY, space);
    }
    bool determinePosition(Point& position, const std::unique_ptr<IFigure> &figure) override;
    ~Stencil() override;
};

class StencilManager : public IStencilManager {
private:
    std::vector<std::unique_ptr<IStencil>> stenciles;
    int width, height, space;
public:
    StencilManager(int sizeX, int sizeY, int p_space = 0): width{sizeX}, height{sizeY}, space{p_space} {
        stenciles.push_back(std::make_unique<Stencil>(sizeX, sizeY, space));
    }
    PointFigureStencil addFigure(const std::unique_ptr<IFigure> &figure) override;
    int rateStencils() const override;
    ~StencilManager() override;
};
#endif // STENCIL_H
