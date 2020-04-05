#include "cutfig.h"
#include <QApplication>
#include "tools.h"

int main(int argc, char *argv[])
{
    //QApplication a(argc, argv);
    //CutFig w;
    //w.show();

    std::vector<std::unique_ptr<IFigure>> v;
    v.push_back(std::make_unique<Rectangle>(10, 20));
    v.push_back(std::make_unique<Rectangle>(20, 20));
    v.push_back(std::make_unique<Rectangle>(30, 20));
    v.push_back(std::make_unique<Rectangle>(40, 20));
    v.push_back(std::make_unique<Rectangle>(50, 20));
    v.push_back(std::make_unique<Rectangle>(60, 20));

    std::vector<Arrangement> final = geneticComputations(1, 6, v, 1, 1);

    for (auto &arr : final)
        arr.printPosition();
    //return a.exec();
}
