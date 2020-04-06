#include<catch2/catch.hpp>
#include "../src/tools.h"

TEST_CASE("Number of arranged rectanlges", "[positions]")
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
