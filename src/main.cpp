#include "cutfig.h"
#include<iostream>

int main()
{
    size_t numberOfIndividuals {3};
    size_t numberOfIterations {1};
    size_t numberOfPopulations {1};
    size_t numberOfIndividualsToChoose {1};
    size_t numberOfChoosen {1};
    size_t stencilSizeX {100};
    size_t stencilSizeY {20};
    size_t stencilSpaceBetweenFigures {0};
    Cutfig cutfig({
      numberOfIndividuals, numberOfIterations, numberOfPopulations,
      numberOfIndividualsToChoose, numberOfChoosen, stencilSizeX,
      stencilSizeY, stencilSpaceBetweenFigures
    });

    std::vector<std::unique_ptr<IFigure>> v;
    v.push_back(std::make_unique<Rectangle>(50, 20));
    v.push_back(std::make_unique<Rectangle>(50, 20));
    v.push_back(std::make_unique<Rectangle>(40, 10));
    try {
      cutfig.addInputFigures(std::move(v));
    } catch(const char* msg){
      std::cerr << msg << '\n';
      return 1;
    }
    std::vector<Arrangement> final = cutfig.geneticComputations();

    for (auto &arr : final)
        arr.printPosition();
}
