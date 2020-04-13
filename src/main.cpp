#include "cutfig.h"
#include<iostream>

int main()
{
    size_t numberOfIndividuals {6};
    size_t numberOfIterations {1};
    size_t numberOfPopulations {1};
    size_t numberOfIndividualsToChoose {1};
    size_t numberOfChoosen {1};
    Cutfig cutfig({numberOfIndividuals, numberOfIterations, numberOfPopulations, numberOfIndividualsToChoose, numberOfChoosen});

    std::vector<std::unique_ptr<IFigure>> v;
    v.push_back(std::make_unique<Rectangle>(10, 20));
    v.push_back(std::make_unique<Rectangle>(20, 20));
    v.push_back(std::make_unique<Rectangle>(30, 20));
    v.push_back(std::make_unique<Rectangle>(40, 20));
    v.push_back(std::make_unique<Rectangle>(50, 20));
    v.push_back(std::make_unique<Rectangle>(60, 20));
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
