/********************************************************************************
** Form generated from reading UI file 'cutfig.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUTFIG_H
#define UI_CUTFIG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CutFig
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CutFig)
    {
        if (CutFig->objectName().isEmpty())
            CutFig->setObjectName(QStringLiteral("CutFig"));
        CutFig->resize(400, 300);
        menuBar = new QMenuBar(CutFig);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        CutFig->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CutFig);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        CutFig->addToolBar(mainToolBar);
        centralWidget = new QWidget(CutFig);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        CutFig->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(CutFig);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        CutFig->setStatusBar(statusBar);

        retranslateUi(CutFig);

        QMetaObject::connectSlotsByName(CutFig);
    } // setupUi

    void retranslateUi(QMainWindow *CutFig)
    {
        CutFig->setWindowTitle(QApplication::translate("CutFig", "CutFig", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CutFig: public Ui_CutFig {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUTFIG_H
