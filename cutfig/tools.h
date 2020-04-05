#ifndef TOOLS_H
#define TOOLS_H

#include "arrangement.h"

void generatePopulation(std::vector<std::vector<size_t>> &populations)
{
    for(auto &population : populations){
        std::iota(population.begin(), population.end(), 0);
        std::shuffle(population.begin(), population.end(), std::default_random_engine());
    }
}

void generateArrangements(const std::vector<std::unique_ptr<IFigure>> &figures, std::vector<std::vector<size_t>> &indexing, std::vector<Arrangement> &arrangements)
{
    for(size_t i = 0; i < indexing.size(); ++i){
        arrangements[i].generate(indexing[i], figures);
    }
}

std::vector<size_t> chooseBestIndividuals(std::vector<Arrangement> &arrangement, size_t numberOfIndividualsToChoose)
{
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

std::vector<size_t> mixingTwoPopulations(const std::vector<size_t> &population1, const std::vector<size_t> &population2)
{
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

void crossing(std::vector<std::vector<size_t>> &populations, std::vector<size_t> &bests)
{
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

void mutation(std::vector<std::vector<size_t>> &populations)
{
    std::random_device ranDev;
    std::random_device::result_type seed = ranDev();
    std::default_random_engine randomEngine(seed);
    std::uniform_int_distribution<size_t> ifMutate (0, 1);
    std::uniform_int_distribution<size_t> chooseIndividual (0, populations[0].size()-1);
    size_t index1, index2;
    size_t val;

    for(auto& population : populations){
        if (ifMutate(randomEngine)){
            index1 = chooseIndividual(randomEngine);
            do {
                index2 = chooseIndividual(randomEngine);
            }while(index1 == index2);

            val = population[index1];
            population[index1] = population[index2];
            population[index2] = val;
        }
    }
}

auto geneticComputations(size_t numberOfPopulations, size_t numberOfIndividuals, const std::vector<std::unique_ptr<IFigure>> &figures, size_t numberOfIterations = 100, size_t numberOfChoosen = 5)
{
    std::vector<std::vector<size_t>> populations {numberOfPopulations};
    for(auto& p : populations)
        p.resize(numberOfIndividuals);

    generatePopulation(populations);

    std::vector<Arrangement> arrangements;
    arrangements.reserve(numberOfPopulations);
    std::vector<Arrangement> finalArrangements;
    finalArrangements.reserve(numberOfIterations);

    for(size_t i=0; i < numberOfIterations; ++i){
        for(size_t j = 0; j < numberOfPopulations; ++j)
            arrangements.emplace_back(0);

        generateArrangements(figures, populations, arrangements);
        std::vector<size_t> bests = chooseBestIndividuals(arrangements, numberOfChoosen);
        finalArrangements.push_back(std::move(arrangements[bests[0]]));
        crossing(populations, bests);
        mutation(populations);
        arrangements.clear();
    }
    return finalArrangements;
}

#endif // TOOLS_H
