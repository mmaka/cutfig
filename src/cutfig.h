#include "arrangement.h"
#include<string>

struct CutfigParams {
  size_t numberOfIndividuals;
  size_t numberOfIterations;
  size_t numberOfPopulations;
  size_t numberOfIndividualsToChoose;
  size_t numberOfChoosen;
};

class ICutfig {
public:
  virtual void addInputFigures(std::vector<std::unique_ptr<IFigure>> vectorOfIFigures) = 0;
  virtual std::vector<Arrangement> geneticComputations() = 0;
  virtual ~ICutfig() = default;
};

class Cutfig : public ICutfig {
  CutfigParams params;
  std::vector<std::unique_ptr<IFigure>> figures;
public:
  explicit Cutfig(const CutfigParams cutParams);
  void addInputFigures(std::vector<std::unique_ptr<IFigure>> vectorOfIFigures) override;
  std::vector<Arrangement> geneticComputations() override;
  ~Cutfig();
private:
  void mutation(std::vector<std::vector<size_t>> &populations);
  void crossing(std::vector<std::vector<size_t>> &populations, std::vector<size_t> &bests);
  std::vector<size_t> mixingTwoPopulations(const std::vector<size_t> &population1, const std::vector<size_t> &population2);
  std::vector<size_t> chooseBestIndividuals(std::vector<Arrangement> &arrangement, size_t numberOfIndividualsToChoose);
  void generateArrangements(const std::vector<std::unique_ptr<IFigure>> &figures, std::vector<std::vector<size_t>> &indexing, std::vector<Arrangement> &arrangements);
  void generatePopulation(std::vector<std::vector<size_t>> &populations);
};
