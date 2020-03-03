#ifndef CUTFIG_H
#define CUTFIG_H

#include <QMainWindow>

namespace Ui {
class CutFig;
}

class CutFig : public QMainWindow
{
    Q_OBJECT

public:
    explicit CutFig(QWidget *parent = 0);
    ~CutFig();

private:
    Ui::CutFig *ui;
};

#endif // CUTFIG_H
