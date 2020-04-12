#include "cutfig.h"

Cutfig::Cutfig(const CutfigParams cutParams) : params{cutParams} {}

Cutfig::~Cutfig(){}

void Cutfig::addInputFigures(std::vector<std::unique_ptr<IFigure>> vectorOfIFigures){
  figures = std::move(vectorOfIFigures);
}

void Cutfig::mutation(std::vector<std::vector<size_t>> &populations){
  std::random_device randev;
  std::random_device::result_type seed = randev();
  std::default_random_engine randomengine(seed);
  std::uniform_int_distribution<size_t> ifmutate (0, 1);
  std::uniform_int_distribution<size_t> chooseindividual (0, populations[0].size()-1);
  size_t index1, index2;
  size_t val;

  for(auto& population : populations){
    if (ifmutate(randomengine)){
      index1 = chooseindividual(randomengine);
      do {
        index2 = chooseindividual(randomengine);
      }while(index1 == index2);

      val = population[index1];
      population[index1] = population[index2];
      population[index2] = val;
    }
  }
}

void Cutfig::crossing(std::vector<std::vector<size_t>> &populations, std::vector<size_t> &bests){
  std::vector<std::vector<size_t>> newPopulation;
  auto populationSize = populations.size();
  newPopulation.reserve(populationSize);
  auto bestsSize = bests.size();

  for(auto item : bests)
      newPopulation.push_back(populations[item]);

  for (size_t i = bestsSize; i < populationSize; ++i){
      std::vector<size_t> &v1 = populations[bests[i % bestsSize]];
      std::vector<size_t> &v2 = populations[bests[(i + 1) % bestsSize]];
      //newPopulation.push_back(mixingTwoPopulations(populations[bests[i % bestsSize]], populations[bests[(i + 1) % bestsSize]]));
      //newPopulation.push_back(mixingTwoPopulations(populations[bests[(i + 1) % bestsSize]], populations[bests[i % bestsSize]]));
      newPopulation.push_back(mixingTwoPopulations(v1, v2));
      newPopulation.push_back(mixingTwoPopulations(v2, v1));
  }
}

std::vector<size_t> Cutfig::mixingTwoPopulations(const std::vector<size_t> &population1, const std::vector<size_t> &population2){
  auto populationSize = population1.size();
  auto numberOfElements = static_cast<size_t>(std::floor(populationSize/2));
  std::vector<size_t>::difference_type offset = static_cast<std::vector<size_t>::difference_type>(numberOfElements);
  std::vector<size_t> result;
  result.reserve(populationSize);

  std::copy_n(population1.begin(), numberOfElements, std::back_inserter(result));
  for (size_t i = 0, position = numberOfElements; i < populationSize; ++i){
      if(std::find(population1.begin(), population1.cbegin() + offset, population2[i]) == population1.begin() + offset)
          result[position++] = population2[i];
  }
  return result;
}

std::vector<size_t> Cutfig::chooseBestIndividuals(std::vector<Arrangement> &arrangement, size_t numberOfIndividualsToChoose){
  std::vector<std::tuple<size_t, int>> rated;
  rated.reserve(arrangement.size());

  for (size_t i = 0; i<arrangement.size(); ++i)
      rated[i] = std::tuple<size_t, int> (i, arrangement[i].stencilManager->rateStencils());

  std::sort(rated.begin(), rated.end(), [](const auto &t1, const auto &t2){return std::get<1>(t1) > std::get<1>(t2);});
  std::vector<size_t> choosen;
  choosen.reserve(numberOfIndividualsToChoose);

  for (size_t i = 0; i < numberOfIndividualsToChoose; ++i)
      choosen.push_back(std::get<0>(rated[i]));

  return choosen;
}

void Cutfig::generateArrangements(const std::vector<std::unique_ptr<IFigure>> &vectorOfIFigures, std::vector<std::vector<size_t>> &indexing, std::vector<Arrangement> &arrangements){
  for(size_t i = 0; i < indexing.size(); ++i){
      arrangements[i].generate(indexing[i], vectorOfIFigures);
  }
}

void Cutfig::generatePopulation(std::vector<std::vector<size_t>> &populations){
  for(auto &population : populations){
      std::iota(population.begin(), population.end(), 0);
      std::shuffle(population.begin(), population.end(), std::default_random_engine());
  }
}

std::vector<Arrangement> Cutfig::geneticComputations(){
  std::vector<std::vector<size_t>> populations {params.numberOfPopulations};
  for(auto& p : populations)
      p.resize(params.numberOfIndividuals);

  generatePopulation(populations);

  std::vector<Arrangement> arrangements;
  arrangements.reserve(params.numberOfPopulations);
  std::vector<Arrangement> finalArrangements;
  finalArrangements.reserve(params.numberOfIterations);

  for(size_t i=0; i < params.numberOfIterations; ++i){
      for(size_t j = 0; j < params.numberOfPopulations; ++j)
          arrangements.emplace_back(0);

      generateArrangements(figures, populations, arrangements);
      std::vector<size_t> bests = chooseBestIndividuals(arrangements, params.numberOfChoosen);
      finalArrangements.push_back(std::move(arrangements[bests[0]]));
      crossing(populations, bests);
      mutation(populations);
      arrangements.clear();
  }
  return finalArrangements;
}
