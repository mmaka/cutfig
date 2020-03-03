#include "cutfig.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CutFig w;
    w.show();

    return a.exec();
}
