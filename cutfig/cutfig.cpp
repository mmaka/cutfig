#include "cutfig.h"
#include "ui_cutfig.h"

CutFig::CutFig(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CutFig)
{
    ui->setupUi(this);
}

CutFig::~CutFig()
{
    delete ui;
}
