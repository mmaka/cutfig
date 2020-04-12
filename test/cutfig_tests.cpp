#include<catch2/catch.hpp>
#include "../src/tools.h"
#include "../src/point.h"

TEST_CASE("Number of returned vectors", "[number]")
{
    std::vector<std::unique_ptr<IFigure>> v;
    v.push_back(std::make_unique<Rectangle>(10, 20));
    v.push_back(std::make_unique<Rectangle>(20, 20));
    v.push_back(std::make_unique<Rectangle>(30, 20));
    v.push_back(std::make_unique<Rectangle>(40, 20));
    v.push_back(std::make_unique<Rectangle>(50, 20));
    v.push_back(std::make_unique<Rectangle>(60, 20));

    std::vector<Arrangement> final = geneticComputations(1, 6, v, 1, 1);
    REQUIRE(final.size() == 1);
}

TEST_CASE("Position of arranged rectanlge", "[positions]")
{
    std::vector<std::unique_ptr<IFigure>> v;
    v.push_back(std::make_unique<Rectangle>(10, 20));
    std::vector<Arrangement> final = geneticComputations(1, 1, v, 1, 1);
    REQUIRE(final[0].getPositionAtIndex(0).print() == "(89, 180)");
}
