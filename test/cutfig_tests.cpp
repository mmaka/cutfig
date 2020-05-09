#include<catch2/catch.hpp>
#include "../src/cutfig.h"
#include "../src/point.h"

TEST_CASE("Number of returned vectors", "[number]")
{
    size_t numberOfIndividuals {6};
    size_t numberOfIterations {1};
    size_t numberOfPopulations {1};
    size_t numberOfIndividualsToChoose {1};
    size_t numberOfChoosen {1};
    size_t stencilSizeX {100};
    size_t stencilSizeY {200};
    size_t stencilSpaceBetweenFigures {0};
    Cutfig cutfig({
      numberOfIndividuals, numberOfIterations, numberOfPopulations,
      numberOfIndividualsToChoose, numberOfChoosen, stencilSizeX,
      stencilSizeY, stencilSpaceBetweenFigures
    });
    std::vector<std::unique_ptr<IFigure>> v;
    v.push_back(std::make_unique<Rectangle>(10, 20));
    v.push_back(std::make_unique<Rectangle>(20, 20));
    v.push_back(std::make_unique<Rectangle>(30, 20));
    v.push_back(std::make_unique<Rectangle>(40, 20));
    v.push_back(std::make_unique<Rectangle>(50, 20));
    v.push_back(std::make_unique<Rectangle>(60, 20));
    cutfig.addInputFigures(std::move(v));
    std::vector<Arrangement> final = cutfig.geneticComputations();
    REQUIRE(final.size() == 1);
}

TEST_CASE("Position of arranged rectanlge", "[positions]")
{
  size_t numberOfIndividuals {1};
  size_t numberOfIterations {1};
  size_t numberOfPopulations {1};
  size_t numberOfIndividualsToChoose {1};
  size_t numberOfChoosen {1};
  size_t stencilSizeX {100};
  size_t stencilSizeY {200};
  size_t stencilSpaceBetweenFigures {0};
  Cutfig cutfig({
    numberOfIndividuals, numberOfIterations, numberOfPopulations,
    numberOfIndividualsToChoose, numberOfChoosen, stencilSizeX,
    stencilSizeY, stencilSpaceBetweenFigures
  });

  std::vector<std::unique_ptr<IFigure>> v;
  v.push_back(std::make_unique<Rectangle>(10, 20));
  cutfig.addInputFigures(std::move(v));
  std::vector<Arrangement> final = cutfig.geneticComputations();
  REQUIRE(final[0].getPositionAtIndex(0).print() == "(90, 180)");
}
