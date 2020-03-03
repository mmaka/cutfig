#include <QtTest>
#include "../../../cutfig/cutfig/tools.h"
#include <vector>

// add necessary includes here

class cutfig_tests : public QObject
{
    Q_OBJECT

public:
    cutfig_tests();
    ~cutfig_tests();

private slots:
    void test_getNumber();
    void test_getNumber_data();

};

cutfig_tests::cutfig_tests()
{

}

cutfig_tests::~cutfig_tests()
{

}

void cutfig_tests::test_getNumber_data()
{
    std::vector<std::pair<int, int>> data {{1, 10}, {30, 300}, {45, 450}};
    QTest::addColumn<int>("number");
    QTest::addColumn<int>("result");
    for (const auto& [first, second] : data)
        QTest::newRow(QString("("+QString::number(first)+", "+QString::number(second)+")").toStdString().c_str()) << first << second;
}

void cutfig_tests::test_getNumber()
{
    QFETCH(int, number);
    QFETCH(int, result);
    QCOMPARE(get_number(number), result);
}

QTEST_APPLESS_MAIN(cutfig_tests)

#include "tst_cutfig_tests.moc"
