#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "test.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT;


public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    enum class unit
    {
        m,
        mm,
        km,
        ft,
        in
    };
    Q_ENUM(unit);


private slots:
    void on_quitButton_clicked();

private:
    Ui::MainWindow *ui;
    test *m_test;
    void SetupUnitMenu();
    int last_index_unit;
    double last_pos_clicked;

    void Convert_menu_unit(int index);

protected:
    bool eventFilter(QObject *sender, QEvent *event);

};
#endif // MAINWINDOW_H
