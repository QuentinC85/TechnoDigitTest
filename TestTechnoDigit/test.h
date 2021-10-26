#ifndef TEST_H
#define TEST_H

#include <QWidget>
#include <QtTest/QtTest>
#include "ui_mainwindow.h"

class test : public QWidget
{
    Q_OBJECT
public:
    test(Ui::MainWindow *m_ui){this->m_ui = m_ui;}
    virtual ~test() {}


public slots :
    void button_test_clicked();

private:
    void launch_test();
    bool test_connection_widget();

    Ui::MainWindow *m_ui;
};




#endif // TEST_H
